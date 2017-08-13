#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
unsigned short int stack[50];
char arr[51];

int topPos = 0;

int pushParenthesis() {
	if (topPos > 50) {
		return -1;
	}
	stack[topPos++] = 1;
	return 1;
}

int popParenthesis() {
	if (topPos <= 0) {
		return -1;
	}
	stack[--topPos] = 0;
	return 1;
}

int main(void) {
	
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		topPos = 0;

		scanf("%s", arr);
		int len = (int)strlen(arr);

		int flag = 1;
		for (int a = 0; a < len; a++) {
			if (arr[a] == '(') {
				if (pushParenthesis() == -1) {
					//printf("NO\n");
					flag = 0;
					break;
				}
			}
			else if (arr[a] == ')') {
				if (popParenthesis() == -1) {
					//printf("NO\n");
					flag = 0;
					break;
				}
			}
		}

		if (topPos == 0 && flag == 1) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}



	}



	return 0;
}