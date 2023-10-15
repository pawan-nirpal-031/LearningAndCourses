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

void movingAverageTransform(Mat &img){
    displayImage(img);
    unsigned int winSize = 3;
    int trows = img.rows-winSize+1;
    int tcols = img.cols-winSize+1;
    Mat transformed(trows,tcols, IMREAD_GRAYSCALE); 

    // accumlate first coloumn prefix sums
    for(int i =1;i<img.rows;i++)
        (img.at<u_char>(i,0)) += static_cast<int>(img.at<u_char>(i-1,0));
    
    // accumlate first row prefix sums
    for(int j = 1;j<img.cols;j++)
       (img.at<u_char>(0,j)) += static_cast<int> (img.at<u_char>(0,j-1));

    // compute the rectangular submatrix prefix sums.
    for(int i =1;i<img.rows;i++)
        for(int j = 1;j<img.cols;j++)
            (img.at<u_char>(i,j)) += (static_cast<int> (img.at<u_char>(i-1,j)) + static_cast<int> (img.at<u_char>(i,j-1)) - static_cast<int> (img.at<u_char>(i-1,j-1)));

    // now use the formula for computing the moving average of a sub matrix of size winSize X winSize by sliding it across the image 
    for(int i = 0;i<trows;i++){
        for(int j = 0;j<tcols;j++){
            unsigned char pointVal = static_cast<int>(img.at<u_char>(i+winSize -1,j+winSize-1));
            if(i>=1)
                pointVal -= static_cast<int>( img.at<u_char>(i-1,j+winSize-1));
            if(j>=1)
                pointVal -= static_cast<int>(img.at<u_char>(i+winSize -1,j-1));
            if(i>=1 and j>=1)
                pointVal += static_cast<int> (img.at<u_char>(i-1,j-1));
            cout<<(int)pointVal<<'\n';
            transformed.at<u_char>(i,j) = (pointVal/(winSize*winSize));
        }
    }
    displayImage(transformed);
}

int main(){
    string imPath = "/home/panirpal/workspace/Learning/Courses/computer-vision/cpp/data/frm.png";
    Mat img = imread(imPath,IMREAD_GRAYSCALE);
    if(!img.empty())
        movingAverageTransform(img);
    
    return 0;
}