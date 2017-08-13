#include <iostream>
#include <math.h>

using namespace std;

int main(void) {

	int start, end;
	int total = 0;
	int minPrime = -1;
	scanf("%d %d", &start, &end);

	for (int i = start; i <= end; i++) {

		if (i < 2) {
			continue;
		}

		bool isPrime = true;
		int range = sqrt(i);
		for (int a = 2; a <= range; a++) {
			if (i%a == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			//printf("%d 소수입니다.\n", i);
			if (minPrime == -1) {
				minPrime = i;
			}
			total+=i;

		}

	}

	if (minPrime == -1) {
		cout << -1 << endl;
	}
	else {
		cout << total << endl << minPrime << endl;

	}
	

	return 0;
}