#pragma warning(disable:4996)
#include <stdio.h>

char arr[101];

int main(void) {
	
	scanf("%s", arr);
	int length = strlen(arr);
	int counter = length;
	char prev = ' ';
	for (int i = 0; i < length; i++) {
		switch (prev) {
		case 'c':
			if (arr[i] == '=') {
				counter--;
			}
			else if (arr[i] == '-') {
				counter--;
			}
			break;
		case 'd':
			if (arr[i] == 'z') {
				if (length - i -1> 0) {
					if (arr[i + 1] == '=') {
						counter--;
					}
				}
			}
			else if (arr[i] == '-') {
				counter--;
			}
			break;
		case 'l':
			if (arr[i] == 'j') {
				counter--;
			}
			break;
		case 'n':
			if (arr[i] == 'j') {
				counter--;
			}
			break;
		case 's':
			if (arr[i] == '=') {
				counter--;
			}
			break;
		case 'z':
			if (arr[i] == '=') {
				counter--;
			}
			break;
		default:

			break;
		}
		prev = arr[i];
	}

	printf("%d\n", counter);


	return 0;
}