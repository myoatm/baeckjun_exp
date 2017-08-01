#pragma warning(disable:4996)
#include <stdio.h>
int main() {
	char c1[4], c2[4];
	int num1, num2;

	scanf("%d %d", &num1, &num2);
	//itoa(num1, c1, 10);
	//itoa(num2, c2, 10);

	sprintf(c1, "%d", num1);
	sprintf(c2, "%d", num2);

	char tmp = c1[0];
	c1[0] = c1[2];
	c1[2] = tmp;

	tmp = c2[0];
	c2[0] = c2[2];
	c2[2] = tmp;
	
	num1 = atoi(c1);
	num2 = atoi(c2);
	printf("%d\n", num1 > num2 ? num1 : num2);

	return 0;
}