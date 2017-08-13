#include <iostream>
#include <cstring>

using namespace std;

int queue[100001];
int front = 0, back = 0;
int main(void) {

	int commCount;
	scanf("%d", &commCount);
	char arr[6];
	int tmp;

	for (int i = 0; i < commCount; i++) {
		scanf("%s", arr);
		if (!strcmp(arr, "push")) {
			scanf("%d", &tmp);
			if (front > 100000) {
				continue;
			}
			queue[back++] = tmp;

		}else if (!strcmp(arr, "pop")) {
			if (front == back) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", queue[front++]);
		}else if (!strcmp(arr, "size")) {
			printf("%d\n", back - front);
		}else if (!strcmp(arr, "empty")) {
			if (front == back) {
				printf("1\n");
			}else {
				printf("0\n");
			}
		}else if (!strcmp(arr, "front")) {
			if (front == back) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", queue[front]);
		}else if (!strcmp(arr, "back")) {
			if (front == back) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", queue[back-1]);
		}

	}

	return 0;
}