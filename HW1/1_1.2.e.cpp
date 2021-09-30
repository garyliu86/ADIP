#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include<time.h>
using namespace cv;
int main1_1_2e()
{
	int i, j,num=0;
	int width = 256;
	int height = 256;
	int size = width * height;
	char OriFile[] = "lena_256.raw";    //Input Image name
	char OutFile[] = "lena256out_e_2.raw"; //Output Raw Image name
	char OutFile_2[] = "lena256out_e_2_2.raw"; //Output Raw Image name
	FILE* lenaFile, * resultFile_e_2,* resultFile_e_2_2;
	lenaFile = fopen(OriFile, "rb");
	resultFile_e_2 = fopen(OutFile, "wb");
	resultFile_e_2_2 = fopen(OutFile_2, "wb");
	if (lenaFile == NULL) {
		puts("Loading File Error!");
		system("PAUSE");
		exit(0);
	}

	unsigned char* lenai = new unsigned char[size];
	fread(lenai, 1, size, lenaFile);
	Mat lenaMat(height, width, CV_8UC1, lenai);
	int a[16],b[16],k,q;
	srand(time(NULL));
	Mat lenaMata(height / 4, width/4, CV_8UC1);
	Mat test(height, width, CV_8UC1);

	int c [16];
	for (k = 0; k < 16; k++) {
		a[k] = (rand() % 4);
		b[k] = (rand() % 4);
		c[k] = 4 * a[k] + b[k];
		for (q = 0; q < k; q++) {

			while (c[k] == c[q]) {

				a[k] = (rand() % 4);
				b[k] = (rand() % 4);
				c[k] = 4 * a[k] + b[k];
				q = 0;
			}
		}
		printf("a=%d b=%d \n", a[k], b[k]);
	}



	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*lenaMata.ptr<uchar>(j, i) = *lenaMat.ptr<uchar>(j, i);
		}
	}
	
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test.ptr<uchar>(j+(64*a[0]), i+(64*b[0])) = *lenaMata.ptr<uchar>(j, i);
		}
	}


	Mat lenaMatb(height / 4, width / 4, CV_8UC1);
	
	for (j = 0; j <= 63; j++)
	{
		for (i = 64; i <= 127; i++)
		{
			*lenaMatb.ptr<uchar>(j, i-64) = *lenaMat.ptr<uchar>(j, i);
		}
	}


	Mat lenaMatc(height / 4, width / 4, CV_8UC1);
	for (j = 0; j <= 63; j++)
	{
		for (i = 128; i <= 191; i++)
		{
			*lenaMatc.ptr<uchar>(j, i -128) = *lenaMat.ptr<uchar>(j, i);
		}
	}


	Mat lenaMatd(height / 4, width / 4, CV_8UC1);
	for (j = 0; j <= 63; j++)
	{
		for (i = 192; i <= 255; i++)
		{
			*lenaMatd.ptr<uchar>(j, i - 192) = *lenaMat.ptr<uchar>(j, i);
		}
	}


	Mat lenaMate(height / 4, width/4, CV_8UC1);
	for (j = 64; j <= 127; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*lenaMate.ptr<uchar>(j-64, i) = *lenaMat.ptr<uchar>(j, i);
		}
	}


	Mat lenaMatf(height / 4, width / 4, CV_8UC1);
	for (j = 64; j <= 127; j++)
	{
		for (i = 64; i <= 127; i++)
		{
			*lenaMatf.ptr<uchar>(j - 64, i - 64) = *lenaMat.ptr<uchar>(j, i);
		}
	}

	Mat lenaMatg(height / 4, width / 4, CV_8UC1);
	for (j = 64; j <= 127; j++)
	{
		for (i = 128; i <= 191; i++)
		{
			*lenaMatg.ptr<uchar>(j - 64, i - 128) = *lenaMat.ptr<uchar>(j, i);
		}
	}


	Mat lenaMath(height / 4, width / 4, CV_8UC1);
	for (j = 64; j <= 127; j++)
	{
		for (i = 192; i <= 255; i++)
		{
			*lenaMath.ptr<uchar>(j - 64, i - 192) = *lenaMat.ptr<uchar>(j, i);
		}
	}

	Mat lenaMatj(height / 4, width / 4, CV_8UC1);
	for (j = 128; j <= 191; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*lenaMatj.ptr<uchar>(j - 128, i ) = *lenaMat.ptr<uchar>(j, i);
		}
	}


	Mat lenaMatk(height / 4, width / 4, CV_8UC1);
	for (j = 128; j <= 191; j++)
	{
		for (i = 64; i <= 127 ;i++)
		{
			*lenaMatk.ptr<uchar>(j - 128, i-64) = *lenaMat.ptr<uchar>(j, i);
		}
	}


	Mat lenaMatl(height / 4, width / 4, CV_8UC1);
	for (j = 128; j <= 191; j++)
	{
		for (i = 128; i <= 191; i++)
		{
			*lenaMatl.ptr<uchar>(j - 128, i - 128) = *lenaMat.ptr<uchar>(j, i);
		}
	}

	Mat lenaMatm(height / 4, width / 4, CV_8UC1);
	for (j = 128; j <= 191; j++)
	{
		for (i = 192; i <= 255; i++)
		{
			*lenaMatm.ptr<uchar>(j - 128, i - 192) = *lenaMat.ptr<uchar>(j, i);
		}
	}

    Mat lenaMatn(height / 4, width / 4, CV_8UC1);
	for (j = 192; j <= 255; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*lenaMatn.ptr<uchar>(j-192 , i ) = *lenaMat.ptr<uchar>(j, i);
		}
	}


	Mat lenaMato(height / 4, width / 4, CV_8UC1);
	for (j = 192; j <= 255; j++)
	{
		for (i = 64; i <= 127; i++)
		{
			*lenaMato.ptr<uchar>(j - 192, i-64) = *lenaMat.ptr<uchar>(j, i);
		}
	}

	Mat lenaMatp(height / 4, width / 4, CV_8UC1);
	for (j = 192; j <= 255; j++)
	{
		for (i = 128; i <= 191; i++)
		{
			*lenaMatp.ptr<uchar>(j - 192, i - 128) = *lenaMat.ptr<uchar>(j, i);
		}
	}
	

	Mat lenaMatq(height / 4, width / 4, CV_8UC1);
	for (j = 192; j <= 255; j++)
	{
		for (i = 192; i <= 255; i++)
		{
			*lenaMatq.ptr<uchar>(j - 192, i - 192) = *lenaMat.ptr<uchar>(j, i);
		}
	}

	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test.ptr<uchar>(j + (64 * a[0]), i + (64 * b[0])) = *lenaMata.ptr<uchar>(j, i);
		}
	}	
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test.ptr<uchar>(j + (64 * a[1]), i + (64 * b[1])) = *lenaMatb.ptr<uchar>(j, i);
		}
	}	
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test.ptr<uchar>(j + (64 * a[2]), i + (64 * b[2])) = *lenaMatc.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test.ptr<uchar>(j + (64 * a[3]), i + (64 * b[3])) = *lenaMatd.ptr<uchar>(j, i);
		}
	}	
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test.ptr<uchar>(j + (64 * a[4]), i + (64 * b[4])) = *lenaMate.ptr<uchar>(j, i);
		}
	}	
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test.ptr<uchar>(j + (64 * a[5]), i + (64 * b[5])) = *lenaMatf.ptr<uchar>(j, i);
		}
	}	
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test.ptr<uchar>(j + (64 * a[6]), i + (64 * b[6])) = *lenaMatg.ptr<uchar>(j, i);
		}
	}	
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test.ptr<uchar>(j + (64 * a[7]), i + (64 * b[7])) = *lenaMath.ptr<uchar>(j, i);
		}
	}	
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test.ptr<uchar>(j + (64 * a[8]), i + (64 * b[8])) = *lenaMatj.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test.ptr<uchar>(j + (64 * a[9]), i + (64 * b[9])) = *lenaMatk.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test.ptr<uchar>(j + (64 * a[10]), i + (64 * b[10])) = *lenaMatl.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test.ptr<uchar>(j + (64 * a[11]), i + (64 * b[11])) = *lenaMatm.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test.ptr<uchar>(j + (64 * a[12]), i + (64 * b[12])) = *lenaMatn.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test.ptr<uchar>(j + (64 * a[13]), i + (64 * b[13])) = *lenaMato.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test.ptr<uchar>(j + (64 * a[14]), i + (64 * b[14])) = *lenaMatp.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test.ptr<uchar>(j + (64 * a[15]), i + (64 * b[15])) = *lenaMatq.ptr<uchar>(j, i);
		}
	}
	imshow("1_1.2e(1)", test);
	//²Ä¤G±i
	Mat test2(height, width, CV_8UC1);
	for (k = 0; k < 16; k++) {
		a[k] = (rand() % 4);
		b[k] = (rand() % 4);
		c[k] = 4 * a[k] + b[k];
		for (q = 0; q < k; q++) {

			while (c[k] == c[q]) {

				a[k] = (rand() % 4);
				b[k] = (rand() % 4);
				c[k] = 4 * a[k] + b[k];
				q = 0;
			}
		}
		printf("a=%d b=%d \n", a[k], b[k]);
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*lenaMata.ptr<uchar>(j, i) = *lenaMat.ptr<uchar>(j, i);
		}
	}

	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test2.ptr<uchar>(j + (64 * a[0]), i + (64 * b[0])) = *lenaMata.ptr<uchar>(j, i);
		}
	}



	for (j = 0; j <= 63; j++)
	{
		for (i = 64; i <= 127; i++)
		{
			*lenaMatb.ptr<uchar>(j, i - 64) = *lenaMat.ptr<uchar>(j, i);
		}
	}



	for (j = 0; j <= 63; j++)
	{
		for (i = 128; i <= 191; i++)
		{
			*lenaMatc.ptr<uchar>(j, i - 128) = *lenaMat.ptr<uchar>(j, i);
		}
	}


	for (j = 0; j <= 63; j++)
	{
		for (i = 192; i <= 255; i++)
		{
			*lenaMatd.ptr<uchar>(j, i - 192) = *lenaMat.ptr<uchar>(j, i);
		}
	}


	for (j = 64; j <= 127; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*lenaMate.ptr<uchar>(j - 64, i) = *lenaMat.ptr<uchar>(j, i);
		}
	}


	for (j = 64; j <= 127; j++)
	{
		for (i = 64; i <= 127; i++)
		{
			*lenaMatf.ptr<uchar>(j - 64, i - 64) = *lenaMat.ptr<uchar>(j, i);
		}
	}

	for (j = 64; j <= 127; j++)
	{
		for (i = 128; i <= 191; i++)
		{
			*lenaMatg.ptr<uchar>(j - 64, i - 128) = *lenaMat.ptr<uchar>(j, i);
		}
	}



	for (j = 64; j <= 127; j++)
	{
		for (i = 192; i <= 255; i++)
		{
			*lenaMath.ptr<uchar>(j - 64, i - 192) = *lenaMat.ptr<uchar>(j, i);
		}
	}


	for (j = 128; j <= 191; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*lenaMatj.ptr<uchar>(j - 128, i) = *lenaMat.ptr<uchar>(j, i);
		}
	}



	for (j = 128; j <= 191; j++)
	{
		for (i = 64; i <= 127; i++)
		{
			*lenaMatk.ptr<uchar>(j - 128, i - 64) = *lenaMat.ptr<uchar>(j, i);
		}
	}



	for (j = 128; j <= 191; j++)
	{
		for (i = 128; i <= 191; i++)
		{
			*lenaMatl.ptr<uchar>(j - 128, i - 128) = *lenaMat.ptr<uchar>(j, i);
		}
	}

	for (j = 128; j <= 191; j++)
	{
		for (i = 192; i <= 255; i++)
		{
			*lenaMatm.ptr<uchar>(j - 128, i - 192) = *lenaMat.ptr<uchar>(j, i);
		}
	}


	for (j = 192; j <= 255; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*lenaMatn.ptr<uchar>(j - 192, i) = *lenaMat.ptr<uchar>(j, i);
		}
	}



	for (j = 192; j <= 255; j++)
	{
		for (i = 64; i <= 127; i++)
		{
			*lenaMato.ptr<uchar>(j - 192, i - 64) = *lenaMat.ptr<uchar>(j, i);
		}
	}


	for (j = 192; j <= 255; j++)
	{
		for (i = 128; i <= 191; i++)
		{
			*lenaMatp.ptr<uchar>(j - 192, i - 128) = *lenaMat.ptr<uchar>(j, i);
		}
	}



	for (j = 192; j <= 255; j++)
	{
		for (i = 192; i <= 255; i++)
		{
			*lenaMatq.ptr<uchar>(j - 192, i - 192) = *lenaMat.ptr<uchar>(j, i);
		}
	}

	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test2.ptr<uchar>(j + (64 * a[0]), i + (64 * b[0])) = *lenaMata.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test2.ptr<uchar>(j + (64 * a[1]), i + (64 * b[1])) = *lenaMatb.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test2.ptr<uchar>(j + (64 * a[2]), i + (64 * b[2])) = *lenaMatc.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test2.ptr<uchar>(j + (64 * a[3]), i + (64 * b[3])) = *lenaMatd.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test2.ptr<uchar>(j + (64 * a[4]), i + (64 * b[4])) = *lenaMate.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test2.ptr<uchar>(j + (64 * a[5]), i + (64 * b[5])) = *lenaMatf.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test2.ptr<uchar>(j + (64 * a[6]), i + (64 * b[6])) = *lenaMatg.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test2.ptr<uchar>(j + (64 * a[7]), i + (64 * b[7])) = *lenaMath.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test2.ptr<uchar>(j + (64 * a[8]), i + (64 * b[8])) = *lenaMatj.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test2.ptr<uchar>(j + (64 * a[9]), i + (64 * b[9])) = *lenaMatk.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test2.ptr<uchar>(j + (64 * a[10]), i + (64 * b[10])) = *lenaMatl.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test2.ptr<uchar>(j + (64 * a[11]), i + (64 * b[11])) = *lenaMatm.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test2.ptr<uchar>(j + (64 * a[12]), i + (64 * b[12])) = *lenaMatn.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test2.ptr<uchar>(j + (64 * a[13]), i + (64 * b[13])) = *lenaMato.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test2.ptr<uchar>(j + (64 * a[14]), i + (64 * b[14])) = *lenaMatp.ptr<uchar>(j, i);
		}
	}
	for (j = 0; j <= 63; j++)
	{
		for (i = 0; i <= 63; i++)
		{
			*test2.ptr<uchar>(j + (64 * a[15]), i + (64 * b[15])) = *lenaMatq.ptr<uchar>(j, i);
		}
	}
	imshow("1_1.2e(2)", test2);
	waitKey(0);


	fwrite(test.ptr<uchar>(0,0), 1, size, resultFile_e_2);
	fwrite(test2.ptr<uchar>(0, 0), 1, size, resultFile_e_2_2);
	fclose(lenaFile);
	delete lenai;
	destroyWindow("lenaFile");



}
