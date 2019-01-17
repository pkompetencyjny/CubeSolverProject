#include<iostream>
#include <vector>
#include "CubeSolver.hpp"
using namespace std;

CubeSolver::CubeSolver(std::vector<char> tab[6])
{
	for (int i = 0; i < 6; i++)
	{

		if (tab[i][4] == 'w')
		{
			white[0] = tab[i][5];
			white[1] = tab[i][8];
			white[2] = tab[i][7];
			white[3] = tab[i][6];
			white[4] = tab[i][3];
			white[5] = tab[i][0];
			white[6] = tab[i][1];
			white[7] = tab[i][2];
			white[8] = tab[i][4];
		}

		if (tab[i][4] == 'y')
		{
			yellow[0] = tab[i][5];
			yellow[1] = tab[i][2];
			yellow[2] = tab[i][1];
			yellow[3] = tab[i][0];
			yellow[4] = tab[i][3];
			yellow[5] = tab[i][6];
			yellow[6] = tab[i][7];
			yellow[7] = tab[i][8];
			yellow[8] = tab[i][4];
		}


		if (tab[i][4] == 'g')
		{
			green[0] = tab[i][2];
			green[1] = tab[i][5];
			green[2] = tab[i][8];
			green[3] = tab[i][7];
			green[4] = tab[i][6];
			green[5] = tab[i][3];
			green[6] = tab[i][0];
			green[7] = tab[i][1];
			green[8] = tab[i][4];
		}

		if (tab[i][4] == 'r')
		{
			red[0] = tab[i][2];
			red[1] = tab[i][5];
			red[2] = tab[i][8];
			red[3] = tab[i][7];
			red[4] = tab[i][6];
			red[5] = tab[i][3];
			red[6] = tab[i][0];
			red[7] = tab[i][1];
			red[8] = tab[i][4];
		}

		if (tab[i][4] == 'b')
		{
			blue[0] = tab[i][2];
			blue[1] = tab[i][5];
			blue[2] = tab[i][8];
			blue[3] = tab[i][7];
			blue[4] = tab[i][6];
			blue[5] = tab[i][3];
			blue[6] = tab[i][0];
			blue[7] = tab[i][1];
			blue[8] = tab[i][4];
		}

		if (tab[i][4] == 'o')
		{
			orange[0] = tab[i][2];
			orange[1] = tab[i][5];
			orange[2] = tab[i][8];
			orange[3] = tab[i][7];
			orange[4] = tab[i][6];
			orange[5] = tab[i][3];
			orange[6] = tab[i][0];
			orange[7] = tab[i][1];
			orange[8] = tab[i][4];
		}
	}

};


void CubeSolver::display(char face[9])
{
	for (int i = 0; i < 9; i++)
	{
		cout << face[i] << " ";
	}
	cout << endl << endl;
};

void CubeSolver::swap(char &a, char &b)
{
	char t = a;
	a = b;
	b = t;
}


