#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main(void) {

	stack<char> st;
	char arr[32]; // 원래는 31개여야하는데 i+1에 대한 접근을 위해
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
			mult *= 3; // 어차피 total에 더할거면 1*3해서 3을만들어야함. 그리고 후에 닫는걸 만나면 나누기해줌
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