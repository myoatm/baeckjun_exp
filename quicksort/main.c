#include <stdio.h>

void swapElem(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void qSort(int start, int end, int *arrayList) {
	
	int pv = start;
	int posSorted = pv;
	int posCurrent = start +1;

	if (start < end) {

		for (; posCurrent <= end; posCurrent++) {
			if (arrayList[pv] > arrayList[posCurrent]) {
				posSorted++;
				swapElem(&arrayList[posSorted], &arrayList[posCurrent]); // �迭�� ��Ҵ� �����ͷ� �Ѿ�������Ƿ� �ּҰ�����
			}
		}
		// posCurrent�� ������ �������� pv��ġ�� ���ĵȸ��������ҿ� �ڸ��� �ٲ�
		swapElem(&arrayList[pv], &arrayList[posSorted]);
		pv = posSorted;
		qSort(start, pv - 1, arrayList);
		qSort(pv+1, end, arrayList);
	}
	               
}

int main(void) {

	int arr[10] = { 4,6 ,7,2,5,9, 1,10, 8,3 };

	int sizeArray = sizeof(arr) / sizeof(int);
	for (int i = 0; i < sizeArray; i++) {
		printf("%d ", arr[i]);
	} 
	printf("\n\n������: \n");

	qSort(0, sizeArray-1, arr);
	
	for (int i = 0; i < sizeArray; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");


	return 0;

}
