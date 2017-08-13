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
				swapElem(&arrayList[posSorted], &arrayList[posCurrent]); // 배열의 요소는 포인터로 넘어가지않으므로 주소값지정
			}
		}
		// posCurrent가 끝까지 돌았으면 pv위치와 정렬된마지막원소와 자리를 바꿈
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
	printf("\n\n정렬후: \n");

	qSort(0, sizeArray-1, arr);
	
	for (int i = 0; i < sizeArray; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");


	return 0;

}
