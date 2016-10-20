#include"main.h"

int adj_matrix[VERTEX][VERTEX] = {
	{0, 		2, 		INFINITY, 	INFINITY, 	10},
	{INFINITY, 	0, 		3, 		INFINITY, 	7},
	{4, 		INFINITY, 	0, 		4, 		INFINITY},
	{INFINITY, 	INFINITY, 	INFINITY, 	0, 		5},
	{INFINITY, 	INFINITY, 	3, 		INFINITY, 	0},
};

int book[VERTEX];

int minimum = INFINITY;

void dfs(int vertex, int distance)
{
	int i = 0;

	if (distance >= minimum)
		return;

	if (END_VERTEX == vertex && distance < minimum) {
		minimum = distance;
		return;
	}

	for (i = 0; i < VERTEX; i++) {
		if ((adj_matrix[vertex][i] < INFINITY) && (book[i] == 0)) {
			book[i] = 1;
			dfs(i, distance + adj_matrix[vertex][i]);
			book[i] = 0;
		}
	}

	return;
}

int main(int argc, char *argv[])
{
	int i, j;
	int a, b;

	memset(book, 0x0, sizeof(book));

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
	book[0] = 1;

	dfs(START_VERTEX, 0);
	printf("the shortest path from %d to %d is %d\n", START_VERTEX, END_VERTEX, minimum);

	return 0;
}

