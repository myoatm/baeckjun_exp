#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int current = 1;
	int counter = 1;
	int num;
	scanf("%d", &num);
	num -= 1;
	while (num > 0){
		num -= ++current;
		counter++;
		if (num == 0) {
			num = current - 1;
			break;
		}
		if (num < 0) {
			num += current - 1;
			break;
		}

	}
	int x, y;
	if (counter%2==1) {
		x = counter - num, y = 1 + num;
	}
	else {
		x = num+1, y = counter-num;
	}

	printf("%d/%d\n", x, y);

	return 0;
}