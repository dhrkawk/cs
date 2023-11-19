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

int main(){
	ListNode *head = NULL;
	
	printf("%d개의 노드가 있습니다\n",get_length(head));
	head = insert_last(head,20);
	print_list(head);
	printf("%d개의 노드가 있습니다\n",get_length(head));
	head = insert_last(head,30);
	print_list(head);
	printf("%d개의 노드가 있습니다\n",get_length(head));
	head = insert_last(head,40);
	print_list(head);
	printf("%d개의 노드가 있습니다\n",get_length(head));
	head = insert_first(head,10);
	print_list(head);
	printf("%d개의 노드가 있습니다\n",get_length(head));
	return 0;
}