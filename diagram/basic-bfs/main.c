#include"main.h"

int adj_matrix[VERTEX][VERTEX] = {
	{0, 		1, 		1, 		INFINITY, 	1},
	{1, 		0, 		INFINITY, 	1, 		INFINITY},
	{1, 		INFINITY, 	0, 		INFINITY, 	INFINITY},
	{INFINITY, 	1, 		INFINITY, 	0, 		INFINITY},
	{1, 		INFINITY, 	INFINITY, 	INFINITY, 	0},
};

int book[VERTEX];
int queue[VERTEX];

void bfs(int start_vertex)
{
	int head;
	int tail;
	int cur;
	int i;

	book[start_vertex] = 1;

	/* push the first vertex into queue */
	head = 0;
	tail = 0;
	queue[tail] = start_vertex;
	tail++;

	while (head < tail) {
		cur = queue[head];
		printf("%d ", cur);

		/* get all the adjacent vertext of cur and put them to the queue */
		for (i = 0; i < VERTEX; i++) {
			if (adj_matrix[cur][i] == 1 && book[i] == 0) {
				queue[tail] = i;
				tail++;

				book[i] = 1;
			}
		}

		head++;
	}

	return;
}

int main(int argc, char *argv[])
{
	int i, j;
	int a, b;

	memset(book, 0x0, sizeof(book));
	memset(queue, 0x0, sizeof(queue));

#ifdef DYNAMIC_INIT
	for (i = 0; i < VERTEX; i++) {
		for (j = 0; j < VERTEX; j++) {
			if (i == j) {
				adj_matrix[i][j] = 0;
			} else {
				adj_matrix[i][j] = INFINITY; 
			}
		}
	}
	
	for (i = 0; i < EDGE; i++) {
		scanf("%d %d", &a, &b);	
		adj_matrix[a][b] = adj_matrix[b][a] = 1;
	}
#endif

#ifdef PRN_ADJ_MATRIX
	for (i = 0; i < VERTEX; i++) {
		for (j = 0; j < VERTEX; j++) {
			printf("%05d ", adj_matrix[i][j]);
		}
		printf("\n");
	}
#endif

	bfs(0);
	printf("\n");

	return 0;
}

