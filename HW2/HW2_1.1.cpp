#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
using namespace cv;

int HW2_1_1()
{
	int width = 256;
	int height = 256;
	int size = width * height;
	char OriFile[] = "lena_256.raw";    //Input Image name
	char OutFile[] = "HW2_1.1.raw"; //Output Raw Image name
	FILE* lenaFile, * resultFile;
	lenaFile = fopen(OriFile, "rb");
	resultFile = fopen(OutFile, "wb");
	if (lenaFile == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	unsigned char* lenai = new unsigned char[size];
	fread(lenai, 1, size, lenaFile);
	Mat lenaMat(height, width, CV_8UC1, lenai);
	Mat lenaMata(15, 18, CV_8UC1);
	Mat lenaMatb(30, 36, CV_8UC1);
	Mat lenaMatc(15, 18, CV_8UC1);
	Mat lenaMatd(30, 36, CV_8UC1);
	Mat lenaMate(height, width, CV_8UC1, lenai);
	int i, j,x,y;
	for (j = 125; j < 140; j++)
	{
		for (i = 125; i < 143; i++)
		{
			lenaMata.data[((j - 125)* lenaMata.cols+(i - 125))] = lenaMat.data[(j* lenaMat.cols+ i)];
		}
	}
	for (j = 0; j < 30; j++)
	{
		for (i = 0; i < 36; i++)
		{
			lenaMatb.data[(j * lenaMatb.cols + i)] = lenaMata.data[((j / 2) * lenaMata.cols + (i / 2))];
		}
	}
	for (j = 0; j < 30; j++)
	{
		for (i = 0; i < 36; i++)
		{
			lenaMat.data[((j +120) * lenaMat.cols + (i+110))] = lenaMatb.data[(j * lenaMatb.cols + i)];
		}
	}


	for (x = 125; x < 140; x++)
	{
		for (y = 160; y < 178; y++)
		{
			lenaMatc.data[((x - 125) * lenaMatc.cols + (y - 160))] = lenaMate.data[(x * lenaMate.cols + y)];
		}
	}
	for (x = 0; x < 30; x++)
	{
		for (y = 0; y < 36; y++)
		{
			lenaMatd.data[(x * lenaMatd.cols + y)] = lenaMatc.data[((x / 2) * lenaMatc.cols + (y / 2))];
		}
	}
	for (x = 0; x < 30; x++)
	{
		for (y = 0; y < 36; y++)
		{
			lenaMat.data[((x + 120) * lenaMat.cols + (y + 150))] = lenaMatd.data[(x * lenaMatd.cols + y)];
		}
	}

	imshow("lenaFileHW_1.1", lenaMat);//display Image	 
	imwrite("HW2_1.1.png", lenaMat);
	waitKey(0);
	fclose(lenaFile);
	fclose(resultFile);
	delete lenai;
	destroyWindow("lenaFile");
}