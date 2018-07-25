#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void applyFilter(const string& fileName, const Mat& kernel) {
    Mat image = imread(fileName, 0);
    Mat newImage = image.clone();
    int band = kernel.cols/2;
    for (int i = band; i < image.rows - band; ++i)
        for (int j = band; j < image.cols - band; ++j) {
            float newVal = 0;
            for (int g = 0; g < kernel.rows; ++ g)
                for (int k = 0; k < kernel.cols; ++k) {
                    newVal += kernel.at<float>(g, k) * image.at<uchar>(i + g - band, j + k - band);
                }
            if (newVal < 0)
                newImage.at<uchar>(i, j) = 0;
            else if (newVal > 255)
                newImage.at<uchar>(i, j) = 255;
            else
                newImage.at<uchar>(i, j) = newVal;
        }
    namedWindow("My image", WINDOW_AUTOSIZE);
    imshow("My image", newImage);
    waitKey(0);
}

int main() {
    string fileName = "/Users/mikhail/Desktop/EDU/openCVTest/openCVTest/a.jpg";
    int kernelDim;
    cin >> kernelDim;
    Mat kernel(kernelDim, kernelDim, CV_32F);
    for (int i = 0; i < kernelDim; ++i)
        for (int j = 0; j < kernelDim; ++j) {
            float pixel;
            cin >> pixel;
            kernel.at<float>(i, j) = pixel;
        }
    applyFilter(fileName, kernel);
    return 0;
}

/*
 
 3
 0.0625 0.125 0.0625
 0.125 0.25 0.125
 0.0625 0.125 0.0625
 
 */
