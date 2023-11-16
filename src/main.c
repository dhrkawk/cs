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

int get_sum(ListNode* head){
	int sum=0;
	for(ListNode* p = head;p!=NULL;p=p->link){
		sum += p ->data;
	}
	return sum;
}

int how_many(ListNode* head, element item){
	int count=0;
	for(ListNode* p = head; p!=NULL; p = p->link){
		if(p->data == item) count++;
	}
	return count;
}

int main(void){
	ListNode *head = NULL;
	head = insert_first(head,1);
	head = insert_first(head,2);
	head = insert_first(head,2);
	head = insert_first(head,3);
	
	printf("노드의 개수는 %d\n",get_count(head));
	printf("노드들의 데이터 합은 %d\n",get_sum(head));
	printf("2는 연결리스트에서 %d번 나타난다.\n",how_many(head,2));
	return 0;
}