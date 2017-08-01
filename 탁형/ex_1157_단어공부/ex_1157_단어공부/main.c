#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
char arr[1000003];
int check[26];
int main(void) {

	//scanf("%s", arr);
	gets(arr);

	int length = strlen(arr);
	for (int i = 0; i < length; i++) {
		if (arr[i] - 97 < 0) {
			check[arr[i] - 65]++;
		}
		else {
			check[arr[i] - 97]++;
		}
	}

	int max =0, maxIndex=-1;
	int flag = 0;

	for (int i = 0; i < 26; i++) {
		if (check[i] == 0) {
			continue;
		}

		if (check[i] > max) {
			max = check[i];
			maxIndex = i;
			flag = 0;
		}
		else if (check[i] == max) {
			flag = 1;
		}
	}

	if (flag == 1) {
		printf("?\n");
	}
	else {
		printf("%c\n", maxIndex+65);
	}
	
	return 0;
}