#include"btree-node.h"


void init_btree(btree_node **bt)
{
	*bt = NULL;

	return;
}

void create_btree(btree_node **bt, char *a)
{
	btree_node *new = NULL, *parent = NULL;

	btree_node *s[BTREE_MAX_NODE];

	int top = -1;
	int i = 0;
	int k = 0;

	while(a[i])
	{
		switch(a[i])
		{
			default: 
				new = (btree_node *)malloc(sizeof(btree_node));
				if (!new)
				{
					printf("Allocate the btree node memory failed!\n");
					exit(1);
				}
				new->data = a[i];
				if (NULL == *bt) // root node
				{
					*bt = new;

				} else if (k == 1) // left node
				{
					parent = s[top];
					parent->left_node = new;

				} else if (k == 2) // right node
				{
					parent = s[top];
					parent->right_node = new;
				}
				break;
			case '(':
				top++;
				s[top] = new;
				k = 1;
				break;

			case ',':
				k = 2;
				break;

			case ')':
				top--;
				break;
			case ' ':
				break; 
		}

		i++; // next char
	}	

	return;
}

void clear_btree(btree_node **bt)
{
	return;
}

int empty_btree(btree_node *bt)
{
	return 1;
}

int depth_btree(btree_node *bt)
{
	return 1;
}

ElemType *find_btree(btree_node *bt, ElemType x)
{
	ElemType *p = NULL;

	return p;
}

void print_btree(btree_node *bt)
{
	if(NULL != bt)
	{
		printf("%c",bt->data);
		
		if (bt->left_node)
		{
			printf("(");
			print_btree(bt->left_node);
		}

		if (bt->right_node)
		{
			printf(",");
			print_btree(bt->right_node);
			printf(")");
		}
	
	}

	return;
}



