/*
	-----------------------------------------------
	Ruben Cobos
	12/7/2022
	COSC-1437-58001
	Microsoft Visual Studio Community 2022 (64-bit)
	Unit 7 - Recursion
	-----------------------------------------------
 */

#include "game_set.h"


void Draw_Game(Tower&); // Draws the entire game set to the screen.

/* Solution based on the description of the iterative
solution from the following Wikepedia page:
https://en.wikipedia.org/wiki/Tower_of_Hanoi */

void Solve(Tower&); // Solves the game puzzle.


int main()
{
	Tower Game; // A virtual Tower of Hanoi game set.

	// Create a virtual set of 7 disks.

	const Disk d1 = { 1, 6 };
	const Disk d2 = { 3, 5 };
	const Disk d3 = { 5, 4 };
	const Disk d4 = { 7, 3 };
	const Disk d5 = { 9, 2 };
	const Disk d6 = { 11, 1 };
	const Disk d7 = { 13, 0 };

	// Place the disks on the first rod.

	Game.Add_Disk(d7, 1);
	Game.Add_Disk(d6, 1);
	Game.Add_Disk(d5, 1);
	Game.Add_Disk(d4, 1);
	Game.Add_Disk(d3, 1);
	Game.Add_Disk(d2, 1);
	Game.Add_Disk(d1, 1);

	cout << 0 << endl;

	// Begin process.

	Draw_Game(Game);
	Solve(Game);

	// End program.
  
	return 0;
}

void Draw_Game(Tower& t) // Draws the entire game set to the screen.
{
	int line = 7;

	cout << "      |      ";
	cout << "   ";
	cout << "      |      ";
	cout << "   ";
	cout << "      |      ";
	cout << endl;

	while (line > 0)
	{
		if (t.Get_Size(1) >= line)
		{
			t.Get_Disk(1, (line - 1)).Draw_Disk();
		}
		else
		{
			cout << "      |      ";
		}

		cout << "   ";

		if (t.Get_Size(2) >= line)
		{
			t.Get_Disk(2, (line - 1)).Draw_Disk();
		}
		else
		{
			cout << "      |      ";
		}

		cout << "   ";

		if (t.Get_Size(3) >= line)
		{
			t.Get_Disk(3, (line - 1)).Draw_Disk();
		}
		else
		{
			cout << "      |      ";
		}

		cout << endl;

		--line;
	}

	cout << "---------------";
	cout << "---------------";
	cout << "----------------";
	cout << endl;
}

