#pragma warning(disable:4996)

#include <stdio.h>

/*
등식 : s*m + t*n = gcd(m, n)
r = r1-q*r2   --> r1 = q*r2 + r    //초기 r1, r2는 (m, n)이고 q는 몫 r은 나머지 
s = s1-q*s2                            //초기 s1, s2는 1, 0이다.
t = t1-q*t2                                 //초기 t1, t2는 0, 1이다.


r = m - n * q
m = n*q + r

s = 1(s1) - q * 0(s2) // s1 == t2 / s2 == t1
t = 0(t1) - q * 1(t2) // (m,n) (n,m) 이므로

s1 = s2
s2 = s
t1 = t2
t2 = t

*/

int main(void) {

	int n;
	
	int M, N, targetX, targetY;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &M, &N, &targetX, &targetY);

		/*
		int counter = 0;
		x = 0; y = 0;
		int maximize = M*N;
		while (counter <= maximize) {

			x++; y++;
			counter++;
			if (x == targetX && y == targetY) {
				break;
			}

			if (x + 1 > M) {
				x = 0;
			}
			if (y + 1 > N) {
				y = 0;
			}

		}
		if (x != targetX || y != targetY) {
			counter = -1;
		}
		*/

		int counter = 0;
		int x = 0, y = 0;
		int leftResult=0, rightResult=0;
		int max = M*N;
		while (leftResult <= max && rightResult <= max) {
			leftResult = M*x + targetX;
			rightResult = N*y + targetY;

			if (leftResult > rightResult) {
				y++;
			}
			else if (leftResult < rightResult) {
				x++;
			}
			else {
				printf("%d\n", leftResult);
				break;
			}

		}
		if (leftResult > max || rightResult > max) {
			printf("-1\n");
		}

		
	}
	

	return 0;
}