#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

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

void insert_max_heap(HeapType *h, element item){
	int i;
	i = ++(h->heap_size);
	
	while((i != 1)&&(item.key > h->heap[i/2].key)){
		h->heap[i] = h->heap[i/2];
		i /=2;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType *h){
	int parent, child;
	element item, temp;
	
	item = h->heap[1]; // 삭제할 노드는 루트노드
	temp = h->heap[(h->heap_size)--];
	parent =1;
	child =2;
	
	while(child <= h->heap_size){
		if((child<h->heap_size)&&(h->heap[child].key < h->heap[child+1].key)){
			child ++;
		} // 왼쪽 자식 노드와 오른쪽 자식 노드 중 오른쪽 자식 노드가 크면 child 변경
		if(temp.key>=h->heap[child].key) break; //최대 heap 만족하면 break
		
		h->heap[parent] =h->heap[child];
		parent = child;
		child *=2;
	}// whlie문을 빠져나오면 parent 위치가 확정됨
	h->heap[parent] = temp;
	return item;
}



int main(){
	element e1= {10}, e2 = {5}, e3 = {30};
	element e4,e5,e6;
	HeapType *heap;
	
	heap = create();
	init(heap);
	
	insert_max_heap(heap,e1);
	insert_max_heap(heap,e2);
	insert_max_heap(heap,e3);
	
	e4 = delete_max_heap(heap);
	printf("<%d> ",e4.key);
	e5 = delete_max_heap(heap);
	printf("<%d> ",e5.key);
	e6 = delete_max_heap(heap);
	printf("<%d> ",e6.key);
	
	free(heap);
	return 0;
	
}
