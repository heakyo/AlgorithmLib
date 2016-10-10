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

#define TOTAL_PAYLOAD 150

#define max(a, b) ((a) > (b) ? (a) : (b))

int dp_kp(int total_payload, int item_num, int *weight, int *price)
{
	if (item_num == 0) {
		if (total_payload < weight[item_num]) {
			return 0;
		} else {
			return price[item_num];
		}
	}

	if (total_payload - weight[item_num] >= 0)
		return max(dp_kp(total_payload - weight[item_num], item_num - 1, weight, price) + price[item_num],
				dp_kp(total_payload, item_num - 1, weight, price));
	
	return dp_kp(total_payload, item_num - 1, weight, price);
}

int main(int argc, char *argv[])
{
	int weight[] = {35, 30, 60, 50, 40, 10, 25};
	int price[]  = {10, 40, 30, 50, 35, 40, 30};
	//int weight[] = {35, 30};
	//int price[]  = {10, 40};

	int items = sizeof(weight) / sizeof(weight[0]);

	printf("max:%d\n", dp_kp(TOTAL_PAYLOAD, items - 1, weight, price));
	
	return 0;
}
