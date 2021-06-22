#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main() {
	string path = "Reasources/test.jpg";
	Mat img = imread(path);
	Mat imgGray;
	Mat imgCan;

	cvtColor(img, imgGray,COLOR_BGR2GRAY);
	Canny(img, imgCan, 25, 75);




	imshow("Image", img);
	imshow("SZurke", imgGray);
	imshow("ke", imgCan);
	waitKey(0);
	return 0;
}