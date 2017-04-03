#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAX_ROW 100
#define MAX_COL 100

int flag = 0;
int n, m;
int x, y, q, p;
int maze[MAX_ROW][MAX_COL];
int book[MAX_ROW][MAX_COL];

int next[4][2] = {  // we have four directions and two coordinates
			{0, 1},  // right
			{1, 0},  // down
			{0, -1}, // left
			{-1, 0}, // up
};

struct position {
	int x;
	int y;
	int s;
};

struct queue {
	struct position pos[100];
	int head;
	int tail;
};

void simulate_input()
{
	n = 5; m =4;
	maze[0][2] = 1;
	maze[2][2] = 1;
	maze[3][1] = 1;
	maze[4][3] = 1;

	x = 1; y = 1;
	p = 4; q = 3;
}

void enqueue(struct queue *q, int x, int y, int s)
{
	q->pos[q->tail].x = x;
	q->pos[q->tail].y = y;
	q->pos[q->tail].s = s;
	q->tail++;
}

void bfs()
{
	struct queue queue;
	int i, step = 0;
	int tx, ty;
	int px, py;
	int flag = 0;

	queue.head = queue.tail = 0;


	queue.pos[0].x = x; queue.pos[0].y = y;
	queue.pos[0].s = step;
	queue.tail++;
 
	book[x][y] = 1;
	
	while (queue.head != queue.tail) {

		px = queue.pos[queue.head].x;
		py = queue.pos[queue.head].y;

		for (i = 0; i < 4; i++) {
			tx = px + next[i][0];
			ty = py + next[i][1];

			if (tx < 0 || tx >= n || ty < 0 || ty >= m)
				continue; 

			if (book[tx][ty] == 0 && maze[tx][ty] == 0) {
				book[tx][ty] = 1;
				enqueue(&queue, tx, ty, queue.pos[queue.head].s + 1);

				if (tx == p && ty == q) {
					flag = 1;
					break;
				}
			}

		}

		if (flag)
			break;

		queue.head++;
	}

	if (queue.head != queue.tail)
		printf("%d\n", queue.pos[queue.tail - 1].s);
	else
		printf("No Way!\n");
}

int main(int argc, char *argv[]) {
	
	int r, c;
	int step = 0;
	
	scanf("%d %d", &n, &m);
	for (r = 0; r < n; r++) {
		for (c = 0; c < m; c++) {
			scanf("%d", &maze[r][c]);
		}
	}
	scanf("%d %d %d %d", &x, &y, &p, &q);

	x--; y--;
	p--; q--;
	
	bfs();
	
	return 0;
}

