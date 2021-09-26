#ifndef _EX_HPP_
#define _EX_HPP_
#include "CImg.h"
#include <cmath>
#include <string>
using namespace std;
using namespace cimg_library;
const double pi(3.14159265);
class Test
{
	public:
		Test();
		~Test();
		void Todisplay();
	//不调用CImg接口函数 
		void DrawTriangle_green();
		void DrawCircle_yellow1();
		void DrawLine1();
		
	//调用CImg接口函数 
		void DrawCircle_yellow2();
		void DrawLine2();
		void Rotate1();
		void Rotate2();
		
		CImg<unsigned char> getSrcImg();
	private:
		CImg<unsigned char> SrcImg; 
};
#endif
