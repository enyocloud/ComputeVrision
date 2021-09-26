#include "Hough.cpp"
//17343124 Îé±ó 2020.10.6
int main() {
	CImg<float> src("test/1.bmp");
	// args: src sigma gradient_threshold vote_threshold peak_dis
	Hough hough(src, 6.5f, 30, 500, 60);
	CImg<float> result = hough.houghProcess(src);
	result.display();
	result.save("result/1.bmp");
	return 0;
}
