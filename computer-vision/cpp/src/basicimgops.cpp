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

void inverionAlongYAxisTransform(Mat &img){ // inversion 
    displayImage(img);
    for(int j =0;j<img.cols/2;j++){
        for(int i = 0;i<img.rows;i++){
            swap(img.at<cv::Vec3b>(i,j),img.at<cv::Vec3b>(i,img.cols - 1 - j));
        }
    }
    displayImage(img);
}




void pixelInverseTransform(Mat &image){
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


void linearContrastStreachingTransform(Mat &img){ // linear contrast streching
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

// Blur effect transformation 
void movingAverageTransform(Mat &img,int winSize=3){
    displayImage(img);
    int trows = img.rows-winSize+1;
    int tcols = img.cols-winSize+1;
    Mat integralImg(img.rows,img.cols,CV_32S);
    
    integralImg.at<int>(0,0) = static_cast<int>(img.at<u_char>(0,0));
    for(int i = 1;i<img.cols;i++)
        integralImg.at<int>(0,i) = static_cast<int>(img.at<u_char>(0,i)) + integralImg.at<int>(0,i-1);
    
    for(int i = 1;i<img.rows;i++)
        integralImg.at<int>(i,0) = static_cast<int>(img.at<u_char>(i,0)) + integralImg.at<int>(i-1,0);
    
    for(int i = 1;i<img.rows;i++){
        for(int j = 1;j<img.cols;j++){
            integralImg.at<int>(i,j) = static_cast<int>(img.at<u_char>(i,j)) + integralImg.at<int>(i-1,j) + integralImg.at<int>(i,j-1) - integralImg.at<int>(i-1,j-1);
        }
    }

    Mat transformed(trows,tcols, IMREAD_GRAYSCALE);
    for(int i = 0;i<trows;i++){
        for(int j = 0;j<tcols;j++){
            int BrSubMat = integralImg.at<int>(i+winSize-1,j+winSize-1);
            if(i>=1)
                BrSubMat -=integralImg.at<int>(i-1,j+winSize-1);
            if(j>=1)
                BrSubMat -=integralImg.at<int>(i+winSize-1,j-1);
            if(i>=1 and j>=1)
                BrSubMat += integralImg.at<int>(i-1,j-1);
            transformed.at<u_char>(i,j) = (BrSubMat/(winSize*winSize));
        }
    }

    displayImage(transformed);
}

void histogramEqualization(Mat &img){
    displayImage(img);
    // map of intensity i : count of i, ie histogram of image
    vector<int> histogram(256,0);
    for(int i =0;i<img.rows;i++){
        for(int j =0;j<img.cols;j++)
            histogram[static_cast<int>(img.at<u_char>(i,j))]+=1;
    }
    // compute cumulative distribution function this is just prefix sums of histogram
    vector<int> cumulativeDistFunc(256,0);
    cumulativeDistFunc[0] = histogram[0];
    int minCdf = cumulativeDistFunc[0];
    int numPixels = img.rows*img.cols;
    for(int i =1;i<256;i++)
        cumulativeDistFunc[i] = cumulativeDistFunc[i-1] + histogram[i];
    for(int i =1;i<256;i++)
        cumulativeDistFunc[i] = (int)(((float)(cumulativeDistFunc[i]-minCdf)/(numPixels-1))*255);
    
    int trows = img.rows;
    int tcols = img.cols;
    Mat transformed(trows,tcols, IMREAD_GRAYSCALE);
    for(int i =0;i<trows;i++){
        for(int j =0;j<tcols;j++){
            int pixelVal = static_cast<int>(img.at<u_char>(i,j));
            int tpixelVal = cumulativeDistFunc[pixelVal];
            transformed.at<u_char>(i,j) = static_cast<u_char>(tpixelVal);
        }
    }
    displayImage(transformed);
}


int main(){
    string imPath = "/home/panirpal/workspace/Learning/Courses/computer-vision/cpp/data/frm.png";
    Mat img = imread(imPath,IMREAD_GRAYSCALE);
    if(!img.empty())
        histogramEqualization(img);
    
    return 0;
}