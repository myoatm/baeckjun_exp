#pragma warning(disable:4996)
#include <stdio.h>


char arr[9];

int main(void) {
	char prev='\0';
	short int flag; // 0 = asc, 1 = desc, -1 = mixed
	int diff;
	for (int i = 0; i < 8; i++) {

		scanf("%d", &arr[i]);

		if (i == 0) {
			switch(arr[i]){
			case 1:
				flag = 0;
				break;
			case 8:
				flag = 1;
				break;
			default:
				flag = -1;
				break;
			}
			prev = arr[i];
			continue;
		}

		diff = arr[i] - prev;
		diff = diff < 0 ? -diff : diff;
		if (diff != 1 || flag == -1) {
			flag = -1;
			break;
		}
		prev = arr[i];
	}

	switch (flag) {
	case 0:
		printf("ascending\n");
		break;
	case 1:
		printf("descending\n");
		break;
	case -1:
		printf("mixed\n");
		break;

	}
	

	return 0;
}