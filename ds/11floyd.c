#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define TRUE 1
#define FALSE 0
#define INF 1000000

int A[MAX_VERTICES][MAX_VERTICES];


typedef struct GraphType {
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;


void print_A(GraphType *g){
	printf("======================\n");
	for(int i=0;i<g->n;i++){
		for(int j=0;j<g->n;j++){
			if(A[i][j]==INF) printf(" * ");
			else printf("%3d ",A[i][j]);
		}
		printf("\n");
	}
}

void floyd(GraphType *g){
	int i,j,k;
	for(i =0; i<g->n;i++){
		for(j=0; j<g->n;j++){
			A[i][j] = g->weight[i][j];
		}
	}
	print_A(g); // 가중치들을 A-1에 넣어주기
	
	for(k=0; k<g->n; k++){
		for(int i=0; i<g->n; i++){
			for(int j=0; j<g->n; j++){
				if(A[i][k]+A[k][j]<A[i][j]){
					A[i][j] = A[i][k] + A[k][j];
				}
			}
		}
		print_A(g);
	}
	
}


int main() {
    GraphType g ={7,{{0,7,INF,INF,3,10,INF},
					 {7,0,4,10,2,6,INF},
					 {INF,4,0,2,INF,INF,INF},
					 {INF,10,2,0,11,9,4},
					 {3,2,INF,11,0,INF,5},
					 {10,6,INF,9,INF,0,INF},
					 {INF,INF,INF,4,5,INF,0}}
				 };
	floyd(&g);
	
    return 0;
}
