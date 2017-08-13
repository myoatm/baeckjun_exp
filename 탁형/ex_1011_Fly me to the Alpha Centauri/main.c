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
		// 최대 속도는 제곱근의 내림과같다. 노가다해보니 그럼

		// 최소 이동횟수를 계산해야하는데, 루트 n이 3이면 1,2,3,2,1 이 된다. 4이면 1,2,3,4,3,2,1. 즉, (2/-n)-1 이 최소 이동횟수.// 
		// 최대 이동가능한 거리는 (/-n)^2. 즉, n-(/-n)^2 하면 남은 이동거리가 나오고, 이를 divider==maxSpeed (/-n)을 이용한다.

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
이 상태에서 4 한번, 3 한번 가면 끝!
	*/
	
}