void CubeSolver::rotate_clock(char choice)
{
	if (choice == 'w')
	{
		cout << "White" << endl;
		swap(white[7], white[3]);
		swap(white[6], white[4]);
		swap(white[0], white[2]);
		swap(white[7], white[5]);
		swap(white[0], white[4]);
		swap(white[1], white[3]);
		//-------------------------
		swap(blue[0], orange[0]);
		swap(blue[7], orange[7]);
		swap(blue[6], orange[6]);
		swap(orange[6], green[6]);
		swap(orange[7], green[7]);
		swap(orange[0], green[0]);
		swap(green[6], red[6]);
		swap(green[7], red[7]);
		swap(green[0], red[0]);
	}
	//-------------------------
	else if (choice == 'r')
	{
		cout << "Red" << endl;
		swap(red[0], red[4]);
		swap(red[7], red[5]);
		swap(red[1], red[3]);
		swap(red[0], red[6]);
		swap(red[1], red[5]);
		swap(red[2], red[4]);
		//-------------------------
		swap(blue[6], white[3]);
		swap(blue[5], white[2]);
		swap(blue[4], white[1]);
		swap(white[1], green[0]);
		swap(white[2], green[1]);
		swap(white[3], green[2]);
		swap(green[0], yellow[3]);
		swap(green[1], yellow[2]);
		swap(green[2], yellow[1]);
		//--------------------------
	}
	//-----------------------------------
	else if (choice == 'y')
	{
		cout << "Yellow" << endl;
		swap(yellow[1], yellow[5]);
		swap(yellow[2], yellow[4]);
		swap(yellow[0], yellow[6]);
		swap(yellow[1], yellow[3]);
		swap(yellow[0], yellow[4]);
		swap(yellow[7], yellow[5]);
		//--------------------------
		swap(blue[4], red[4]);
		swap(blue[3], red[3]);
		swap(blue[2], red[2]);
		swap(red[2], green[2]);
		swap(red[3], green[3]);
		swap(red[4], green[4]);
		swap(green[4], orange[4]);
		swap(green[3], orange[3]);
		swap(green[2], orange[2]);
		//--------------------------
	}
	//-------------------------------------
	else if (choice == 'o')
	{
		cout << "Orange" << endl;
		swap(orange[4], orange[0]);
		swap(orange[3], orange[1]);
		swap(orange[5], orange[7]);
		swap(orange[4], orange[2]);
		swap(orange[5], orange[1]);
		swap(orange[6], orange[0]);
		//--------------------------
		swap(blue[2], yellow[5]);
		swap(blue[1], yellow[6]);
		swap(blue[0], yellow[7]);
		swap(yellow[5], green[6]);
		swap(yellow[6], green[5]);
		swap(yellow[7], green[4]);
		swap(green[6], white[7]);
		swap(green[5], white[6]);
		swap(green[4], white[5]);
		//--------------------------
	}
	//-------------------------------------
	else if (choice == 'g')
	{
		cout << "Green" << endl;
		swap(green[6], green[2]);
		swap(green[5], green[3]);
		swap(green[7], green[1]);
		swap(green[4], green[6]);
		swap(green[7], green[3]);
		swap(green[0], green[2]);
		//--------------------------
		swap(white[5], orange[2]);
		swap(white[4], orange[1]);
		swap(white[3], orange[0]);
		swap(yellow[3], orange[2]);
		swap(yellow[4], orange[1]);
		swap(yellow[5], orange[0]);
		swap(yellow[3], red[6]);
		swap(yellow[4], red[5]);
		swap(yellow[5], red[4]);
		//--------------------------
	}
	//-------------------------------------------
	else if (choice == 'b')
	{
		cout << "Blue" << endl;
		swap(blue[1], blue[7]);
		swap(blue[2], blue[6]);
		swap(blue[5], blue[3]);
		swap(blue[2], blue[0]);
		swap(blue[7], blue[3]);
		swap(blue[6], blue[4]);
		//--------------------------
		swap(yellow[1], orange[4]);
		swap(yellow[0], orange[5]);
		swap(yellow[7], orange[6]);
		swap(white[7], orange[4]);
		swap(white[0], orange[5]);
		swap(white[1], orange[6]);
		swap(white[7], red[0]);
		swap(white[0], red[1]);
		swap(white[1], red[2]);
		//--------------------------
	}
}

void CubeSolver::solution()
{
	cout << endl;
	cout << "White cross:" << endl;
	solve_white_cross();
	cout << endl;
	cout << "White corners:" << endl;
	solve_white_corners();
	cout << endl;
	cout << "Middle layer" << endl;
	solve_middle_layer();
	cout << endl;
	cout << "Yellow cross" << endl;
	solve_yellow_cross();
	cout << endl;
	cout << "Yellow Corners" << endl;
	solve_yellow_corners();
	cout << endl;
	cout << "Yellow Corners orientation" << endl;
	yellow_corner_orientation();
	cout << endl;
	yellow_edges_colour_arrangement();
}



