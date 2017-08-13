#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

bool numberIndex[1000001];
// 그닥 좋은코드라고 생각이 안드는게 비효율적이기도하고? 

int main(void) {

	memset(numberIndex, true, sizeof(numberIndex) / sizeof(bool));
	int x,y;

	scanf("%d %d", &x, &y);

	for (int i = 4; i <= y; i+=2) {
		numberIndex[i] = false;
	}
	for (int i = 3; i <= sqrt(y); i+=2) { // i의 배수들 조질거임
		// 2의배수들은 볼것도없다.
		//printf("%d \n", i);
		for (int a = 2; i*a <= y; a++) {
			numberIndex[i*a] = false;
		}
	}

	numberIndex[0] = false; numberIndex[1] = false;

	for (int i = x; i <= y; i++) {
		if (numberIndex[i] == true) {
			printf("%d \n", i);
		}
	}


	return 0;
}