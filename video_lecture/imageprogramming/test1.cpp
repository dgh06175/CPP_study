#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include "my.h"
#include <vector>

#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;

typedef struct {
	int r, g, b;
}int_rgb;


int** IntAlloc2(int height, int width)
{
	int** tmp;
	tmp = (int**)calloc(height, sizeof(int*));
	for (int i = 0; i < height; i++)
		tmp[i] = (int*)calloc(width, sizeof(int));
	return(tmp);
}

void IntFree2(int** image, int height, int width)
{
	for (int i = 0; i < height; i++)
		free(image[i]);

	free(image);
}


float** FloatAlloc2(int height, int width)
{
	float** tmp;
	tmp = (float**)calloc(height, sizeof(float*));
	for (int i = 0; i < height; i++)
		tmp[i] = (float*)calloc(width, sizeof(float));
	return(tmp);
}

void FloatFree2(float** image, int height, int width)
{
	for (int i = 0; i < height; i++)
		free(image[i]);

	free(image);
}

int_rgb** IntColorAlloc2(int height, int width)
{
	int_rgb** tmp;
	tmp = (int_rgb**)calloc(height, sizeof(int_rgb*));
	for (int i = 0; i < height; i++)
		tmp[i] = (int_rgb*)calloc(width, sizeof(int_rgb));
	return(tmp);
}

void IntColorFree2(int_rgb** image, int height, int width)
{
	for (int i = 0; i < height; i++)
		free(image[i]);

	free(image);
}

int** ReadImage(char* name, int* height, int* width)
{
	Mat img = imread(name, IMREAD_GRAYSCALE);
	int** image = (int**)IntAlloc2(img.rows, img.cols);

	*width = img.cols;
	*height = img.rows;

	for (int i = 0; i < img.rows; i++)
		for (int j = 0; j < img.cols; j++)
			image[i][j] = img.at<unsigned char>(i, j);

	return(image);
}

void WriteImage(char* name, int** image, int height, int width)
{
	Mat img(height, width, CV_8UC1);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			img.at<unsigned char>(i, j) = (unsigned char)image[i][j];

	imwrite(name, img);
}


void ImageShow(char* winname, int** image, int height, int width)
{
	Mat img(height, width, CV_8UC1);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			img.at<unsigned char>(i, j) = (unsigned char)image[i][j];
	imshow(winname, img);
	waitKey(0);
}



int_rgb** ReadColorImage(char* name, int* height, int* width)
{
	Mat img = imread(name, IMREAD_COLOR);
	int_rgb** image = (int_rgb**)IntColorAlloc2(img.rows, img.cols);

	*width = img.cols;
	*height = img.rows;

	for (int i = 0; i < img.rows; i++)
		for (int j = 0; j < img.cols; j++) {
			image[i][j].b = img.at<Vec3b>(i, j)[0];
			image[i][j].g = img.at<Vec3b>(i, j)[1];
			image[i][j].r = img.at<Vec3b>(i, j)[2];
		}

	return(image);
}

void WriteColorImage(char* name, int_rgb** image, int height, int width)
{
	Mat img(height, width, CV_8UC3);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			img.at<Vec3b>(i, j)[0] = (unsigned char)image[i][j].b;
			img.at<Vec3b>(i, j)[1] = (unsigned char)image[i][j].g;
			img.at<Vec3b>(i, j)[2] = (unsigned char)image[i][j].r;
		}

	imwrite(name, img);
}

void ColorImageShow(char* winname, int_rgb** image, int height, int width)
{
	Mat img(height, width, CV_8UC3);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			img.at<Vec3b>(i, j)[0] = (unsigned char)image[i][j].b;
			img.at<Vec3b>(i, j)[1] = (unsigned char)image[i][j].g;
			img.at<Vec3b>(i, j)[2] = (unsigned char)image[i][j].r;
		}
	imshow(winname, img);

}

