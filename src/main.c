#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef struct{
	int id;
	int arrival_time;
	int service_time;
}element;

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
		exit(1);
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
	int minutes =60;
	int total_wait =0;
	int total_customers =0;
	int service_time_a = 0; // 종업원 a의 서비스 시간
	int service_time_b = 0; // 종업원 b의 서비스 시간
	int service_customer;
	QueueType q;
	QueueType q2;
	init_queue(&q);
	init_queue(&q2);
	
	srand(time(NULL));
	for(int clock=0; clock<minutes; clock++){
		printf("현재 시각= %d\n",clock);
		if((rand()%10)<3){ //고객이 들어올 확률 33.33%
			element customer;
			customer.id=total_customers++; // 온 순서에 따라 id부여
			customer.arrival_time=clock; // 도착시간
			customer.service_time=rand()%7 +1; // 손님의 서비스 이용시간도 랜덤
			enqueue(&q,customer);
			printf("고객 %d이 %d분에 들어옵니다. 업무처리시간= %d분\n",
				  customer.id,customer.arrival_time,customer.service_time);
		}
		if(service_time_a>0){
			service_time_a--;
		}
		if(service_time_b>0){ //else if로 처리하면 a만 감소
			service_time_b--;
		}
		if(!is_empty(&q)){
			if(service_time_a>0 && service_time_b>0){
				printf("대기가 필요합니다\n");
			}
			else if(service_time_a==0){
				element customer = dequeue(&q);
				service_customer = customer.id;
				service_time_a = customer.service_time;
				printf("고객 %d이 %d분에 직원a에게 업무를 시작합니다. 대기시간은 %d분이었습니다.\n",
					  customer.id,clock,clock-customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
			else if(service_time_b==0){
				element customer = dequeue(&q);
				service_customer = customer.id;
				service_time_b = customer.service_time;
				printf("고객 %d이 %d분에 직원b에게 업무를 시작합니다. 대기시간은 %d분이었습니다.\n",
					  customer.id,clock,clock-customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
		}	
	}	
	printf("전체 대기 시간 = %d분 \n",total_wait);
	return 0;
}