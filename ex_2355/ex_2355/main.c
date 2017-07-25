#pragma warning(disable:4996)
#include <stdio.h>
#if defined INT_MAX
#else
	#define INT_MAX 2147483647
#endif

int main(void) {

	long long i, j;
	scanf("%lld %lld", &i, &j);
	if (i >j) {
		long long int temp = i;
		i = j;
		j = temp;
	}

	long long result = (i + j) * (((j - i) + 1) / 2);
	result += (i - j + 1) % 2 == 0 ? 0 : (i + j) / 2;

	if (result > INT_MAX) {
		result = INT_MAX;
	}
	printf("%d", result);

	return 0;
}