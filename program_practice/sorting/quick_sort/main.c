/*
 * =====================================================================================
 *
 *       Filename:  quick_sorting.c
 *
 *    Description:  quick sort
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

void swap(int *a, int *b)
{
	int temp = 0;

	temp = *a;
	*a = *b;
	*b = temp;
}

/* from small number to big number */
void quick_sort(int *ary, int left, int right)
{
	int l = left;
	int r = right;
	int base = 0;

	if (left > right)
		return;

	base = ary[left];

	while (l != r) {
	
		while (ary[r] > base && r > l)
			r--;

		while (ary[l] <= base && r > l)
			l++;

		// exchange
		swap(&ary[l], &ary[r]);
	}
	swap(&ary[left], &ary[r]);

	quick_sort(ary, left, r-1);
	quick_sort(ary, l+1, right);
}

int main(int argc, char *argv[])
{
	int test_array[] = {3, 6, 4, 2, 0, 1, 8, 5, 7};
	//int test_array[] = {8, 7, 6, 5, 4, 3, 2, 1, 0};
	//int test_array[] = {8,7,6};

	int i = 0;
	int len = sizeof(test_array) / sizeof(test_array[0]);

	quick_sort(test_array, 0, len - 1);

	for (i = 0; i < len; i++)
		printf("%d ", test_array[i]);

	printf("\n");

	return 0;
}