void CubeSolver::white_bottom(char q)
{
	if ((yellow[0] == 'w' && blue[3] == q) || (yellow[2] == 'w' && red[3] == q) || (yellow[4] == 'w' && green[3] == q) || (yellow[6] == 'w' && orange[3] == q))
	{
		if (q == 'b')
		{
			while (blue[3] != q || yellow[0] != 'w')
			{
				rotate_clock('y');
			}
		}
		if (q == 'r')
		{
			while (red[3] != q || yellow[2] != 'w')
			{
				rotate_clock('y');
			}
			if (q != 'b')
			{
				while (white[0] != 'w' && blue[7] != 'b')
				{
					rotate_clock('w');
				}
			}
		}
		if (q == 'g')
		{
			while (green[3] != q || yellow[4] != 'w')
			{
				rotate_clock('y');
			}
			if (q != 'b')
			{
				while (white[0] != 'w' && blue[7] != 'b')
				{
					rotate_clock('w');
				}
			}
		}
		if (q == 'o')
		{
			while (orange[3] != q || yellow[6] != 'w')
			{
				rotate_clock('y');
			}
			if (q != 'b')
			{
				while (white[0] != 'w' && blue[7] != 'b')
				{
					rotate_clock('w');
				}
			}
		}
		rotate_clock(q); rotate_clock(q);
	}
}

void CubeSolver::right_alg(char a, char c)
{
	rotate_clock(a); rotate_clock(a); rotate_clock(a);
	rotate_clock('y'); rotate_clock(a); white_bottom(c);
}

void CubeSolver::white_right(char q)
{
	if (blue[1] == 'w' || red[1] == 'w' || green[1] == 'w' || orange[1] == 'w')
	{
		if (blue[5] == q && red[1] == 'w')
		{
			right_alg('b', q);
		}
		if (red[5] == q && green[1] == 'w')
		{
			right_alg('r', q);
		}
		if (green[5] == q && orange[1] == 'w')
		{
			right_alg('g', q);
		}
		if (orange[5] == q && blue[1] == 'w')
		{
			right_alg('o', q);
		}
	}
}

void CubeSolver::left_alg(char a, char c)
{
	rotate_clock(a); rotate_clock('y'); rotate_clock(a);
	rotate_clock(a); rotate_clock(a); white_bottom(c);
}

void CubeSolver::white_left(char q)
{
	if (blue[5] == 'w' || red[5] == 'w' || green[5] == 'w' || orange[5] == 'w')
	{
		if (blue[5] == 'w' && red[1] == q)
		{
			left_alg('r', q);
		}
		if (red[5] == 'w' && green[1] == q)
		{
			left_alg('g', q);
		}
		if (green[5] == 'w' && orange[1] == q)
		{
			left_alg('o', q);
		}
		if (orange[5] == 'w' && blue[1] == q)
		{
			left_alg('b', q);
		}
	}
}


void CubeSolver::top_alg(char a, char b, char c)
{
	rotate_clock(a); rotate_clock(a); rotate_clock(a);
	rotate_clock('w'); rotate_clock(b); rotate_clock('w');
	rotate_clock('w'); rotate_clock('w'); white_bottom(c);
}

void CubeSolver::white_top(char q)
{
	if (blue[7] == 'w' && white[0] == q)
	{
		top_alg('b', 'r', q);
	}
	if (red[7] == 'w' && white[2] == q)
	{
		top_alg('r', 'g', q);
	}
	if (green[7] == 'w' && white[4] == q)
	{
		top_alg('g', 'o', q);
	}
	if (orange[7] == 'w' && white[6] == q)
	{
		top_alg('o', 'b', q);
	}
}

void CubeSolver::inv_alg(char a, char b, char c)
{
	rotate_clock(a); rotate_clock(b); rotate_clock('y');
	rotate_clock('y'); rotate_clock('y'); rotate_clock(b);
	rotate_clock(b); rotate_clock(b); rotate_clock(a);
	rotate_clock(a); rotate_clock(a); white_bottom(c);
}

void CubeSolver::white_bottom_inverted(char q)
{
	if (blue[3] == 'w' || red[3] == 'w' || green[3] == 'w' || orange[3] == 'w')
	{
		if (blue[3] == 'w' && yellow[0] == q)
		{
			inv_alg('b', 'r', q);
		}
		if (red[3] == 'w' && yellow[2] == q)
		{
			inv_alg('r', 'g', q);
		}
		if (green[3] == 'w' && yellow[4] == q)
		{
			inv_alg('g', 'o', q);
		}
		if (orange[3] == 'w' && yellow[6] == q)
		{
			inv_alg('o', 'b', q);
		}
	}
}


