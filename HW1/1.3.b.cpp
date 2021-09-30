#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include<time.h>
using namespace cv;
int main1_3b()
{
	int width = 256;
	int height = 256;
	int size = width * height;
	char OriFile[] = "lena_256.raw";    //Input Image name
	char OutFile_c[] = "lena256out_1.3b.raw"; //Output Raw Image name
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
	int i, j;
	//1.3.b
	Mat lenaMata(height, width, CV_8UC1, lenai);
	int a, b;
	srand(time(NULL));

	a = (rand() % 100 - 50) + 1;
	printf("%d", a);


		for (j = 0; j <= 255; j++)
		{
			for (i = 0; i <= 255; i++)
			{
				if (*lenaMata.ptr<uchar>(j, i) >= 255 - a & a>0)
				{
					*lenaMata.ptr<uchar>(j, i) = 255;
				}
				if (*lenaMata.ptr<uchar>(j, i) < 255 - a & a > 0)
				{
					*lenaMata.ptr<uchar>(j, i) += a;
				}
				if (*lenaMata.ptr<uchar>(j, i) <= -a & a < 0)
				{
					*lenaMata.ptr<uchar>(j, i) = 0;
				}
				if (*lenaMata.ptr<uchar>(j, i) > -a & a < 0)
				{
					*lenaMata.ptr<uchar>(j, i) += a;
				}

			}
		}
	
	


	imshow("lenaFile1.3.b", lenaMata);
	fwrite(lenaMata.ptr<uchar>(0, 0), 1, size, resultFile_1_1_2_c);
	waitKey(0);
}