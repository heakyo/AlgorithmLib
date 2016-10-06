/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  greedy algorithm practice
 *    				knapsack problem
 *
 *        Version:  1.0
 *        Created:  2016年10月06日 20时08分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>

#define MAX_PAYLOAD 150
#define MAX_ITEMS 7

enum {
	UNSELECTED = 0,
	SELECETED,
};

enum greedy_policy {
	PRICE_POLICY,
	WEIGHT_POLICY,
	RATIO_POLICY,
	TOTAL_POLICY
};

typedef struct {
	int weight;
	int price;
	int status; // 0:unselected 1:selected
} bag_item_t;

typedef int (*greedy_func_fn)(bag_item_t *pbag_item, int rest_weight);

void greedy_algo(bag_item_t *pbag_item, greedy_func_fn greedy_func)
{
	int idx = -1;
	int rest_weight = MAX_PAYLOAD; // the total weight left
	int total_price = 0;
	int total_weight = 0;

	printf("pick up items: ");
	while ((idx = greedy_func(pbag_item, rest_weight)) != -1) {

		rest_weight -= pbag_item[idx].weight;
		total_price += pbag_item[idx].price;
		total_weight += pbag_item[idx].weight;

		printf("\033[1;32;20m%d \033[0m", idx + 1);
	}

	printf("\ntotal weight is \033[1;32;20m%d\033[0m <= %d\n", total_weight, MAX_PAYLOAD);
	printf("total price is \033[1;32;20m%d\033[0m\n", total_price);
}

int greedy_price(bag_item_t *pbag_item, int rest_weight)
{
	int mp = 0; // max price
	int i = 0;
	int max_idx = -1;
	
	for (i = 0; i < MAX_ITEMS; i++) {
		if (pbag_item[i].price > mp && 
			UNSELECTED == pbag_item[i].status &&
			pbag_item[i].weight <= rest_weight) {

			mp = pbag_item[i].price;
			max_idx = i;
		}
	}

	if (max_idx != -1)
		pbag_item[max_idx].status = SELECETED;

	return max_idx;
}

int greedy_weight(bag_item_t *pbag_item, int rest_weight)
{
	int mw = rest_weight; // min weight
	int i = 0;
	int min_idx = -1;
	
	for (i = 0; i < MAX_ITEMS; i++) {
		if (pbag_item[i].weight < mw && 
			UNSELECTED == pbag_item[i].status &&
			pbag_item[i].weight <= rest_weight) {

			mw = pbag_item[i].weight;
			min_idx = i;
		}
	}

	if (min_idx != -1)
		pbag_item[min_idx].status = SELECETED;

	return min_idx;
}

int greedy_ratio(bag_item_t *pbag_item, int rest_weight)
{
	float mr = 0; // min weight
	float cur_ratio = 0;
	int i = 0;
	int max_idx = -1;
	
	for (i = 0; i < MAX_ITEMS; i++) {
	
		cur_ratio = (float)pbag_item[i].price / (float)pbag_item[i].weight;

		if (cur_ratio > mr && 
			UNSELECTED == pbag_item[i].status &&
			pbag_item[i].weight <= rest_weight) {

			mr = cur_ratio;
			max_idx = i;
		}
	}

	if (max_idx != -1)
		pbag_item[max_idx].status = SELECETED;

	return max_idx;
}

int main(int argc, char *argv[])
{
	bag_item_t bag_item[MAX_ITEMS] = {
		{35,10},{30,40},{60,30},{50,50},
		{40,35},{10,40},{25,30},
	};

	int policy = 0;

	if (argc != 2) {
		printf("\033[1;31;20mparameter should be only one\n\033[0m");
		return -2;
	}

	policy = atoi(argv[1]);

	greedy_func_fn greedy_func[TOTAL_POLICY] = {
		greedy_price,
		greedy_weight,
		greedy_ratio,
	};

	printf("greedy policy ------ \033[1;32;20m");
	switch (policy) {
	case PRICE_POLICY:
		printf("price policy");
		break;
	case WEIGHT_POLICY:
		printf("weight policy");
		break;
	case RATIO_POLICY:
		printf("ratio policy");
		break;
	default:
		printf("\033[1;31;20mwrong policy\n\033[0m");
		return -1;
		
	}
	printf("\033[0m\n");

	greedy_algo(bag_item, greedy_func[policy]);

	return 0;
}

/* debug */
// printf("\nrw:%d", rest_weight);
// printf("mw:%d w:%d p:%d s:%d\n", mw, pbag_item[i].weight, pbag_item[i].price, pbag_item[i].status);

