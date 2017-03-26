#include"main.h"

int a[] = {2, 4, 1, 2, 5, 6};
int b[] = {3, 1, 3, 5, 6, 4};

void put_card(struct stack *s, int card)
{
	s->top++;
	s->data[s->top] = card;
}

void handle_cards(struct queue *q, struct stack *s)
{
	int card;

	card = get_cards(q, s);
	if (!card)
		return;

	put_card(s, card);
}

/* 
 * return 0: 
 * 	if the card is the same with any card on table
 *
 * return value:
 * 	if put the card on the end of the cards
 */
int get_cards(struct queue *q, struct stack *s)
{
	int flg = 0;
	int i, j, t;

	t = q->data[q->head];
	q->head++;
	for (i = 0; i <= s->top; i++) {
		if (t == s->data[i]) {
			flg = 1;
			q->data[q->tail] = t;
			q->tail++;

			while (t != s->data[s->top]) {
				q->data[q->tail] = s->data[s->top];
				q->tail++;
				s->top--;
			}

			q->data[q->tail] = s->data[s->top];
			q->tail++;
			s->top--;
			break;
		}
	}

	if (!flg)
		return t;

	return !flg;
}

int main(int argc, char *argv[])
{
	struct queue q1, q2;
	struct stack s;

	int i, j;
	int t;
	int flg = 0;

	/* init q1 and q2 and s */
	q1.head = q1.tail = 0;
	for (i = 0; i < ARRAY_CNT(a); i++) {
		q1.data[q1.tail] = a[i];
		q1.tail++;
	}

	q2.head = q2.tail = 0;
	for (i = 0; i < ARRAY_CNT(b); i++) {
		q2.data[q2.tail] = b[i];
		q2.tail++;
	}

	s.top = -1;

	printf("A init cards: ");
	for (i = 0; i < ARRAY_CNT(a); i++)
		printf("%d ", q1.data[i]);
	printf("\n");
	printf("B init cards: ");
	for (i = 0; i < ARRAY_CNT(b); i++)
		printf("%d ", q2.data[i]);
	printf("\n");

	while ((q1.head < q1.tail) && (q2.head < q2.tail)) {
		
		handle_cards(&q1, &s);
		if (q1.head == q1.tail)
			break;

		handle_cards(&q2, &s);
	}

	if (q1.head < q1.tail) {
		printf("A win! Cards on q1 are ");
		for (i = q1.head; i < q1.tail; i++)
			printf("%d ", q1.data[i]);
		printf("\n");

	}

	if (q2.head < q2.tail) {
		printf("B win! Cards on q2 are ");
		for (i = q2.head; i < q2.tail; i++)
			printf("%d ", q2.data[i]);
		printf("\n");
	}

	printf("Cards on the table:");
	for (i = 0; i <= s.top; i++)
		printf("%d ", s.data[i]);
	printf("\n");

	return 0;
}

