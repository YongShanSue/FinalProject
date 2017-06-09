
//////HW12.cpp		 
//////Author:	YUNG-SHAN SU 
//////Date: 5/22


#include<stdio.h>
#include<stdlib.h>
#include"VEC.h"
#include<math.h>
#include<sys/time.h>
#include <string> 
using namespace std; 
#define MAXITER 100000
#define ERROR_ENDURE 0.000000001
void Newton_Horner(int degree, VEC & answer,VEC &polynomial, int maxiter, double error_endure, COMPLEX initial_x);
void Linquadric(int degree, VEC & answer,VEC &polynomial, int maxiter, double error_endure, COMPLEX initial_x);
void Bairstow(int degree, VEC & answer,VEC &polynomial, int maxiter, double error_endure, COMPLEX initial_x);
VEC check_answer(int degree,VEC answer,VEC polynomial);
VEC solve_2_polynominial(double p,double q);
int main(int argc,char **argv){
	FILE *fPtr;
	string filename;
	if ( argc != 2 )	
		filename="ta1.dat";
	else
		filename=argv[1];
	fPtr = fopen(filename.c_str(), "r");
	if (!fPtr) {
        printf("Error\n");
        exit(1);
    }
    int degree;   
    fscanf(fPtr, "%d\n", &degree);
    printf("Degree: %d\n",degree);
    VEC equa(degree+1);
    double reg;
    int poly;
    for(int i=0;i<=degree;i++){
    	fscanf(fPtr,"%lf x^%d\n",&reg,&poly);
    	equa[i]=reg;
    }
    printf("Polynomial Cofficient:\t" );
    equa.print();   
    COMPLEX initial_x(0,-2);
    VEC answer(degree);
    //Newton_Honner
    
    printf("\nNewton_Honner\n");
    Newton_Horner(degree, answer,equa,MAXITER,ERROR_ENDURE, initial_x);
    printf("Answer:\t" );
    answer.print();
    VEC answer_error=check_answer(degree,answer,equa);
    printf("Error:\t");
    answer_error.print();
    
    //Linquadric
    printf("\nLinquadric\n");
    Linquadric(degree, answer,equa,MAXITER,ERROR_ENDURE, initial_x);
    printf("Answer:\t" );
    answer.print();
     answer_error=check_answer(degree,answer,equa);
    printf("Error:\t");
    answer_error.print();

    //Linquadric
    printf("\nBairstow\n");
    Bairstow(degree, answer,equa,MAXITER,ERROR_ENDURE, initial_x);
    printf("Answer:\t" );
    answer.print();
     answer_error=check_answer(degree,answer,equa);
    printf("Error:\t");
    answer_error.print();
    
    return 0;
}	

