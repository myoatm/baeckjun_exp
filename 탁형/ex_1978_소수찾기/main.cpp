#include <iostream>
#include <math.h>

using namespace std;

int main(void) {

	int n;
	int counter = 0;
	scanf("%d", &n);

	int tmp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);

		if (tmp < 2) {
			continue;
		}

		bool isPrime = true;
		int range = sqrt(tmp);
		for (int a = 2; a <= range; a++) {
			if (tmp%a == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			//printf("%d 소수입니다.\n", tmp);
			counter++;

		}

	}

	cout << counter << endl;

	return 0;
}