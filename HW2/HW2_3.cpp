#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
using namespace cv;
int HW_3(){
	int width = 256;
	int height = 256;
	int size = width * height;
	char OriFile[] = "lena_256.raw";

	char OutFile[] = "HW2_3_lena_8bit.raw"; //Output Raw Image name

	FILE* lenaFile, * resultFile, * baboonfile, * resultFile2;
	lenaFile = fopen(OriFile, "rb");
	resultFile = fopen(OutFile, "wb");
	if (lenaFile == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}
	unsigned char* lenai = new unsigned char[size];
	unsigned char* banbooni = new unsigned char[size];
	fread(lenai, 1, size, lenaFile);

	Mat lenaMat(height, width, CV_8UC1, lenai);
	Mat lenaMata(256 *4, 256 * 4, CV_8UC1);
	float x = 0, y = 0;
	int i, j;
	int x0 = int(x) - 1;
	int y0 = int(y) - 1;
	int x1 = int(x);
	int y1 = int(y);
	int x2 = int(x) + 1;
	int y2 = int(y) + 1;
	int x3 = int(x) + 2;
	int y3 = int(y) + 2;
	uchar* p;
	uchar* q0;
	uchar* q1;
	uchar* q2;
	uchar* q3;
	float BiCubicPoly(float x);
for (i = 0; i < 256 * 4; i++)
{
	for (j = 0; j < 256 *4; j++)
	{
		x = i / 4;
		y = j /4;
		int x0 = int(x) - 1;
		int y0 = int(y) - 1;
		int x1 = int(x);
		int y1 = int(y);
		int x2 = int(x) + 1;
		int y2 = int(y) + 1;
		int x3 = int(x) + 2;
		int y3 = int(y) + 2;
		if ((x0 >= 0) && (x3 < lenaMat.cols) && (y0 >= 0) && (y3 < lenaMat.rows))
		{
			float a = -0.5;
			float abs_x;

			float W_x0;
			abs_x = abs(x - x0);
			if (abs_x <= 1.0)
			{
				W_x0 = (a + 2) * pow(abs_x, 3) - (a + 3) * pow(abs_x, 2) + 1;
			}
			else if (abs_x < 2.0)
			{
				W_x0 = a * pow(abs_x, 3) - 5 * a * pow(abs_x, 2) + 8 * a * abs_x - 4 * a;
			}
			else
				W_x0 = 0;

			float W_x1;
			abs_x = abs(x - x1);
			if (abs_x <= 1.0)
			{
				W_x1 = (a + 2) * pow(abs_x, 3) - (a + 3) * pow(abs_x, 2) + 1;
			}
			else if (abs_x < 2.0)
			{
				W_x1 = a * pow(abs_x, 3) - 5 * a * pow(abs_x, 2) + 8 * a * abs_x - 4 * a;
			}
			else
				W_x1 = 0;

			float W_x2;
			abs_x = abs(x - x2);
			if (abs_x <= 1.0)
			{
				W_x2 = (a + 2) * pow(abs_x, 3) - (a + 3) * pow(abs_x, 2) + 1;
			}
			else if (abs_x < 2.0)
			{
				W_x2 = a * pow(abs_x, 3) - 5 * a * pow(abs_x, 2) + 8 * a * abs_x - 4 * a;
			}
			else
				W_x2 = 0;

			float W_x3;
			abs_x = abs(x - x3);
			if (abs_x <= 1.0)
			{
				W_x3 = (a + 2) * pow(abs_x, 3) - (a + 3) * pow(abs_x, 2) + 1;
			}
			else if (abs_x < 2.0)
			{
				W_x3 = a * pow(abs_x, 3) - 5 * a * pow(abs_x, 2) + 8 * a * abs_x - 4 * a;
			}
			else
				W_x3 = 0;

			float W_y0;
			abs_x = abs(y - y0);
			if (abs_x <= 1.0)
			{
				W_y0 = (a + 2) * pow(abs_x, 3) - (a + 3) * pow(abs_x, 2) + 1;
			}
			else if (abs_x < 2.0)
			{
				W_y0 = a * pow(abs_x, 3) - 5 * a * pow(abs_x, 2) + 8 * a * abs_x - 4 * a;
			}
			else
				W_y0 = 0;

			float W_y1;
			abs_x = abs(y - y1);
			if (abs_x <= 1.0)
			{
				W_y1 = (a + 2) * pow(abs_x, 3) - (a + 3) * pow(abs_x, 2) + 1;
			}
			else if (abs_x < 2.0)
			{
				W_y1 = a * pow(abs_x, 3) - 5 * a * pow(abs_x, 2) + 8 * a * abs_x - 4 * a;
			}
			else
				W_y1 = 0;


			float W_y2;
			abs_x = abs(y - y2);
			if (abs_x <= 1.0)
			{
				W_y2 = (a + 2) * pow(abs_x, 3) - (a + 3) * pow(abs_x, 2) + 1;
			}
			else if (abs_x < 2.0)
			{
				W_y2 = a * pow(abs_x, 3) - 5 * a * pow(abs_x, 2) + 8 * a * abs_x - 4 * a;
			}
			else
				W_y2 = 0;



			float W_y3;
			abs_x = abs(y - y3);
			if (abs_x <= 1.0)
			{
				W_y3 = (a + 2) * pow(abs_x, 3) - (a + 3) * pow(abs_x, 2) + 1;
			}
			else if (abs_x < 2.0)
			{
				W_y3 = a * pow(abs_x, 3) - 5 * a * pow(abs_x, 2) + 8 * a * abs_x - 4 * a;
			}
			else
				W_y3 = 0;



			float W_x0y0 = W_x0 * W_y0;
			float W_x0y1 = W_x0 * W_y1;
			float W_x0y2 = W_x0 * W_y2;
			float W_x0y3 = W_x0 * W_y3;
			float W_x1y0 = W_x1 * W_y0;
			float W_x1y1 = W_x1 * W_y1;
			float W_x1y2 = W_x1 * W_y2;
			float W_x1y3 = W_x1 * W_y3;
			float W_x2y0 = W_x2 * W_y0;
			float W_x2y1 = W_x2 * W_y1;
			float W_x2y2 = W_x2 * W_y2;
			float W_x2y3 = W_x2 * W_y3;
			float W_x3y0 = W_x3 * W_y0;
			float W_x3y1 = W_x3 * W_y1;
			float W_x3y2 = W_x3 * W_y2;
			float W_x3y3 = W_x3 * W_y3;

			lenaMata.data[(i * lenaMata.cols + j)] = (lenaMat.data[(x0 * lenaMat.cols + y0)] * W_x0y0 +
				lenaMat.data[(x0 * lenaMat.cols + y1)] * W_x0y1 +
				lenaMat.data[(x0 * lenaMat.cols + y2)] * W_x0y2 +
				lenaMat.data[(x0 * lenaMat.cols + y3)] * W_x0y3 +
				lenaMat.data[(x1 * lenaMat.cols + y0)] * W_x1y0 +
				lenaMat.data[(x1 * lenaMat.cols + y1)] * W_x1y1 +
				lenaMat.data[(x1 * lenaMat.cols + y2)] * W_x1y2 +
				lenaMat.data[(x1 * lenaMat.cols + y3)] * W_x1y3 +
				lenaMat.data[(x2 * lenaMat.cols + y0)] * W_x2y0 +
				lenaMat.data[(x2 * lenaMat.cols + y1)] * W_x2y1 +
				lenaMat.data[(x2 * lenaMat.cols + y2)] * W_x2y2 +
				lenaMat.data[(x2 * lenaMat.cols + y3)] * W_x2y3 +
				lenaMat.data[(x3 * lenaMat.cols + y0)] * W_x3y0 +
				lenaMat.data[(x2 * lenaMat.cols + y1)] * W_x3y1 +
				lenaMat.data[(x2 * lenaMat.cols + y2)] * W_x3y2 +
				lenaMat.data[(x2 * lenaMat.cols + y3)] * W_x3y3);
		}
	}
}
int n = 0;
Mat ANS(1024, 1024, CV_8UC1);
printf("how many bits do you want:");
scanf("%d", &n);
int max_color = 256;
for (j = 0; j <= 1023; j++)
{
	for (i = 0; i <= 1023; i++)
	{
		int a = max_color / pow(2, n);
		ANS.data[(i * ANS.cols + j)] = lenaMata.data[((i * lenaMata.cols + j))] / a / (pow(2, n) - 1) * (max_color - 1);
	
	}
}
imshow("HW_3", ANS);//display Image	
waitKey(0);

imwrite("HW2_3_lena_2bit.png", ANS);
fclose(lenaFile);
fclose(resultFile);
delete lenai;
destroyWindow("lenaFile");
waitKey(0);
}