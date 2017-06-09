//////VEC.cpp		 
//////Author:	YUNG-SHAN SU 
//////Date: 3/19 



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "VEC.h"
#include "COMPLEX.h"
VEC::VEC(int n){		// uninit constructor, val set to 0
	dim=n;
	val=(COMPLEX *)calloc(n,sizeof(COMPLEX));
}
VEC::VEC(const VEC &v1){	// copy constructor
	dim=v1.dim;
	val=(COMPLEX*)malloc(dim*sizeof(COMPLEX));
	for (int i=0;i<dim;i++){
		val[i]=v1.val[i];
	}
}

VEC::~VEC(){// destructor
	free(val);
}

int VEC::len(){// dimension of the vector
	return(dim);
}

VEC & VEC::operator=(const VEC &v1){ // assignment
	for (int i=0;i<v1.dim;i++)
		val[i]=v1.val[i];
	return *this;
}
VEC & VEC::operator=(double &a){ // assignment
	for (int i=0;i<dim;i++)
		val[i]=a;
	return *this;
}
VEC & VEC::operator+=(const VEC v1){// V += v1;
	for(int i=0;i<dim;i++)
		val[i]+=v1.val[i];
	return *this;
}
VEC & VEC::operator-=(const VEC v1){ // V -= v1;
	for(int i=0;i<dim;i++)
		val[i]-=v1.val[i];
	return *this;
}
VEC & VEC::operator*=(double a){ // V *= dbl;
	for(int i=0;i<dim;i++)
		val[i]*=a;
	return *this;
}
VEC & VEC::operator/=(double a){// V /= dbl;
	for(int i=0;i<dim;i++)
		val[i]/=a;
	return *this;
}
VEC VEC::operator+(const VEC &v1){ // V + v1
	VEC v2(*this);
	for(int i=0;i<v2.dim;i++)
		v2.val[i]+=v1.val[i];
	return v2; 
}
VEC VEC::operator-(const VEC &v1){ // V - v1
	VEC v2(*this);
	for(int i=0;i<v2.dim;i++)
		v2.val[i]-=v1.val[i];
	return v2; 
}
COMPLEX VEC::operator*(VEC &v1){// inner product
	COMPLEX sum(0,0);
	for (int i=0;i<dim;i++){
		sum+=val[i]*v1.val[i];
            
    }
	return sum;
} 
VEC VEC::operator*(double a){// V * dbl
	VEC v2(*this);
	for(int i=0;i<dim;i++)
		v2.val[i]*=a;
	return v2;
}
VEC VEC::operator/(double a){ // V / dbl
	VEC v2(*this);
	for(int i=0;i<dim;i++)
		v2.val[i]/=a;
	if (a==0)
		printf("your division have a problem: Divisor is 0");
	return v2;
}
COMPLEX & VEC::operator[](int n){ // indexing
	if (n<0) 
		n=0;
	else if (n>=dim) 
		n=dim-1;
	return val[n];
}
VEC operator*(double a,const VEC v1){
	VEC v2(v1);
	v2*=a;
	return v2;
}


void	VEC::print(){
	for(int i=0;i<dim;i++)
		val[i].print();
	printf("\n");
}
VEC VEC::absolute(){
	VEC v2(*this);
	double reg;
	for(int i=0;i<v2.len();i++){
		reg=v2[i].absolute();
		v2[i]=reg;
	}
	return v2;
}
