#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_QUEUE_SIZE 100

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
}TreeNode;

typedef TreeNode *element;
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
		return 0;
	}
	q->front = (q->front +1) % MAX_QUEUE_SIZE;
	element item = q->data[(q->front)];	
	return item;
}

void level_order(TreeNode *ptr){
	QueueType q;
	init_queue(&q);
	if(ptr == NULL) return;
	enqueue(&q,ptr);
	while(!is_empty(&q)){
		ptr = dequeue(&q);
		printf("[%d] ",ptr->data);
		if(ptr->left){
			enqueue(&q,ptr->left);
		}
		if(ptr->right){
			enqueue(&q,ptr->right);
		}
	}
}

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;

int main(){
	printf("레벨 순회=");
	level_order(root);
	printf("\n");
	return 0;
}
