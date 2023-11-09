#include <stdio.h>

int binomial(int n,int k){
	if(k==0 || k==n) return 1;
	else  return binomial(n-1,k-1)+binomial(n-1,k);
}

int factorial(int n){
	int result=1;
	for(int i=1;i<=n;i++){
		result *= i;
	}
	return result;
}

int main(void){
	int output;
	int n=5; 
	int k=2;
	output = factorial(n)/(factorial(k)*factorial(n-k));
	printf("%d\n",output);
	return 0;
}
