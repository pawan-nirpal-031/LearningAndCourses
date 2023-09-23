#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <math.h>
#include <algorithm>
using namespace std;
using namespace cv;

void displayImage(Mat &img,unsigned int time=0){
    imshow("frame",img);
    waitKey(time);
}

void Transform1(Mat &image){
    displayImage(image);
    for (int y = 0; y < image.rows; ++y) {
        for (int x = 0; x < image.cols; ++x) {
            cv::Vec3b &pixel = image.at<cv::Vec3b>(y, x);
            pixel[0] += 20;
            pixel[1] += 20;
            pixel[2] += 20;
        }
    }
    displayImage(image);
}

void Transform2(Mat &img){ // inversion 
    displayImage(img);
    for(int j =0;j<img.cols/2;j++){
        for(int i = 0;i<img.rows;i++){
            swap(img.at<cv::Vec3b>(i,j),img.at<cv::Vec3b>(i,img.cols - 1 - j));
        }
    }
    displayImage(img);
}




void Transform3(Mat &image){
    displayImage(image);
    for (int y = 0; y < image.rows; ++y) {
        for (int x = 0; x < image.cols; ++x) {
            cv::Vec3b &pixel = image.at<cv::Vec3b>(y, x);
            pixel[0] = 255 - pixel[0];
            pixel[1] = 255 - pixel[1];
            pixel[2] = 255 - pixel[2];
        }
    }
    displayImage(image);
}


void Transform4(Mat &img){
    displayImage(img);
    u_char maxVal = 0;
    u_char minVal = 255;
    for(int i =0;i<img.rows;i++){
        for(int j =0;j<img.cols;j++){
            maxVal = max(maxVal,img.at<u_char>(i,j));
            minVal = min(minVal,img.at<u_char>(i,j));
        }
    }
    for(int i =0;i<img.rows;i++){
        for(int j =0;j<img.cols;j++){
            img.at<u_char>(i,j) = (img.at<u_char>(i,j) - minVal)*(255/(maxVal-minVal));
        }
    }
    displayImage(img);
}

int main(){
    string imPath = "/home/panirpal/workspace/Learning/Courses/computer-vision/cpp/data/frm.png";
    Mat img = imread(imPath,IMREAD_GRAYSCALE);
    if(!img.empty()){
        Transform4(img);
    }    
    return 0;
}