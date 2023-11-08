#include <stdio.h>
#define MAX(a,b) (((a)>(b)?(a):(b)))
#define MAX_DEGREE 101
typedef struct{
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

int start= 0; // 두 다항식의 최고차항의 계수 합이 0이 아닌 차수까지 이동시켜주는 포인터

polynomial poly_add1(polynomial A,polynomial B){
	polynomial C;
	int Apos=0; 
	int Bpos=0; 
	int Cpos=0;
	int degree_a = A.degree;
	int degree_b = B.degree;
	int Apointer = A.degree; // 최고차항을 가르키는 포인터
	
	C.degree = MAX(A.degree,B.degree);
	
	while(Apos<=A.degree && Bpos<=B.degree){
		if(degree_a>degree_b){
			C.coef[Cpos++]=A.coef[Apos++];
			degree_a--;
		}
		else if(degree_a == degree_b){ // 두 다항식 둘다
			if(degree_a==Apointer){ // 최고차항이라면
				if(A.coef[start]+B.coef[start]==0){ //최고차항의 계수의 합이 0인지 확인
					start++; // 포인터를 옮겨준다
					Apointer--;
				}
			}
		
			C.coef[Cpos++]= A.coef[Apos++] + B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else{
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void print_poly(polynomial p){
	for(int i=start;i<p.degree;i++){ // 포인터 위치부터 출력을 시작해준다
		printf("%3.lfx^%d + ",p.coef[i],p.degree-i);
	}
	
	printf("%3.lf\n",p.coef[p.degree]);
}

int main(){
	polynomial a= {4,{6,0,0,0,10}};
	polynomial b= {4,{-6,0,5,0,1}};
	polynomial c;
	
	print_poly(a);
	print_poly(b);
	c= poly_add1(a,b);
	printf("-------------------------------\n");
	print_poly(c);
	return 0;
}
