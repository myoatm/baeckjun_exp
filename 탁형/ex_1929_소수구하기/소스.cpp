#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

bool numberIndex[1000001];
// �״� �����ڵ��� ������ �ȵ�°� ��ȿ�����̱⵵�ϰ�? 

int main(void) {

	memset(numberIndex, true, sizeof(numberIndex) / sizeof(bool));
	int x,y;

	scanf("%d %d", &x, &y);

	for (int i = 4; i <= y; i+=2) {
		numberIndex[i] = false;
	}
	for (int i = 3; i <= sqrt(y); i+=2) { // i�� ����� ��������
		// 2�ǹ������ ���͵�����.
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