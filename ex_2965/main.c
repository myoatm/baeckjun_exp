#pragma warning (disable:4996) 
#include <stdio.h>

int main(void) {

	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	printf("%d", (B - A) > (C - B) ? (B - A - 1) : (C - B - 1));

	return 0;
}