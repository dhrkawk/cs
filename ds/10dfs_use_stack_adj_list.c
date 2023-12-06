#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct{
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType *s){
	s->top=-1;
}

int is_empty(StackType *s){
	if(s->top == -1){
		return 1;
	}
	else return 0;
}

int is_full(StackType *s){
	if(s->top == (MAX_STACK_SIZE-1)){
		return 1;
	}
	else return 0;
}

void push(StackType *s,element item){
	if(is_full(s)){
		fprintf(stderr,"스택 가득참");
		exit(1);
	}
	s->top ++;
	s->data[(s->top)]= item;
}

element pop(StackType *s){
	if(is_empty(s)){
		fprintf(stderr,"스택 빔");
		exit(1);
	}
	
	return s ->data[(s->top)--];
	
	//return s->data[(s->top)]; 
	//(s->top)-- 이렇게 값 반환하고 top을 줄이려고 했는데
	//return을 하면 함수가 끝난다..^^
}

////////////////////////////////////////////////////////////////////////////////////////////이하 dfs 코드



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

int visited[MAX_VERTICES];

void dfs_list(GraphType *g,int v){
	GraphNode *w;
	visited[v]= TRUE;
	printf("정점 %d -> ",v);
	for(w=g->adj_list[v];w;w=w->link){
		if(!visited[w->vertex]){
			dfs_list(g,w->vertex);
		}
	}
}

void dfs_iterative(GraphType *g,int v){
	StackType *s = (StackType*)malloc(sizeof(StackType));
	GraphNode *w;
	push(s,v);
	while(!is_empty(s)){
		v=pop(s);
		if(visited[v]!=TRUE){
			visited[v]=TRUE;
			printf("정점 %d -> ",v);
			for(w=g->adj_list[v];w;w=w->link){
				if(!visited[w->vertex]){
					push(s,w->vertex);
				}
			}
		}
	}
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
	
	printf("깊이 우선 탐색\n");
	dfs_iterative(g,0);
	printf("\n");
	
	free(g);
	return 0;
}
