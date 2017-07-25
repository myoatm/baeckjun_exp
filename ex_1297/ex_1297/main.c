#pragma warning (disable:4996) 
#include <stdio.h>
#include <math.h>

int main(void) {


	// diagonal , height ratio, width ratio
	// to height length, width length
	
	int diagonal, hRatio, wRatio;
	
	scanf("%d %d %d", &diagonal, &hRatio, &wRatio);
	
	
	//
	double basedH = sqrt(pow(diagonal,2) / (pow((double)hRatio / wRatio, 2) + 1) );
	int h, w;
	w = floor(basedH);
	h = basedH* ((double)hRatio / wRatio);

	printf("%d %d", h, w);

	return 0;
}