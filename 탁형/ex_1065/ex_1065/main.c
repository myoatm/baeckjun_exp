#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>


int isArithmaticSequence(int n) {
	int backup = n;
	int preSeq=255, currSeq = 0; // 255�� �� �ڸ����� ������ ���� �� ���� ������ ���ÿ� char�� �ִ�ũ��. ���� ����ȭ�ʿ�� �뵵
	int lastNum = n % 10;
	
	if (n < 100) {
		return 1;
	}
	
	while (n > 0) { 
		if (n == backup) { // run once
			n /= 10;
			continue;
		}
		currSeq = lastNum - (n % 10);
		lastNum = n % 10;
		n /= 10;
		if (preSeq == 255) { // run once
			preSeq = currSeq;
			//n /= 10;
			continue;
		}

		if (preSeq != currSeq) {
			return 0;
		}
		

	}

	return 1;
}

int main(void) {

	int n;
	int sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (isArithmaticSequence(i) == 1) {
			//printf("%d\n", i);
			sum++;
		}
	}
	printf("%d\n", sum);

	return 0;
}