void CubeSolver::solve_white_cross()
{
	char prefer[4] = { 'b','r','g','o' };
	for (int i = 0; i < 4; i++)
	{
		if (white[0] == 'w' && blue[7] == prefer[i]) { rotate_clock('b'); }
		if (white[2] == 'w' && red[7] == prefer[i]) { rotate_clock('r'); }
		if (white[4] == 'w' && green[7] == prefer[i]) { rotate_clock('g'); }
		if (white[6] == 'w' && orange[7] == prefer[i]) { rotate_clock('o'); }
		white_bottom(prefer[i]); white_bottom_inverted(prefer[i]); white_left(prefer[i]); white_right(prefer[i]); white_top(prefer[i]);
		if (i != 0)
		{
			while (blue[7] != 'b') { rotate_clock('w'); }
		}
		if (white[0] == 'w' && white[2] == 'w' && white[4] == 'w' && white[6] == 'w' &&blue[7] == 'b' && red[7] == 'r' && green[7] == 'g' && orange[7] == 'o')
		{
			break;
		}
	}
}

void CubeSolver::white_corners_alg_left()
{
	rotate_clock('b'); rotate_clock('b'); rotate_clock('b');
	rotate_clock('y'); rotate_clock('y'); rotate_clock('y');
	rotate_clock('b');
}

void CubeSolver::white_corners_alg_right()
{
	rotate_clock('r');
	rotate_clock('y');
	rotate_clock('r'); rotate_clock('r'); rotate_clock('r');
}

void CubeSolver::solve_white_corners()
{
	while (red[0] != 'r' || red[6] != 'r' || blue[0] != 'b' || blue[6] != 'b' || orange[0] != 'o' || orange[6] != 'o' || green[0] != 'g' || green[6] != 'g')
	{
		while (red[7] != 'r')
		{
			rotate_clock('w');
		}
		if (blue[4] == 'w' || red[4] == 'w' || green[4] == 'w' || orange[4] == 'w')
		{
			while (blue[4] != 'w')
			{
				rotate_clock('y');
			}
			while (red[2] != red[7])
			{
				rotate_clock('w');
			}
			white_corners_alg_left();
			while (red[7] != 'r')
			{
				rotate_clock('w');
			}
		}
		else if (blue[2] == 'w' || red[2] == 'w' || green[2] == 'w' || orange[2] == 'w')
		{
			while (red[2] != 'w')
			{
				rotate_clock('y');
			}
			while (red[7] != yellow[1])
			{
				rotate_clock('w');
			}
			white_corners_alg_right();
			while (red[7] != 'r')
			{
				rotate_clock('w');
			}
		}
		else if (yellow[1] == 'w' || yellow[3] == 'w' || yellow[5] == 'w' || yellow[7] == 'w')
		{
			while (yellow[1] != 'w')
			{
				rotate_clock('y');
			}
			while (red[2] != blue[7])
			{
				rotate_clock('w');
			}
			rotate_clock('b'); rotate_clock('b'); rotate_clock('b');
			rotate_clock('y'); rotate_clock('y');
			rotate_clock('b');
			while (blue[4] != 'w')
			{
				rotate_clock('y');
			}
			while (red[2] != red[7])
			{
				rotate_clock('w');
			}
			white_corners_alg_left();
			while (red[7] != 'r')
			{
				rotate_clock('w');
			}
		}
		else
		{
			while (red[7] == red[0])
			{
				rotate_clock('w');
			}
			white_corners_alg_left();
			while (red[7] != 'r')
			{
				rotate_clock('w');
			}
		}
	}
}

void CubeSolver::middle_place_left_alg(char left, char center)
{
	rotate_clock('y'); rotate_clock('y'); rotate_clock('y');
	rotate_clock(left); rotate_clock(left); rotate_clock(left);
	rotate_clock('y');
	rotate_clock(left);
	rotate_clock('y');
	rotate_clock(center);
	rotate_clock('y'); rotate_clock('y'); rotate_clock('y');
	rotate_clock(center); rotate_clock(center); rotate_clock(center);

}

