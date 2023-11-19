#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
}ListNode;

typedef struct ListType{
	int size;
	ListNode *head;
	ListNode *tail;
}ListType;

ListType *create(){
	ListType *plist = (ListType*)malloc(sizeof(ListType));
	plist -> size = 0;
	plist -> head = plist->tail = NULL;
	return plist;
}

void error(char *message){
	fprintf(stderr,"%s\n",message);
	exit(1);
}




void insert_last(ListType* plist, element data){
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if(temp == NULL) error("메모리 할당 에러");
	temp->data = data;
	temp->link = NULL;
	if(plist->tail == NULL){
		plist->head = plist->tail = temp;
	}
	else{
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}



void poly_print(ListType* plist){
	ListNode* p = plist->head;
	
	for(; p; p = p->link){
		printf("%d-> ",p->data);
	}
	printf("NULL\n");
}

void insert(ListNode* pre, element data){
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if(temp == NULL) error("메모리 오류");
	temp->data = data;
	temp->link = pre->link;
	pre->link = temp;
}

int get_count(ListNode* head){  //10번
	int count=0;
	for(ListNode *p = head; p!=NULL;p= p->link){
		count++;
	}
	return count;
}

void split(ListType* list1,ListType* list2,ListType* list3){
	ListNode* p = list3->head;
	int num = list3->size;
	if(num%2!=0){
		for(int i=0;i<(num-1)/2;i++){
			insert_last(list1,p->data);
			p=p->link;
			insert_last(list2,p->data);
			p=p->link;
		}
		insert_last(list1,p->data);
	}
	else{
		for(int i=0;i<(num/2)-1;i++){
			insert_last(list1,p->data);
			p=p->link;
			insert_last(list2,p->data);
			p=p->link;
		}
		insert_last(list1,p->data);
		p=p->link;
		insert_last(list2,p->data);
	}
}


int main(void){
	ListType *list1, *list2, *list3;
	
	list1 = create();
	list2 = create();
	list3 = create();
	
	insert_last(list3,10);
	insert_last(list3,20);
	insert_last(list3,30);
	insert_last(list3,40);
	insert_last(list3,50);
	insert_last(list3,60);
	
	split(list1,list2,list3);
	poly_print(list1);
	poly_print(list2);
	poly_print(list3);
	
	free(list1);
	free(list2);
	free(list3);
}
