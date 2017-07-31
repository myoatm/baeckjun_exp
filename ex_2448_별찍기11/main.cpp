#pragma warning(disable:4996)
#include <stdio.h>

bool check[3072][6144]; // 3072*2 -1;
void recur(int size, int row, int col) {
	int underline = (2 * size - 1);

	if (size == 3) {
		check[row][col] = true;
		check[row+1][col-1] = true; check[row + 1][col+ 1] = true;	
		for (int i = 0; i < 5; i++) {
			check[row + 2][col -2+ i] = true;
		}
		return;
	}
	size /= 2;
	recur(size, row + 0, col + 0);
	recur(size, row+ size, col - size);
	recur(size, row+ size, col + size);
}
// n은 대각선의 길이
// 밑변의 길이 = 2(n-1) +1 == 2n-1;

int main(void) {
	int n;
	scanf("%d", &n);
	int underline = (2 * n) - 1;
	recur(n, 0, underline/2);
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < underline; col++) {
			if (check[row][col] == false) {
				printf(" ");
			}
			else { printf("*"); }
		}
		printf("\n");
	}

	return 0;
	


}