void CubeSolver::middle_place_right_alg(char center, char right)
{
	rotate_clock('y');
	rotate_clock(right);
	rotate_clock('y'); rotate_clock('y'); rotate_clock('y');
	rotate_clock(right); rotate_clock(right); rotate_clock(right);
	rotate_clock('y'); rotate_clock('y'); rotate_clock('y');
	rotate_clock(center); rotate_clock(center); rotate_clock(center);
	rotate_clock('y');
	rotate_clock(center);
}

void CubeSolver::solve_middle_layer()
{
	while (red[5] != 'r' || red[1] != 'r' || blue[1] != 'b' || blue[5] != 'b' || orange[1] != 'o' || orange[5] != 'o' || green[1] != 'g' || green[5] != 'g')
	{

		if ((orange[1] != 'o' && green[5] != 'g') && (orange[1] != 'y' || green[5] != 'y'))
		{
			while (green[3] != 'y' && yellow[4] != 'y')
			{
				rotate_clock('y');
			}
			middle_place_right_alg('g', 'o');
		}

		else if ((orange[5] != 'o' && blue[1] != 'b') && (orange[5] != 'y' || blue[1] != 'y'))
		{
			while (orange[3] != 'y' && yellow[6] != 'y')
			{
				rotate_clock('y');
			}
			middle_place_right_alg('o', 'b');
		}

		else if ((blue[5] != 'b' && red[1] != 'r') && (blue[5] != 'y' || red[1] != 'y'))
		{
			while (blue[3] != 'y' && yellow[0] != 'y')
			{
				rotate_clock('y');
			}
			middle_place_right_alg('b', 'r');
		}

		else if ((red[5] != 'r' && green[1] != 'g') && (red[5] != 'y' || green[1] != 'y'))
		{
			while (red[3] != 'y' && yellow[2] != 'y')
			{
				rotate_clock('y');
			}
			middle_place_right_alg('r', 'g');
		}

		while (red[3] == 'y' || yellow[2] == 'y')
		{
			rotate_clock('y');
		}

		if (red[3] == 'r' && yellow[2] != 'y')
		{
			if (yellow[2] == 'g')
			{
				middle_place_right_alg('r', 'g');
			}
			else if (yellow[2] = 'b')
			{
				middle_place_left_alg('b', 'r');
			}
		}
		else if (red[3] == 'b' && yellow[2] != 'y')
		{
			rotate_clock('y');
			if (yellow[0] == 'r')
			{
				middle_place_right_alg('b', 'r');
			}
			else if (yellow[0] = 'o')
			{
				middle_place_left_alg('o', 'b');
			}
		}
		else if (red[3] == 'o' && yellow[2] != 'y')
		{
			rotate_clock('y'); rotate_clock('y');
			if (yellow[6] == 'b')
			{
				middle_place_right_alg('o', 'b');
			}
			else if (yellow[6] = 'g')
			{
				middle_place_left_alg('g', 'o');
			}
		}
		else if (red[3] == 'g' && yellow[2] != 'y')
		{
			rotate_clock('y'); rotate_clock('y'); rotate_clock('y');
			if (yellow[4] == 'o')
			{
				middle_place_right_alg('g', 'o');
			}
			else if (yellow[4] = 'r')
			{
				middle_place_left_alg('r', 'g');
			}
		}
	}
}

void CubeSolver::yellow_cross_algorithm()
{
	rotate_clock('r');
	rotate_clock('y');
	rotate_clock('g');
	rotate_clock('y'); rotate_clock('y'); rotate_clock('y');
	rotate_clock('g'); rotate_clock('g'); rotate_clock('g');
	rotate_clock('r'); rotate_clock('r'); rotate_clock('r');
}


void CubeSolver::solve_yellow_cross()
{
	while (yellow[0] != 'y' || yellow[2] != 'y' || yellow[4] != 'y' || yellow[6] != 'y')
	{
		if ((yellow[0] == 'y' && yellow[6] == 'y') || (yellow[4] == 'y' && yellow[6] == 'y')
			|| (yellow[2] == 'y' && yellow[4] == 'y') || (yellow[0] == 'y' && yellow[2] == 'y'))
		{
			while (yellow[0] != 'y' && yellow[6] != 'y')
			{
				rotate_clock('y');
			}
			yellow_cross_algorithm();
		}
		if ((yellow[2] == 'y' && yellow[6] == 'y') || (yellow[0] == 'y' && yellow[4] == 'y'))
		{
			while (yellow[0] != 'y' && yellow[4] != 'y')
			{
				rotate_clock('y');
			}
			yellow_cross_algorithm();
			yellow_cross_algorithm();
		}
		else if (yellow[8] == 'y')
		{
			yellow_cross_algorithm();
			rotate_clock('y');
			yellow_cross_algorithm();
			yellow_cross_algorithm();
		}
	}
}

