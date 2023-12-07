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

int visited[MAX_VERTICES];

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

void bfs_mat(GraphType *g,int v){
	int w;
	QueueType *q = (QueueType*)malloc(sizeof(QueueType));
	init_queue(q);
	
	visited[v]= TRUE;
	printf("%d 방문 -> ",v);
	enqueue(q,v);
	
	while(!is_empty(q)){
		v= dequeue(q);
		for(w=0;w<g->n;w++){
			if(g->adj_mat[v][w] && !visited[w]){
				visited[w] = TRUE;
				printf("%d 방문 -> ",w);
				enqueue(q,w);
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
	bfs_mat(g,0);
	printf("\n");
	free(g);
	return 0;
}
