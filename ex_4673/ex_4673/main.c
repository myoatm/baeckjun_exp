#include <stdio.h>
#include <stdlib.h>


short int checked[10001];

//int isSelfNumber(int n) {
void isSelfNumber(int n) {
	int backup = n;
	int sum = n;

	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	if (sum <= 10000) {
		checked[sum] = 1;
	}
	//return sum;

}

int main(void) {
	

	for (int i = 1; i <= 10000; i++) {
		/*
		if (isSelfNumber(i)>0) {
			checked[i] = 1;
		}
		*/
		isSelfNumber(i);
	}
	for (int i = 1; i <= 10000; i++) {
		if (!checked[i]) {
			printf("%d\n", i);
		}
	}



	return 0;
}