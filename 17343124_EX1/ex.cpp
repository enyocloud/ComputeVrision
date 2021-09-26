#include "ex.hpp"
using namespace std;
bool cmp(double x , double y);

Test::Test() {
	SrcImg.load_bmp("1.bmp");
}

Test::~Test() {}

void Test::Todisplay() {
	SrcImg.display("hw1");
}

CImg<unsigned char> Test::getSrcImg() {
	return SrcImg;
}
void Test::DrawTriangle_green() {
	cimg_forXY(SrcImg, x, y) {
		if (y > 60-15*sqrt(3)/3 && y < 60+30*sqrt(3)/3){
			if (x > (y + 50 * sqrt(3) - 60) / sqrt(3) && x < (y - 70 * sqrt(3) - 60) / (-1 * sqrt(3))) {
				SrcImg(x, y, 0) = 0;
				SrcImg(x, y, 1) = 255;
				SrcImg(x, y, 2) = 0;
			}
		}
	}
}

void Test::DrawCircle_yellow1() {
	cimg_forXY(SrcImg, x, y) {
		if (pow(pow(x-60,2)+pow(y-60,2),0.5) < 20) {
			SrcImg(x,y,0) = 255;
			SrcImg(x,y,1) = 255;
			SrcImg(x,y,2) = 0;
		}
	}
}

void Test::DrawLine1() {
	double x0 = 100*cos(45*pi/180);
	double y0 = 100*sin(45*pi/180);
	cimg_forXY(SrcImg, x, y) {
		if (x == 0) {
			if (y == 0) {
				SrcImg(x,y,0) = 255;
				SrcImg(x,y,1) = 0;
				SrcImg(x,y,2) = 0;
			}
		}
		else {
			if (cmp((double)y, (double)x*tan(45*pi/180)) && (double)x <= x0 && (double)y <= y0) {
				SrcImg(x,y,0) = 255;
				SrcImg(x,y,1) = 0;
				SrcImg(x,y,2) = 0;
			}
		}
	}
}

void Test::DrawCircle_yellow2() {
	unsigned char yellow[] = { 255, 255, 0 };
	SrcImg.draw_circle(60, 60, 20, yellow);
}
		
void Test::DrawLine2() {
	unsigned char red[] = {255,0,0};
	SrcImg.draw_line(0,0,100*cos(45*pi/180),100*sin(45*pi/180),red);
}

void Test::Rotate1(){
	SrcImg.rotate(15);
}

void Test::Rotate2(){
	SrcImg.rotate(30);
}

bool cmp(double x , double y) { //compare x and y，如果差值小于一定范围则近似相等
	if (abs(x - y) <= 0.5)
		return 1;
	return 0;
}
