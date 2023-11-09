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
	t->a = 100;
	strcpy(t->words,"just testing");
	printf("%d이랑 %s\n",t->a,t->words);
	free(t);
	return 0;
}