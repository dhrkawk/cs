#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct test{
	int a;
	char words[20];
}Test;

int main(){
	Test* t;
	t = (Test*)malloc(sizeof(Test));
	if(t==NULL){
		fprintf(stderr,"널포인터 오류");
		exit(1);
	}
<<<<<<< HEAD:src/main.c
	t->a = 100;
	strcpy(t->words,"just testing");
	printf("%d이랑 %s\n",t->a,t->words);
	free(t);
	return 0;
}
=======
	printf("\n");
}
>>>>>>> c74aebe3da1c51b284910d2a74745a6866d7e1cb:ds_practice/3_8_10.c
