#pragma warning(disable:4996)
#include <iostream>
#include <deque>

using namespace std;


/* deque 
1. pop
a1, a2, a3, a4, ... -> a2, a3, a4, ...

2. pushLeft
a1, a2, a3, a4, ... -> a2, a3, a4, a1, ...

3. pushRight
a1, a2, a3, a4, ... -> a4, a1, a2, a3, ...


*/

// n개의 원소가 들어있는 dq에서 m개를 뽑을거임
// 2번째 줄에 m개의 원소들을 쭉 적으면
// 그걸 1번연산으로 뽑기위해서 2,3번 연산이 몇번 수행되어야하는지

int findFromFront(deque<int> *dq, int val) {
	int length = dq->size();

	for (int i = 0; i < length; i++) {
		if (val == dq->at(i)) {
			return i;
		}
	}
	return -1;
}
int findFromEnd(deque<int> *dq, int val) {
	int length = dq->size();
	int counter=1; //오른쪽에서 바로 찾았어도 결국 한번 밀어야 pop할 수 있는 위치로 옮
	for (int i = length-1; i >=0; i--) {
		if (val == dq->at(i)) {
			return counter;
		}
		counter++;
		
	}
	return -1;
}

void pushToRight(deque<int> *dq, int count) { // right end to left first
	
	for (int i = 0; i < count; i++) {
		int tmp = dq->back();
		dq->pop_back();
		dq->push_front(tmp);
	}

}

void pushToLeft(deque<int> *dq, int count) { // left first to right end

	for (int i = 0; i < count; i++) {
		int tmp = dq->front();
		dq->pop_front();
		dq->push_back(tmp);
		
	}

}


int main(void) {

	int n, m;
	scanf("%d %d", &n, &m);
	deque<int> dq;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	int tmp;
	int total=0;
	for (int i = 0; i < m; i++) {
		scanf("%d", &tmp);
		int findFront = findFromFront(&dq, tmp);
		int findEnd = findFromEnd(&dq, tmp);
		if (findFront <= findEnd) {
			pushToLeft(&dq, findFront);
			total += findFront;

		} else {
			pushToRight(&dq, findEnd);
			total += findEnd;
		}
		dq.pop_front();
	}

	printf("%d\n", total);



	return 0;
}