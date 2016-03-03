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

	*bt = NULL;

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
				new->left_node = NULL;
				new->right_node = NULL;

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
				if (top == BTREE_MAX_NODE - 1)
				{
					printf("the stack is already full!");
					exit(1);
				}
				top++;
				s[top] = new;
				k = 1;
				break;

			case ',':
				k = 2;
				break;

			case ')':
				if (top == -1)
				{
					printf("the stack is already empty!");
					exit(1);
				}
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
	if (*bt != NULL)
	{
		clear_btree(&((*bt)->left_node));

		clear_btree(&((*bt)->right_node));

		free(*bt);
		*bt = NULL;		
	}

	return;
}

int empty_btree(btree_node *bt)
{
	return ((NULL == bt) ? 1 : 0);
}

int depth_btree(btree_node *bt)
{
	if(NULL == bt)
	{
		return 0;
	}

	return MAX(depth_btree(bt->left_node), depth_btree(bt->right_node)) + 1;
}

ElemType *find_btree(btree_node *bt, ElemType x)
{	
	if (bt != NULL)
	{
		if(bt->data == x)
		{
			return &bt->data;
		}

	}

	return NULL;
}

void print_btree(btree_node *bt)
{
	if(NULL != bt)
	{
		printf("%c",bt->data);
		
		if (bt->left_node != NULL || bt->right_node != NULL)
		{
			printf("(");
			print_btree(bt->left_node);

			if(bt->right_node != NULL)
			{
				printf(",");
				print_btree(bt->right_node);
			}

			printf(")");
		}
	
	}

	return;
}

