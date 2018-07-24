#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void myShowImg(const string& fileName) {
    Mat image = imread(fileName);
    namedWindow("My image", WINDOW_AUTOSIZE);
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            if (i % 20 == 0 || j % 20 == 0) {
                image.at<Vec3b>(i, j)[0] = 0;
                image.at<Vec3b>(i, j)[1] = 0;
                image.at<Vec3b>(i, j)[1] = 0;
            }
        }
    }
    imshow("My image", image);
    waitKey(0);
}

int main() {
    string fileName = "/Users/mikhail/Desktop/EDU/openCVTest/openCVTest/a.jpg";
    myShowImg(fileName);
    return 0;
}
