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

ListNode* reverse(ListNode *head){
	ListNode *p, *q, *r;
	p= head; // 역순으로 만들 리스트
	q= NULL; // 역순으로 만들 노드
	while(p != NULL){
		r = q; // 역순으로 된 리스트
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}


int main(void){
	ListNode *head1 = NULL;
	ListNode *head2 = NULL;
	
	head1= insert_first(head1,10);
	head1= insert_first(head1,20);
	head1= insert_first(head1,30);
	print_list(head1);
	
	head2= reverse(head1);
	print_list(head2);
	return 0;
}
