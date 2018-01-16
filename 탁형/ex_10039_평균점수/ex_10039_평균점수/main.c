#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int tmp;
	int score = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &tmp);
		score += tmp<40? 40 : tmp;
	}
	printf("%d\n", score/5);
	
	return 0;
}