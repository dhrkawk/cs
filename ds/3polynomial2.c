#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct{
	int row;
	int col;
	int value;
}element;

typedef struct{
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms;
}SparseMatrix;

SparseMatrix matrix_transpose(SparseMatrix a){
	SparseMatrix b;
	
	int bindex;
	b.rows = a.rows;
	b.cols = a.cols;
	b.terms = a.terms;
	
	if(a.terms>0){
		bindex=0;
		for(int n=0;n<a.cols;n++){  // 기존 행렬의 열이 행으로 바뀌니까 열기준
			for(int i=0; i<a.terms; i++){ // 0이 아닌 항의 개수만큼
				if(a.data[i].col == n){ 
                // 열기준으로 같은 값이 있으면 새 행렬에 넣자
					b.data[bindex].row= a.data[i].col;
					b.data[bindex].col= a.data[i].row;
					b.data[bindex].value= a.data[i].value;
					bindex++;
				}
			}
		}
	}
	return b;
}

void matrix_print(SparseMatrix a){
	printf("================\n");
	for(int i=0; i<a.terms;i++){
		printf("%d %d %d\n",a.data[i].row, a.data[i].col,a.data[i].value);
	}
	printf("================\n");
}

int main(){
<<<<<<< HEAD:src/main.c
	SparseMatrix m = {
		{{0,3,7},{1,0,9},{1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2}},
		6,
		6,
		7
	};
	SparseMatrix result;
	
	result = matrix_transpose(m);
	matrix_print(result);
}
=======
	int As=0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
	poly_add2(As,Ae,Bs,Be,&Cs,&Ce);
	printf("%d %d %d %d %d %d\n",As,Ae,Bs,Be,Cs,Ce);
	print_poly(As,Ae);
	print_poly(Bs,Be);
	printf("----------------------\n");
	print_poly(Cs,Ce);
	return 0;
}
>>>>>>> d0d2160aa4c9182d403cc07e1c30fa9e28226c7b:ds/3polynomial2.c
