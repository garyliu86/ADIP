#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
using namespace cv;

int main1_1_2b()
{
	int width = 256;
	int height = 256;
	int size = width * height;
	char OriFile[] = "lena_256.raw";    //Input Image name
	char OutFile_c[] = "lena256out_c.raw"; //Output Raw Image name
	char OutFile_d[] = "lena256out_d.raw";
	FILE* lenaFile, * resultFile_1_1_2_c, * resultFile_1_1_2_d;
	lenaFile = fopen(OriFile, "rb");
	resultFile_1_1_2_c = fopen(OutFile_c, "wb");
	resultFile_1_1_2_d = fopen(OutFile_d, "wb");
	if (lenaFile == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	unsigned char* lenai = new unsigned char[size];
	fread(lenai, 1, size, lenaFile);
	Mat lenaMat(height, width, CV_8UC1, lenai);
	int i, j, a, b, c;
	//1.2.b
	uchar* data2 = lenaMat.ptr<uchar>(123);
	printf("1.2.b(1):The (123,234)intensity value is %d\n", data2[234]);
	uchar* data = lenaMat.ptr<uchar>(0);
	printf("1.2.b(2):The (5487)intensity value is %d\n", data[5487]);
	b = 5487 / 256;
	c = 5487 - b * 256;
	printf("The 5487 pixel coordinate is row=%d,column=%d", b, c);
	fclose(lenaFile);
	delete lenai;
	destroyWindow("lenaFile");
}