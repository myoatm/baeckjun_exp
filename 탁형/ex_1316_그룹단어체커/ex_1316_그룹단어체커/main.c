#pragma warning(disable:4996)
#include <stdio.h>

char arr[102];
char isGroupWord[101] = { 1, };


int main(void) {

	int n, len;
	char prev;
	int check[26];

	scanf("%d", &n);
	int counter=n;

	for (int i = 0; i < n; i++) {
		
		scanf("%s", arr);

		for (int aa = 0; aa < 26; aa++) {
			check[aa] = -1;
		}

		len = strlen(arr);
		int backN = len;
		for (int a = 0; a < len; a++) {
			int idx =arr[a] - 97;
			if (check[idx] == -1) {
				check[idx] = a;
				prev = arr[a];
			}
			else {
				if (prev == arr[a]) {
					check[idx] = a;
				}
				else {
					backN--;
					break;
				}
			}
		}
		if (backN != len) {
			counter--;
		}
	}

	printf("%d\n", counter);

	return 0;
}
