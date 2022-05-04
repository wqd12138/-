#include<cmath>
#include"vect.h"//这个头文件包含了iostream头文件

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{

	 double const Rad_to_deg =45.0/atan(1.0);
	 void Vector::set_mag()
	 {
		mag = sqrt(x*x + y*y);//长度
	 }

	 void Vector::set_ang()
	 {
		 if (x==0.0&&y==0.0)
			ang = 0.0;
		 else
			ang =atan2(y,x);
	 }

	 void Vector::set_x()
	 {
		x = mag*cos(ang);
	 }

	 void Vector::set_y()
	 {
		y = mag*sin(ang);
	 }

	 Vector::Vector()
	 {
		x=y=mag=ang=0.0;
		mode =RECT;
	 }

	 Vector::Vector(double n1,double n2,Mode form)
	 {
		mode = form;
		if (form == POL)
		{
			x=n1;
			y=n2;
			set_mag();
			set_ang();
		}
		else if (form == RECT)
		{
			mag = n1;
			ang = n2/Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout<<"3rd argument is erro"<<std::endl;
			x=y=mag=ang=0.0;
			mode =RECT;
		}
	 }

	 void Vector::reset(double n1,double n2,Mode form )
	 {
		mode = form;
		if (form == POL)
		{
			x=n1;
			y=n2;
			set_mag();
			set_ang();
		}
		else if (form == RECT)
		{
			mag = n1;
			ang = n2/Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout<<"3rd argument is erro"<<std::endl;
			x=y=mag=ang=0.0;
			mode =RECT;
		}

	 }
	 Vector::~Vector()
	 {
	 
	 }

	 void Vector::polar_mode()
	 {
		mode = POL;
	 }

	 void Vector::rect_mode()
	 {
		mode = RECT;
	 }

	 Vector Vector::operator+(const Vector &v) const
	 {
		return Vector(this->x + v.x,this->y + v.y);
	 }

	 Vector Vector::operator-(const Vector &v) const
	 {
		return Vector(this->x - v.x,this->y - v.y);
	 }

	 Vector Vector::operator-() const
	 {
		return Vector(-x,-y);
	 }

	 Vector Vector::operator*(double n) const
	 {
		return Vector(n*x,n*y);
	 }

	  Vector operator*(double n,const Vector &v) //友元函数不需要加作用域限定符  const函数只针对成员函数
	 {
		return Vector(v*n);
	 }

	std::ostream &operator<<(std::ostream &os,const Vector &v)
	{
		if (v.mode==Vector::RECT)
		{
			os<<"(x,y) = ("<<v.x<< ", " <<v.y<< ")";
		}
		else if (v.mode == Vector::POL)
		{
			os<< "(m,a) = (" <<v.ang<<", "<<v.ang*Rad_to_deg<< ")";
		}
		else
			os<<"Vector object mode is invalid"<<std::endl;
		return os;
	}

}