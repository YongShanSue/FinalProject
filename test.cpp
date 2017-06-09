
//////HW12.cpp		 
//////Author:	YUNG-SHAN SU 
//////Date: 5/22


#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include"COMPLEX.h"
#include<math.h>
#include<sys/time.h>
#define R 1
#define L 1
#define C 1
#define V 1


int main(int argc,char **argv){
	COMPLEX test(2,1);
	COMPLEX test1(5,-3);
	test.print();
	test1.print();
	test1+=test;
	test1.print();
	test1-=test;
	test1.print();
	test1*=test;
	test1.print();
	COMPLEX test2(0,0);
	test2=test+test;
	test2.print();
	test2=test-test;
	test2.print();
	test2=test*test;
	test2.print();
	test2=test*test;
	test2.print();
}	


