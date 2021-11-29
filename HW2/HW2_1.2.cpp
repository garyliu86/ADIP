#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
using namespace cv;

int HW2_1_2()
{
	int width = 256;
	int height = 256;
	int size = width * height;
	char OriFile[] = "lena_256.raw";  //Input Image name
	char OriFile1[] = "lena_256_fuzzy.raw";

	char OutFile[] = "HW2_1.2.raw"; 
	char OutFile1[] = "HW2_1.2_fuzzy.raw";
	FILE* lenaFile, *lenaFile1,* resultFile,* resultFile1;
	lenaFile = fopen(OriFile, "rb");
	lenaFile1 = fopen(OriFile1, "rb");
	resultFile = fopen(OutFile, "wb");
	resultFile1 = fopen(OutFile1, "wb");
	if (lenaFile == NULL || lenaFile1 == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	unsigned char* lenai = new unsigned char[size];
	unsigned char* lenai1 = new unsigned char[size];
	fread(lenai, 1, size, lenaFile);
	fread(lenai1, 1, size, lenaFile1);
	Mat lenaMat(height, width, CV_8UC1, lenai);
	Mat lenaMata(128, 128, CV_8UC1);
	Mat lenaMatb(height, width, CV_8UC1, lenai1);
	Mat lenaMatc(128, 128, CV_8UC1);
	int i, j;
	for (j = 0; j < 255; j += 2)
	{
		for (i = 0; i < 255; i += 2)
		{
			lenaMata.data[((j / 2) * lenaMata.cols + (i / 2))] = lenaMat.data[(j * lenaMat.cols + i)];
		}
	}

	imshow("lenaFileHW_1.2", lenaMata);//display Image	 

	imwrite("HW2_1.2.png", lenaMata);
	waitKey(0);
	//fuzzy
	for (j = 0; j < 255; j += 2)
	{
		for (i = 0; i < 255; i += 2)
		{
			lenaMatc.data[((j / 2) * lenaMatc.cols + (i / 2))] = lenaMatb.data[(j * lenaMatb.cols + i)];
		}
	}
	imshow("lenaFileHW_1.2_fuzzy", lenaMatc);//display Image
	imwrite("HW2_1.2_fuzzy.png", lenaMatc);
	waitKey(0);
	fclose(lenaFile);
	fclose(lenaFile1);
	fclose(resultFile);
	fclose(resultFile1);
	delete lenai;
	delete lenai1;
	destroyWindow("lenaFile");
}