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
	printf("%d ",s->data[s->top]); // 오류 디버깅용
}

element pop(StackType *s){
	if(is_empty(s)){
		fprintf(stderr,"스택 빔");
		exit(1);
	}
	
	return s ->data[(s->top)--];
}

int eval(char exp[]){
	int length = strlen(exp);
	char ch;
	StackType *s;
	s=(StackType*)malloc(sizeof(StackType));
	init_stack(s);
	int value, op1, op2;
	for(int i=0; i<length; i++){
		ch = exp[i];
		if(ch != '+' && ch != '-' && ch != '*' && ch != '/'){
			value = ch - '0';
			push(s,value);
		}
		else{
			op2 = pop(s);
			op1 = pop(s); // op1이랑 op2를 바꿔서 pop에 넣었다가 나누기에서 몫이 틀리는
			              // 오류를 발생시켰다. 스택의 pop을 잘 체크하자
			switch(ch){
				case '+': push(s,op1+op2); break;
				case '-': push(s,op1-op2); break;
				case '*': push(s,op1*op2); break;
				case '/': push(s,op1/op2); break;	
			}
		}
	}
	return pop(s);
}
	


int main(){
	printf("후위 표기식은 82/3-32*+\n");
	printf("결과값은 %d\n",eval("82/3-32*+"));
	return 0;
}
