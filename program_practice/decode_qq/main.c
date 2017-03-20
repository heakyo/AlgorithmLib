#include"main.h"

//int a[] = {6, 3, 1, 7, 5, 8, 9, 2, 4};
int a[] = {6};

int main(int argc, char *argv[])
{
	struct queue q;
	int n = sizeof(a) / sizeof(a[0]);
	int i = 0;

	memcpy(q.data, a, n * 8);
	q.head = 0;	
	q.tail = n; 

	for (i = 0; i < n; i++)
		printf("%d ", q.data[i]);
	printf("\n");

	while (q.head < q.tail) {
		
		/* get the deleted num */
		printf("%d ", q.data[q.head]);
		q.head++;
		
		if (q.head != q.tail) {
			q.data[q.tail] = q.data[q.head];
			q.tail++;
			q.head++;
		}
		
	}
	printf("\n");

	return 0;
}

