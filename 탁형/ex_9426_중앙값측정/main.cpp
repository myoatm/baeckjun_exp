#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	vector<int> tempLog;
	vector<int> tempIdx;

	vector<int>::iterator it;

	int n, k;
	long long int total = 0;
	cin >> n >> k;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;

		if (tempLog.size() == k) {
			int idx = min_element(tempIdx.begin(), tempIdx.end()) - tempIdx.begin();

			tempIdx.erase(tempIdx.begin() + idx);
			tempLog.erase(tempLog.begin() + idx);

			if (k == 0) {
				continue;
			}
		}
		if (tempLog.size() == 0) {
			tempLog.push_back(temp);
			tempIdx.push_back(i);
		}
		else {
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

		/*
		cout << endl << endl;
		for (int j = 0; j < tempLog.size(); j++) {
			cout << "(" << tempLog.at(j) << ", " << tempIdx.at(j) << ")";
		}
		*/

		if (tempLog.size() == k) {
			//cout << "Áß¾Ó°ª: " << tempLog[(k-1) / 2] << endl;
			total += tempLog[(k-1) / 2];
		}
		//cout << endl << endl;


	}

	printf("%lld\n", total);



	return 0;
}