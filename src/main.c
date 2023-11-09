#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	StackType *s2;
	s2= (StackType*)malloc(sizeof(StackType));
	init_stack(s2);
	StackType *s3;
	s3= (StackType*)malloc(sizeof(StackType));
	init_stack(s3);
	
	char exp[100];
	scanf("%[^\n]s",exp);   // 공백을 포함해서 문자열을 입력받기 위해 [^/n]추가
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
			push(s,ch);
			push(s2,ch);
		}
	}
	while(!is_empty(s2)){
		push(s3,pop(s2));
	}
	
	for(int i=0;i<s3->capacity;i++){
		if(pop(s)!=pop(s3)){
			printf("회문 아님\n");
			break;
		}
		else{
			printf("회문임\n");
			break;
		}
	}
	
	free(s);
	free(s2);
	free(s3);
	
	return 0;
}