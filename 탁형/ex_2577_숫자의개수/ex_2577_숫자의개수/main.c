#pragma warning(disable:4996)
#include <stdio.h>


short int countList[10];

int main(void) {
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	int result = a*b*c;
	while (result > 0) {
		countList[result % 10]++;
		result /= 10;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", countList[i]);
	}


	return 0;
}