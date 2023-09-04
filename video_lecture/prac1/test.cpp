#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

Mat src, dst, src_gray;

int main()
{
    int rtn = 0;
    src = imread("testScreenshot.png");
    cout << "test" << endl;

    cvtColor(src, src_gray, COLOR_RGB2GRAY);
    imshow("imgGRAY", src_gray);

    rtn = waitKey(0);
    if (rtn == 27)
        return 0;
    return 0;
}
// g++ -std=c++17 `pkg-config opencv4 --libs --cflags opencv4` test.cpp -o output