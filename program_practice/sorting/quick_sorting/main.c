/*
 * =====================================================================================
 *
 *       Filename:  quick_sorting.c
 *
 *    Description:  quick sorting
 *
 *        Version:  1.0
 *        Created:  2016年10月08日 21时25分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>

enum {
	RIGHT = 0,
	LEFT,
	TOTAL,
};

void swap(int *a, int *b)
{
	int temp = 0;

	temp = *a;
	*a = *b;
	*b = temp;
}

/* from small number to big number */
void quick_sorting(int *ary, int left, int right)
{
	int l = left;
	int r = right;
	int base = 0;
	int mv_flg = RIGHT;

	base = ary[left];

	while (l != r) {
	
		if (RIGHT == mv_flg) {
			if (ary[r] > base) {
				r--;
				continue;
			}
			
			mv_flg = LEFT;
		}

		if (LEFT == mv_flg) {
			if (ary[l] <= base) {
				l++;
				continue;
			}

			mv_flg = TOTAL;
		}

		// exchange
		if (TOTAL == mv_flg) {
			swap(&ary[l], &ary[r]);	
			mv_flg = RIGHT;
		}
	}
	if (left != r)
		swap(&ary[left], &ary[r]);

	if (left < r-1)
		quick_sorting(ary, left, r-1);

	if ((l+1) < right)
		quick_sorting(ary, l+1, right);
}

int main(int argc, char *argv[])
{
	int test_array[9] = {3, 6, 4, 2, 0, 1, 8, 5, 7};
	//int test_array[9] = {8, 7, 6, 5, 4, 3, 2, 1, 0};
	//int test_array[3] = {8,7,6};
	int i = 0;
	int len = sizeof(test_array) / sizeof(test_array[0]);

	quick_sorting(test_array, 0, len - 1);

	for (i = 0; i < len; i++)
		printf("%d ", test_array[i]);

	printf("\n");

	return 0;
}
