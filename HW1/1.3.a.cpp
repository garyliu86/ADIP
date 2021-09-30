#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include<time.h>
using namespace cv;
int main1_3_a()
{
	int width = 256;
	int height = 256;
	int size = width * height;
	char OriFile[] = "lena_256.raw";    //Input Image name
	char OutFile_c[] = "lena256out_1.3a.raw"; //Output Raw Image name
	FILE* lenaFile, * resultFile_1_1_2_c, * resultFile_1_1_2_d, * lenaMatab;
	lenaFile = fopen(OriFile, "rb");
	resultFile_1_1_2_c = fopen(OutFile_c, "wb");
	if (lenaFile == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}

	unsigned char* lenai = new unsigned char[size];
	fread(lenai, 1, size, lenaFile);
	//1.3.a
	int i, j;
	Mat lenaMata(height, width, CV_8UC1, lenai);
		for (j = 0; j <= 255; j++)
	{
			for (i = 0; i <= 255; i++)
		{
				if (*lenaMata.ptr<uchar>(j, i) > 205)
				{
					*lenaMata.ptr<uchar>(j, i) = 255;
				}
				else{
					*lenaMata.ptr<uchar>(j, i) += 50;
				}

		}
	}
	imshow("lenaFile1.3.a", lenaMata);
	fwrite(lenaMata.ptr<uchar>(0, 0), 1, size, resultFile_1_1_2_c);
	waitKey(0);
}