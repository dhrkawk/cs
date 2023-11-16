#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
}ListNode;



void error(char *message){
	fprintf(stderr,"%s\n",message);
	exit(1);
}

ListNode* insert_first(ListNode *head, int value){
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode *head, ListNode *pre, element value){
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data=value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head){
	ListNode* removed;
	if(head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* delete(ListNode* head, ListNode* pre){
	ListNode* removed;
	removed = pre->link;
	pre->link = removed ->link;
	free(removed);
	return head;
}

void print_list(ListNode* head){
	for(ListNode *p = head; p!=NULL;p= p->link){
		printf("%d->",p->data);
	}
	printf("NULL \n");
}

element get_entry(ListNode* head, int index){
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p= head;
	for(int i=0;i<index-1;i++){
		p = p->link;
	}
	return p->data;
}

ListNode* delete_element(ListNode* head,element item){
	ListNode* p =head;
	ListNode* pre = head;
	ListNode* removed;
	
	while(p->data != item) p = p->link;
	removed = p;
	while(pre->link != p) pre = pre->link; //삭제하려는 노드의 이전노드 포인터를 찾아서
	pre->link = removed->link; // 링크 필드를 삭제하는 노드가 연결하던 노드로 옮긴다.
	free(removed);
	return head;
}



int main(void){
	ListNode *head = NULL;
	head = insert_first(head,1);
	head = insert_first(head,2);
	head = insert_first(head,3);
	head = insert_first(head,4);
	
	head = delete_element(head,3);
	print_list(head);
	
	return 0;
}