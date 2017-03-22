#include"main.h"

int a[] = {2, 4, 1, 2, 5, 6};
int b[] = {3, 1, 3, 5, 6, 4};
//int a[] = {1, 2};
//int b[] = {1, 2};

int main(int argc, char *argv[])
{
	struct queue q1, q2;
	struct stack s;

	int i, j;
	int t;

	memset(q1.q, 0x0, 400);
	memset(q2.q, 0x0, 400);
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

#if 1
 	for (i = 1; i < 0; i++) {
		s.top++;
		s.s[s.top] = i;
		printf("%d ", s.s[s.top]);
	}
	printf("\n");
	printf("top:%d\n", s.top);
#endif

	while ((q1.head < q1.tail) && (q2.head < q2.tail)) {
		t = q1.q[q1.head];
		q1.head++;
		for (i = 0; i <= s.top; i++) {
			if (t == s.s[i]) {
				for (j = i; j <= s.top; j++) {
					q1.q[q1.tail] = s.s[j];
					q1.tail++;
				}
				q1.q[q1.tail] = t;
				q1.tail++;

				s.top -= j;
				break;
			}
		}
		if (i == s.top + 1) { /* put the card on the table */
			s.top++;
			s.s[s.top] = t;
		}

		t = q2.q[q2.head];
		q2.head++;
		for (i = 0; i <= s.top; i++) {
			if (t == s.s[i]) {
				for (j = i; j <= s.top; j++) {
					q2.q[q2.tail] = s.s[j];
					q2.tail++;
				}
				q2.q[q2.tail] = t;
				q2.tail++;

				s.top -= j;
				break;
			}
		}
		if (i == s.top + 1) { /* put the card on the table */
			s.top++;
			s.s[s.top] = t;
		}
	}

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

