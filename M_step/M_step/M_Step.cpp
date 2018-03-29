#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

#if 0
int main(int argc, char **argv)
{
	//新建一个uchar类型的单通道矩阵（grayscale image 灰度图）
	Mat m(300, 400, CV_8U, Scalar(0));

	for (int col = 0; col < 400; col++)
	{
		for (int row = 195; row < 205; row++)
		{
			cout << (int)(*(m.data + m.step[0] * row + m.step[1] * col)) << " ==>  ";

			//给第[row, col]个像素点赋值
			*(m.data + m.step[0] * row + m.step[1] * col) = 255;

			cout << (int)(*(m.data + m.step[0] * row + m.step[1] * col)) << endl;
		}
	}

	imshow("M_Step", m);
	cvWaitKey();

	return 0;
}
#endif

int main(int argc, char **argv)
{
	Mat m = imread("./lena.jpg");
	int *p_address;
	Vec3i color;

	for (int col = 20; col < 40; col++)
	{
		for (int row = 20; row < 40; row++)
		{
			color[0] = (int)(*(m.data + m.step[0] * row + m.step[1] * col));	//B
			color[1] = (int)(*(m.data + m.step[0] * row + m.step[1] * col + m.elemSize1()));	//G
			color[2] = (int)(*(m.data + m.step[0] * row + m.step[1] * col + m.elemSize1() * 2));	//R

			cout << color[0] << "," << color[1] << "," << color[2] << "  ==>  ";

			color[0] = 255;
			color[1] = 0;
			color[2] = 0;
			
			*(m.data + m.step[0] * row + m.step[1] * col) = color[0];
			*(m.data + m.step[0] * row + m.step[1] * col + m.elemSize1()) = color[1];
			*(m.data + m.step[0] * row + m.step[1] * col + m.elemSize1() * 2) = color[2];

			cout << (int)(*(m.data + m.step[0] * row + m.step[1] * col)) << "," << (int)(*(m.data + m.step[0] * row + m.step[1] * col + m.elemSize1())) << "," <<
				(int)(*(m.data + m.step[0] * row + m.step[1] * col + m.elemSize1() * 2))  << endl;

		}

	}

	imshow("lena", m);
	cvWaitKey();

	return 0;
}