template <typename _TP>
void ConnectedComponentLabeling(_TP** seg, int height, int width, int** label, int* no_label)
{

	//Mat bw = threshval < 128 ? (img < threshval) : (img > threshval);
	Mat bw(height, width, CV_8U);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			bw.at<unsigned char>(i, j) = (unsigned char)seg[i][j];
	}
	Mat labelImage(bw.size(), CV_32S);
	*no_label = connectedComponents(bw, labelImage, 8); // 0        Ե        

	(*no_label)--;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			label[i][j] = labelImage.at<int>(i, j);
	}
}

#define imax(x, y) ((x)>(y) ? x : y)
#define imin(x, y) ((x)<(y) ? x : y)

int BilinearInterpolation(int** image, int width, int height, double x, double y)
{
	int x_int = (int)x;
	int y_int = (int)y;

	int A = image[imin(imax(y_int, 0), height - 1)][imin(imax(x_int, 0), width - 1)];
	int B = image[imin(imax(y_int, 0), height - 1)][imin(imax(x_int + 1, 0), width - 1)];
	int C = image[imin(imax(y_int + 1, 0), height - 1)][imin(imax(x_int, 0), width - 1)];
	int D = image[imin(imax(y_int + 1, 0), height - 1)][imin(imax(x_int + 1, 0), width - 1)];

	double dx = x - x_int;
	double dy = y - y_int;

	double value
		= (1.0 - dx) * (1.0 - dy) * A + dx * (1.0 - dy) * B
		+ (1.0 - dx) * dy * C + dx * dy * D;

	return((int)(value + 0.5));
}


void DrawHistogram(char* comments, int* Hist)
{
	int histSize = 256; /// Establish the number of bins
	// Draw the histograms for B, G and R
	int hist_w = 512; int hist_h = 512;
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



void Ex0907_0(int** img, int height, int width) {
	for (int y = height / 4; y < height / 4 * 3; y++) {
		for (int x = width / 4; x < width / 4 * 3; x++) {
			img[y][x] = 0;
		}
	}

	for (int y = height; y >= 0; y--) {
		for (int x = y; x < width; x++) {
			//img[y][x] = 0;
			img[y][x] = 255 - img[y][x];
		}
	}
}

void Thresholding(int threshold, int** img_in, int y0, int size_y, int x0, int size_x, IMAGE output)
{
	for (int y = y0; y < size_y; y++) {
		for (int x = x0; x < size_x; x++) {
			if (img_in[y][x] >= threshold) output.data[y][x] = 255;
			else output.data[y][x] = 0;
		}
	}
}

void Thresholding1(IMAGE input, IMAGE output)
{
	int max = 50;
	Thresholding(max * 3, input.data, 0, input.height / 2, 0, input.width / 2, output);
	Thresholding(max * 2, input.data, 0, input.height / 2, input.width / 2, input.width, output);
	Thresholding(max * 1, input.data, input.height / 2, input.height, 0, input.width / 2, output);
	Thresholding(max * 0, input.data, input.height / 2, input.height, input.width / 2, input.width, output);
	ImageShow((char*)"output", output.data, output.height, output.width);
}

void Thresholding2(int threshold, IMAGE* input, IMAGE* output)
{
	for (int y = 0; y < input->height; y++) {
		for (int x = 0; x < input->width; x++) {
			if (input->data[y][x] >= threshold) output->data[y][x] = 255;
			else output->data[y][x] = 0;
		}
	}
	ImageShow((char*)"output", output->data, output->height, output->width);
}

#define IMAX(x, y) ((x > y) ? x : y)
#define IMIN(x, y) ((x < y) ? x : y)

void AddValue(int value, IMAGE input, IMAGE output)
{
	for (int y = 0; y < input.height; y++) {
		for (int x = 0; x < input.width; x++) {
			output.data[y][x] = IMIN(IMAX(input.data[y][x] + value, 0), 255);
		}
	}
	ImageShow((char*)"output", output.data, output.height, output.width);
}

void EX0918_1()
{
	const char* fileName = "TestImages/barbara.png";
	IMAGE input;
	input.data = ReadImage((char*)fileName, &input.height, &input.width);
	
	IMAGE output;
	output.height = input.height;
	output.width = input.width;
	output.data = (int**)IntAlloc2(input.height, input.width);

	//Thresholding1(input, output);
	//Thresholding2(128, &input, &output);
	AddValue(128, input, output);
}

void EX0918_2()
{
	int a[7] = { 1, 2, -3, -10, 5, 9, -1 };
	int maxValue = -INT_MAX;

	for (int i = 0; i < 7; i++) {
		maxValue = IMAX(maxValue, a[i]);
	}
	printf("%d", maxValue);
}

void ImageClipping(int** img, int height, int width)
{
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			img[y][x] = IMIN(IMAX(img[y][x], 0), 255);
		}
	}
}

