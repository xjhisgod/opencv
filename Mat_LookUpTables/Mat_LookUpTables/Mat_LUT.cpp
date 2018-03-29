#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;


#if 0
void Invert(Mat &img, const uchar* const lookup)
{
	int rows = img.rows;
	int cols = img.cols*img.channels();
	for (int i = 0; i<rows; i++)
	{
		uchar *p = img.ptr<uchar>(i);
		for (int j = 0; j<cols;j++)
			p[j] = lookup[p[j]];
	}
}

int main()
{
	Mat src = imread("test.jpg");  //将任意一张名为test.jpg的图片放置于工程文件夹test中
	if (!src.data)
	{
		cout << "error! The image is not built!" << endl;
		return -1;
	}
	// 为了演示效果，将图片转换成灰度图片
	Mat img1 = src;
	//cvtColor( src, img1, CV_RGB2GRAY );
	imshow("src file", img1);
	//建立查找表
	uchar lookup[256];
	for (int i = 0; i<256; i++)
		lookup[i] = 255 - i;
	//调用自定义图像取反函数
	Invert(img1, lookup);
	imshow("target file", img1);
	waitKey();
	return 0;
}
#endif

int main(int argc, char **argv)
{
	Mat img_src = imread("test.jpg");
	if(!img_src.data)
	{
		cout << "read image test.jpg failed" << endl;
		return -1;
	}
	// 为了演示效果，将图片转换成灰度图片
	Mat img1 = img_src;
	//cvtColor( src, img1, CV_RGB2GRAY );
	imshow("First", img1);
	//建立查找表
	Mat lookUpTable(1, 256, CV_8U);
	uchar *p = lookUpTable.data;
	for (int i = 0; i<256; i++)
		p[i] = 255 - i;
	//通过LUT函数实现图像取反
	LUT(img1, lookUpTable, img1);

	imshow("Second", img1);
	waitKey();

	return 0;
}

