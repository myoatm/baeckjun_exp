#include <iostream>
#include <queue>

using namespace std;

// 1~1000까지 쓰자.
bool map[1001][1001];

int main(void) {

	
	queue<int> q;

	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);

	int x, y;
	for (int i = 0; i<M; i++) {
		scanf("%d %d", &x, &y);
		map[x][y] = true;

	}


	return 0;
}