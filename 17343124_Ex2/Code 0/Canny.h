/*ʵ��canny��Ե����ԭ��ͨ����˵��������ɢ�����ݶȱƽ��������ݶ�ά�ҶȾ����ݶ�������Ѱ��ͼ��ҶȾ���
�ĻҶ�Ծ��λ�ã�Ȼ����ͼ���н���Щ�����������γ���ͼ��ı�Ե
һ���ͼ�����canny��Ե���Ҫ�������¼�����
1.��ͼ����лҶȻ�����Gimg = 0.299R+0.587G+0.114B
2.��ͼ����и�˹�˲�(��ȥͼƬ�������Ա�Ե����Ӱ��)
3.��һ��ƫ�������޲���������ݶȵķ�ֵ�ͷ���
4.���ݶȷ�ֵ���зǼ���ֵ����
5.˫��ֵ�������ӱ�Ե
*/

#ifndef CANNY_H_
#define CANNY_H_
#include <iostream>
#include "CImg.h"
#include <cmath>

using namespace std;
using namespace cimg_library;

class Canny {
private:
	CImg<int> img;
	int rows;
	int cols;
	int *smoothedim;
	int *delta_x;  //x�����һ�׵���
	int *delta_y;  //y�����һ�׵���
	float *dirim;  //�ݶȵķ���
	int *magnitude; //�ݶȵķ�ֵ
	int *nms;   //�Ǽ���ֵ���ƺ�õ�����
	int *edge;  //��Ե����
public:
	Canny();
	Canny(string name);
	~Canny();
	void RGBtoGray();
	void gaussian_smooth(float sigma);
	//����x,y�����һ�׵���
	void derrivative_x_y();
	//�����ݶ����ϵķ�������x��Ϊ��ʱ�뷽��ָ���Ļ���
	void radian_direction(int xdirtag, int ydirtag);
	//�����ݶȵķ�ֵ
	void magnitude_x_y();
	//���зǼ���ֵ����
	void non_max_supp();
	//˫��ֵ���
	void apply_hysteresis(float tlow, float thigh);
	//Ĭ�ϲ������ø�˹�˲���׼��Ϊ2.0������ֵΪ0.25������ֵΪ0.75
	CImg<int> canny_image();
	//�������л�ȡ���ı�Եͼ,sigma��ʾ��˹�˲��Ĳ�����tlow��thighΪ������ֵ
	CImg<int> canny_image(int sigma, float tlow, float thigh);
	//ѡ��������Ե��Ͻ��ľ�������
	CImg<int> canny_line(CImg<int> picture, int distance);
	//ɾ������С��20�ı�Ե��
	CImg<int> delete_line(CImg<int> picture);
	//��ʾͼ��
	void display();
	//��д����̵Ĳ���
	void test();
};

#endif
