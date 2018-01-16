#pragma warning(disable:4996)

#include <stdio.h>

char arr[16];
short int range[10] = {-1,2,5,8,11,14,18,21,25,26};

int convertASCII2Number(int n) {
	for (int i = 0; i <= 10; i++) {
		if (range[i] >= n) {
			return i+1;
		}
	}

	return -1;
}
int main(void) {
	
	scanf("%s", arr);
	int sum = 0;

	int length = strlen(arr);
	for (int i = 0; i < length; i++) {
		int result = convertASCII2Number(arr[i] - 65);
		if (result >=0) {
			sum += result+1; // 1을누르는데 2초가걸림. 2는 3초
		}
	}
	printf("%d\n",sum);


	return 0;
}