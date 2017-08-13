#pragma warning(disable:4996)
#include <iostream>
#include <queue>

using namespace std;

unsigned short int jos[5001];

int main(void) {

	queue<int> q;

	int n, term;
	scanf("%d %d", &n, &term);
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	
	printf("<");
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < term-1; j++) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		printf("%d", q.front());
		q.pop();
		if (!q.empty()) {
			printf(", ");
		}
		else {
			break;
		}

	}
	printf(">\n");
	


	return 0;
}
