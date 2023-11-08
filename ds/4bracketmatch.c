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

/*괄호짝이 맞는지(조건 3 위배), 스택이 비어 있지는 않는지(조건 1, 조건2 위배), 마지막 괄호까지 처리했는데
스택이 비어있지 않은 지(조건1 위배)를 체크해 준다.*/
	
int check_matching(const char *in)
{
	StackType *s;
	s=(StackType*)malloc(sizeof(StackType));
	init_stack(s);
	int length = strlen(in);
	char left, right;
	
	for(int i=0;i<length; i++){
		left = in[i];
		switch(left){
			case '(': case '{': case '[':
				push(s,left);
				break;
			case ')': case '}': case ']':
				if(is_empty(s)){ //스택이 비어있진 않은가
                    free(s);
					return 0;
				}
				else{
					right = pop(s);
					if((right==')' && left !='(')||
						(right=='}'&& left !='{')||
						(right==']'&& left !='[')){
                        free(s);
						return 0; // 짝이 안맞진 않은가
					}
					break;
				}
		}
	}
	if(!is_empty(s)) {
        free(s);
        return 0; //오른쪽 괄호가 다 나왔는데 스택이 남아있는가
    }
    free(s);
    return 1;
	
}

int main(){
	char *p= "{A[(i+1]=0;}";
	if(check_matching(p)==1){
		printf("%s 괄호검사성공\n",p);
	}
	else{
		printf("%s 괄호검사실패\n",p);
	}
}
