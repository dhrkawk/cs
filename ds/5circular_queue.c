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

void queue_print(QueueType *q){
	printf("QUEUE(front=%d rear=%d) = ", q->front,q->rear);
	if(!is_empty(q)){
		int i= q->front;
		do{
			i=(i+1)%MAX_QUEUE_SIZE;
			printf("%d | ",q->data[i]);
			if(i==q->rear) break;
		}while(i != q->front);
	}
	printf("\n");
}


int main(){
	QueueType q;
	init_queue(&q);
	element a;
	printf("---데이터 추가 단계---\n");
	while(!is_full(&q)){
		printf("정수를 입력하시오: ");
		scanf("%d",&a);
		enqueue(&q,a);
		queue_print(&q);
	}
	printf("큐가 포화상태입니다.\n");
	
	printf("\n");
	
	printf("---데이터 삭제 단계---\n");
	while(!is_empty(&q)){
		a = dequeue(&q);
		printf("꺼내진 정수: %d \n",a);
		queue_print(&q);
	}
	printf("큐는 공백상태입니다.\n");
	return 0;
}
