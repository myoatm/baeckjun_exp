#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	
	
	stack<int> st;
	string str;

	int n;
	scanf("%d", &n);

	int tmp;
	int max = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);

		if (tmp > max) {
			for (int j = max+1; j <= tmp; j++) {
				st.push(j);
				//printf("+\n");
				str += "+\n";
			}
			
		}
		else if (tmp < st.top()) {
			printf("NO\n");
			return 0; // break을하면 str이 나오므로..
		}

		// 선처리하고 pop
		st.pop();

		/*
		if (i == n - 1) {
			str += "-";
		}
		else {
			str += "-\n";

		}*/
		str += "-\n";

		if (tmp > max) {
			max = tmp;
		}

	}
	cout << str;


	return 0;
}