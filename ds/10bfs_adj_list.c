#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct{
	element data[MAX_QUEUE_SIZE];
	int front;
	int rear;
}QueueType;

void error(char *message){
	fprintf(stderr,"%s\n",message);
	exit(1);
}

int is_empty(QueueType *q){
	if(q->front == q->rear) return 1;
	else return 0;
}


void init_queue(QueueType *q){
	q->front = q->rear = 0;
}


int is_full(QueueType *q){
	if((q->rear +1)%MAX_QUEUE_SIZE == q->front) return 1;
	else return 0;
}

void enqueue(QueueType *q,element item){
	if(is_full(q)){
		error("큐가 가득 참");
		exit(1);
	}
	q->rear = (q->rear +1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType *q){
	if(is_empty(q)){
		error("큐가 빔");
		return -1;
	}
	q->front = (q->front +1) % MAX_QUEUE_SIZE;
	element item = q->data[(q->front)];	
	return item;
}

/////////////////////////////////////////////////////////////////////아래로 인접행렬 그래프
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


void bfs_list(GraphType *g,int v){
	GraphNode *w;
	QueueType *q=(QueueType*)malloc(sizeof(QueueType));
	init_queue(q);
	visited[v] = TRUE;
	printf("%d 방문 -> ",v);
	enqueue(q,v);
	while(!is_empty(q)){
		v=dequeue(q);
		for(w=g->adj_list[v];w;w=w->link){
			if(!visited[w->vertex]=TRUE){
				visited[w->vertex] = TRUE;
				printf("%d 방문 -> ",w->vertex);
				enqueue(q,w->vertex);
			}
		}
	}
}

int main(){
	GraphType *g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for(int i=0; i<6; i++){
		insert_vertex(g,i);
	}
	insert_edge(g,0,2);
	insert_edge(g,2,1);
	insert_edge(g,2,3);
	insert_edge(g,0,4);
	insert_edge(g,4,5);
	insert_edge(g,1,5);
	
	printf("너비 우선 탐색\n");
	bfs_list(g,0);
	printf("\n");
	free(g);
	return 0;
}
