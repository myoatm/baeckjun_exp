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
			pq.push(tmp); // �켱������ ���� ���Ľ�Ŵ �׷��� �װ� ������� �ش� �� ã�Ƽ� �̾Ƹ������.

		}
		int counter = 0;
		while (!pq.empty()) {
			int idx = q.front().idx;
			int prio = q.front().priority;
			q.pop(); // ��� ������ �ϴ� pop���ְ� �ƴϸ� �ٽ� push�ؼ� �ڷ� ����
			if (pq.top() == prio) {
				pq.pop();
				counter++;
				if (idx == docPos) {
					printf("%d\n", counter);
					// break�Ϸ��� q�� �������.
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
