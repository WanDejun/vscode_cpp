#include <cstdio>
#include <conio.h>
#include <cmath>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

const double Pi=3.14159;

//取点样参数
const int A_DIV=20;
const int B_DIV=80;
const double DA=2*Pi/A_DIV;
const double DB=2*Pi/B_DIV;

//旋转参数
const int a1_DIV=25;
const int a2_DIV=25;

//打印参数
const double XMIN=-3.5;
const double XMAX=3.5;
const double YMIN=-3.5;
const double YMAX=3.5;
const int ROW=30;
const int COL=60;
const int PIXDEP=7;
const char pix[]=" .,o0#@";
double graph[ROW][COL];

struct vector3d {
	double x, y, z;
	
	vector3d(){}
	vector3d(double _x, double _y, double _z): x(_x), y(_y), z(_z) {}
	
	/// 旋转, U' :a  , L' : b  (Pi/180 rad)
	vector3d rotate(double a, double b) {
		a=a*Pi/180;
		b=b*Pi/180;
		static double sa,sb,ca,cb;
		sa=sin(a);
		ca=cos(a);
		sb=sin(b);
		cb=cos(b);
		return vector3d (
			x*(ca)  + y*(-sa*cb)  + z*(-sa*sb) ,
			x*(sa)  + y*(ca*cb)   + z*(ca*sb)  ,
			0       + y*(-sb)     + z*(cb)
		);
	}
	
	/// 甜甜圈该点法向量 
	vector3d normalVector() {
		return vector3d (
			x-(x+x)/sqrt(x*x+y*y),
			y-(y+y)/sqrt(x*x+y*y),
			z
		);
	}
	
	/// 模 
	double norm() {
		return sqrt(x*x+y*y+z*z);
	}
	
	/// cos(夹角) 
	friend double angle(vector3d &P, vector3d &Q) {
		return (P.x*Q.x + P.y*Q.y + P.z*Q.z)/(P.norm()+Q.norm());
	}
};

int main() {
	
	vector<vector3d> pointSamples;
	
	// 取点样 
	for (int i=0; i<A_DIV; i++) {
		for (int j=0; j<B_DIV; j++) {
			pointSamples.emplace_back(vector3d( cos(i*DA)*(2+cos(j*DB)), sin(i*DA)*(2+cos(j*DB)), sin(j*DB)));
		}
	}
	
	
	int a1=0, a2=0, opr;
	vector3d tmp, tmpN, light(0,0,1);
	int indexCol,indexRow;
	double ang;
	while (1) {
		// 输入 
		opr=getch();
		if (opr=='d')
			a1=(a1+1)%a1_DIV;
		else if (opr=='a')
			a1=(a1-1+a1_DIV)%a1_DIV;
		else if (opr=='w')
			a2=(a2+1)%a2_DIV;
		else if (opr=='s')
			a2=(a2-1+a2_DIV)%a2_DIV;
		
		// 渲染
		for (int i=0; i<ROW; i++)
			for (int j=0; j<COL; j++)
				graph[i][j]=0;
		for (vector3d &I: pointSamples) {
			tmp=I.rotate(a1*360/a1_DIV, a2*360/a2_DIV);
			tmpN=I.normalVector().rotate(a1*360/a1_DIV, a2*360/a2_DIV);
			if (tmp.x>=XMIN && tmp.x<=XMAX)
				indexCol=int((tmp.x-XMIN)/((XMAX-XMIN)/COL));
			else continue;
			
			if (tmp.y>=YMIN && tmp.y<=YMAX)
				indexRow=int((tmp.y-YMIN)/((YMAX-YMIN)/ROW));
			else
				continue;
			
			if (tmpN.z>0) {
				ang=angle(tmpN, light);
				graph[indexRow][indexCol]+=max(ang,0.0);
			}
		}
		
		
		// 打印 
		for (int i=0; i<ROW; i++) {
			putchar('\n');
			for (int j=0; j<COL; j++) {
				putchar(pix[min(PIXDEP-1,int(graph[i][j]/(1.5/PIXDEP)))]);
			}
		}
		
		//break;
	}
	 
	
	return 0;
}
