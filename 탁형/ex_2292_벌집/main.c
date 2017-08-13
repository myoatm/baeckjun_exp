#pragma warning(disable:4996)
#include <stdio.h>

/*
1
6 (6)
12 (6+6)
18 (6+6+6)
24 (6+6+6+6)

1
7
19
37
61

13 : 3
58 : 5
65 : 6
*/

int main(void) {

	int current = 0;
	int counter = 1;
	int num;
	scanf("%d", &num);
	num -= 1;
	while (num>0) {
		current += 6;
		num -= current;
		counter++;
	}


	printf("%d\n", counter);

	//58 :
	/*
	58 - 1 = 57
	57 - 7 = 50
	50 - 13 = 37
	37 - 19 = 18
	18 - 25 < 0

	*/


	return 0;
}