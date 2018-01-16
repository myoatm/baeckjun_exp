#pragma warning(disable:4996)
#include <stdio.h>

char arr[21];
int main(void) {

	int n, repeat;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &repeat);
		scanf("%s", arr);
		for (int a = 0; a < strlen(arr); a++) {
			for (int j = 0; j < repeat; j++) {
				printf("%c", arr[a]);
			}
		}
		printf("\n");
	}

	return 0;
}