#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

bool numberIndex[123456 * 2 + 1];
// 그닥 좋은코드라고 생각이 안드는게 비효율적이기도하고? 

int main(void) {

	int x, y;
	while (true) {
		scanf("%d", &x);
		if (x == 0) {
			break;
		}
		y = 2 * x++;


		memset(numberIndex, true, sizeof(numberIndex) / sizeof(bool));

		for (int i = 4; i <= y; i += 2) {
			numberIndex[i] = false;
		}
		for (int i = 3; i <= sqrt(y); i += 2) { // i의 배수들 조질거임
												// 2의배수들은 볼것도없다.
												//printf("%d \n", i);
			for (int a = 2; i*a <= y; a++) {
				numberIndex[i*a] = false;
			}
		}

		numberIndex[0] = false; numberIndex[1] = false;

		int counter = 0;
		for (int i = x; i <= y; i++) {
			if (numberIndex[i] == true) {
				counter++;
			}
		}
		// while (scanf("%d", &n) && n) { // scanf함과동시에 equal연산으로 0&&0 인지 체크

		

		printf("%d \n", counter);

	}

	

	return 0;
}