void ImageMix(double value, int** input1, int** input2, int** output, int height, int width)
{
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			output[y][x] = input1[y][x] * value + input2[y][x] * (1 - value);
		}
	}
	//ImageClipping(output, height, width);
	ImageShow((char*)"output", output, height, width);
}

void EX0918_3()
{
	int height, width;
	const char* fileName1 = "TestImages/barbara.png";
	const char* fileName2 = "TestImages/lena.png";

	int** img_1 = ReadImage((char*)fileName2, &height, &width);
	int** img_0 = ReadImage((char*)fileName1, &height, &width);


	int** output = (int**)IntAlloc2(height, width);

	for (double alpha = 0.1; alpha < 0.9; alpha += 0.1) {
		ImageMix(alpha, img_0, img_1, output, height, width);
	}
}

void ImageExpand(int** input, int** output, int height, int width)
{
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			output[y][x] = input[y][x] * (255.0 / 128.0);
		}
	}
	ImageClipping(output, height, width); // 255 이상인 값들 255로 바꿔줌
	ImageShow((char*)"ImageExpandOutput", output, height, width);
}

void GammaCorrection(double value, int** input, int** output, int height, int width)
{
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			output[y][x] = pow(input[y][x] / 256.0, value) * 255.0;
		}
	}
	ImageShow((char*)"GammaCorrectionOutput", output, height, width);
}

void StransformPtr(int input, double a, double b, double c, double d, int& output)
{
	if (input < a) {
		output = (int)((double)input * c / a);
	}
	else if (a <= input && input < b) {
		output = (int)((d - c) / (b - a) * ((double)input - a) + c);
	}
	else {
		output = ((255.0 - d) / (255.0 - b)) * ((double)input - b) + d;
	}
}

void EX0921_1()
{
	int height, width;
	const char* fileName = "TestImages/yezi.jpg";
	int** img = ReadImage((char*)fileName, &height, &width);
	int** output = (int**)IntAlloc2(height, width);

	// ImageExpand(img, output, height, width);
	/*for (double g = 0.1; g <= 20.0; g *= 2)
	{
		GammaCorrection(g, img, output, height, width);
	}*/
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			StransformPtr(img[y][x], 50, 150, 100, 200, output[y][x]);
		}
	}
	ImageShow((char*)"stretchingInput", img, height, width);
	ImageShow((char*)"stretchingOutput", output, height, width);
}

void GetHistogram(int** img, int height, int width, int* histogram)
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			histogram[img[i][j]] += 1;
		}
	}
}

// (참고용) 함수 내 선언된 배열이나 변수의 메모리는 그 함수를 벗어나느 순간 해제되어 사용 불가능하다.
int* GetHistogram2(int** img, int height, int width)
{
	int hist[256] = { 0, };
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			hist[img[i][j]] += 1;
		}
	}

	return hist;
}

void GetSumHistogram(int** img, int height, int width, int* histogram)
{
	int chist[256] = { 0, };
	int count = 0;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			chist[img[i][j]]++;
		}
	}
	histogram[0] = 0;
	for (int index = 1; index < 256; index += 1) {
		histogram[index] += chist[index] + histogram[index - 1];
	}
}

void EX0921()
{
	int height, width;
	const char* fileName = "TestImages/lena.png";
	int** img = ReadImage((char*)fileName, &height, &width);
	int** output = (int**)IntAlloc2(height, width);
	// int histogram[256] = { 0, };

	//GetHistogram(img, height, width, histogram);
	int *histPtr = GetHistogram2(img, height, width);

	DrawHistogram((char*)output, histPtr);
}

