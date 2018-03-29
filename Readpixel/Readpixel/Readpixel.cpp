
#include<iostream>  
#include<opencv2\opencv.hpp>  
using namespace std;
using namespace cv;


//at()函数
//int main(int argc, char* argv[]) {
//	Mat grayim(600, 800, CV_8UC1);
//	Mat colorim(600, 800, CV_8UC3);
//	for (int i = 0;i<grayim.rows;i++) {
//		for (int j = 0;j<grayim.cols;j++) {
//			grayim.at<uchar>(i, j) = (i + j) % 255;
//		}
//	}
//	for (int i = 0;i<colorim.rows;i++) {
//		for (int j = 0;j<colorim.cols;j++) {
//			Vec3b pixel;
//			pixel[0] = i % 255;
//			pixel[1] = j % 255;
//			pixel[2] = 0;
//			colorim.at<Vec3b>(i, j) = pixel;
//		}
//	}
//	imshow("grayim", grayim);
//	imshow("colorim", colorim);
//	waitKey(0);
//	return 0;
//}

//迭代器
//int main(int argc, char* argv[]) {
//	Mat grayim(600, 800, CV_8UC1);
//	Mat colorim(600, 800, CV_8UC3);
//	MatIterator_<uchar> grayit, grayend;
//	for (grayit = grayim.begin<uchar>(), grayend = grayim.end<uchar>();grayit != grayend;grayit++) {
//		*grayit = rand() % 255;
//	}
//	MatIterator_<Vec3b> colorit, colorend;
//	for (colorit = colorim.begin<Vec3b>(), colorend = colorim.end<Vec3b>();colorit != colorend;colorit++) {
//		(*colorit)[0] = rand() % 255;
//		(*colorit)[1] = rand() % 255;
//		(*colorit)[2] = rand() % 255;
//	}
//	imshow("grayim", grayim);
//	imshow("colorim", colorim);
//	waitKey(0);
//	return 0;
//}


//使用指针
int main(int argc,char* argv[]){  
<span style="white-space:pre">    </span>Mat grayim(600,800,CV_8UC1);  
<span style="white-space:pre">    </span>Mat colorim(600,800,CV_8UC3);  
<span style="white-space:pre">    </span>for(int i=0;i<grayim.rows;i++){  
<span style="white-space:pre">        </span>uchar* ptr=grayim.ptr<uchar>(i);  
<span style="white-space:pre">        </span>for(int j=0;j<grayim.cols;j++)  
<span style="white-space:pre">            </span>ptr[j]=(i+j)%255;  
<span style="white-space:pre">    </span>}  
<span style="white-space:pre">    </span>for(int i=0;i<colorim.rows;i++){  
<span style="white-space:pre">        </span>Vec3b* ptr=colorim.ptr<Vec3b>(i);  
<span style="white-space:pre">        </span>for(int j=0;j<colorim.cols;j++){  
<span style="white-space:pre">            </span>ptr[j][0]=i%255;  
<span style="white-space:pre">            </span>ptr[j][1]=j%255;  
<span style="white-space:pre">            </span>ptr[j][2]=0;  
<span style="white-space:pre">        </span>}  
<span style="white-space:pre">    </span>}  
<span style="white-space:pre">    </span>imshow("grayim",grayim);  
<span style="white-space:pre">    </span>imshow("colorim",colorim);  
<span style="white-space:pre">    </span>waitKey(0);  
<span style="white-space:pre">    </span>return 0;  
} 
