#include"main.h"

int adj_matrix[VERTEX][VERTEX] = {
	{0, 		1, 		1, 		INFINITY, 	1},
	{1, 		0, 		INFINITY, 	1, 		INFINITY},
	{1, 		INFINITY, 	0, 		INFINITY, 	1},
	{INFINITY, 	1, 		INFINITY, 	0, 		INFINITY},
	{1, 		INFINITY, 	1, 		INFINITY, 	0},
};

int main(int argc, char *argv[])
{
	int i, j;
	int a, b;

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

	return 0;
}

