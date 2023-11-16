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

int get_count(ListNode* head){
	int count=0;
	for(ListNode *p = head; p!=NULL;p= p->link){
		count++;
	}
	return count;
}

ListNode* insert_last(ListNode* head,element item){
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = item;
	newnode->link = NULL;
	ListNode* p = head;
	if(p==NULL) head = newnode;
	else {
		while(p->link !=NULL){
			p = p->link;
		}
		p->link = newnode;
	}
	return head;
}

int main(void){
	ListNode *head = NULL;
	element item;
	int num;
	printf("노드의 개수: ");
	scanf("%d",&num);
	for(int i=0; i<num; i++){
		printf("노드 #%d의 데이터: ",i+1);
		scanf("%d",&item);
		head = insert_last(head,item);
		print_list(head);
	}
	
	return 0;
}