#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 100

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

element get_count(DequeType *q){
	element count=0;
	if(q->front < q->rear){
		count = (q->rear - q->front);
	}
	else if(q->front > q->rear){
		count = MAX_QUEUE_SIZE - (q->front - q->rear);
	}
	return count;
}

int main(){
	DequeType q;
	init_deque(&q);
	
	char exp[100];
	scanf("%[^\n]s",exp);   
	// 공백을 포함해서 문자열을 입력받기 위해 [^/n]추가
	char ch;
	
	for(int i=0;i<strlen(exp);i++){
		ch=exp[i];
		if(ch<='Z'&&ch>='A'){
			ch = ch+('a'-'A');
			exp[i]=ch;
		}
	}
	for(int i=0;i<strlen(exp);i++){
		ch=exp[i];
		if(ch<='z'&&ch>='a'){
			add_front(&q,ch);
		}
	}
	if(strlen(exp)%2 ==0){
		int count =0;
		while(!is_empty(&q)){
			if(delete_front(&q)==delete_rear(&q)){
				count++;
			}
		}
		if(count==(strlen(exp)/2)){
			printf("회문입니다\n");
		}
		else printf("회문이 아닙니다\n");
	}
	else{
		int count =0;
		while(get_count(&q)!=1){
			if(delete_front(&q)==delete_rear(&q)){
				count++;
			}
		}
		if(count==(strlen(exp)/2)){
			printf("회문입니다\n");
		}
		else printf("회문이 아닙니다\n");
		
	}
	return 0;
}