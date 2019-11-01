/*
Zachary Williams
10/30/19
The Unique Paths challenge - idea from https://leetcode.com/problems/unique-paths/

A robot is located at the top-left corner of a m x n grid.
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid.
How many possible unique paths are there?
Note: m and n will be at most 100.


*/

#include <iostream>
#include <vector>

using namespace std;

int checkGrid(const int width, const int height)
{
	

	//int** grid = new int*[height];
	//for (int i = 0; i < height; i++)
	//	grid[i] = new int[width];
	//
	// Declaration above omitted due to being too slow

	vector< vector<int> > grid(width, vector<int>(height));
	grid[width - 1][height - 1] = 0;
	// Vector was used instead of 2D array for simplicity as well as not needing to delete the vector from memory
	// Vector also was much easier to implement when the width and height of the grid are not known at compile time, but rather run time

	// Remember that for this challenge the robot may only move DOWN or RIGHT at any given time

	// Fills and edge of the grid with 1; needed for nested loop
	for (int ctr = 0; ctr < width; ctr++)
	{
		grid[ctr][0] = 1;
	}

	// Fills another edge of the grid with 1; needed for nested loop
	for (int ctr = 0; ctr < height; ctr++)
	{
		grid[0][ctr] = 1;
	}

	// At start, all values in the grid are 1
	for (int ctr = 1; ctr < width; ctr++)
	{

		for (int newCtr = 1; newCtr < height; newCtr++)
		{
			grid[ctr][newCtr] = grid[ctr - 1][newCtr] + grid[ctr][newCtr - 1];
			// This line tallies up the total number of paths by starting at the block at (1,1),
			// putting the current number of unique paths in it's current block
			// and then continually adding based off of it's previous iteration by moving to the 
			// block below the current block.
			// If there is no block below the current block, it will move to the column and start over.
		}
	}

	return grid[width - 1][height - 1];

	// Recursive solution was omitted from program due to having bad time complexity
}




int main()
{
	int m; // input var used for width of the grid
	int n; // input var used for height of the grid
	int paths; // number of unique paths in the grid
	

	do {
		cout << "Please enter the desired width of your grid " <<endl;
		if (cin >> m  && m > 0) // input checker
		{
			cout << "Please enter the desired height of your grid " << endl;
			if (cin >> n && n > 0) // input checker
			{
				// valid numbers
				break;
			}
		}
		
		// not valid numbers
		cout << "Invalid Input! Please input a positive numerical value." << endl <<endl;
		cin.clear();
		while (cin.get() != '\n');


	} while (1);

	paths = checkGrid(m,n);
	cout << "The total number of unique paths is " << paths << endl;


	system("pause");
	return 0;
}