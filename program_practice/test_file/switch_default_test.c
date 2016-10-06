#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int a = 0;

	a = atoi(argv[1]);

	switch(a)
	{
		default:
			printf("%d\n", a);
			break;
		case 1:
			printf("%d\n", 1);
			break;
		case 2:
			printf("%d\n", 2);
			break;
	}
	return 0;
}
