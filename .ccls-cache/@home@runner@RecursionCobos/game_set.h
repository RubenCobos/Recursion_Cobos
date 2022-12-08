/*
	-----------------------------------------------
	Ruben Cobos
	12/7/2022
	COSC-1437-58001
	Microsoft Visual Studio Community 2022 (64-bit)
	Unit 7 - Recursion
	-----------------------------------------------
 */

#include <iostream>
#include <vector>


using namespace std;


class Disk // A Tower of Hanoi disk object.
{
	private:

		int diameter;
		int spacing;

	public:

		Disk() { diameter = 0; spacing = 0; }
		Disk(int d, int s) { diameter = d; spacing = s; }
		void Set_Diameter(int d) { diameter = d; }
		void Set_Spacing(int s) { spacing = s; }
		int Get_Diameter() const { return diameter; }
		int Get_Spacing() const { return spacing; }
		void Draw_Disk() const;
		~Disk() { ; }
};

void Disk::Draw_Disk() const // Draws a disk to the screen.
{
	for (int i = 0; i < spacing; ++i)
	{
		cout << ' ';
	}
	for (int i = 0; i < diameter; ++i)
	{
		cout << '=';
	}
	for (int i = 0; i < spacing; ++i)
	{
		cout << ' ';
	}
}

class Tower // A virtual Tower of Hanoi game set.
{
	private:

		vector<Disk> rod1;
		vector<Disk> rod2;
		vector<Disk> rod3;

	public:

		Tower() { ; }
		void Add_Disk(const Disk&, int);
		void Remove_Disk(int);
		int Get_Size(int) const;
		const Disk& Get_Disk(int, int) const;
		void Move_Disk(int, int);
		~Tower() { ; }
};

void Tower::Add_Disk(const Disk& d, int rod) // Add a disk to a rod.
{
	if (rod == 1)
	{
		rod1.push_back(d);
	}
	if (rod == 2)
	{
		rod2.push_back(d);
	}
	if (rod == 3)
	{
		rod3.push_back(d);
	}
}

void Tower::Remove_Disk(int rod) // Remove a disk from a rod.
{
	if (rod == 1)
	{
		rod1.pop_back();
	}
	if (rod == 2)
	{
		rod2.pop_back();
	}
	if (rod == 3)
	{
		rod3.pop_back();
	}
}

int Tower::Get_Size(int rod) const // Get the stack size of a rod.
{
	if (rod == 1)
	{
		return rod1.size();
	}
	if (rod == 2)
	{
		return rod2.size();
	}
	if (rod == 3)
	{
		return rod3.size();
	}
}

const Disk& Tower::Get_Disk(int rod, int position) const // Return the top disk of a stack.
{
	if (rod == 1)
	{
		return rod1[position];
	}
	if (rod == 2)
	{
		return rod2[position];
	}
	if (rod == 3)
	{
		return rod3[position];
	}
}

void Tower::Move_Disk(int from_rod, int to_rod) // Move a disk from one rod to another.
{
	if (from_rod == 1)
	{
		if (to_rod == 2)
		{
			rod2.push_back(rod1[rod1.size() - 1]);
			rod1.pop_back();
		}
		if (to_rod == 3)
		{
			rod3.push_back(rod1[rod1.size() - 1]);
			rod1.pop_back();
		}
	}
	if (from_rod == 2)
	{
		if (to_rod == 1)
		{
			rod1.push_back(rod2[rod2.size() - 1]);
			rod2.pop_back();
		}
		if (to_rod == 3)
		{
			rod3.push_back(rod2[rod2.size() - 1]);
			rod2.pop_back();
		}
	}
	if (from_rod == 3)
	{
		if (to_rod == 1)
		{
			rod1.push_back(rod3[rod3.size() - 1]);
			rod3.pop_back();
		}
		if (to_rod == 2)
		{
			rod2.push_back(rod3[rod3.size() - 1]);
			rod3.pop_back();
		}
	}
}