void CubeSolver::yellow_corners_algorithm()
{
	rotate_clock('g');
	rotate_clock('y');
	rotate_clock('g'); rotate_clock('g'); rotate_clock('g');
	rotate_clock('y');
	rotate_clock('g');
	rotate_clock('y'); rotate_clock('y');
	rotate_clock('g'); rotate_clock('g'); rotate_clock('g');
}

void CubeSolver::solve_yellow_corners()
{
	while (yellow[1] != 'y' || yellow[3] != 'y' || yellow[5] != 'y' || yellow[7] != 'y')
	{
		if ((yellow[1] == 'y' && yellow[3] != 'y' && yellow[5] != 'y' && yellow[7] != 'y')
			|| (yellow[3] == 'y' && yellow[1] != 'y' && yellow[5] != 'y' && yellow[7] != 'y')
			|| (yellow[5] == 'y' && yellow[1] != 'y' && yellow[3] != 'y' && yellow[7] != 'y')
			|| (yellow[7] == 'y' && yellow[1] != 'y' && yellow[3] != 'y' && yellow[5] != 'y'))
		{
			while (yellow[1] != 'y')
			{
				rotate_clock('y');
			}
			yellow_corners_algorithm();
		}
		else if ((green[2] == 'y' && green[4] == 'y' && yellow[1] == 'y' && yellow[7] == 'y')
			|| (orange[2] == 'y' && orange[4] == 'y' && yellow[1] == 'y' && yellow[3] == 'y')
			|| (blue[2] == 'y' && blue[4] == 'y' && yellow[3] == 'y' && yellow[5] == 'y')
			|| (red[2] == 'y' && red[4] == 'y' && yellow[5] == 'y' && yellow[7] == 'y'))
		{
			while (red[2] != 'y' && red[4] != 'y' && yellow[5] != 'y' && yellow[7] != 'y')
			{
				rotate_clock('y');
			}
			yellow_corners_algorithm();
		}
		else if ((red[4] == 'y' && orange[2] == 'y' && yellow[1] == 'y' && yellow[7] == 'y')
			|| (blue[2] == 'y' && green[4] == 'y' && yellow[1] == 'y' && yellow[3] == 'y')
			|| (red[2] == 'y' && orange[4] == 'y' && yellow[3] == 'y' && yellow[5] == 'y')
			|| (blue[4] == 'y' && green[2] == 'y' && yellow[5] == 'y' && yellow[7] == 'y'))
		{
			while (red[2] != 'y' && orange[4] != 'y' && yellow[3] != 'y' && yellow[5] != 'y')
			{
				rotate_clock('y');
			}
			yellow_corners_algorithm();
		}
		else if ((green[2] == 'y' && green[4] == 'y' && blue[2] == 'y' && blue[4] == 'y')
			|| (red[2] == 'y' && red[4] == 'y' && orange[2] == 'y' && orange[4] == 'y'))
		{
			while (green[2] != 'y' && green[4] != 'y' && blue[2] != 'y' && blue[4] != 'y')
			{
				rotate_clock('y');
			}
			yellow_corners_algorithm();
		}
		else if ((green[2] == 'y' && orange[2] == 'y' && orange[4] == 'y' && blue[4] == 'y')
			|| (red[4] == 'y' && orange[2] == 'y' && blue[2] == 'y' && blue[4] == 'y')
			|| (red[2] == 'y' && red[4] == 'y' && green[4] == 'y' && blue[2] == 'y')
			|| (green[2] == 'y' && green[4] == 'y' && orange[4] == 'y' && red[2] == 'y'))
		{
			while (green[2] != 'y' && orange[2] != 'y' && orange[4] != 'y' && blue[4] != 'y')
			{
				rotate_clock('y');
			}
			yellow_corners_algorithm();
		}
		else if ((yellow[1] == 'y' && yellow[5] == 'y' && yellow[3] != 'y' && yellow[7] != 'y')
			|| (yellow[3] == 'y' && yellow[7] == 'y' && yellow[1] != 'y' && yellow[5] != 'y'))
		{
			while (red[2] != 'y' && green[4] != 'y')
			{
				rotate_clock('y');
			}
			yellow_corners_algorithm();
		}
	}
}

