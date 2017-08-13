#pragma warning(disable:4996)
#include <iostream>
#include <queue>

using namespace std;

unsigned short int jos[5001];


template <typename T>
void clearQ(queue<T> &_q) {
	queue<T> emptyQ;
	swap(_q, emptyQ);
}

typedef struct Key {
	int idx;
	int priority;
}Key;

int main(void) {

	queue<Key> q;
	priority_queue<int> pq;

	int n;
	scanf("%d", &n);

	int docCount, docPos;
	int tmp;
	for (int i = 0; i < n; i++) {

		scanf("%d %d", &docCount, &docPos);
		for (int j = 0; j < docCount; j++) {
			scanf("%d", &tmp);
			q.push({ j, tmp });
			pq.push(tmp); // 우선순위를 먼저 정렬시킴 그래서 그거 뽑은대로 해당 놈만 찾아서 뽑아먹으면됌.

		}
		int counter = 0;
		while (!pq.empty()) {
			int idx = q.front().idx;
			int prio = q.front().priority;
			q.pop(); // 얘는 무조건 일단 pop해주고 아니면 다시 push해서 뒤로 보냄
			if (pq.top() == prio) {
				pq.pop();
				counter++;
				if (idx == docPos) {
					printf("%d\n", counter);
					// break하려면 q를 비워야함.
					queue<Key> emptyQ;
					swap(q, emptyQ);
					priority_queue<int> emptyPQ;
					swap(pq, emptyPQ);
					break;

				}
			}
			else {
				q.push({ idx, prio });
			}

		}

	}




	return 0;
}
