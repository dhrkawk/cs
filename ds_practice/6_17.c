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

void alternate(ListType* head1, ListType* head2, ListType* head3){
	ListNode* p = head1->head;
	ListNode* q = head2->head;
	
	while(p&&q){ // p와 q가 null이 아닌동안
		insert_last(head3,p->data);
		p=p->link;
		insert_last(head3,q->data);
		q=q->link;
	}
	
	for(; p!=NULL; p= p->link){
		insert_last(head3, p->data);
	}
	for(; q!=NULL; q = q->link){
		insert_last(head3, q->data);
	}
}







int main(void){
	ListType *list1, *list2, *list3;
	
	list1 = create();
	list2 = create();
	list3 = create();
	
	insert_last(list1,10);
	insert_last(list1,20);
	insert_last(list1,30);
	
	insert_last(list2,1);
	insert_last(list2,2);
	insert_last(list2,3);
	
	alternate(list1,list2,list3);
	poly_print(list3);
	
	free(list1);
	free(list2);
	free(list3);
}
