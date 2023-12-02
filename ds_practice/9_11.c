#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
#define SIZE 8

typedef struct element {
	char todo[50];
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
	char c;
	HeapType *h;
	h=create();
	init(h);
	while(c!='q'){
		printf("삽입(i), 삭제(d): ");
		scanf("%c",&c);
		if(c=='i'){
			element e;
			printf("할일: ");
			scanf("%s",e.todo);
			scanf("%c",&c); //공백 받기
			printf("우선순위: ");
			scanf("%d",&e.key);
			scanf("%c",&c); //공백 받기
			insert_max_heap(h,e);
		}
		else if(c=='d'){
			element e;
			e = delete_max_heap(h);
			printf("제일 우선 순위가 높은 일은 %s \n",e.todo);
			scanf("%c",&c); //공백 받기
		}
		else if(c=='q') break;
	}
	return 0;
}
