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

ListNode* search_list(ListNode* head,element x){
	ListNode* p = head;
	while(p !=NULL){
		if(p->data == x) return p;
		p=p->link;
	}
	return NULL;
}

int where_is_x(ListNode* head,element x){
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p = head;
	int count =1;
	ListNode* search = search_list(head,x);
	if(search != NULL){
		while(p!=search){
			count++;
			p=p->link;
		}
		return count;
	}
	else{
		count =0;
		return count;
	}
}

int main(void){
	ListNode *head = NULL;
	
	
	for(int i=0; i<5;i++){
		head= insert_first(head,i);
		print_list(head);
	}
	int pos = where_is_x(head,3); // where_is_x를 pos위치에 바로 넣으면
	                              // 계속 함수를 호출한다. 조심.
	
	if(pos!=0){
		printf("3은 %d번째 노드입니다\n",pos);
	}
	else{
		printf("3은 리스트에 없습니다\n");
	}
	
	
	head= delete_first(head);
	print_list(head); // 지우고 나서 한번 더 확인
	
	pos= where_is_x(head,3);
	if(pos!=0){
		printf("3은 %d번째 노드입니다\n",pos);
	}
	else{
		printf("3은 리스트에 없습니다\n");
	}
	
	return 0;
}
