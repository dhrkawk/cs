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
	char input;
	printf("입력을 원하면 i을, 출력을 원하면 o를, 종료를 원하면 e을 입력하세요\n");
	scanf("%c", &input);
	while(input != 'e'){
		if(input =='i'){
			element p;
			printf("정수를 입력하세요:");
			scanf("%d",&p);
			push(s1,p);
			peek(s1);
		}
		else if(input =='o'){
			if(is_empty(s2)){
				while(!is_empty(s1)){
					push(s2,pop(s1));
				}
			}
			printf("%d\n", pop(s2));
			
		}
		scanf("%c",&input);
	}  
    free(s1);
    free(s2);
	return 0;
}