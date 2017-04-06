#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAZE_ROW 50
#define MAZE_COL 50

struct point {
	int x;
	int y;
};

#if 0
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
#endif
char maze[MAZE_ROW][MAZE_COL];
int n, m;
int sx, sy;

int book[MAZE_ROW][MAZE_COL];

int next[4][2] = {
	{0, 1}, // right
	{1, 0}, // down
	{0, -1}, // left
	{-1, 0}  // up
};

int kill_enemies(int x, int y)
{
	int i = 0;
	int tx, ty;
	int sum;

	sum = 0;

	for (i = 0; i < 4; i++) {
		tx = x; ty = y;

		switch(i) {
		case 0:
			while (maze[tx][ty] != '#') {
				if (maze[tx][ty] == 'G')
					sum++;

				ty++;
			}
			break;
		case 1:
			while (maze[tx][ty] != '#') {
				if (maze[tx][ty] == 'G')
					sum++;

				tx++;
			}
			break;
		case 2:
			while (maze[tx][ty] != '#') {
				if (maze[tx][ty] == 'G')
					sum++;

				ty--;
			}
			break;
		case 3:
			while (maze[tx][ty] != '#') {
				if (maze[tx][ty] == 'G')
					sum++;

				tx--;
			}
			break;
		}

	}

	return sum;
}

void display_maze()
{
	int r, c;

	for (r = 0; r < n; r++) {
		for (c = 0; c < m; c++)
			printf("%c ", maze[r][c]);

		printf("\n");
	}
}

int main()
{
	struct point queue[MAZE_ROW * MAZE_COL];
	int head;
	int tail;
	int nx, ny;
	int ex = 0, ey = 0;
	int i;
	int sum, max;

	memset(queue, 0, sizeof(queue[0]) * MAZE_ROW * MAZE_COL);
	head = tail = 0;

	scanf("%d %d %d %d", &n, &m, &sx, &sy);
	for (i = 0; i < n; i++)
		scanf("%s", maze[i]);

	queue[tail].x = sx;
	queue[tail].y = sy;
	tail++;

	book[sx][sy] = 1;

	sum = 0;
	max = 0;

	while (head < tail) {


		sum = kill_enemies(queue[head].x, queue[head].y);
		if (sum > max) {
			max = sum;
			ex = queue[head].x;
			ey = queue[head].y;
		}
	
		for (i = 0; i < 4; i++) {

			nx = queue[head].x + next[i][0];
			ny = queue[head].y + next[i][1];

			if (maze[nx][ny] == '.' && book[nx][ny] == 0) { // enqueue
				queue[tail].x = nx;
				queue[tail].y = ny;
				tail++;

				book[nx][ny] = 1;
			}

		}

		head++;
	}

	//printf("max:%d (%d, %d)\n", max, ex, ey);
	printf("%d\n", max);
}

