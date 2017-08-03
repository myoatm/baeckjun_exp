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

	if (start < end) { // 정렬 범위가 올바를때만
		for (; posCurrent <= end; posCurrent++) { // posCurrent는 end까지 돌아야한다.
			if (sortArray[posCurrent] < sortArray[pv]) { // posCurrent원소가 pv 원소보다 작다면..
				posSorted++;
				swapElem(&sortArray[posCurrent], &sortArray[posSorted]); // 피벗은 고정돼야함. // 피벗 바로 옆(오른쪽)에 순차적으로 쌓아야함.
				// 따라서 pv과 교체하는것이아니라 posSorted를 1증가시키고 그 위치로 땡긴다.
				// 왜냐면 posSorted의 현재는 정렬된 원소까지의 위치기때문에 정렬되지않은 다음원소와 posCurrent의 원소를 교체한다.
			}
		}
		// for 반복이 끝난다면 pv원소와 정렬된원소의 위치를 바꾼다.
		swapElem(&sortArray[posSorted], &sortArray[pv]);
		// 바꿧으면 기존 posSorted의 값을 pv에게 준다.
		// posSorted와 pv가 swap된게아니라 그들이 가르키는 idx의 원소들이 교환된것이기때문.
		pv = posSorted;

		// 모든 분기가 끝났다면 교환된 pv의 위치를 기준으로 좌우를 나누어 qSort를 재귀시킨다.
		qSort(start, pv - 1, sortArray);
		qSort(pv + 1, end, sortArray);
	}
	// if문에 안걸친다면 해야할 조치는 하나도 없음. 종결

}

int arr[1000];
//unsigned short int arr[10000000]; // 이렇게풀면안됌...
int main(void) {
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);	
	}

	qSort(0, n - 1, arr);

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");

	return 0;

}