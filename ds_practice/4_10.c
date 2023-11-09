#include <stdio.h>
#include <stdlib.h>
#define MAX_ARR_SIZE 6

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
		s->capacity *=2;
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
	s= (StackType*)malloc(sizeof(StackType));
	init_stack(s);
	
	printf("정수 배열의 크기: %d\n",MAX_ARR_SIZE);
	printf("정수를 입력하시오: ");
	for(int i=0; i<MAX_ARR_SIZE; i++){
		int tmp;
		scanf("%d",&tmp);
		push(s,tmp);
	}
	printf("\n");
	printf("반전된 정수 배열: ");
	for(int i=0;i<MAX_ARR_SIZE;i++){
		printf("%d ",pop(s));
	}
	printf("\n");
	free(s);
	
	return 0;
}
