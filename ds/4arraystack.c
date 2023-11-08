#include <stdio.h>
#include <stdlib.h>
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

element peek(StackType *s){
	if(is_empty(s)){
		fprintf(stderr,"스택 빔");
		exit(1);
	}
	return s->data[(s->top)];
}

int main(){
	StackType *s1;
	StackType *s2;
	s1 = (StackType*)malloc(sizeof(StackType));
	s2 = (StackType*)malloc(sizeof(StackType));
	init_stack(s1);
	init_stack(s2);
	push(s1,1);
	push(s1,2);
	push(s1,3);
	push(s2,pop(s1));
	push(s2,pop(s1));
	push(s2,pop(s1));
	printf("%d \n", peek(s2));
	printf("%d \n", pop(s2));
	printf("%d \n", pop(s2));
	printf("%d \n", pop(s2));
    free(s1);
    free(s2);
	return 0;
}
