#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

char arr[1000005];
/*
int main(void) {

	fgets(arr, sizeof(arr), stdin);
	
	int length = strlen(arr);
	arr[length - 1] = '\0';

	int counter=0;
	char prev = ' ';

	for (int i = 0; i < length-1; i++) {
		
		if (arr[i] != ' ' && prev != arr[i] && i > length-2) {
			counter++;
		}
		prev = arr[i];
	}

	if (length == 1) {
		counter = 0;
	}
	else if (counter == 0) {
		counter = 1;
	}

	printf("%d\n", counter);

}
*/

int main(void) {

	fgets(arr, sizeof(arr), stdin);

	int length = strlen(arr);
	arr[length - 1] = '\0';
	
	int counter = 0;
	int continueCharCount = 0;
	int prevCharCount = 0;

	char prev = '\0';
	for (int i = 0; i < length - 1; i++) {
		if (arr[i] != ' ' && arr[i] != '\0') {
			continueCharCount++;
		}
		else {
			if (prevCharCount > 0) {
				counter++;
			}
			prevCharCount = 0;
			continueCharCount = 0;
		}
		prevCharCount = continueCharCount;
		//printf("%c : %d\n", arr[i], continueCharCount);
	}
	if (prevCharCount > 0) {
		counter++;
	}
	printf("%d\n", counter);

	return 0;
}