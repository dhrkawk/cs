#include <stdio.h>


//3-4
int main(){
	int two[10];
	for(int i=0; i<10;i++){
		two[i]=1;
	}
	for(int j=1;j<10;j++){
		two[j] = two[j-1]*2;
	}
}


//3-5
struct person{
    char name[10];
    int age;
    float wage;
}

//3-6
typedef struct{
    float real;
    float imaginary;
}complex;

complex c1,c2;

//3-7
Complex complex_add(Complex a, Complex b){
    Complex c;
    c.real = a.real + b.real;
    c.imaginary = a.imaginary + b. imaginary;
    return c;
}