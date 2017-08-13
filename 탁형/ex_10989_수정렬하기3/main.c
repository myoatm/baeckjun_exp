#pragma warning(disable:4996)
#include <stdio.h>

void swapElem(int *_x, int *_y) {
	int temp = *_x;
	*_x = *_y;
	*_y = temp;
}

void qSort(int start, int end, int *sortArray) {
	int pv = start;
	int posSorted = start;
	int posCurrent = start + 1;

	if (start < end) { // ���� ������ �ùٸ�����
		for (; posCurrent <= end; posCurrent++) { // posCurrent�� end���� ���ƾ��Ѵ�.
			if (sortArray[posCurrent] < sortArray[pv]) { // posCurrent���Ұ� pv ���Һ��� �۴ٸ�..
				posSorted++;
				swapElem(&sortArray[posCurrent], &sortArray[posSorted]); // �ǹ��� �����ž���. // �ǹ� �ٷ� ��(������)�� ���������� �׾ƾ���.
																		 // ���� pv�� ��ü�ϴ°��̾ƴ϶� posSorted�� 1������Ű�� �� ��ġ�� �����.
																		 // �ֳĸ� posSorted�� ����� ���ĵ� ���ұ����� ��ġ�⶧���� ���ĵ������� �������ҿ� posCurrent�� ���Ҹ� ��ü�Ѵ�.
			}
		}
		// for �ݺ��� �����ٸ� pv���ҿ� ���ĵȿ����� ��ġ�� �ٲ۴�.
		swapElem(&sortArray[posSorted], &sortArray[pv]);
		// �مf���� ���� posSorted�� ���� pv���� �ش�.
		// posSorted�� pv�� swap�ȰԾƴ϶� �׵��� ����Ű�� idx�� ���ҵ��� ��ȯ�Ȱ��̱⶧��.
		pv = posSorted;

		// ��� �бⰡ �����ٸ� ��ȯ�� pv�� ��ġ�� �������� �¿츦 ������ qSort�� ��ͽ�Ų��.
		qSort(start, pv - 1, sortArray);
		qSort(pv + 1, end, sortArray);
	}
	// if���� �Ȱ�ģ�ٸ� �ؾ��� ��ġ�� �ϳ��� ����. ����

}

int arr[10001]; // 0~10000���� ���� �Է����� ������ �ش� ���� ī��Ʈ�Ѵ�.
// �̴� ���� �ߺ��Ǳ⶧��.


//unsigned short int arr[10000000]; // �̷���Ǯ��ȉ�...
int main(void) {
	int n;

	scanf("%d", &n);
	int tmp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		arr[tmp]++;
	}

	/*
	qSort(0, n - 1, arr);
	*/
	// ��Ʈ�� �ʿ䰡 ����...
	
	for (int i = 1; i <= 10000; i++) { // �迭�� �� �������ϹǷ�...
		for (int j = 0; j < arr[i]; j++) {
				printf("%d\n", i);
				// �� arr�� ���� 0�̾ƴϸ� �ش����ŭ ������ָ�ȴ�.. �Ź�...
		}
	}

	return 0;

}