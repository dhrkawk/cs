#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0

typedef struct GraphNode{
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType{
	int n;
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

void init_graph(GraphType *g){
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

//===================================================== stack code
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
}

int topo_sort(GraphType *g){
	int i;
	StackType s;
	GraphNode *node;
	
	int *in_degree = (int*)malloc(g->n * sizeof(int));
	for(i=0; i<g->n;i++){
		in_degree[i]=0;
	} // 배열 초기화
	for(i =0; i<g->n; i++){
		GraphNode *node = g->adj_list[i];
		while(node != NULL){
			in_degree[node->vertex]++;
			node = node->link;
		}
	} // 각 노드에 들어오는 간선 수 만큼 ++
	
	init_stack(&s);
	for(i=0; i<g->n; i++){
		if(in_degree[i]==0) push(&s,i);
	}
	
	while(!is_empty(&s)){
		int w;
		w = pop(&s);
		printf("정점 %d -> ",w);
		node = g->adj_list[w];
		while(node !=NULL){
			int u = node->vertex;
			in_degree[u]--;
			if(in_degree[u]==0) push(&s,u);
			node = node->link;
		}
	}
	free(in_degree);
	printf("\n");
	return (i == g->n);
	
}

int main(){
	GraphType *g = (GraphType*)malloc(sizeof(GraphType));
	init_graph(g);
	
	for(int i=0;i<6;i++){
		insert_vertex(g,i);
	}
	insert_edge(g,0,2);
	insert_edge(g,0,3);
	insert_edge(g,1,3);
	insert_edge(g,1,4);
	insert_edge(g,2,3);
	insert_edge(g,2,5);
	insert_edge(g,3,5);
	insert_edge(g,4,5);
	
	topo_sort(g);
	
	return 0;
}