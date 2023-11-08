#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct{
	element data[MAX_QUEUE_SIZE];
	int front;
	int rear;
}DequeType;

void error(char *message){
	fprintf(stderr,"%s\n",message);
	exit(1);
}

int is_empty(DequeType *q){
	if(q->front == q->rear) return 1;
	else return 0;
}


void init_deque(DequeType *q){
	q->front = q->rear = 0;
}


int is_full(DequeType *q){
	if((q->rear +1)%MAX_QUEUE_SIZE == q->front) return 1;
	else return 0;
}

void add_rear(DequeType *q,element item){
	if(is_full(q)){
		error("큐가 가득 참");
		exit(1);
	}
	q->rear = (q->rear +1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element delete_front(DequeType *q){
	if(is_empty(q)){
		error("큐가 빔");
		return -1;
	}
	q->front = (q->front +1) % MAX_QUEUE_SIZE;
	element item = q->data[(q->front)];	
	return item;
}

void add_front(DequeType *q,element item){
	if(is_full(q)){
		error("큐가 가득 참");
		exit(1);
	}
	q->data[q->front] = item;
	//front는 맨 앞 요소의 바로 앞을 가리키므로
	//front에 item을 넣은 후 인덱스를 조정해주는 것이 옳다.
	q->front = (q->front -1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType *q){
	if(is_empty(q)){
		error("큐가 빔");
		return -1;
	}
	int prev = q->rear;
	// 꺼낼 데이터의 인덱스를 prev에 저장
	q->rear = (q->rear -1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}


void deque_print(DequeType *q){
	printf("Deque(front=%d rear=%d) = ", q->front,q->rear);
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
	DequeType q;
	init_deque(&q);
	for(int i=0; i<3;i++){
		add_front(&q,i);
		deque_print(&q);
	}
	for(int i=0; i<3;i++){
		delete_rear(&q);
		deque_print(&q);
	}
	return 0;
}