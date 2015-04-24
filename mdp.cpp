/* MP4 Notes */
/* Use Value Iteration */ 
/* Solve the Bellman equation to compute the utilites of every state and find the policy */ 

#include "mdp.h"

int main()
{

	//row 0
	grid[0][0] = plus_one; 
	grid[1][0] = wall; 
	grid[2][0] = plus_one; 
	grid[3][0] = space; 
	grid[4][0] = space;
	grid[5][0] = plus_one; 

	//row 1
	grid[0][1] = space; 
	grid[1][1] = negative_one; 
	grid[2][1] = space; 
	grid[3][1] = plus_one;  
	grid[4][1] = wall; 
	grid[5][1] = negative_one;  

	//row 2
	grid[0][2] = space; 
	grid[1][2] = space; 
	grid[2][2] = negative_one; 
	grid[3][2] = space;  
	grid[4][2] = plus_one; 
	grid[5][2] = space;  

	//row 3
	grid[0][3] = space; 
	grid[1][3] = space; 
	grid[2][3] = start; 
	grid[3][3] = negative_one;  
	grid[4][3] = space; 
	grid[5][3] = plus_one;  

	//row 4
	grid[0][4] = space; 
	grid[1][4] = wall; 
	grid[2][4] = wall; 
	grid[3][4] = wall;  
	grid[4][4] = negative_one; 
	grid[5][4] = space;  

	//row 5
	grid[0][5] = space; 
	grid[1][5] = space; 
	grid[2][5] = space; 
	grid[3][5] = space;  
	grid[4][5] = space; 
	grid[5][5] = space;  

	

	for (int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 6; y++)
		{
			if (grid[x][y] == plus_one)
				utility_grid[x][y] = 1.0;
			else if (grid[x][y] == negative_one)
				utility_grid[x][y] = -1.0; 
			else 
				utility_grid[x][y] = 0.0; 
		}
	}

	value_iteration(grid, utility_grid); 

	for (int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 6; y++)
		{
			if (grid[x][y] != wall)
				cout << "(" << x << "," << y << "): " << utility_grid[x][y] << endl; 
		}
	}

}

void value_iteration(cell grid[6][6], double utility_grid[6][6])
{

	// repeat for 20 times
	for (int i = 0; i < 1; i++)
	{
		// for each state i
		for (int x = 0; x < 6; x++)
		{
			for (int y = 0; y < 6; y++)
			{
				bool calculated = false; 
				double top = 0.0, left = 0.0, right = 0.0, bot = 0.0; 
				if (grid[x][y] == space || grid[x][y] == start)
				{
					calculated = true; 
					// try going left 
					if (x - 1 >= 0)	{
						if (grid[x-1][y] != wall)
						{
							left += 0.8 * utility_grid[x][y]; 
							if (y + 1 <= 5) {
								if (grid[x][y+1] != wall) {
									left += 0.1 * utility_grid[x][y+1];
								}
							} else {
								left += 0.1 * utility_grid[x][y]; 
							}

							if (y - 1 >= 0) {
								if (grid[x][y-1] != wall) {
									left += 0.1 * utility_grid[x][y-1];
								}
							} else {
								left += 0.1 * utility_grid[x][y]; 
							}
						}
					} else {
						left += 0.8 * utility_grid[x][y]; 
						if (y + 1 <= 5) {
							if (grid[x][y+1] != wall) {
								left += 0.1 * utility_grid[x][y+1];
							}
						} else {
							left += 0.1 * utility_grid[x][y]; 
						}

						if (y - 1 >= 0) {
							if (grid[x][y-1] != wall) {
								left += 0.1 * utility_grid[x][y-1];
							}
						} else {
							left += 0.1 * utility_grid[x][y]; 
						}
					} 

					// try going right
					if (x + 1 <= 5)	{
						if (grid[x+1][y] != wall)
						{
							right += 0.8 * utility_grid[x][y]; 
							if (y + 1 <= 5) {
								if (grid[x][y+1] != wall) {
									right += 0.1 * utility_grid[x][y+1];
								}
							} else {
								right += 0.1 * utility_grid[x][y]; 
							}

							if (y - 1 >= 0) {
								if (grid[x][y-1] != wall) {
									right += 0.1 * utility_grid[x][y-1];
								}
							} else {
								right += 0.1 * utility_grid[x][y]; 
							}
						}
					} else {
						right += 0.8 * utility_grid[x][y]; 
						if (y + 1 <= 5) {
							if (grid[x][y+1] != wall) {
								right += 0.1 * utility_grid[x][y+1];
							}
						} else {
							right += 0.1 * utility_grid[x][y]; 
						}

						if (y - 1 >= 0) {
							if (grid[x][y-1] != wall) {
								right += 0.1 * utility_grid[x][y-1];
							}
						} else {
							right += 0.1 * utility_grid[x][y]; 
						}
					} 
					
					// try going bot 
					if (y + 1 <= 5)	{
						if (grid[x][y + 1] != wall)
						{
							bot += 0.8 * utility_grid[x][y]; 
							if (x + 1 <= 5) {
								if (grid[x+1][y] != wall) {
									bot += 0.1 * utility_grid[x+1][y];
								}
							} else {
								bot += 0.1 * utility_grid[x][y]; 
							}

							if (x - 1 >= 0) {
								if (grid[x-1][y] != wall) {
									bot += 0.1 * utility_grid[x-1][y];
								}
							} else {
								bot += 0.1 * utility_grid[x][y]; 
							}
						}
					} else {
						bot += 0.8 * utility_grid[x][y]; 
						if (x + 1 <= 5) {
							if (grid[x+1][y] != wall) {
								bot += 0.1 * utility_grid[x+1][y];
							}
						} else {
							bot += 0.1 * utility_grid[x][y]; 
						}

						if (x - 1 >= 0) {
							if (grid[x-1][y] != wall) {
								bot += 0.1 * utility_grid[x-1][y];
							}
						} else {
							bot += 0.1 * utility_grid[x][y]; 
						}
					}

					// try going top  
					if (y - 1 >= 0)	{
						if (grid[x][y -1] != wall)
						{
							top += 0.8 * utility_grid[x][y]; 
							if (x + 1 <= 5) {
								if (grid[x+1][y] != wall) {
									top += 0.1 * utility_grid[x+1][y];
								}
							} else {
								top += 0.1 * utility_grid[x][y]; 
							}

							if (x - 1 >= 0) {
								if (grid[x-1][y] != wall) {
									top += 0.1 * utility_grid[x-1][y];
								}
							} else {
								top += 0.1 * utility_grid[x][y]; 
							}
						}
					} else {
						top += 0.8 * utility_grid[x][y]; 
						if (x + 1 <= 5) {
							if (grid[x+1][y] != wall) {
								top += 0.1 * utility_grid[x+1][y];
							}
						} else {
							top += 0.1 * utility_grid[x][y]; 
						}

						if (x - 1 >= 0) {
							if (grid[x-1][y] != wall) {
								top += 0.1 * utility_grid[x-1][y];
							}
						} else {
							top += 0.1 * utility_grid[x][y]; 
						}
					} 
				}

				if (calculated)
					utility_grid[x][y] = -0.04 + max(max(left, right), max(top, bot)); 
			}
		}
	}
}