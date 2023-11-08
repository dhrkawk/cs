#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
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

int prec(char op){
	switch(op){
		case '(': case ')' : return 0;
		case '+': case '-' : return 1;
		case '*': case '/' : return 2;
	}
	return -1;
}

void infix_to_postfix(char exp[]){
	char ch,top_op;
	StackType *s;
	s=(StackType *)malloc(sizeof(StackType));
	init_stack(s);
	int length = strlen(exp);
	for(int i=0; i<length; i++){
		ch = exp[i];
		switch(ch){
			case '+': case '-': case '*': case'/':
				while(prec(ch)<=prec(s->data[s->top]) && !is_empty(s)){
					printf("%c",pop(s));
				}
			    push(s,ch);
				break;
			case '(':
				push(s,ch);
				break;
			case ')':
				top_op=pop(s);
				while(top_op !='('){
					printf("%c", top_op);
					top_op=pop(s);
				}
				break;
			default:
				printf("%c",ch);
				break;
		}
	}
	while(!is_empty(s)){
		printf("%c",pop(s));
	}
	free(s);
}





int main(){
	char *s = "(2+3)*4+9";
	printf("중위표시수식 %s\n", s);
	printf("후위표시수식 ");
	infix_to_postfix(s);
	printf("\n");
	return 0;
}
