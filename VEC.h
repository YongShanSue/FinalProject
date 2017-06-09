//////VEC.h	 
//////Author:	YUNG-SHAN SU 
//////Date: 3/19 



#ifndef VEC_H
#define VEC_H
#include "COMPLEX.h"
class VEC {
	private:
		int dim; // vector length
		COMPLEX *val; // array to store vector
	public:
		VEC(int n); // uninit constructor, val set to 0
		VEC(const VEC &v1); // copy constructor
		~VEC(); // destructor
		int len(); // dimension of the vector
		VEC &operator=(const VEC &v1); // assignment
		VEC &operator=(double &a); // assignment
		VEC &operator=(const COMPLEX &a); // assignment
		VEC &operator+=(const VEC v1); // V += v1;
		VEC &operator-=(const VEC v1); // V -= v1;
		VEC &operator*=(double a); // V *= dbl;
		VEC &operator/=(double a); // V /= dbl;
		VEC operator+(const VEC &v1); // V + v1
		VEC operator-(const VEC &v1); // V - v1
		COMPLEX operator*(VEC &v1); // inner product
		VEC operator*(double a); // V * dbl
		VEC operator/(double a); // V / dbl
		VEC absolute();		//absolute(vector)
		COMPLEX &operator[](int n); // indexing
		void	print();
	friend VEC operator*(double a,const VEC v1); // dbl x V
	
};
VEC operator*(double a,const VEC v1);
VEC *newVEC(int n); // create dynamic VEC
//
#endif	
