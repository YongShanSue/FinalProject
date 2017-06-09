//////COMPLEX.cpp		 
//////Author:	YUNG-SHAN SU 
//////Date: 6/7 



#include <stdio.h>
#include <stdlib.h>
#include "COMPLEX.h"
#include <math.h>


COMPLEX::COMPLEX(double re,double im){
	real_part=re;
	imaginary_part=im;
}
COMPLEX::~COMPLEX(){
	return;
}
double COMPLEX::real(){

	return real_part;
}
double COMPLEX::imaginary(){
	return imaginary_part;
}
COMPLEX COMPLEX::conjugate(){
	imaginary_part=-1.0*imaginary_part;
	COMPLEX a(*this);
	imaginary_part=-1.0*imaginary_part;
	return a;
}

COMPLEX & COMPLEX::operator=(COMPLEX v1){
	real_part=v1.real();
	imaginary_part=v1.imaginary();
	return *this;
} // assignment
COMPLEX & COMPLEX::operator=(double &a){
	real_part=a;
	imaginary_part=0;
	return *this;
}// assignment

COMPLEX &COMPLEX::operator+=(COMPLEX v1){// V += v1;
	real_part+=v1.real();
	imaginary_part+=v1.imaginary();
	return *this;
}
COMPLEX &COMPLEX::operator+=(double &a){// V += v1;
	real_part+=a;
	return *this;
}
COMPLEX &COMPLEX::operator-=(COMPLEX v1){// V += v1;
	real_part-=v1.real();
	imaginary_part-=v1.imaginary();
	return *this;
}
COMPLEX &COMPLEX::operator-=(double &a){// V += v1;
	real_part-=a;
	return *this;
}
COMPLEX &COMPLEX::operator*=(COMPLEX v1){// V += v1;
	double a=imaginary_part*v1.real()+real_part*v1.imaginary();
	double b=real_part*v1.real()-imaginary_part*v1.imaginary();
	real_part=b;
	imaginary_part=a;
	return *this;
}
COMPLEX &COMPLEX::operator*=(double &a){// V += v1;
	real_part*=a;
	imaginary_part*=a;
	return *this;
}
COMPLEX &COMPLEX::operator/=(COMPLEX v1){// V += v1;
	COMPLEX v1_conjugate=v1.conjugate();
	COMPLEX reg=v1*(v1_conjugate);
	double divisor=reg.real();

	(*this)=((*this)*v1_conjugate)/divisor;
	return *this;
}
COMPLEX &COMPLEX::operator/=(double &a){// V += v1;
	real_part /=a;
	imaginary_part /=a;
	return *this;
}
COMPLEX COMPLEX::operator+(COMPLEX v1){// V + v1
	COMPLEX v(*this);
	v+=v1;
	return v;
}
COMPLEX COMPLEX::operator-(COMPLEX v1){// V - v1
	COMPLEX v(*this);
	v-=v1;
	return v;
}
COMPLEX COMPLEX::operator*(COMPLEX v1){// V - v1
	COMPLEX v(*this);
	v*=v1;
	return v;
}
COMPLEX COMPLEX::operator*(double a){// V - v1
	COMPLEX v(*this);
	v*=a;
	return v;
}
COMPLEX COMPLEX::operator/(COMPLEX v1){// V - v1
	COMPLEX v(*this);
	v/=v1;
	return v;
}
COMPLEX COMPLEX::operator/(double a){// V - v1
	COMPLEX v(*this);
	v/=a;
	return v;
}
double COMPLEX::absolute(){
	double sum=0;
	sum=sqrt(real_part*real_part+imaginary_part*imaginary_part);
	return sum;
}	//absolute(vector)
void	COMPLEX::print(){
	printf("%g +%gi\t",real_part,imaginary_part);
	//printf("%g\t",real_part);
}
COMPLEX operator*(double a,COMPLEX v1){
	COMPLEX v2(v1);
	v2*=a;
	return v2;
} // dbl x V	