void normalHistogram(int** img, int height, int width, int* hist)
{
	int chist[256] = { 0 };
	GetSumHistogram(img, height, width, chist);
	int n = height * width;
	for (int i = 0; i < 256; i++) {
		hist[i] = chist[i] * 255.0 / n;
	}
}

void histEq(int** img, int** output, int height, int width)
{
	int hist[256] = { 0 };
	normalHistogram(img, height, width, hist);
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			output[y][x] = hist[img[y][x]];
		}
	}
}

void EX0925() {
	int height, width;
	const char* fileName = "TestImages/lenax0.5.png";
	int** img = ReadImage((char*)fileName, &height, &width);
	int** output = (int**)IntAlloc2(height, width);

	histEq(img, output, height, width);
	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output", output, height, width);
}

// 모든 픽셀을 주변 N * N 크기의 픽셀들의 평균 밝기로 대체하는 함수
void MeanFilteringNxN(int N, int** img, int height, int width, int** img_out)
{
	int n = (N - 1) / 2;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int sum = 0;
			for (int i = -n; i <= n; i++) {
				for (int j = -n; j <= n; j++) {
					int nx = x + i;
					int ny = y + j;
					if (nx < 0) nx = 0;
					if (ny < 0) ny = 0;
					if (nx >= width) nx = width - 1;
					if (ny >= height) ny = height - 1;
					sum += img[ny][nx];
				}
			}
			img_out[y][x] = (int)((double)sum / ((n * 2 + 1) * (n * 2 + 1)));
		}
	}
}

void EX1005() {
	int height, width;
	const char* fileName = "TestImages/barbara.png";
	int** img = ReadImage((char*)fileName, &height, &width);
	int** output = (int**)IntAlloc2(height, width);
	for (int N = 3; N <= 15; N += 2) {
		MeanFilteringNxN(N, img, height, width, output);
		ImageShow((char*)"output", output, height, width);
	}
}

float NxN_평균(int N, int** img, int x, int y, int height, int width) {
	int n = (N - 1) / 2;
	float sum = 0;
	for (int i = -n; i <= n; i++) {
		for (int j = -n; j <= n; j++) {
			int nx = x + i;
			int ny = y + j;
			if (nx < 0) nx = 0;
			if (ny < 0) ny = 0;
			if (nx >= width) nx = width - 1;
			if (ny >= height) ny = height - 1;
			sum += img[ny][nx];
		}
	}
	return sum / (N * N);
}

void Avg3x3_WithMask(int** img, int height, int width, int** img_out)
{
	float mask[3][3] = { { 1.0f / 9, 1.0f / 9, 1.0f / 9},
						 {1.0f / 9, 1.0f / 9, 1.0f / 9},
						 {1.0f / 9, 1.0f / 9, 1.0f / 9} };
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (x == 0 || x == width - 1 || y == 0 || y == height - 1) { // 가장자리인 경우
				img_out[y][x] = img[y][x];
			}
			else { // 가장자리가 아닌 경우
				float output = 0.0;
				for (int cy = -1; cy <= 1; cy++) {
					for (int cx = -1; cx <= 1; cx++) {
						output += mask[cy + 1][cx + 1] * img[y + cy][x + cx];
					}
				}
				img_out[y][x] = (int)(output + 0.5);
			}
		}
	}
}

float Masking(int y, int x, float** mask, int** img, int width, int height, int n) {
	float sum = 0.0;
	for (int i = -n; i <= n; i++) {
		for (int j = -n; j <= n; j++) {
			int nx = i + 1;
			int ny = j + 1;
			int my = y + i;
			int mx = x + j;
			if (nx < 0) nx = 0;
			if (mx < 0) mx = 0;
			if (ny < 0) ny = 0;
			if (my < 0) my = 0;
			if (nx >= width) nx = width - 1;
			if (mx >= width) mx = width - 1;
			if (ny >= height) ny = height - 1;
			if (my >= height) my = height - 1;
			sum += mask[nx][ny] * img[my][mx];
		}
	}
	return (double)sum / ((n * 2 + 1) * (n * 2 + 1));
}

