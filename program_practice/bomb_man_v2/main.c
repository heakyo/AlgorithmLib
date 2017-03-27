#include"main.h"

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

int get_killed_enemy(int r, int c)
{

	int i, x, y;
	int sum = 0;

	for (i = 0; i < TOTAL; i++) {

		switch(i) {
		case UP:
			x = r - 1; y = c;
			while (maze[x][y] != '#') {
				if (maze[x][y] == 'G')
					sum++;

				x--;
			}
			break;
		case RIGHT:
			x = r; y = c + 1;
			while (maze[x][y] != '#') {
				if (maze[x][y] == 'G')
					sum++;

				y++;
			}
			break;
		case DOWN:
			x = r + 1; y = c;
			while (maze[x][y] != '#') {
				if (maze[x][y] == 'G')
					sum++;

				x++;
			}
			break;
		case LEFT:
			x = r; y = c - 1;
			while (maze[x][y] != '#') {
				if (maze[x][y] == 'G')
					sum++;

				y--;
			}
			break;
		default:
			printf("Can't get here\n");
		}
	}

	return sum;
}

void show_maze()
{
	int r, c;
	for (r = 0; r < MAZE_ROW; r++) {
		for (c = 0; c < MAZE_COL; c++) {
			printf("%c ", maze[r][c]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int r, c, x, y;
	int sum, max = 0;

	show_maze();

	for (r = 0; r < MAZE_ROW; r++) {
		for (c = 0; c < MAZE_COL; c++) {
			if ('.' == maze[r][c]) {
				sum = get_killed_enemy(r, c);

				if (sum > max) {
					max = sum;
					x = r;
					y = c;
				}
			}
		}
	}

	printf("max(%d, %d): %d\n", x, y, max);

	return 0;
}

