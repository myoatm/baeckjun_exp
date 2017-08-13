#include <stdio.h>

int stack[10001];

int main(void) {

	int n;
	scanf("%d", &n);

	char comm[6];
	int pushItem;
	int topPointer = 0;
	
	for (int i = 0; i < n; i++) {
		scanf("%s", comm);

		if (strcmp(comm, "push") == 0) {
			if (topPointer >= 10001) {
				continue;
			}

			scanf("%d", &pushItem);
			stack[topPointer] = pushItem;
			topPointer++;
		}

		else if (strcmp(comm, "pop") == 0) {
			if (topPointer <= 0) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", stack[topPointer - 1]);
			topPointer--;
		}

		else if (strcmp(comm, "size") == 0) {
			printf("%d\n", topPointer);
		}

		else if (strcmp(comm, "top") == 0) {
			if (topPointer <= 0) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", stack[topPointer - 1]);
		}
		else if (strcmp(comm, "empty") == 0) {
			if (topPointer <= 0) {
				printf("1\n");
				continue;
			}
			else {
				printf("0\n");
			}
		}

	}

	return 0;
}