#pragma warning(disable:4996)
#include <stdio.h>
#include <limits.h>
#include <math.h>
typedef struct idxVector {
	int idx;
	int count;
} idxVector;

void qSelect(int start, int end, short int findNum) {

}

void swapRef(short int *x, short int *y) {
	short int temp = *x;
	*x = *y;
	*y = temp;
}
void swapRefIdxVector(idxVector *x, idxVector *y) {
	idxVector temp = *x;
	*x = *y;
	*y = temp;
}

void bbSortCounter(idxVector *listArray) {
	for (int i = 0; i < 8000; i++) {
		for (int j = 0; j < 8000; j++) {
			if (listArray[i].count > listArray[j].count) {
				swapRefIdxVector(&listArray[i], &listArray[j]);
				
			}
		}
	}
}

void qSortCounterDesc(int start, int end, idxVector *listArray) {

	int pv = start;
	int posSorted = start;
	int posCurrent = start + 1;

	if (start < end) {
		for (; posCurrent <= end; posCurrent++) {
			if (listArray[posCurrent].count > listArray[pv].count) {
				posSorted++;
				swapRefIdxVector(&listArray[posCurrent], &listArray[posSorted]);
			}
		}
		// based sort end.
		swapRefIdxVector(&listArray[posSorted], &listArray[pv]);
		pv = posSorted;

		qSortCounterDesc(start, pv - 1, listArray);
		qSortCounterDesc(pv + 1, end, listArray);
	}


}
void qSortCounterAsc(int start, int end, idxVector *listArray) {

	int pv = start;
	int posSorted = start;
	int posCurrent = start + 1;

	if (start < end) {
		for (; posCurrent <= end; posCurrent++) {
			if (listArray[posCurrent].idx < listArray[pv].idx) {
				posSorted++;
				swapRefIdxVector(&listArray[posCurrent], &listArray[posSorted]);
			}
		}
		// based sort end.
		swapRefIdxVector(&listArray[posSorted], &listArray[pv]);
		pv = posSorted;

		qSortCounterAsc(start, pv - 1, listArray);
		qSortCounterAsc(pv + 1, end, listArray);
	}


}
int qSortCounterPreWork(int start, int end, idxVector *listArray) {
	int currentFinder = start;
	for (int i = start; i <= end; i++) {
		if (listArray[i].count > 0) {
			swapRefIdxVector(&listArray[currentFinder], &listArray[i]);
			currentFinder++;
		}
	}
	return currentFinder;
}


void qSort(int start, int end, short int *listArray) {

	int pv = start;
	int posSorted = start;
	int posCurrent = start + 1;

	if (start < end) {
		for (; posCurrent <= end; posCurrent++) {
			if (listArray[posCurrent] < listArray[pv]) {
				posSorted++;
				swapRef(&listArray[posCurrent], &listArray[posSorted]);
			}
		}
		// based sort end.
		swapRef(&listArray[posSorted], &listArray[pv]);
		pv = posSorted;

		qSort(start, pv - 1, listArray);
		qSort(pv + 1, end, listArray);
	}
	

}


short int arr[500001]; //입력되는 정수의 절대값은 4,000
idxVector idxCounter[8001]; // +4000 //0~3999는 -4000~-1,  4000은 0. 4001~8000

int main(void) {

	int num;
	scanf("%d", &num);


	int tmp;
	int max = SHRT_MIN , min= SHRT_MAX;
	int total = 0;
	for (int i = 0; i < num; i++) {
		
		scanf("%d", &tmp);
		arr[i] = tmp;
		total += tmp;
		int counterIdx = tmp + 4000;
		idxCounter[counterIdx].idx = tmp;
		
		idxCounter[counterIdx].count++;
	}

	qSort(0, num - 1, arr);

	int rangedIndexCounter = qSortCounterPreWork(0, 8000, idxCounter) ;
	qSortCounterDesc(0, rangedIndexCounter-1, idxCounter);
	
	int range = arr[num-1] - arr[0];
	int avg = (int)round((double)total / num);

	int tmpMax = idxCounter[0].count;
	int lastI = 0;
	for (; lastI < rangedIndexCounter;) {
		if (tmpMax > idxCounter[lastI].count) {
			break;
		}
		lastI++;
	}
	
	int rateNumber;
	qSortCounterAsc(0, lastI - 1, idxCounter);
	if (lastI < 3) {
		rateNumber = idxCounter[0].idx;
	}
	else {
		rateNumber = idxCounter[1].idx;

	}
	///*
	printf("평균 : %d\n", avg);
	printf("중앙값 : %d\n", arr[num/2]);
	printf("최빈값 : %d\n", rateNumber);
	printf("범위 : %d\n", range);
	
	/*
	printf("%d\n", avg);
	printf("%d\n", arr[num/2]);
	printf("%d\n", rateNumber);
	printf("%d\n", range);
	*/

	return 0;
}