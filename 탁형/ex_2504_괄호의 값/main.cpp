#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main(void) {

	stack<char> st;
	char arr[32]; // ������ 31�������ϴµ� i+1�� ���� ������ ����
	scanf("%s", arr);
	int lenArr = strlen(arr);

	int mult = 1;
	int total = 0;
	for (int i = 0; i < lenArr; i++) {

		if (arr[i] == '(') {
			st.push(arr[i]);
			mult *= 2;
			if (arr[i + 1] == ')') {
				total += mult;
			}

		}else if (arr[i] == '[') {
			st.push(arr[i]);
			mult *= 3; // ������ total�� ���ҰŸ� 1*3�ؼ� 3����������. �׸��� �Ŀ� �ݴ°� ������ ����������
			if (arr[i + 1] == ']') {
				total += mult;
			}
		}else if (arr[i] == ')' && !st.empty()) { // pop only can be stack does not empty.
			
			if (st.top() != '(') {
				printf("0");
				return 0;
			}
			mult /= 2;
			st.pop();
		}
		else if (arr[i] == ']' && !st.empty()) {
			if (st.top() != '[') {
				printf("0");
				return 0;
			}
			mult /= 3;
			st.pop();
		}

	}

	printf("%d\n", st.empty() ? total : 0);


	return 0;
}