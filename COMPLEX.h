//////COMPLEX.h	 
//////Author:	YUNG-SHAN SU 
//////Date: 6/7



#ifndef COMPLEX_H
#define COMPLEX_H

class COMPLEX {
	private:
		double real_part; // array to store vector
		double imaginary_part;
	public:
		COMPLEX(double re,double im); // uninit constructor, val set to 0
		~COMPLEX(); // destructor
		double real();
		double imaginary();
		COMPLEX conjugate();
		COMPLEX &operator=(COMPLEX v1); // assignment
		COMPLEX &operator=(double &a); // assignment
		COMPLEX &operator+=(COMPLEX v1); // V += v1;
		COMPLEX &operator+=(double &a); // V += v1;
		COMPLEX &operator-=(COMPLEX v1); // V -= v1;
		COMPLEX &operator-=(double &a); // V -= v1;	
		COMPLEX &operator*=(double &a); // V *= dbl;
		COMPLEX &operator*=(COMPLEX v1); // V -= v1;
		COMPLEX &operator/=(double &a); // V /= dbl;
		COMPLEX &operator/=(COMPLEX v1); // V -= v1;

		COMPLEX operator+(COMPLEX v1); // V + v1
		COMPLEX operator-(COMPLEX v1); // V - v1
		COMPLEX operator*(COMPLEX v1); // inner product
		COMPLEX operator/(COMPLEX v1); // inner product
		COMPLEX operator*(double a); // V * dbl
		COMPLEX operator/(double a); // V / dbl
		
		double absolute();		//absolute(vector)
		void	print();
		friend COMPLEX operator*(double a,COMPLEX v1); // dbl x V

};

#endif	
