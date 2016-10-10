/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Dynamic Programming
 *    				Longest Increasing Subsequence
 *
 *        Version:  1.0
 *        Created:  2016年10月09日 14时33分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

#define LEN 8

int dy_lis(int str_len, int *src, int *dest)
{
	int max_j = 0;
	int j = 0;
	int i = 0;
	int last_idx = str_len - 1;

	if (str_len == 1)
		return 1;

	for (i = 0; i < last_idx; i++) {
		if (src[last_idx] >= src[i]) {
			j = dy_lis(i + 1, src, dest);

			if (j > max_j) {
				max_j = j;
			}
		}
	}

	return max(max_j + 1, dy_lis(str_len - 1, src, dest));
}

int main(int argc, char *argv[])
{
	int src[LEN] = {1, 2, 3, 3, 5, 4, 6, 2};
	//int src[LEN] = {1, 2, 3, 3};
	int dest[LEN];

	int i = 0;

	printf("LIS: %d\n", dy_lis(LEN, src, dest));

#if 0
	for (i = 0; i < LEN; i++) {
		
		if (dest[i] == 0)
			break;

		printf("%d ", dest[i]);
	}
	printf("\n");
#endif

	return 0;
}
