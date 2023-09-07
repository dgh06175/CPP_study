#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

#include <opencv2/opencv.hpp>

using namespace cv;

typedef struct
{
    int r, g, b;
} int_rgb;

int **IntAlloc2(int height, int width)
{
    int **tmp;
    tmp = (int **)calloc(height, sizeof(int *));
    for (int i = 0; i < height; i++)
        tmp[i] = (int *)calloc(width, sizeof(int));
    return (tmp);
}

void IntFree2(int **image, int height, int width)
{
    for (int i = 0; i < height; i++)
        free(image[i]);

    free(image);
}

float **FloatAlloc2(int height, int width)
{
    float **tmp;
    tmp = (float **)calloc(height, sizeof(float *));
    for (int i = 0; i < height; i++)
        tmp[i] = (float *)calloc(width, sizeof(float));
    return (tmp);
}

void FloatFree2(float **image, int height, int width)
{
    for (int i = 0; i < height; i++)
        free(image[i]);

    free(image);
}

int_rgb **IntColorAlloc2(int height, int width)
{
    int_rgb **tmp;
    tmp = (int_rgb **)calloc(height, sizeof(int_rgb *));
    for (int i = 0; i < height; i++)
        tmp[i] = (int_rgb *)calloc(width, sizeof(int_rgb));
    return (tmp);
}

void IntColorFree2(int_rgb **image, int height, int width)
{
    for (int i = 0; i < height; i++)
        free(image[i]);

    free(image);
}

int **ReadImage(char *name, int *height, int *width)
{
    Mat img = imread(name, IMREAD_GRAYSCALE);
    int **image = (int **)IntAlloc2(img.rows, img.cols);

    *width = img.cols;
    *height = img.rows;

    for (int i = 0; i < img.rows; i++)
        for (int j = 0; j < img.cols; j++)
            image[i][j] = img.at<unsigned char>(i, j);

    return (image);
}

void WriteImage(char *name, int **image, int height, int width)
{
    Mat img(height, width, CV_8UC1);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            img.at<unsigned char>(i, j) = (unsigned char)image[i][j];

    imwrite(name, img);
}

void ImageShow(char *winname, int **image, int height, int width)
{
    Mat img(height, width, CV_8UC1);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            img.at<unsigned char>(i, j) = (unsigned char)image[i][j];
    imshow(winname, img);
    waitKey(0);
}

int_rgb **ReadColorImage(char *name, int *height, int *width)
{
    Mat img = imread(name, IMREAD_COLOR);
    int_rgb **image = (int_rgb **)IntColorAlloc2(img.rows, img.cols);

    *width = img.cols;
    *height = img.rows;

    for (int i = 0; i < img.rows; i++)
        for (int j = 0; j < img.cols; j++)
        {
            image[i][j].b = img.at<Vec3b>(i, j)[0];
            image[i][j].g = img.at<Vec3b>(i, j)[1];
            image[i][j].r = img.at<Vec3b>(i, j)[2];
        }

    return (image);
}

void WriteColorImage(char *name, int_rgb **image, int height, int width)
{
    Mat img(height, width, CV_8UC3);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            img.at<Vec3b>(i, j)[0] = (unsigned char)image[i][j].b;
            img.at<Vec3b>(i, j)[1] = (unsigned char)image[i][j].g;
            img.at<Vec3b>(i, j)[2] = (unsigned char)image[i][j].r;
        }

    imwrite(name, img);
}

void ColorImageShow(char *winname, int_rgb **image, int height, int width)
{
    Mat img(height, width, CV_8UC3);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            img.at<Vec3b>(i, j)[0] = (unsigned char)image[i][j].b;
            img.at<Vec3b>(i, j)[1] = (unsigned char)image[i][j].g;
            img.at<Vec3b>(i, j)[2] = (unsigned char)image[i][j].r;
        }
    imshow(winname, img);
}

template <typename _TP>
void ConnectedComponentLabeling(_TP **seg, int height, int width, int **label, int *no_label)
{

    // Mat bw = threshval < 128 ? (img < threshval) : (img > threshval);
    Mat bw(height, width, CV_8U);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            bw.at<unsigned char>(i, j) = (unsigned char)seg[i][j];
    }
    Mat labelImage(bw.size(), CV_32S);
    *no_label = connectedComponents(bw, labelImage, 8); // 0        Ե

    (*no_label)--;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            label[i][j] = labelImage.at<int>(i, j);
    }
}

#define imax(x, y) ((x) > (y) ? x : y)
#define imin(x, y) ((x) < (y) ? x : y)

int BilinearInterpolation(int **image, int width, int height, double x, double y)
{
    int x_int = (int)x;
    int y_int = (int)y;

    int A = image[imin(imax(y_int, 0), height - 1)][imin(imax(x_int, 0), width - 1)];
    int B = image[imin(imax(y_int, 0), height - 1)][imin(imax(x_int + 1, 0), width - 1)];
    int C = image[imin(imax(y_int + 1, 0), height - 1)][imin(imax(x_int, 0), width - 1)];
    int D = image[imin(imax(y_int + 1, 0), height - 1)][imin(imax(x_int + 1, 0), width - 1)];

    double dx = x - x_int;
    double dy = y - y_int;

    double value = (1.0 - dx) * (1.0 - dy) * A + dx * (1.0 - dy) * B + (1.0 - dx) * dy * C + dx * dy * D;

    return ((int)(value + 0.5));
}

void DrawHistogram(char *comments, int *Hist)
{
    int histSize = 256; /// Establish the number of bins
    // Draw the histograms for B, G and R
    int hist_w = 512;
    int hist_h = 512;
    int bin_w = cvRound((double)hist_w / histSize);

    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));
    Mat r_hist(histSize, 1, CV_32FC1);
    for (int i = 0; i < histSize; i++)
        r_hist.at<float>(i, 0) = Hist[i];
    /// Normalize the result to [ 0, histImage.rows ]
    normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

    /// Draw for each channel
    for (int i = 1; i < histSize; i++)
    {
        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
             Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))),
             Scalar(255, 0, 0), 2, 8, 0);
    }

    /// Display
    namedWindow(comments, WINDOW_AUTOSIZE);
    imshow(comments, histImage);

    waitKey(0);
}

void Ex0907_0(int **img, int height, int width)
{
    for (int y = height / 4; y < height / 4 * 3; y++)
    {
        for (int x = width / 4; x < width / 4 * 3; x++)
        {
            img[y][x] = 0;
        }
    }

    for (int y = height; y >= 0; y--)
    {
        for (int x = y; x < width; x++)
        {
            // img[y][x] = 0;
            img[y][x] = 255 - img[y][x];
        }
    }
    // 2019036020 이상현입니다.
}

int main()
{
    int height, width;
    int **img = ReadImage((char *)"lena.png", &height, &width);
    // int** img = ReadImage((char*)"me.png", &height, &width);

    // int** img_out = (int**)IntAlloc2(height, width); // int img_out[512][512];

    Ex0907_0(img, height, width);

    // for (int i = height / 3 - 50; i < height / 3; i++) {
    //	for (int j = width / 3; j < width / 2 + 100; j++) {
    //		img[i][j] = 255;
    //	}
    // }

    ImageShow((char *)"output", img, height, width);

    return 0;
}
