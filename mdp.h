
#include <iostream>
#include <algorithm>

using namespace std; 
typedef enum cell
{
	plus_one, negative_one, wall, start, space
} cell;
void value_iteration(cell grid[6][6], double utility_grid[6][6]);
double utility_grid[6][6]; 
cell grid[6][6]; 