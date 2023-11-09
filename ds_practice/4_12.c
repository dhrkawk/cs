#include <stdio.h>
#include <stdlib.h>
#include <string.h> // 코드 10에서 추가


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

// 스택 코드는 코드10과 동일

element peek(StackType *s){
	if(is_empty(s)){
		fprintf(stderr,"스택 빔");
		exit(1);
	}
	else return s ->data[(s->top)];
}


int main(){
	StackType *s;
	s= (StackType*)malloc(sizeof(StackType));
	init_stack(s);
	
	int countA=0; 
	int countB=0;
	char exp[100];
	char ch;
	scanf("%s",exp);
	for(int i=0;i<strlen(exp);i++){
		ch=exp[i];
		push(s,ch);
		if(peek(s)=='a'||peek(s)=='A'){
			countA++;	
		}
		else if(peek(s)=='b'||peek(s)=='B'){
			countB++;
		}
	}
	printf("%d%c%d%c",countA,'a',countB,'b');
	printf("\n");
    free(s);
	return 0;
}
