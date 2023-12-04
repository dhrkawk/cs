#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
#define SIZE 8


typedef struct HeapType{
	int data;
	struct HeapType* link;
}HeapType;


HeapType* create_node(int data) {
	HeapType* new_node;
	new_node = (HeapType*)malloc(sizeof(new_node));
	new_node->data = data;
	new_node->link = NULL;
	return new_node;
}

void insert_max_heap(HeapType** phead, HeapType* new_node) {
	new_node->link = *phead; // NULL 아님
	*phead = new_node;
}
int delete_max_heap(HeapType** phead){
	if(*phead==NULL){
		printf("heap이 빔\n");
		return -1;
	}
	int max = 0;
	int temp;
	HeapType *target;
	HeapType *p = *phead;
	HeapType *prev = *phead;
	for(HeapType *node = p; node !=NULL;node = node->link){
		if(node->data > max){
			max = node->data;
			target = node;
		}
	}
	if(target == p){//최우선순위 노드가 헤드노드면
		*phead = p->link; // 헤드 교체
		free(target);
		return max;
	}
	else{
		while(prev->link !=target){
			prev=prev->link;
		}
		prev->link = target->link;
	}
	free(target);
	
	
	return max;
}

void print_list(HeapType* phead){
	for(HeapType *p = phead; p!=NULL;p= p->link){
		printf("%d->",p->data);
	}
	printf("NULL \n");
}


int main(){
	HeapType *head = NULL;
	for(int i=0; i<5;i++){
		HeapType *temp = create_node(i);
		insert_max_heap(&head,temp);
		print_list(head);
	}
	
    int deleted_value = delete_max_heap(&head);
    printf("우선순위 큐 삭제 data: %d\n", deleted_value);
    print_list(head);
	return 0;
}
