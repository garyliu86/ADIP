#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include<time.h>
using namespace cv;
int main1_1_2f()
{
	int width = 256;
	int height = 256;
	int size = width * height;
	char OriFile_01[] = "p01.raw";  //Input Image name
	char OriFile_02[] = "p02.raw";
	char OriFile_03[] = "p03.raw";
	char OriFile_04[] = "p04.raw";
	char OutFile[] = "1_1.2_f.raw"; //Output Raw Image name
	FILE* lenaFile_01, * lenaFile_02, * lenaFile_03, * lenaFile_04, *resultFile_f;
	lenaFile_01 = fopen(OriFile_01, "rb");
	lenaFile_02 = fopen(OriFile_02, "rb");
	lenaFile_03 = fopen(OriFile_03, "rb");
	lenaFile_04 = fopen(OriFile_04, "rb");
	resultFile_f = fopen(OutFile, "wb");
	if (lenaFile_01 == NULL& lenaFile_02 == NULL & lenaFile_03 == NULL & lenaFile_04 == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}

	unsigned char* P01 = new unsigned char[size];
	unsigned char* P02 = new unsigned char[size];
	unsigned char* P03 = new unsigned char[size];
	unsigned char* P04 = new unsigned char[size];
	fread(P01, 1, size, lenaFile_01);
	fread(P02, 1, size, lenaFile_02);
	fread(P03, 1, size, lenaFile_03);
	fread(P04, 1, size, lenaFile_04);

	int i, j;
	Mat tt(512,512, CV_8UC1);

	Mat lenaMat_01(height, width, CV_8UC1, P01);
	for (j = 0; j <= 255; j++)
	{
		for (i = 0; i <= 255; i++)
		{
			*tt.ptr<uchar>(j+256, i+256) = *lenaMat_01.ptr<uchar>(j, i);
		}
	}

	Mat lenaMat_02(height, width, CV_8UC1, P02);
	for (j = 0; j <= 255; j++)
	{
		for (i = 0; i <= 255; i++)
		{
			*tt.ptr<uchar>(j+256 , i ) = *lenaMat_02.ptr<uchar>(j, i);
		}
	}

	Mat lenaMat_03(height, width, CV_8UC1, P03);
	for (j = 0; j <= 255; j++)
	{
		for (i = 0; i <= 255; i++)
		{
			*tt.ptr<uchar>(j , i) = *lenaMat_03.ptr<uchar>(j, i);
		}
	}
	
	Mat lenaMat_04(height, width, CV_8UC1, P04);
	for (j = 0; j <= 255; j++)
	{
		for (i = 0; i <= 255; i++)
		{
			*tt.ptr<uchar>(j, i+256) = *lenaMat_04.ptr<uchar>(j, i);
		}
	}
	imshow("1_1.2.f", tt);
	waitKey(0);
	fwrite(tt.ptr(0,0), 1, 512*512, resultFile_f);
	fclose(resultFile_f);
	return 0;
}