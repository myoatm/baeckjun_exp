#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

bool numberIndex[10001];
// 그닥 좋은코드라고 생각이 안드는게 비효율적이기도하고? 

int main(void) {

	
	int n;
	scanf("%d", &n);
	for (int loopCount = 0; loopCount < n; loopCount++) {
	
		int x, y;
		scanf("%d", &y);
		//while (scanf("%d", &y) && y) {
			// while (scanf("%d", &n) && n) { // scanf함과동시에 equal연산으로 0&&0 인지 체크
			//y = 2 * x++;

			memset(numberIndex, true, sizeof(numberIndex) / sizeof(bool));

			for (int i = 4; i <= y; i += 2) { numberIndex[i] = false; } // 짝수조짐
			for (int i = 3; i*i <= y; i += 2) {
													// i의 배수들 조질거임
													// 2의배수들은 볼것도없다.
													//printf("%d \n", i);
				for (int a = 2; i*a <= y; a++) {
					numberIndex[i*a] = false;
				}
			}
			numberIndex[0] = false; numberIndex[1] = false;

			int a, b, mid = y >> 1;
			for (a = b = mid; b <= y; a--, b++) { // 두수의 차가 가장 적으려면 y/2부터 시작해서 각각 +1, -1 씩하면됌.
				if (numberIndex[a] && numberIndex[b]) {
					printf("%d %d\n", a, b);
					break;
				}
			}


		//}

	}
	



	return 0;
}