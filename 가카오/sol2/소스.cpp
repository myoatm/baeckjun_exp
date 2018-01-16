#include <iostream>
#include <vector>
using namespace std;

int calMin(int a, int b, int c) {
	a = a < b ? a : b;
	return a < c ? a : c;
}
int solution(vector<vector<int>> board) {
	int maxNum = 0;

	int maxY = board.size();
	int maxX = board[0].size();

	for (int i = 0; i < maxX; i++) {
		for (int j = 0; j < maxY; j++) {
			if (board[i][j] == 1) { // 순차탐색이라 상관무
				int prevUp = i-1 >= 0 ? board[i - 1][j] : 0;
				int prevDiag = j-1 >= 0 ? board[i][j - 1] : 0;
				int prevLeft = i-1>= 0 && j-1 >= 0 ? board[i - 1][j - 1] : 0;
				board[i][j] = calMin(prevUp, prevDiag, prevLeft) + 1;

				if (maxNum < board[i][j]) {
					maxNum = board[i][j];
				}

			}
		}
	}

	return maxNum*maxNum;
}


int main(void) {

	printf("시작");
	vector<vector<int>> test;
	/*
	test.push_back({ 0, 1, 1, 1 });
	test.push_back({ 1, 1, 1, 1 });
	test.push_back({ 1, 1, 1, 1 });
	test.push_back({ 0,0,1,0 });
	*/
	test.push_back({ 1 });

	int ans = solution(test);

	cout << ans << endl;
	return 0;

}