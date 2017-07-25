#pragma warning (disable:4996) 

#include <stdio.h>

int n;

int main(void) {
	scanf("%d", &n);
	
	int tmp;
	while (1) {
		scanf("%d", &tmp);
		if (tmp == 0) break;

		if (tmp%n == 0) {
			printf("%d is a multiple of %d.\n", tmp, n);
		}
		else {
			printf("%d is NOT a multiple of %d.\n", tmp, n);
		}

	}

	return 0;
}