/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  dynamic programming
 *    				01 knapsack problem
 *
 *        Version:  1.0
 *        Created:  2016年10月10日 14时33分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<string.h>

//#define DEBUG

#define TOTAL_PAYLOAD 150
#define TOTAL_ITEMS 7

#define max(a, b) ((a) > (b) ? (a) : (b))

int dp_memo[TOTAL_PAYLOAD + 1][TOTAL_ITEMS + 1];

/*-----------------------------------------------------------------------------
 * description:
 * 	pick up some items from num a0,a1...ai to put in the knapsack whose capacity
 * 	is cur_payload for getting the max value of items.
 *-----------------------------------------------------------------------------*/
int dp_kp(int cur_payload, int item_num, int *weight, int *price)
{
	int ret = 0;

	if (dp_memo[cur_payload][item_num] >= 0)
		return dp_memo[cur_payload][item_num];

	// 1. no item can be choosed
	// 2. or no capacity to put any item in
	if (item_num == -1 || cur_payload == 0)
		return 0;

	if (cur_payload >= weight[item_num]) {
		ret = max(dp_kp(cur_payload - weight[item_num], item_num - 1, weight, price) + price[item_num],
			dp_kp(cur_payload, item_num - 1, weight, price));

	} else {
		ret = dp_kp(cur_payload, item_num - 1, weight, price);
	}

	return dp_memo[cur_payload][item_num] = ret;
}

int main(int argc, char *argv[])
{
	int weight[] = {35, 30, 60, 50, 40, 10, 25};
	int price[]  = {10, 40, 30, 50, 35, 40, 30};

	memset(dp_memo, -1, sizeof(dp_memo));
	printf("max:%d\n", dp_kp(TOTAL_PAYLOAD, TOTAL_ITEMS - 1, weight, price));

#ifdef DEBUG
	int c = 0;
	int i = 0;
	int j = 0;

	for (i = 0; i < TOTAL_PAYLOAD + 1; i++) {
		for (j = 0; j < TOTAL_ITEMS + 1; j++) {
			if (dp_memo[i][j] != -1) {
				printf("%d %d %d\n", i, j, dp_memo[i][j]);
				c++;
			}
		}
	}

	printf("c:%d\n", c);
#endif /*  DEBUG */

	return 0;
}