void CubeSolver::yellow_corner_orientation_algorithm()
{
	rotate_clock('g'); rotate_clock('g'); rotate_clock('g');
	rotate_clock('r');
	rotate_clock('g'); rotate_clock('g'); rotate_clock('g');
	rotate_clock('o'); rotate_clock('o');
	rotate_clock('g');
	rotate_clock('r'); rotate_clock('r'); rotate_clock('r');
	rotate_clock('g'); rotate_clock('g'); rotate_clock('g');
	rotate_clock('o'); rotate_clock('o');
	rotate_clock('g'); rotate_clock('g');
	rotate_clock('y'); rotate_clock('y'); rotate_clock('y');
}

void CubeSolver::yellow_corner_orientation()
{
	while (red[2] != 'r' || red[4] != 'r' || green[2] != 'g' || green[4] != 'g'
		|| orange[2] != 'o' || orange[4] != 'o' || blue[2] != 'b' || blue[4] != 'b')
	{
		if ((red[2] == red[4]) || (green[2] == green[4]) || (orange[2] == orange[4]) || (blue[2] == blue[4]))
		{
			while (orange[2] != orange[4])
			{
				rotate_clock('y');
			}
			yellow_corner_orientation_algorithm();
			while (blue[2] != 'b')
			{
				rotate_clock('y');
			}
		}
		else
		{
			while (orange[4] != 'o' && red[4] != 'r')
			{
				rotate_clock('y');
			}
			yellow_corner_orientation_algorithm();
			while (orange[2] != orange[4])
			{
				rotate_clock('y');
			}
			yellow_corner_orientation_algorithm();
			while (blue[2] != 'b')
			{
				rotate_clock('y');
			}
		}
	}
}

void CubeSolver::yellow_edges_colour_arrangement_right()
{
	rotate_clock('r'); rotate_clock('r');
	rotate_clock('y'); rotate_clock('y'); rotate_clock('y');
	rotate_clock('g'); rotate_clock('g'); rotate_clock('g');
	rotate_clock('b');
	rotate_clock('r'); rotate_clock('r');
	rotate_clock('b'); rotate_clock('b'); rotate_clock('b');
	rotate_clock('g');
	rotate_clock('y'); rotate_clock('y'); rotate_clock('y');
	rotate_clock('r'); rotate_clock('r');
}

void CubeSolver::yellow_edges_colour_arrangement_left()
{
	rotate_clock('r'); rotate_clock('r');
	rotate_clock('y');
	rotate_clock('b');
	rotate_clock('g'); rotate_clock('g'); rotate_clock('g');
	rotate_clock('r'); rotate_clock('r');
	rotate_clock('b'); rotate_clock('b'); rotate_clock('b');
	rotate_clock('g');
	rotate_clock('y');
	rotate_clock('r'); rotate_clock('r');
}

void CubeSolver::yellow_edges_colour_arrangement()
{
	while (red[2] != 'r')
	{
		rotate_clock('r');
	}
	if (red[3] == 'o' && orange[3] == 'r' && blue[3] == 'g' && green[3] == 'b')
	{
		yellow_edges_colour_arrangement_left();
	}
	else if (red[3] == 'b' && blue[3] == 'r')
	{
		yellow_edges_colour_arrangement_left();
	}
	else if (red[3] == 'g' && green[3] == 'r')
	{
		yellow_edges_colour_arrangement_left();
	}
	while (orange[2] != orange[3])
	{
		rotate_clock('y');
	}
	if (red[3] == green[2])
	{
		yellow_edges_colour_arrangement_right();
	}
	else if (red[3] == blue[2])
	{
		yellow_edges_colour_arrangement_left();
	}
	while (red[3] != 'r')
	{
		rotate_clock('y');
	}
}
