#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
int arr[2187][2187];

void recur(int size, int posX, int posY) {
	if (size == 1) {
		arr[posX][posY] = 1;
		return;
	}
	size /= 3;
	for (int i = 0; i<3 ; i ++) {
		for (int j = 0; j < 3; j ++) {
			if (i == 1 && j == 1) {
				continue;
			}
			recur(size, posX + (size * i), posY + (size * j));
		}
	}
}

int main(void) {
	int n;
	scanf("%d", &n);

	recur(n, 0, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				printf(" ");
			}
			else { printf("*");	}
		}
		printf("\n");
	}

	return 0;
}