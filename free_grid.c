#include "shell.h"
/**
* free_grid - free memory
* @grid: input double pointer
* Return: no return
*/

void free_grid(char **grid)
{
	int j, height = 0;

	while (grid[height])
	{
		height++;
	}
	if (grid != NULL && height > 0)
	{
		for (j = 0; j < height; j++)
		{
			free(grid[j]);
		}
		free(grid);
	}
}
