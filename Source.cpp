#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
void main() {
	float fa = 1.1, fb = 2.2, fc = 3.3;
	float* pfarr[3] = { &fa, &fb, &fc };
	printf("%.1f, %.2f, %f\n", *(pfarr[0]), *(*(pfarr + 1)), *(*(pfarr + 2)));
}