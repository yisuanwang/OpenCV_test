#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "mainwindow.h"
#include <QApplication>
#include "opencv2/opencv.hpp"
#include "cv.h"
#include <math.h>

using namespace std;
using namespace cv;

/*
 * date 2020-1-25
 * chenjunhao
 * 利用Sobel算子对图像进行边缘处理
 *
 */

int main(int argc, char *argv[])
{

   namedWindow("a",CV_WINDOW_AUTOSIZE);
   Mat m1= imread("/home/yisuanwang/timg.jpg");
   imshow("a",m1);

   Mat m2,gray;
   GaussianBlur(m1,m2,Size(3,3),0,0);
   cvtColor(m2,gray,CV_BGR2GRAY);
   imshow("a gray",gray);
   Mat xgrad,ygrad;
   Sobel(gray,xgrad,CV_16S,1,0,3);
   Sobel(gray,ygrad,CV_16S,0,1,3);
   convertScaleAbs(xgrad,xgrad);
   convertScaleAbs(ygrad,ygrad);
   imshow("a13",xgrad);
   imshow("a14",ygrad);

    Mat xyg=Mat(xgrad.size(),xgrad.type());
    int w=xgrad.cols;
    int h = ygrad.rows;
    for(int r=0;r<h;r++)
        for(int c=0;c<w;c++){
            int xg=xgrad.at<uchar>(r,c);
            int yg=ygrad.at<uchar>(r,c);
            int xy=xg+yg;
            xyg.at<uchar>(r,c)=saturate_cast<uchar>(xy);
        }
   imshow("a19",xyg);

   waitKey(0);
   return 0;
}
