#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

typedef struct GraphNode{
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType{
	int n;
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

void init(GraphType *g){
	g->n =0;
	for(int v=0; v<MAX_VERTICES;v++){
		g->adj_list[v]=NULL;
	}
}

void insert_vertex(GraphType *g,int v){
	if((g->n)+1 >MAX_VERTICES){
		fprintf(stderr,"그래프 정점 개수 초과");
		return;
	}
	g->n++;
}
void insert_edge(GraphType *g,int u, int v){
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	if(u >= g->n || v>=g->n){
		fprintf(stderr,"정점 번호 오류");
	}
	node->vertex =v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node; // 리스트의 처음에 삽입
	
}

void print_adj_mat(GraphType *g){
	for(int i=0; i< g->n; i++){
		GraphNode *p = g->adj_list[i];
		printf("정점 %d의 인접 리스트",i);
		while(p!=NULL){
			printf("-> %d", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

int get_degree(GraphType* g, int v){
	GraphNode *n = g->adj_list[v];
	int count=0;
	while(n!=NULL){
		count++;
		n = n->link;
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
	insert_edge(g,1,0);
	insert_edge(g,0,2);
	insert_edge(g,2,0);
	insert_edge(g,0,3);
	insert_edge(g,3,0);
	insert_edge(g,1,2);
	insert_edge(g,2,1);
	insert_edge(g,2,3);
	insert_edge(g,3,2);
	print_adj_mat(g);
	
	printf("1의 차수는 %d\n",get_degree(g,1));
	printf("2의 차수는 %d\n",get_degree(g,2));
	
	free(g);
	return 0;
}

