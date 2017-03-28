#include"main.h"

int main(int argc, char *argv[])
{
	char txt[MAX_LEN];
	struct stack s;
	int mid, len;
	int i;
	int rc = 1;

	scanf("%s", txt);

	s.top = -1;

	len = strlen(txt);
	mid = len / 2;

	for (i = 0; i < mid; i++) {
		s.top++;
		s.data[s.top] = txt[i];
	}

	if (len % 2 == 0) {
		i = mid;
	} else {
		i = mid + 1;
	}
	while (i < len) {
		if (txt[i] != s.data[s.top]) {
			rc = 0;
			break;
		}
		s.top--;
		i++;
	}

	if (!rc) {
		printf("NO\n");
	} else {
		printf("YES\n");
	}

	return 0;
}

