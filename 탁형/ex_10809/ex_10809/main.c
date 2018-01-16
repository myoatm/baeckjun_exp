#pragma warning(disable:4996)
#include <stdio.h>

char arr[101];
short int check[26];
int main(void) {
	for (int i = 0; i < 26; i++) {
		check[i] = -1;
	}
	scanf("%s", &arr);
	int key = 0;
	for (int i = 0; i < strlen(arr); i++) {
		key = arr[i] - 97;
		if (check[key] == -1) {
			check[key] = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", check[i]);
	}

	return 0;
}