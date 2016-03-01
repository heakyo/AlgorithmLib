#include<stdio.h>
#include<stdlib.h>
#include"btree-node.h"

int main()
{
	btree_node *bt = NULL;
	//char b[50] = "a(b(c),d(e(f,g),h(,i)))";
	char b[50] = "a(b,)";

	printf("%s\n",b);

	init_btree(&bt);
	create_btree(&bt, b);

	print_btree(bt);
	
	return 0;
}