float Masking_NEW(int y, int x, float** mask, int** img) {
	float sum = 0.0;

	for (int y0 = -1; y0 <= 1; y0++) {
		for (int x0 = -1; x0 <= 1; x0++) {
			sum += mask[y0 + 1][x0 + 1] * img[y + y0][x + x0];
		}
	}
	return ((int)sum + 0.5);
}

void Masking3x3(float** mask, int** img, int height, int width, int** img_out) {
	int n = 1;
	int sum = 0;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			img_out[y][x] = Masking(y, x, mask, img, width, height, n);
		}
	}

}

void Masking3x3_NEW(float** mask, int** img, int height, int width, int** img_out) {

	for (int y = 1; y < height-1; y++) {
		for (int x = 1; x < width-1; x++) {
			img_out[y][x] = Masking_NEW(y, x, mask, img);
		}
	}
}

void EX1012() {
	int height, width;
	const char* fileName = "TestImages/barbara.png";
	int** img = ReadImage((char*)fileName, &height, &width);
	float** output = (float**)IntAlloc2(height, width);
	int** img_out = (int**)IntAlloc2(height, width);

	for (int n = 1; n < 11; n+=2) {
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				output[y][x] = NxN_평균(n, img, x, y, height, width);
			}
		}

		Masking3x3(output, img, height, width, img_out);
		ImageShow((char*)"output", img_out, height, width);
	}
}

int FindMaxValue(int** img, int height, int width) {
	int maxValue = 0;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (img[y][x] > maxValue) {
				maxValue = img[y][x];
			}
		}
	}
	return maxValue;
}

int FindMinValue(int** img, int height, int width) {
	int minValue = 0;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (img[y][x] < minValue) {
				minValue = img[y][x];
			}
		}
	}
	return minValue;
}

void MagGradient(int** img, int height, int width, int** img_out) {
	int Gx, Gy;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
				img_out[y][x] = img[y][x];
			}
			else {
				Gx = img[y][x + 1] - img[y][x - 1];
				Gy = img[y + 1][x] - img[y - 1][x];
				img_out[y][x] = abs(Gx) + abs(Gy);
			}
		}
	}
}

void NormalizeByMax(int** img, int height, int width) {
	int max_val = FindMaxValue(img, height, width);

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			img[y][x] = (int)(((double)img[y][x] / max_val) * 255);
		}
	}
}

#define _FXFY_ 0
#define _FX_ 1
#define _FY_ 2

void DetectEdgeByDerivative(int mode, int** img, int height, int width, int** img_out) {
	for (int y = 0; y < height - 1; y++) {
		for (int x = 0; x < width - 1; x++) {
			int fx = img[y][x + 1] - img[y][x];
			int fy = img[y + 1][x] - img[y][x];

			switch (mode)
			{
			case _FXFY_:
				img_out[y][x] = imin(abs(fx) + abs(fy), 255);
				break;
			case _FX_:
				img_out[y][x] = abs(fx);
				break;
			case _FY_:
				img_out[y][x] = abs(fy);
				break;
			default:
				break;
			}
		}
	}
}

void EX1016_1() {
	int height, width;
	int** img = ReadImage((char*)"TestImages/barbara.png", &height, &width);
	int** img_out = IntAlloc2(height, width);
	/*MagGradient(img, height, width, img_out);
	NormalizeByMax(img_out, height, width);*/

	ImageShow((char*)"-1", img, height, width);

	DetectEdgeByDerivative(_FXFY_, img, height, width, img_out);
	NormalizeByMax(img_out, height, width);
	ImageShow((char*)"0", img_out, height, width);

	DetectEdgeByDerivative(_FX_, img, height, width, img_out);
	NormalizeByMax(img_out, height, width);
	ImageShow((char*)"1", img_out, height, width);

	DetectEdgeByDerivative(_FY_, img, height, width, img_out);
	NormalizeByMax(img_out, height, width);
	ImageShow((char*)"2", img_out, height, width);
}

