#pragma warning(disable:4996)
#include <stdio.h>

int arr[10];

inline void numToFillArray(int n) {
	int i = 0;
	while (n > 0) {
		arr[i++] = n % 10;
		n /= 10;
	}
}

inline void bbSort() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i] < arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}

		}

	}


}

int main(void) {

	//init
	for (int i = 0; i < 10; i++) {
		arr[i] = -1;
	}

	int num;
	scanf("%d", &num);
	numToFillArray(num);
	bbSort();
	for (int i = 10-1; i >=0; i--) {
		if (arr[i] != -1) {
			printf("%d", arr[i]);
		}

	}
	printf("\n");


	return 0;
}