#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode{
	element data;
	struct DListNode *llink;
	struct DListNode *rlink;
}DListNode;

void init(DListNode* phead){
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DListNode* phead){
	DListNode* p;
	for(p = phead->rlink; p != phead; p=p->rlink){
		printf("<-| %d |-> ",p->data);
	}
	printf("\n");
}

void dinsert(DListNode *before,element data){
	DListNode *newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void ddelete(DListNode *head, DListNode *removed){
	if(removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

DListNode* search(DListNode *L,element data){
	DListNode *p;
	DListNode *check = NULL;
	for(p=L->rlink; p!=L; p = p->rlink){
		if(p->data ==data){
			check =p;
		}
	}
	return check;
}

int main(){
	DListNode *head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	
	printf("추가 단계\n");
	for(int i=0; i<5;i++){
		dinsert(head,i);
		print_dlist(head);
	}
	
	DListNode* x = search(head,3);
	if(x==NULL){
		printf("찾는 값이 리스트에 없습니다\n");
	}
	else{
		printf("%d가(이) 리스트에 있습니다.\n",x->data);
	}
	
	printf("삭제 단계\n");
	for(int i=0; i<5;i++){
		print_dlist(head);
		ddelete(head,head->rlink);
	}
	free(head);

	return 0;
}