#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
using namespace cv;

int main2()
{
	int width = 512;
	int height = 512;
	int size = width * height;
	char OriFile[] = "haha.raw";    //Input Image name
	char OutFile[] = "hahaout.raw"; //Output Raw Image name
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
	putText(lenaMat, "109318059", Point(20, 40), FONT_HERSHEY_COMPLEX, 1, Scalar(0, 255, 0));
	putText(lenaMat, "my name is Cheng-Han ", Point(50, 450), FONT_HERSHEY_COMPLEX, 1, Scalar(0, 255, 0));
	imshow("lenaFile", lenaMat);//display Image	 
	fwrite(lenai, 1, size, resultFile);
	waitKey(0);
	fclose(lenaFile);
	delete lenai;
	destroyWindow("lenaFile");
}