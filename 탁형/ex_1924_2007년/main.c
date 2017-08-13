#pragma warning(disable:4996)
#include <stdio.h>

int dayEachMonth[] = {31, 28, 31, 30, 31, 30, 31,31, 30, 31, 30, 31};
char *strWeekDay[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main(void) {
	int mon, day;

	scanf("%d %d", &mon, &day);
	int currday = 0;

	for (int i = 1; i < mon; i++) {
		currday += dayEachMonth[i-1];
	}
	currday += day;
	printf("%s\n", strWeekDay[currday % 7]);

	return 0;
}