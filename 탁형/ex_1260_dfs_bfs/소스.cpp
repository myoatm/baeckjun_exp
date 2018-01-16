#pragma warning(disable:4996)
#include <iostream>
#include <queue>

using namespace std;

bool map[1001][1001];
bool isVisit[1001];
int n, m, first;

inline void resetIsVisit() {
	for (int i = 0; i <= 1000; i++) {
		isVisit[i] = false;
	}
}

void DFS(int item) {
	isVisit[item] = true;
	printf("%d ", item);

	for (int i = 1; i <= n; i++) {
		if (map[item][i] && !isVisit[i]) {
			DFS(i);
		}
	}
	
}

void BFS(int first) {
	queue<int> q;

	q.push(first);
	int visit;
	while (!q.empty()) {
		visit = q.front(); q.pop();
		if (!isVisit[visit]) {
			printf("%d ", visit);
			isVisit[visit] = true;
		}
		for (int i = 1; i <= n; i++) {
			if (map[visit][i] && !isVisit[i]) {
				q.push(i);
			}
		}
	}
}

int main(void) {



	scanf("%d %d %d", &n, &m, &first);

	int x, y;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		map[x][y] = map[y][x] = true;
	}
	DFS(first);
	printf("\n");
	resetIsVisit();
	BFS(first);
	printf("\n");




	return 0;
}