void AbsImage(int** img, int height, int width)
{
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			img[y][x] = abs(img[y][x]);
		}
	}
}

void laplacian(float** mask, int** img, int** img_out, int height, int width) {
	Masking3x3_NEW(mask, img, height, width, img_out);
	AbsImage(img_out, height, width);
	NormalizeByMax(img_out, height, width);
}

void MagSobel(int** img, int height, int width, int** img_out)
{
	for (int y = 0; y < height - 1; y++) {
		for (int x = 0; x < width - 1; x++) {
			int fx = (img[y - 1][x + 1] - img[y - 1][x - 1])
				+ 2 * (img[y][x + 1] - img[y][x - 1])
				+ (img[y + 1][x + 1] - img[y + 1][x - 1]);
			int fy = (img[y + 1][x - 1] - img[y - 1][x - 1])
				+ 2 * (img[y + 1][x] - img[y - 1][x])
				+ (img[y + 1][x + 1] - img[y - 1][x + 1]);
			img_out[y][x] = abs(fx) + abs(fy); // 그라디언트의 크기
		}
	}
}

void SobelDetect(int** img, int height, int width, int** img_out1, int** img_out2, int** img_out3)
{
	float** mask = (float**)FloatAlloc2(3, 3);
	mask[0][0] = -1; mask[0][1] = -2, mask[0][2] = -1;
	mask[1][0] = 0; mask[1][1] = 0, mask[1][2] = 0;
	mask[2][0] = 1; mask[2][1] = 2, mask[2][2] = 1;

	float** mask2 = (float**)FloatAlloc2(3, 3);
	mask2[0][0] = -1; mask2[0][1] = 0, mask2[0][2] = 1;
	mask2[1][0] = -2; mask2[1][1] = 0, mask2[1][2] = 2;
	mask2[2][0] = -1; mask2[2][1] = 0, mask2[2][2] = 1;

	Masking3x3_NEW(mask, img, height, width, img_out1);
	AbsImage(img_out1, height, width);

	Masking3x3_NEW(mask2, img, height, width, img_out2);
	AbsImage(img_out2, height, width);

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			img_out3[y][x] = img_out1[y][x] + img_out2[y][x];
		}
	}

	NormalizeByMax(img_out1, height, width);
	NormalizeByMax(img_out2, height, width);
	NormalizeByMax(img_out3, height, width);
}

void EX1019_1() {
	int height, width;
	int** img = ReadImage((char*)"TestImages/lenaGN15.png", &height, &width);
	int** img_out = IntAlloc2(height, width);
	int** img_out0 = IntAlloc2(height, width);
	int** img_out1 = IntAlloc2(height, width);
	int** img_out2 = IntAlloc2(height, width);

	SobelDetect(img, height, width, img_out0, img_out1, img_out2);
	ImageShow((char*)"out", img_out2, height, width);
}

void ClippingImage(int** img_in, int height, int width, int** img_out) {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			img_out[y][x] = imin(imax(img_in[y][x], 0), 255);
		}
	}
}

void EdgeEnhanceImage(float alpha, int** img, int height, int width, int** img_out) {
	float** mask = (float**)FloatAlloc2(3, 3);
	mask[0][0] = -alpha; mask[0][1] = -alpha, mask[0][2] = -alpha;
	mask[1][0] = -alpha; mask[1][1] = 1 + 8 * alpha, mask[1][2] = -alpha;
	mask[2][0] = -alpha; mask[2][1] = -alpha, mask[2][2] = -alpha;

	Masking3x3_NEW(mask, img, height, width, img_out);
	ClippingImage(img_out, height, width, img_out);
}

void EX1023_1() {
	int height, width;
	int** img = ReadImage((char*)"TestImages/kim.jpg", &height, &width);
	int** img_out = IntAlloc2(height, width);
	for (float a = 0.1; a < 1.0; a += 0.1) {
		EdgeEnhanceImage(a, img, height, width, img_out);
		ImageShow((char*)"out", img_out, height, width);
	}
}

