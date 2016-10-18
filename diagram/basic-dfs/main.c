#include"main.h"

int adj_matrix[VERTEX][VERTEX] = {
	{0, 		1, 		1, 		INFINITY, 	1},
	{1, 		0, 		INFINITY, 	1, 		INFINITY},
	{1, 		INFINITY, 	0, 		INFINITY, 	1},
	{INFINITY, 	1, 		INFINITY, 	0, 		INFINITY},
	{1, 		INFINITY, 	1, 		INFINITY, 	0},
};

int book[VERTEX];

int sum = 0;

void dfs(int vertex)
{
	int i = 0;

	printf("%d ", vertex);
	sum++;
	if (VERTEX == sum)
		return;

	for (i = 0; i < VERTEX; i++) {
		if (adj_matrix[vertex][i] == 1 && book[i] == 0) {
			book[i] = 1;
			dfs(i);
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

	dfs(0);
	printf("\n");

	return 0;
}

