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

#if 0
	t = head;
	if (t->data > a) {
		p->next = head;
		head = p;
	} else {
		while (NULL != t->next) {
			if (t->next->data > a) {
				p->next = t->next;
				t->next = p;
				break;
			}
			t = t->next;
		}
		if (NULL == t->next) {
			t->next = p; 
		}
	}
#else
	t = head;
	q = t;
	while (NULL != t) {
		if (t->data > a) {
			p->next = t;
			q->next = p;
			break;
		}
		q = t;
		t = t->next;
	}
	if (NULL == t) {
		q->next = p; 
	}
#endif

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