void bubbling(int* a, int* b) {
	if (*a > *b) {
		int temp = *a;
		*a =* b;
		*b = temp;
	}
}

void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			bubbling(&arr[j], &arr[j + 1]);
		}
	}
}

void getBlockNxN(int y, int x, int** img, int* data, int N) {
	int count = 0;
	int half = N / 2;

	for (int i = -half; i <= half; i++) {
		for (int j = -half; j <= half; j++) {
			data[count] = img[y + i][x + j];
			count++;
		}
	}
}

void medianFiltering(int** img, int height, int width, int** img_out, int N) {
	int dataSize = N * N;
	int* data = (int*)malloc(dataSize * sizeof(int));

	for (int y = N / 2; y < height - N / 2; y++) {
		for (int x = N / 2; x < width - N / 2; x++) {
			getBlockNxN(y, x, img, data, N);
			bubbleSort(data, dataSize);
			img_out[y][x] = data[dataSize / 2];
		}
	}

	for (int y = 0; y < height; y++) {
		img_out[y][0] = img[y][0];
		img_out[y][width - 1] = img[y][width - 1];
	}

	for (int x = 0; x < width; x++) {
		img_out[0][x] = img[0][x];
		img_out[height - 1][x] = img[height - 1][x];
	}

	free(data);
}

void EX1030_1() {
	int height, width;
	int** img = ReadImage((char*)"TestImages/lenaSP20.png", &height, &width);
	int** img_out = IntAlloc2(height, width);
	int** img_out2 = IntAlloc2(height, width);

	medianFiltering(img, height, width, img_out, 5);

	ImageShow((char*)"in", img, height, width);
	ImageShow((char*)"out", img_out, height, width);

}

// 0차 보건
void ZeroOrderInterpolation(int** img, int height, int width, int** img_out)
{
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			img_out[2 * y][2 * x] = img[y][x];
			img_out[2 * y][2 * x + 1] = img[y][x];
			img_out[2 * y + 1][2 * x] = img[y][x];
			img_out[2 * y + 1][2 * x + 1] = img[y][x];
		}
	}
}

void UpSamplingx2_avg(int** img, int height, int width, int** img_out)
{
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int A = img[y][x];
			int B = img[y][MIN(x + 1, width - 1)];
			int C = img[MIN(y + 1, height - 1)][x];
			int D = img[MIN(y + 1, height - 1)][MIN(x + 1, width - 1)];
			img_out[2 * y][2 * x] = img[y][x]; // A
			img_out[2 * y][2 * x + 1] = (A + B) / 2; // E
			img_out[2 * y + 1][2 * x] = (A + C) / 2; // F
			img_out[2 * y + 1][2 * x + 1] = (A + B + C + D) / 4; // I
		}
	}
}

void EX1102_1() {
	int height, width;
	int** img = ReadImage((char*)"TestImages/s_lena.png", &height, &width);
	int height2 = height * 2, width2 = width * 2;
	int** img_out = IntAlloc2(height2, width2);

	//ZeroOrderInterpolation(img, height, width, img_out);
	//UpSamplingx2_avg(img, height, width, img_out);

	double y0 = 100.2;
	double x0 = 150.3;

	for (int y = 0; y < height2; y++) {
		for (int x = 0; x < width2; x++) {
			img_out[y][x] = BilinearInterpolation(img, width, height, y / 2.0, x / 2.0);
		}
	}

	ImageShow((char*)"in", img, height, width);
	ImageShow((char*)"out", img_out, height2, width2);
}

void imageTranslation(int ty, int tx, int** image, int height, int width, int** img_out) {
	for (int yp = 0; yp < height; yp++) {
		for (int xp = 0; xp < width; xp++) {
			int y = yp + ty;
			int x = xp + tx;
			if (y < 0 || y > height - 1 || x < 0 || x > width - 1) {
				continue;
			}
			else {
				img_out[y][x] = image[yp][xp];
			}
		}
	}
}

