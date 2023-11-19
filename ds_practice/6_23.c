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

ListNode* insert_ascending(ListNode* head,element data){
	ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
	temp->data = data;
	temp->link = NULL;
	ListNode *p = head;
	if(p == NULL){
		head=temp;
	}
	else{
		if(p->data > data){
			temp->link = head;
			head = temp;
		}
		else{
			while(p->data < data && p->link != NULL){
				p=p->link;
			}
			if(p->data > data){
				ListNode* pre = head;
				while(pre->link !=p){
					pre = pre->link;
				}
				temp->link = pre->link;
				pre->link = temp;
			}
			else{
				temp->link = p->link;
				p->link = temp;
			}
			
		}
	}
	return head;
}



int main(void){
	ListNode *head = NULL;
	head = insert_ascending(head,1);
	print_list(head);
	head = insert_ascending(head,4);
	print_list(head);
	head = insert_ascending(head,2);
	print_list(head);
	head = insert_ascending(head,6);
	print_list(head);
	head = insert_ascending(head,3);
	print_list(head);
	head = insert_ascending(head,5);
	print_list(head);
	
	return 0;
}
