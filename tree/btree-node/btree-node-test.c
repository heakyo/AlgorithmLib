#include<stdio.h>
#include<stdlib.h>
#include"btree-node.h"

int main()
{
	btree_node *bt = NULL;
	char b[50] = "a(b(c),d(e(f,g),h(,i)))";
	//char b[50] = "a";
	int depth = 0;

	printf("%s\n",b);

	init_btree(&bt);
	create_btree(&bt, b);

	print_btree(bt);
	printf("\n");
	
	depth = depth_btree(bt);
	printf("btree depth:%d\n", depth);
	
	return 0;
}
