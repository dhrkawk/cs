#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
#define SIZE 8

typedef struct{
	int key;
}element;
typedef struct{
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create(){
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType *h){
	h->heap_size=0;
}

void insert_min_heap(HeapType *h, element item){
	int i;
	i = ++(h->heap_size);
	
	while((i != 1)&&(item.key < h->heap[i/2].key)){
		h->heap[i] = h->heap[i/2];
		i /=2;
	}
	h->heap[i] = item;
}

void delete_min_heap(HeapType *h,int key){
	int parent, child;
	element item, temp;
	
	for(int i=1;i<h->heap_size;i++){
		if(h->heap[i].key ==key){
			parent = i;
			child = 2*i;
			break;
		}
	}
	item = h->heap[parent]; // 삭제할 노드는 바뀐 parent
	temp = h->heap[(h->heap_size)--];
	
	while(child <= h->heap_size){
		if((child<h->heap_size)&&(h->heap[child].key > h->heap[child+1].key)){
			child ++;
		} 
		if(temp.key<=h->heap[child].key) break;
		
		h->heap[parent] =h->heap[child];
		parent = child;
		child *=2;
	}// whlie문을 빠져나오면 parent 위치가 확정됨
	h->heap[parent] = temp;
}

void print_tree(HeapType *h){
	for(int i=1;i<=h->heap_size;i++){
		printf("%d-> ",h->heap[i].key);
	}
	printf("\n");
}


int main(){
	HeapType *h;
	h=create();
	init(h);
	
	element e1= {10}, e2 = {5}, e3 = {30};

	insert_min_heap(h,e1);
	insert_min_heap(h,e2);
	insert_min_heap(h,e3);
	printf("\n");
	
	delete_min_heap(h,5);
	print_tree(h);
	
	
	return 0;
}
