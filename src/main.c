#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct{
	element *data;
	int capacity;
	int top;
}StackType;

void init_stack(StackType *s){
	s->top=-1;
	s->capacity = 1;
	s->data=(element*)malloc(s->capacity*sizeof(element));
}

int is_empty(StackType *s){
	if(s->top == -1){
		return 1;
	}
	else return 0;
}

int is_full(StackType *s){
	if(s->top == (s->capacity-1)){
		return 1;
	}
	else return 0;
}

void push(StackType *s,element item){
	if(is_full(s)){
		s->capacity *=2; // 가득 찰 때마다 2배씩 realloc 해준다
		s->data =(element*)realloc(s->data,s->capacity*(sizeof(element)));
	}
	s->top ++;
	s->data[s->top]=item;
}

element pop(StackType *s){
	if(is_empty(s)){
		fprintf(stderr,"스택 빔");
		exit(1);
	}
	
	return s ->data[(s->top)--];
}

int main(){
	StackType *s;
	s = (StackType*)malloc(sizeof(StackType));
	init_stack(s);

	push(s,1);
	push(s,2);
	push(s,3);
	printf("%d \n", pop(s));
	printf("%d \n", pop(s));
	printf("%d \n", pop(s));
	return 0;
}