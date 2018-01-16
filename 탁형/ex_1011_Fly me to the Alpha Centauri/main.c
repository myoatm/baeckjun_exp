#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>

int main(void) {

	int n, posS, posE;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &posS, &posE);
		int subDist = posE - posS;
		int maxSpeed = sqrt(subDist);
		// �ִ� �ӵ��� �������� ����������. �밡���غ��� �׷�

		// �ּ� �̵�Ƚ���� ����ؾ��ϴµ�, ��Ʈ n�� 3�̸� 1,2,3,2,1 �� �ȴ�. 4�̸� 1,2,3,4,3,2,1. ��, (2/-n)-1 �� �ּ� �̵�Ƚ��.// 
		// �ִ� �̵������� �Ÿ��� (/-n)^2. ��, n-(/-n)^2 �ϸ� ���� �̵��Ÿ��� ������, �̸� divider==maxSpeed (/-n)�� �̿��Ѵ�.

		int moveCount = 2 * maxSpeed - 1;
		int maximizeDistance = pow(maxSpeed, 2.0);

		moveCount += ceil((subDist - maximizeDistance) / (double)maxSpeed);

		printf("%d\n", moveCount);
	}
	return 0;
	/*
	23

1 : 22
2 : 20
3 : 17
4 : 13
3 : 10
2 : 8
1 : 7
�� ���¿��� 4 �ѹ�, 3 �ѹ� ���� ��!
	*/
	
}