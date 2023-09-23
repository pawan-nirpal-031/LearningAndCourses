#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <math.h>
using namespace std;
using namespace cv;

void displayImage(Mat &img,unsigned int time=0){
    imshow("frame",img);
    waitKey(time);
}

unsigned char getValue(Vec3b &bgrPixel){
    unsigned char sum = (bgrPixel[2] + bgrPixel[1] +bgrPixel[0])/3;
    return sum;
}

int main(){
    string imPath = "/home/panirpal/workspace/Learning/computer-vision/data/frm.png";
    Mat img = imread(imPath,IMREAD_COLOR);
    if(!img.empty()){
        for(int i = 0;i<img.rows;i++){
            for(int j =0;j<img.cols;j++){
                Vec3b bgrPixel = img.at<Vec3b>(i,j); 
                unsigned char grayScale = getValue(bgrPixel);
                img.at<Vec3b>(i,j) = {grayScale,grayScale,grayScale};
            }
        }
        displayImage(img);
    }
}