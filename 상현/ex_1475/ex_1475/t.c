#pragma warning (disable:4996) 
#include <stdio.h>

#define MAX_SINGLE_NUMBERIC_RANGE 10
int availNumber[MAX_SINGLE_NUMBERIC_RANGE];
int n;
int answer = 0;

void addAvailNumber() {
	for (int i = 0; i < MAX_SINGLE_NUMBERIC_RANGE; i++) {
		availNumber[i]++;
	}
}

int main(void) {

	//scanf_s("%d", &n, sizeof(int));
	scanf("%d", &n);

	while (n / MAX_SINGLE_NUMBERIC_RANGE >= 0) {
		
		int currentNumber = n % MAX_SINGLE_NUMBERIC_RANGE;


		if (currentNumber == 6 || currentNumber == 9) {
			if (availNumber[6] <= 0 && availNumber[9] <= 0) {
				addAvailNumber();
				answer++;
			}

			if (currentNumber == 6 && availNumber[6] >0) {
				availNumber[6]--;
			}
			else if(currentNumber ==6 && availNumber[6] <=0) {
				availNumber[9]--;
			}else if (currentNumber == 9 && availNumber[9] > 0) {
				availNumber[9]--;
			}else if (currentNumber == 9 && availNumber[9] <= 0) {
				availNumber[6]--;
			}

		}
		else {
			if (availNumber[currentNumber] <= 0) {
				addAvailNumber();
				answer++;
			}
			availNumber[currentNumber]--;

		}

		n /= MAX_SINGLE_NUMBERIC_RANGE;


		if (n == 0) {
			break;
		}
	}
	
	printf("%d", answer);
	
	return 0;
}