void imageTranslation_TWO(int ty, int tx, int** image, int height, int width, int** img_out) {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int yp = y + ty;
			int xp = x + tx;
			if (yp < 0 || yp > height - 1 || xp < 0 || xp > width - 1) {
				continue;
			}
			else {
				img_out[yp][xp] = image[y][x];
			}
		}
	}
}

#ifndef PI

#define PI 3.14159265358979323846

#endif

void Rotation(double theta, int** img, int height, int width, int** img_out)
{
	double rad = theta / 180.0 * PI; // degree -> rad로 변환
	/*for (int y_prime = 0; y_prime < height; y_prime++) {
		for (int x_prime = 0; x_prime < width; x_prime++) {
			int y = -x_prime * sin(rad) + y_prime * cos(rad);
			int x = x_prime * cos(rad) + y_prime * sin(rad);
			if (x < 0 || x >= width || y < 0 || y >= height) continue;
			else img_out[y_prime][x_prime] = BilinearInterpolation(img, width, height, y, x);
		}
	}*/
	int centerX = width / 2;
	int centerY = height / 2;

	for (int y_prime = 0; y_prime < height; y_prime++) {
		for (int x_prime = 0; x_prime < width; x_prime++) {
			int translatedX = x_prime - centerX;
			int translatedY = y_prime - centerY;

			int x = (int)(translatedX * cos(rad) - translatedY * sin(rad) + centerX);
			int y = (int)(translatedX * sin(rad) + translatedY * cos(rad) + centerY);

			if (x >= 0 && x < width && y >= 0 && y < height)
				img_out[y_prime][x_prime] = BilinearInterpolation(img, width, height, x, y);
			else
				continue;
		}
	}
}

struct AffineT {
	double a, b, c, d;
	int x0, y0, x0_prime, y0_prime;
};

void AffineTransform(AffineT p,	int** img, int height, int width, int** img_out)
{
	double a_prime = p.d / (p.a * p.d - p.b * p.c), b_prime = -p.b / (p.a * p.d - p.b * p.c);
	double c_prime = -p.c / (p.a * p.d - p.b * p.c), d_prime = p.a / (p.a * p.d - p.b * p.c);
	for (int y_prime = 0; y_prime < height; y_prime++) {
		for (int x_prime = 0; x_prime < width; x_prime++) {
			int y = c_prime * (x_prime - p.x0_prime) + d_prime * (y_prime - p.y0_prime) + p.y0;
			int x = a_prime * (x_prime - p.x0_prime) + b_prime * (y_prime - p.y0_prime) + p.x0;
			if (x < 0 || x >= width || y < 0 || y >= height) continue;
			else img_out[y_prime][x_prime] = BilinearInterpolation(img, width, height, x, y);
		}
	}
}


void EX1106_1() {
	int height, width;
	int** img = ReadImage((char*)"TestImages/lena.png", &height, &width);
	int** img_out = IntAlloc2(height, width);

	int tx = -50, ty = 50;
	imageTranslation(ty, tx, img, height, width, img_out);
	

	ImageShow((char*)"in", img, height, width);
	ImageShow((char*)"out", img_out, height, width);
}

void EX1106_2() {
	int height, width;
	int** img = ReadImage((char*)"TestImages/lena.png", &height, &width);
	int** img_out = IntAlloc2(height, width);

	float degree = 45.0;
	Rotation(degree, img, height, width, img_out);


	ImageShow((char*)"in", img, height, width);
	ImageShow((char*)"out", img_out, height, width);
}

void EX1106_3() {
	int height, width;
	int** img = ReadImage((char*)"TestImages/lena.png", &height, &width);
	int** img_out = IntAlloc2(height, width);


	AffineT para;
	para.a = 1.0, para.b = -1.0;
	para.c = 1.0, para.d = 1.0;
	para.y0 = height / 2, para.x0 = width / 2;
	para.y0_prime = height / 2, para.x0_prime = width / 2;

	AffineTransform(para, img, height, width, img_out);


	ImageShow((char*)"in", img, height, width);
	ImageShow((char*)"out", img_out, height, width);
}

void EX1109_1() {

}

int main() {
	EX1106_3();
}
