int HW2_1_1(), HW2_1_2(), HW2_1_3_nearestneighbor(), HW2_1_3_bilinear(), HW2_1_3_bicubic(), HW2_2(), HW_3();
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
	char a[20];
	int b = 1;
	while (b) {
		printf("\n�D�ؽs��:\nHW2_1_1\nHW2_1_2\nHW2_1_3_nearestneighbor\nHW2_1_3_bilinear\nHW2_1_3_bicubic\nHW2_2\nHW2_3\n�����{���Х�:end\nEnter the question number to select result:");
		scanf("%s", a);
		if (strcmp(a, "HW2_1_1") == 0) {
			HW2_1_1();
		}
		if (strcmp(a, "HW2_1_2") == 0) {
			HW2_1_2();
		}
		if (strcmp(a, "HW2_1_3_nearestneighbor") == 0) {
			HW2_1_3_nearestneighbor();
		}
		if (strcmp(a, "HW2_1_3_bilinear") == 0) {
			HW2_1_3_bilinear();
		}
		if (strcmp(a, "HW2_1_3_bicubic") == 0) {
			HW2_1_3_bicubic();
		}
		if (strcmp(a, "HW2_2") == 0) {
			HW2_2();
		}
		if (strcmp(a, "HW2_3") == 0) {
			HW_3();
		}
		if (strcmp(a, "end") == 0) {
			b = 0;
			break;
		}
	}
}
