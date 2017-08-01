#pragma warning(disable:4996)
#include <stdio.h>


char arr[81];

int main(void) {
	int n;
	scanf("%d", &n);
	

	for (int a = 0; a < n; a++) {
		int straight = 0;
		int	score = 0;
		scanf("%s", &arr);
		int length = strlen(arr);
		for (int i = 0; i < length; i++) {
			if (arr[i] == 'X') {
				if (straight > 0) {
					score += (straight*(straight + 1)) / 2;
					straight = 0;
				}
			}
			else if (arr[i] == 'O') {
				straight++;
			}
		}
		if (straight > 0) {
			score += (straight*(straight + 1)) / 2;
			straight = 0;
		}
		printf("%d\n", score);
		score = 0;
	}




	return 0;
}