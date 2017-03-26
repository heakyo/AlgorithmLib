#include"main.h"

int match[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int num_match_cnt(int x)
{
	int cnt = 0;

	while (x / 10 != 0) {
		cnt += match[x % 10];
		x /= 10;
	}

	cnt += match[x];

	return cnt;
}

int main(int argc, char *argv[])
{
	int m = 0;
	int a, b, c;
	int total_cnt = 0;

	scanf("%d", &m);
	
	for (a = 0; a < 1111; a++)
		for (b = 0; b < 1111; b++) {
			c = a + b;

			if (num_match_cnt(a) + num_match_cnt(b) + num_match_cnt(c) == (m-4))
				total_cnt++;
		}

	printf("%d\n", total_cnt);
	return 0;
}

