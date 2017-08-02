#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {

	int n;
	scanf("%d", &n);
	int buildingW, buildingH, seqVisitor;

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &buildingH, &buildingW, &seqVisitor);
		
		int counter = 1;
		int roomFloor;
 		while (1) {
			if (seqVisitor <= buildingH) {
				roomFloor = seqVisitor;
				break;
			}
			seqVisitor -= buildingH;
			counter++;
		}
		printf("%d", roomFloor);
		if (counter < 10) {
			printf("0");
		}
		printf("%d\n", counter);

	}


	return 0;
}