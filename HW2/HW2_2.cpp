#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>

#include <math.h>
using namespace cv;

int HW2_2()
{
	int width = 256;
	int height = 256;
	int size = width * height;
	char OriFile[] = "lena_256.raw";
	char OriFile_baboon[] = "baboon_256.raw";//Input Image name
	char OutFile[] = "HW2_2_lena_1bit.raw"; //Output Raw Image name
	char OutFile_banboon[] = "HW2_banboon_1bit.raw";
	FILE* lenaFile, * resultFile,*baboonfile, * resultFile2;
	lenaFile = fopen(OriFile, "rb");
	baboonfile = fopen(OriFile_baboon, "rb");
	resultFile = fopen(OutFile, "wb");
	resultFile2 = fopen(OutFile_banboon, "wb");
	if (lenaFile == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	unsigned char* lenai = new unsigned char[size];
	unsigned char* banbooni = new unsigned char[size];
	fread(lenai, 1, size, lenaFile);
	fread(banbooni, 1, size, baboonfile);
	Mat lenaMat(height, width, CV_8UC1, lenai);
	Mat banboonMat(height, width, CV_8UC1, banbooni);
	Mat ANS(height, width, CV_8UC1);
	Mat ANS2(height, width, CV_8UC1);
	int n=0;
	printf("how many bits do you want:");
	scanf("%d",&n);
	int i, j;
	double mse=0,mse2=0,psnr,psnr2;
	int max_color = 256;
	for (j = 0; j <= 255; j++)
	{
		for (i = 0; i <= 255; i++)
		{
			int a = max_color / pow(2, n);
			ANS.data[(i* ANS.cols+ j)]= lenaMat.data[((i* lenaMat.cols+j) )]/ a / (pow(2, n) - 1) * (max_color - 1);
			mse += pow(ANS.data[(i * ANS.cols + j)] - lenaMat.data[((i * lenaMat.cols + j))], 2);
				 	
			
		}
	}
	mse = mse / 256 / 256;
	psnr = log10(255 * 255 / mse) * 10;
	printf("\nlena %dbits mse is %f\n", n, mse);
	printf("lena %dbits psnr is %f\n", n, psnr);

	for (j = 0; j <= 255; j++)
	{
		for (i = 0; i <= 255; i++)
		{
			int a = max_color / pow(2, n);
			ANS2.data[(i * ANS.cols + j)] = banboonMat.data[((i * lenaMat.cols + j))] / a / (pow(2, n) - 1) * (max_color - 1);
			mse2 += pow(ANS2.data[(i * ANS.cols + j)] - banboonMat.data[((i * lenaMat.cols + j))], 2);


		}
	}
	mse2 = mse2 / 256 / 256;
	psnr2 = log10(255 * 255 / mse2) * 10;
	printf("banboon %dbits mse is %f\n", n,mse2);
	printf("banboon %dbits psnr is %f", n,psnr2);


	imshow("lenaFileHW2_2_lena\n", ANS);//display Image	
	waitKey(0);
	imshow("lenaFileHW2_2_banboon", ANS2);
	imwrite("HW2_2_lena_1bit.png", ANS);
	imwrite("HW2_2banboon_1bit.png", ANS2);
	waitKey(0);
	fclose(lenaFile);
	fclose(resultFile);
	delete lenai;
	destroyWindow("lenaFile");

}