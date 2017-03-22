#include"main.h"

int show_linked_list()
{

}

int main(int argc, char *argv[])
{
	struct node *p, *q, *head, *t;
	int n, a;
	int i;
	
	head = NULL;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a);

		p = (struct node *)malloc(sizeof(*p));
		if (!p)
			return -1;
		p->data = a;
		p->next = NULL;

		if (NULL == head) {
			head = p;
		} else {
			q->next = p;
		}

		q = p;
	}
	
	/* the inserted value */
	scanf("%d", &a);
	p = (struct node *)malloc(sizeof(*p));
	if (!p)
		return -1;
	p->data = a;
	p->next = NULL;

	t = head;
	if (t->data > a) { /* the node is inserted in the beginning */
		p->next = head;
		head = p;
	} else {
		/* the node is inserted in the middle */
		while (NULL != t->next) {
			if (t->next->data > a) {
				p->next = t->next;
				t->next = p;
				break;
			}
			t = t->next;
		}

		/* the node is inserted in the end */
		if (NULL == t->next)
			t->next = p; 
	}

	t = head;	
	while (t != NULL) {
		printf("%d ", t->data);
		q = t;
		t = t->next;

		free(q);
	}
	printf("\n");

	return 0;
}

