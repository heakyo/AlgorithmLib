#include"bomb_man.h"

int main() {

	char maze[MAZE_ROW][MAZE_COL] = {
			'#','#','#','#','#','#','#','#','#','#','#','#','#',
			'#','G','G','.','G','G','G','#','G','G','G','.','#',
			'#','#','#','.','#','G','#','G','#','G','#','G','#',
			'#','.','.','.','.','.','.','.','#','.','.','G','#',
			'#','G','#','.','#','#','#','.','#','G','#','G','#',
			'#','G','G','.','G','G','G','.','#','.','#','#','#',
			'#','G','#','.','#','G','#','.','#','.','#','#','#',
			'#','#','G','.','.','.','G','.','.','.','.','.','#',
			'#','G','#','.','#','G','#','#','#','.','#','G','#',
			'#','.','.','.','G','#','G','G','G','.','G','G','#',
			'#','G','#','.','#','G','#','G','#','.','#','G','#',
			'#','G','G','.','G','G','G','#','G','.','G','G','#',
			'#','#','#','#','#','#','#','#','#','#','#','#','#'
	};

	int i, j, k;
	int posX, posY, max_count = 0;
	int total_count = 0;

	for (i = 0; i < MAZE_ROW; i++)
	{
		for (j = 0; j < MAZE_COL; j++)
		{
			if (maze[i][j] != '.')
			{
				continue;
			}

			for (k = EAST; k <= NORTH; k++)
			{
				total_count += kill_count(maze, i, j, k);	
			}

			if (total_count > max_count)
			{
				posX = i;
				posY = j;
				max_count = total_count;

				printf("posXY:(%d, %d) max count:%d\n", posX, posY, max_count);
				total_count = 0;
			}
		}
	}

	printf("posXY:(%d, %d) max count:%d\n", posX, posY, max_count);
	maze[posX][posY] = 'B';

	for (i = 0; i < MAZE_ROW; i++)
	{
		for (j = 0; j < MAZE_COL; j++)
		{
			printf("%c",maze[i][j]);
		}

		printf("\n");
	}
	printf("\n");

    return 0;
}

static int kill_count(char maze[MAZE_ROW][MAZE_COL], int posX, int posY, int dir)
{
	int i, j;
	int killEnemyCount = 0;

	switch(dir)
	{
	case EAST:
		for (j = posY+1; j < MAZE_COL; j++)
		{
			if(maze[posX][j] == '#')
			{
				break;
			}

			if (maze[posX][j] == 'G')
			{
				killEnemyCount++; 
			}
		}
		break;

	case SOUTH:
		for (i = posX+1; i < MAZE_ROW; i++)
		{
			if(maze[i][posY] == '#')
			{
				break;
			}

			if (maze[i][posY] == 'G')
			{
				killEnemyCount++; 
			}
		}
		break;

	case WEST:
		for (j = posY-1; j >= 0; j--)
		{
			if(maze[posX][j] == '#')
			{
				break;
			}

			if (maze[posX][j] == 'G')
			{
				killEnemyCount++; 
			}
		}
		break;

	case NORTH:
		for (i = posX+1; i > 0; i--)
		{
			if(maze[i][posY] == '#')
			{
				break;
			}

			if (maze[i][posY] == 'G')
			{
				killEnemyCount++; 
			}
		}
		break;

	default:
		printf("The direction is wrong!\n");	
	} /* end switch */

	return killEnemyCount;

}


