int  main1_1_2e(), main1_1_2f(), main1_3_a(), main1_3b(), main2(), main1_1_2b(), main1_1_2c(), main1_1_2d();
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
using namespace std;
int main(){
    char a[20];
	int b=1;
	while (b) {
		printf("\n題目編號:\n1.2.b\n1.2.c\n1.2.d\n1.2.e\n1.2.f\n1.3.a\n1.3.b \n2\n結束程式請打:end\nEnter the question number to select result:");
		scanf("%s", a);
		if (strcmp(a, "1.2.b") == 0) {
			main1_1_2b();
		}
		if (strcmp(a, "1.2.c") == 0) {
			main1_1_2c();
		}
		if (strcmp(a, "1.2.d") == 0) {
			main1_1_2d();
		}
		if (strcmp(a, "1.2.e") == 0) {
			main1_1_2e();
		}
		if (strcmp(a, "1.2.f") == 0) {
			main1_1_2f();
		}
		if (strcmp(a, "1.3.a") == 0) {
			main1_3_a();
		}
		if (strcmp(a, "1.3.b") == 0) {
			main1_3b();
		}
		if (strcmp(a, "2") == 0) {
			main2();
		}
		if (strcmp(a, "end") == 0) {
			b = 0;
			break;
		}
	}
}