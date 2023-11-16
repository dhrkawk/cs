#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct PersonNode{
	char Name[20];
	int Age;
	float Height;
}PersonNode;

typedef struct ListNode{
	PersonNode pe;
	struct ListNode *link;
}ListNode;

ListNode* insert_first(ListNode *head, char name[], int age,float height){
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	strcpy(p->pe.Name,name);
	p->pe.Age = age;
	p->pe.Height = height;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head){
	for(ListNode *p = head;p!=NULL;p=p->link){
		printf("Name:%s  Age:%d  Height:%f ->\n", p->pe.Name,p->pe.Age,p->pe.Height);
	}
	printf("NULL\n");
}

int main(void){
	ListNode *head = NULL;
	head = insert_first(head,"choi",30,1.3);
	head = insert_first(head,"lee",48,1.4);
	head = insert_first(head,"park",27,1.2);
	head = insert_first(head,"Kim",34,1.7);

	print_list(head);
	
	return 0;
}