void Solve(Tower& t) // Solves the game puzzle.
{
	int rodA = 0;
	int rodB = 0;

	static int move_num = 0;

	++move_num;
	cout << move_num << endl;
  
  // Move the smallest piece to the left.
  //
	// rod1
	if (t.Get_Size(1) > 0 &&
		t.Get_Disk(1, t.Get_Size(1) - 1).Get_Diameter() == 1)
	{
		t.Move_Disk(1, 3);
	}
	// rod2
	else if (t.Get_Size(2) > 0 &&
			 t.Get_Disk(2, t.Get_Size(2) - 1).Get_Diameter() == 1)
	{
		t.Move_Disk(2, 1);
	}
	// rod3
	else if (t.Get_Size(3) > 0 &&
			 t.Get_Disk(3, t.Get_Size(3) - 1).Get_Diameter() == 1)
	{
		t.Move_Disk(3, 2);
	}

	Draw_Game(t);

	++move_num;

	if (move_num < 128)
	{
		cout << move_num << endl;
	}
  
  // Only 1 legal move left.
  //
	// rod1
	if (t.Get_Size(1) > 0 && t.Get_Disk(1, t.Get_Size(1) - 1).Get_Diameter() != 1)
	{
		// from rod1 to rod2
		if (t.Get_Size(2) == 0)
		{
			t.Move_Disk(1, 2);
		}
		else if (t.Get_Disk(1, t.Get_Size(1) - 1).Get_Diameter() <
				 t.Get_Disk(2, t.Get_Size(2) - 1).Get_Diameter())
		{
			t.Move_Disk(1, 2);
		}
		else if (t.Get_Disk(1, t.Get_Size(1) - 1).Get_Diameter() >
				 t.Get_Disk(2, t.Get_Size(2) - 1).Get_Diameter() &&
				 t.Get_Disk(2, t.Get_Size(2) - 1).Get_Diameter() != 1)
		{
			t.Move_Disk(2, 1);
		}
		// from rod1 to rod3
		if (t.Get_Size(3) == 0)
		{
			t.Move_Disk(1, 3);
		}
		else if (t.Get_Disk(1, t.Get_Size(1) - 1).Get_Diameter() <
				 t.Get_Disk(3, t.Get_Size(3) - 1).Get_Diameter())
		{
			t.Move_Disk(1, 3);
		}
		else if (t.Get_Disk(1, t.Get_Size(1) - 1).Get_Diameter() >
				 t.Get_Disk(3, t.Get_Size(3) - 1).Get_Diameter() &&
				 t.Get_Disk(3, t.Get_Size(3) - 1).Get_Diameter() != 1)
		{
			t.Move_Disk(3, 1);
		}
	}
	// rod2
	else if (t.Get_Size(2) > 0 && t.Get_Disk(2, t.Get_Size(2) - 1).Get_Diameter() != 1)
	{
		// from rod2 to rod1
		if (t.Get_Size(1) == 0)
		{
			t.Move_Disk(2, 1);
		}
		else if (t.Get_Disk(2, t.Get_Size(2) - 1).Get_Diameter() <
				 t.Get_Disk(1, t.Get_Size(1) - 1).Get_Diameter())
		{
			t.Move_Disk(2, 1);
		}
		else if (t.Get_Disk(2, t.Get_Size(2) - 1).Get_Diameter() >
				 t.Get_Disk(1, t.Get_Size(1) - 1).Get_Diameter() &&
				 t.Get_Disk(1, t.Get_Size(1) - 1).Get_Diameter() != 1)
		{
			t.Move_Disk(1, 2);
		}
		// from rod2 to rod3
		if (t.Get_Size(3) == 0)
		{
			t.Move_Disk(2, 3);
		}
		else if (t.Get_Disk(2, t.Get_Size(2) - 1).Get_Diameter() <
				 t.Get_Disk(3, t.Get_Size(3) - 1).Get_Diameter())
		{
			t.Move_Disk(2, 3);
		}
		else if (t.Get_Disk(2, t.Get_Size(2) - 1).Get_Diameter() >
				 t.Get_Disk(3, t.Get_Size(3) - 1).Get_Diameter() &&
				 t.Get_Disk(3, t.Get_Size(3) - 1).Get_Diameter() != 1)
		{
			t.Move_Disk(3, 2);
		}
	}
	// rod3
	else if (t.Get_Size(3) > 0 && t.Get_Disk(3, t.Get_Size(3) - 1).Get_Diameter() != 1)
	{
		// from rod3 to rod1
		if (t.Get_Size(1) == 0)
		{
			t.Move_Disk(3, 1);
		}
		else if (t.Get_Disk(3, t.Get_Size(3) - 1).Get_Diameter() <
				 t.Get_Disk(1, t.Get_Size(1) - 1).Get_Diameter())
		{
			t.Move_Disk(3, 1);
		}
		else if (t.Get_Disk(3, t.Get_Size(3) - 1).Get_Diameter() >
				 t.Get_Disk(1, t.Get_Size(1) - 1).Get_Diameter() &&
				 t.Get_Disk(1, t.Get_Size(1) - 1).Get_Diameter() != 1)
		{
			t.Move_Disk(1, 3);
		}
		// from rod3 to rod2
		if (t.Get_Size(2) == 0)
		{
			t.Move_Disk(3, 2);
		}
		else if (t.Get_Disk(3, t.Get_Size(3) - 1).Get_Diameter() <
				 t.Get_Disk(2, t.Get_Size(2) - 1).Get_Diameter())
		{
			t.Move_Disk(3, 2);
		}
		else if (t.Get_Disk(3, t.Get_Size(3) - 1).Get_Diameter() >
				 t.Get_Disk(2, t.Get_Size(2) - 1).Get_Diameter() &&
				 t.Get_Disk(2, t.Get_Size(2) - 1).Get_Diameter() != 1)
		{
			t.Move_Disk(2, 3);
		}
	}

	if (move_num < 128)
	{
		Draw_Game(t);
	}

	if (t.Get_Size(2) == 7 || t.Get_Size(3) == 7)
	{
		return;
	}
	else
	{
		Solve(t); // Recursion.
	}
}