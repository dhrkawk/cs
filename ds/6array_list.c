#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct{
	element array[MAX_LIST_SIZE];
	int size;
}ArrayListType;

void error(char *message){
	fprintf(stderr,"%s\n",message);
	exit(1);
}

void init_List(ArrayListType *L){
	L->size =0;
}


int is_empty(ArrayListType *L){
	return L->size ==0;
}


int is_full(ArrayListType *L){
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType *L,int pos){
	if(pos<0 || pos>L->size){
		error("위치 오류");
	}
	return L->array[pos];
}

void print_List(ArrayListType *L){
	for(int i=0; i<L->size; i++){
		printf("%d -> ",L->array[i]);
	}
	printf("\n");
}

void insert_last(ArrayListType *L, element item){
	if(is_full(L)){
		error("리스트 오버플로우");
	}
	L->array[L->size++] = item;
}

void insert(ArrayListType *L, int pos, element item){
	if(is_full(L)){
		error("리스트 오버플로우");
	}
	if(pos<0 || pos>L->size){
		error("위치 오류1");
	}
	for(int i=L->size-1;i>=pos;i--){
		L->array[i+1] = L->array[i];
	}
	L->array[pos] = item;
	L->size ++;
}

void insert_first(ArrayListType *L, element item){
	if(is_full(L)){
		error("리스트 오버플로우");
	}
	
	for(int i=L->size-1;i>=0;i--){
		L->array[i+1] = L->array[i];
	}
	L->array[0] = item;
	L->size ++;
}

element delete(ArrayListType *L, int pos){
	if(pos<0 || pos>L->size){
		error("위치 오류");
	}
	element item = L->array[pos];
	for(int i=pos; i<L->size-1;i++){
		L->array[i] = L->array[i+1];
	}
	L->size--;
	return item;
}



int main(){
	ArrayListType *list;
	list = (ArrayListType*)malloc(sizeof(ArrayListType));
	init_List(list);
	
	insert(list,0,10);
	print_List(list);
	insert(list,0,20);
	print_List(list);
	insert(list,0,30);
	print_List(list);
	insert_last(list,40);
	print_List(list);
	delete(list,0);
	print_List(list);
	insert_first(list,80);
	print_List(list);
	return 0;
}