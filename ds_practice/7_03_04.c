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

void print_list(ListNode* head){
	ListNode* p;
	if(head ==NULL) return;
	p = head->link;
	do{
		printf("%d-> ",p->data);
		p=p->link;
	}while(p!=head);
	printf("%d-> \n",p->data);
}

ListNode* insert_first(ListNode* head, element data){
	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
	node->data=data;
	if(head == NULL){
		head= node;
		node->link = head;
	}
	else{
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data){
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data=data;
	if(head==NULL){
		head= node;
		node->link =head;
	}
	else{
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}

int get_length(ListNode *head){
	ListNode*p = head;
	int count=1;
	if(p==NULL){
		count =0;
	}
	else{
		while(p->link != head){
			p=p->link;
			count++;
		}
	}
	return count;
}

ListNode *search(ListNode *L,element data){ //03
	ListNode *temp = L->link;;
	for(temp;temp != L;temp = temp->link){
		if(temp->data == data){
			return temp;
		}
	}
	return NULL;
}

int get_size(ListNode* L){ //04
	int count=1;
	ListNode *temp = L->link;;
	for(temp;temp != L;temp = temp->link){
		count++;
	}
	return count;
}

int main(){
	ListNode *head = NULL;
	
	head = insert_last(head,20);
	head = insert_last(head,30);
	head = insert_last(head,40);
	head = insert_first(head,10);
	print_list(head);
	
	printf("리스트에 %d개의 노드가 있습니다.\n",get_size(head));
	
	ListNode* x = search(head,30);
	if(x==NULL){
		printf("찾는 값이 없습니다\n");
	}
	else{
		printf("%d가(이) 리스트에 있습니다.\n",x->data);
	}
	
	return 0;
}
