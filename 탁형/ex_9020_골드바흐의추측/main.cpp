#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

bool numberIndex[10001];
// �״� �����ڵ��� ������ �ȵ�°� ��ȿ�����̱⵵�ϰ�? 

int main(void) {

	
	int n;
	scanf("%d", &n);
	for (int loopCount = 0; loopCount < n; loopCount++) {
	
		int x, y;
		scanf("%d", &y);
		//while (scanf("%d", &y) && y) {
			// while (scanf("%d", &n) && n) { // scanf�԰����ÿ� equal�������� 0&&0 ���� üũ
			//y = 2 * x++;

			memset(numberIndex, true, sizeof(numberIndex) / sizeof(bool));

			for (int i = 4; i <= y; i += 2) { numberIndex[i] = false; } // ¦������
			for (int i = 3; i*i <= y; i += 2) {
													// i�� ����� ��������
													// 2�ǹ������ ���͵�����.
													//printf("%d \n", i);
				for (int a = 2; i*a <= y; a++) {
					numberIndex[i*a] = false;
				}
			}
			numberIndex[0] = false; numberIndex[1] = false;

			int a, b, mid = y >> 1;
			for (a = b = mid; b <= y; a--, b++) { // �μ��� ���� ���� �������� y/2���� �����ؼ� ���� +1, -1 ���ϸ��.
				if (numberIndex[a] && numberIndex[b]) {
					printf("%d %d\n", a, b);
					break;
				}
			}


		//}

	}
	



	return 0;
}