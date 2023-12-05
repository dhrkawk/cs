#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

typedef struct GraphType{
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

void init(GraphType *g){
	g->n =0;
	for(int r=0; r<MAX_VERTICES;r++){
		for(int c=0; c<MAX_VERTICES;c++){
			g->adj_mat[r][c]=0;
		}
	}
}

void insert_vertex(GraphType *g,int v){
	if((g->n)+1 >MAX_VERTICES){
		fprintf(stderr,"그래프 정점 개수 초과");
		return;
	}
	g->n++;
}
void insert_edge(GraphType *g,int start, int end){
	if(start >= g->n||end>=g->n){
		fprintf(stderr,"정점 번호 오류");
	}
	g->adj_mat[start][end]=1;
	g->adj_mat[end][start]=1;
}

void print_adj_mat(GraphType *g){
	for(int i=0; i< g->n; i++){
		for(int j=0; j<g->n;j++){
			printf("%2d ",g->adj_mat[i][j]);
		}
		printf("\n");
	}
}

int get_degree(GraphType *g,int v){
	int count=0;
	for(int j=0;j<g->n;j++){
		if(g->adj_mat[v][j]==1){
			count++;
		}
	}
	return count;
}

int main(){
	GraphType *g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for(int i=0;i<4;i++){
		insert_vertex(g,i);
	}
	insert_edge(g,0,1);
	insert_edge(g,0,2);
	insert_edge(g,0,3);
	insert_edge(g,1,2);
	insert_edge(g,2,3);
	print_adj_mat(g);

	printf("0의 차수는 %d\n",get_degree(g,0));
	printf("1의 차수는 %d\n",get_degree(g,1));
	
	free(g);
	return 0;
}

