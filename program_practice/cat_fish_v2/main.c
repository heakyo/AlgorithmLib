#include"main.h"

//int a[] = {2, 4, 1, 2, 5, 6};
//int b[] = {3, 1, 3, 5, 6, 4};
int a[] = {2, 4, 1, 2, 5, 6};
int b[] = {3, 1, 3, 5, 6, 4};

int main(int argc, char *argv[])
{
	struct queue q1, q2;
	struct stack s;

	int i, j;
	int t;
	int flg = 0;

	memset(q1.q, 0x0, 4000);
	memset(q2.q, 0x0, 4000);
	memcpy(q1.q, a, sizeof(a));
	q1.head = 0;
	q1.tail = ARRAY_CNT(a);
	memcpy(q2.q, b, sizeof(a));
	q2.head = 0;
	q2.tail = ARRAY_CNT(b);

	s.top = -1;

	for (i = 0; i < ARRAY_CNT(a); i++)
		printf("%d ", q1.q[i]);
	printf("\n");
	for (i = 0; i < ARRAY_CNT(b); i++)
		printf("%d ", q2.q[i]);
	printf("\n");

#if 0
 	for (i = 1; i < 0; i++) {
		s.top++;
		s.s[s.top] = i;
		printf("%d ", s.s[s.top]);
	}
	printf("\n");
	printf("top:%d\n", s.top);
#endif

	while ((q1.head < q1.tail) && (q2.head < q2.tail)) {
		flg = 0;
		t = q1.q[q1.head];
		q1.head++;
		for (i = 0; i <= s.top; i++) {
			if (t == s.s[i]) {
				flg = 1;
				printf("q1----i:%d b-top: %d ", i, s.top);
				q1.q[q1.tail] = t;
				q1.tail++;
				for (j = s.top; j >= i; j--) {
					q1.q[q1.tail] = s.s[j];
					q1.tail++;
				}

				//s.top = i - 1;
				s.top -= ((s.top - i) + 1);
				printf("a-top: %d\n", s.top);
				break;
			}
		}
		if (!flg) { /* put the card on the table */
			s.top++;
			s.s[s.top] = t;
		}
		if (q1.head >= q1.tail)
			break;

		flg = 0;
		t = q2.q[q2.head];
		q2.head++;
		for (i = 0; i <= s.top; i++) {
			if (t == s.s[i]) {
				flg = 1;
				printf("q2----i:%d b-top: %d ", i, s.top);
				q2.q[q2.tail] = t;
				q2.tail++;
				for (j = s.top; j >= i; j--) {
					q2.q[q2.tail] = s.s[j];
					q2.tail++;
				}

				//s.top = j - 1;
				s.top -= ((s.top - i) + 1);
				printf("a-top: %d\n", s.top);
				break;
			}
		}
		if (!flg) { /* put the card on the table */
			s.top++;
			s.s[s.top] = t;
		}
		if (q1.head >= q1.tail)
			break;
	#if 1
		printf("table(%d):", s.top);
		for (i = 0; i <= s.top; i++)
			printf("%d ", s.s[i]);
		printf("\n");

		printf("q1(%d %d):", q1.head, q1.tail);
		for (i = q1.head; i < q1.tail; i++)
			printf("%d ", q1.q[i]);
		printf("\t\t");
		printf("q2(%d %d):", q2.head, q2.tail);
		for (i = q2.head; i < q2.tail; i++)
			printf("%d ", q2.q[i]);
		printf("\n\n");
	#endif
	}

	printf("head1:%d head2:%d tail1:%d tail2:%d\n", q1.head, q2.head, q1.tail, q2.tail);

	printf("table:");
	for (i = 0; i <= s.top; i++)
		printf("%d ", s.s[i]);
	printf("\n");

	for (i = q1.head; i < q1.tail; i++)
		printf("%d ", q1.q[i]);
	printf("\n");
	for (i = q2.head; i < q2.tail; i++)
		printf("%d ", q2.q[i]);
	printf("\n");

	return 0;
}

