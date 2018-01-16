#pragma warning(disable:4996)

#include <iostream>
typedef long long ll;

using namespace std;

class DefinitionTest {
private:
public:
	template <typename T>
	T test(T a, T b);
	bool test(bool a, bool b) = delete;
	double test(double a, double b) = delete;
};

template <typename T>
T DefinitionTest::test(T a, T b) {

	return a + b;
}


int main(void) {

	auto dt = DefinitionTest();
	cout << dt.test(1, 2) << endl;
	cout << dt.test(1.0, 2.0) << endl;
	cout << dt.test(true, false) << endl;

	cout << endl << endl;
	int n;
	scanf("%d", &n);

	ll prev = 1;
	ll prevprev = 0;
	
	ll tmp = 1L;
	for (int i = 1; i < n; i++) {
		tmp = prev + prevprev;
		prevprev = prev;
		prev = tmp;
	}

	printf("%lld\n", tmp);


	return 0;
}