void Newton_Horner(int degree, VEC & answer,VEC &polynomial, int maxiter, double error_endure, COMPLEX initial_x){
	int n=degree;
	VEC poly(polynomial);
	COMPLEX x_guess(initial_x);
	int count=0;
	while(n>=1){
		double error=1+error_endure;
		int iter_num=0;
		VEC b(n+2);
		VEC c(n+2);
		while((error>=error_endure) && (iter_num<maxiter)){
			
			b[1]=poly[0];
			c[2]=b[1];
			for(int i=2;i<n+2;i++){
				COMPLEX reg= (x_guess*b[i-1]);
				b[i] = poly[i-1] + reg;
			}
			for(int i=3;i<n+2;i++){
				COMPLEX reg = (x_guess*c[i-1]);
				c[i] = b[i-1] + reg;
			}
			COMPLEX reg= (b[n+1]/c[n+1]);
			//printf("%d\t",iter_num);b[n+1].print();c[n+1].print();(b[n+1]/c[n+1]).print();printf("\n");
			x_guess = x_guess - reg;
			error=b[n+1].absolute();
			iter_num++;
			count++;
		}
		//printf("Iteration Number:\t%d\n",iter_num);
		answer[degree-n]=x_guess;
		VEC reg(n);
		poly=reg;
		for(int j=0;j<n;j++)
			poly[j]=b[j+1];
		n=n-1;
	}
	printf("IterationSum\t%d\n",count);
}
void Linquadric(int degree, VEC & answer,VEC &polynomial, int maxiter, double error_endure, COMPLEX initial_x){
	int n=degree;
	VEC poly(polynomial);
	COMPLEX x_guess(initial_x);
	COMPLEX p=(poly[n-1]/poly[n-2]);
	COMPLEX q=(poly[n]/poly[n-2]);
	COMPLEX R(0,0);
	COMPLEX S(0,0);
	COMPLEX one(1,0);
	double zero;
	int count=0;
	while(n>=2){
		double error=1+error_endure;
		int iter_num=0;
		p=(poly[n-1]/poly[n-2]);
		q=(poly[n]/poly[n-2]);
		VEC b(n+1);
		///////////Polynomial Process
		R=R+one;
		S=S+one;
		while((S.absolute()>=error_endure) &&(R.absolute()>=error_endure) && (iter_num<maxiter)){
			b[0]=zero;
			b[1]=zero;
			for(int i=2;i<n+1;i++){
				b[i]=poly[i-2] - p*b[i-1] - q*b[i-2];
			}
			R=poly[n-1]-p*b[n]-q*b[n-1];
			S=poly[n]-q*b[n];
			
			p=p+R/(b[n].real());
			q=q+S/(b[n].real());
			//R.print();S.print();p.print();q.print();printf("\n");
			iter_num++;
			count++;

		}
		//printf("Iteration Number:\t%d\n",iter_num);
		//p.print();q.print();printf("\n");
		VEC ansreg=solve_2_polynominial(p.real(),q.real());
		answer[degree-n]=ansreg[0];
		answer[degree-n+1]=ansreg[1];
		VEC reg(n-1);
		poly=reg;
		n=n-2;
		for(int j=0;j<n+1;j++)
			poly[j]=b[j+2];
		if(n==1){
			answer[degree-1]=-1.0*b[n+2]/b[n+1];
		}
	}
	printf("IterationSum\t%d\n",count);
	
}
void Bairstow(int degree, VEC & answer,VEC &polynomial, int maxiter, double error_endure, COMPLEX initial_x){
	int n=degree;
	VEC poly(polynomial);
	COMPLEX x_guess(initial_x);
	COMPLEX p(0,0);
	COMPLEX q(0,0);
	COMPLEX R(0,0);
	COMPLEX S(0,0);
	COMPLEX one(1,0);
	COMPLEX zero(0,0);
	int count=0;
	while(n>=2){
		double error=1+error_endure;
		int iter_num=0;
		p=zero;
		q=zero;
		//p.print();
		//q.print();
		VEC b(n+1);
		VEC c(n+1);
		VEC d(n+1);
		///////////Polynomial Process
		R=R+one;
		S=S+one;
		while((S.absolute()>=error_endure) &&(R.absolute()>=error_endure) && (iter_num<maxiter)){
			b[2]=poly[0];
			b[3]=poly[1]-p*b[2];
			for(int i=4;i<n+1;i++){
				b[i]=poly[i-2] - p*b[i-1] - q*b[i-2];
			}
			R=poly[n-1]-p*b[n]-q*b[n-1];
			S=poly[n]-q*b[n];
			//R.print();S.print();printf("\n");
			c[2]=zero;
			c[3]=-1.0*b[2]-p*c[2];
			for(int i=4;i<n+1;i++){
				c[i]=-1.0*b[i-1] - p*c[i-1] - q*c[i-2];
			}
			COMPLEX derivative_Rp=-1.0*b[n]-p*c[n]-q*c[n-1];
			COMPLEX derivative_Sp=-1.0*q*c[n];
			d[2]=zero;
			d[3]=-1.0*p*d[2];
			for(int i=4;i<n+1;i++){
				d[i]=-1.0*p*d[i-1] - b[i-2] -q*d[i-2];
			}
			COMPLEX derivative_Rq=-1.0*p*d[n] -b[n-1] -q*d[n-1];
			COMPLEX derivative_Sq=-1.0*b[n] -q*d[n];
			COMPLEX deter=(derivative_Rp*derivative_Sq)-(derivative_Sp*derivative_Rq);
			p=p-(derivative_Sq*R-derivative_Rq*S)/deter;
			q=q-(-1.0*derivative_Sp*R+derivative_Rp*S)/deter;
			//R.print();S.print();p.print();q.print();printf("\n");
			iter_num++;
			count++;
		}
		//printf("Iteration Number:\t%d\n",iter_num);
		//p.print();q.print();printf("\n");
		VEC ansreg=solve_2_polynominial(p.real(),q.real());
		answer[degree-n]=ansreg[0];
		answer[degree-n+1]=ansreg[1];
		VEC reg(n-1);
		poly=reg;
		n=n-2;
		for(int j=0;j<n+1;j++)
			poly[j]=b[j+2];
		if(n==1){
			answer[degree-1]=-1.0*b[n+2]/b[n+1];
		}
	}
	printf("IterationSum\t%d\n",count);
}
VEC check_answer(int degree,VEC answer,VEC polynomial){
	VEC error(degree);
	error=0;
	for(int a=0;a<degree;a++){
		for(int i=0;i<degree+1;i++){
			COMPLEX reg(polynomial[i]);
			for(int count=0;count < degree-i;count++){
				reg*=answer[a];
			}
			error[a]+=reg;
		}
	}
	
	return error.absolute();
}
VEC solve_2_polynominial(double p,double q){
	VEC ans(2);
	if(p*p-4*q>=0){
		//printf("Discriminant: %f\n",p*p-4*q);
		COMPLEX reg1((-1.0*p+sqrt(p*p-4*q))/2.0,0);
		ans[0]=reg1;
		COMPLEX reg2((-1.0*p-sqrt(p*p-4*q))/2.0,0);
		ans[1]=reg2;
	}
	else{
		COMPLEX reg1( ((-1.0*p)/2.0),sqrt(-p*p+4*q)/2.0 );
		ans[0]=reg1;
		COMPLEX reg2(((-1.0*p)/2.0),-1.0*sqrt(-p*p+4*q)/2.0 );
		ans[1]=reg2;
	}
	return ans;
}