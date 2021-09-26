#include "ImageWarping.cpp"
#include <time.h>
#include <iostream>
int main() {
	CImg<float> src("Dataset/6.bmp");
	// args: src sigma gradient_threshold vote_threshold peak_dis
	//1-6.5,700
	//2-4.5,400
	//3-5.5,500
	//4-4.5,400
	//5-4.0,300 
	//6-6.0,500 
	Hough hough(src, 6.0f, 30, 500, 60);
	CImg<float> result = hough.imageWarping(src);
	result.display();
	result.save("result/6.bmp");
	return 0;
}
