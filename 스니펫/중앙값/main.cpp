#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	vector<int> tempLog;
	vector<int> tempIdx;

	vector<int>::iterator it;
	//vector<int>::iterator it;


	int n, k;
	cin >> n >> k;

	int temp, prevTemp;
	for (int i = 0; i < n; i++) {
		cin >> temp;

		if (tempLog.size() == 0) {
			tempLog.push_back(temp);
			tempIdx.push_back(i);
		}
		else {
			if (tempLog.size() == k) {

			}
			int left = 0, right = tempLog.size() - 1, mid;
			int midVal;
			while (left <= right) {
				mid = (left + right) / 2;
				midVal = tempLog[mid];
				if (midVal == temp) {
					break;
				}

				if (midVal > temp) {
					right = mid - 1;
				}
				else { // midVal < temp
					left = mid + 1;

				}
			}
			if (midVal < temp) {
				mid += 1;
			}
			it = tempLog.begin();
			tempLog.insert(it + mid, temp);
			it = tempIdx.begin();
			tempIdx.insert(it + mid, i);

		}
		prevTemp = temp;




		cout << endl << endl;
		for (int j = 0; j < tempLog.size(); j++) {
			cout << "(" << tempLog.at(j) << ", " << tempIdx.at(j) << ")";
		}
		cout << endl << endl;


		cout << "Áß¾Ó°ª: " << tempLog[i / 2] << endl;

	}




	return 0;
}