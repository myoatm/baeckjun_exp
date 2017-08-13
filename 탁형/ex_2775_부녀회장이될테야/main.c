#pragma warning(disable:4996)
#include <stdio.h>

int getRoomVolume(int _floor, int _number) {
	
	if (_floor == 0) {
		return _number;
	}
	if (_number == 1) {
		return 1;
	}
	return getRoomVolume(_floor - 1, _number) + getRoomVolume(_floor, _number - 1);
}

int main(void) {
	int n;
	int floor, roomNumber;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &floor, &roomNumber);
		printf("%d\n", getRoomVolume(floor, roomNumber));
	}

	return 0;
}