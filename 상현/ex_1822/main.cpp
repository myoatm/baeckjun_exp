#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> setA, setB;
bool inclA[500000];

int main() {

	int numA, numB, counter = 0;
	scanf("%d %d", &numA, &numB);

	int tmp;
	for (int i = 0; i < numA; i++) {
		scanf("%d", &tmp);
		setA.push_back(tmp);
	}

	for (int i = 0; i < numB; i++) {
		scanf("%d", &tmp);
		setB.push_back(tmp);
	}

	sort(setA.begin(), setA.end());

	int posS=0, posE = numA-1;
	int posMid;

	for (int i = 0; i < numB; i++) {
		posS = 0, posE = numA - 1;
		while (posS <= posE) {

			posMid = (posS + posE) / 2;

			if (setA[posMid] == setB[i]) {
				counter++;
				inclA[posMid] = true;
				break;
			}

			if (setA[posMid] > setB[i]) {
				posE = posMid-1;
			}
			else if (setA[posMid] <setB[i] ) {
				posS = posMid +1;
			}
		}

	}

	if (numA - counter == 0) {
		printf("0");
	}
	else {

		printf("%d\n", numA - counter);
		for (int i = 0; i < numA; i++) {
			if (inclA[i] == false) {
				printf("%d ", setA[i]);
			}
		}
	}

	return 0;
}