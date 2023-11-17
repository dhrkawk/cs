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

int get_count(ListNode* head){
	int count=0;
	for(ListNode *p = head; p!=NULL;p= p->link){
		count++;
	}
	return count;
}

ListNode* delete_odd(ListNode* head){
	ListNode* removed;
	ListNode* itr;
	
	int num=get_count(head);
	if(head==NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	itr = head; // head 삭제
	
	for(int i=0;i<(num-1)/2;i++){
		removed = itr ->link;
		itr->link = removed->link;
		free(removed);
		itr = itr->link;
	} // for문으로 남은 홀수번째 노드들 삭제
	
	return head;
	
}


int main(void){
	ListNode *head = NULL;
	for(int i=0;i<6;i++){
		head =insert_first(head,i);
	}
	print_list(head);
	head = delete_odd(head);
	print_list(head);
}
