#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

bool numberIndex[123456 * 2 + 1];
// �״� �����ڵ��� ������ �ȵ�°� ��ȿ�����̱⵵�ϰ�? 

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
		for (int i = 3; i <= sqrt(y); i += 2) { // i�� ����� ��������
												// 2�ǹ������ ���͵�����.
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
		// while (scanf("%d", &n) && n) { // scanf�԰����ÿ� equal�������� 0&&0 ���� üũ

		

		printf("%d \n", counter);

	}

	

	return 0;
}