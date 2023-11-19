#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
	int coef;
	int expon;
	struct ListNode *link;
}ListNode;

typedef struct ListType{
	int size;
	ListNode *head;
	ListNode *tail;
}ListType;

ListType *create(){
	ListType *plist = (ListType*)malloc(sizeof(ListType));
	plist -> size = 0;
	plist -> head = plist->tail = NULL;
	return plist;
}

void error(char *message){
	fprintf(stderr,"%s\n",message);
	exit(1);
}

void insert_last(ListType* plist, int coef, int expon){
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if(temp == NULL) error("메모리 할당 에러");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if(plist->tail == NULL){
		plist->head = plist->tail = temp;
	}
	else{
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

void poly_add(ListType* a, ListType* b, ListType* c){
	ListNode* p = a->head;
	ListNode* q = b->head;
	int sum;
	
	while(p&&q){ // p와 q가 null이 아닌동안
		if(p->expon == q->expon){ //case1
			sum = p->coef + q -> coef;
			if(sum !=0) insert_last(c,sum,p->expon);
			p = p->link;
			q = q->link;
		}
		else if(p->expon > q->expon){ //case2
			insert_last(c,p->coef,p->expon);
			p = p->link;
		}
		else{ //case3
			insert_last(c,q->coef,q->expon);
			q = q->link;
		}
	}
	
	for(; p!=NULL; p= p->link){
		insert_last(c, p->coef, p->expon);
	}
	for(; q!=NULL; q = q->link){
		insert_last(c, q->coef, q->expon);
	}
}

void poly_print(ListType* plist){
	ListNode* p = plist->head;
	
	printf("polynomial = ");
	for(; p; p = p->link){
		printf("%d^%d + ",p->coef,p->expon);
	}
	printf("\n");
}

int poly_eval(ListType* plist,element x){
	ListNode* p = plist->head;
	int sum=0;
	for(; p; p = p->link){
		int coef,exp;
		int mult=1;
		coef = p->coef;
		exp = p->expon;
		for(int i=0;i<exp;i++){
			mult *=x;
		}
		sum += (coef)*mult;
	}
	return sum;
}



int main(void){
	ListType *list1, *list2, *list3;
	
	list1 = create();
	list2 = create();
	list3 = create();
	
	insert_last(list1,3,6);
	insert_last(list1,7,3);
	insert_last(list1,-2,2);
	insert_last(list1,-9,0);
	
	insert_last(list2,-2,6);
	insert_last(list2,-4,4);
	insert_last(list2,6,2);
	insert_last(list2,6,1);
	insert_last(list2,1,0);
	
	poly_print(list1);
	poly_print(list2);
	
	poly_add(list1,list2,list3);
	poly_print(list3);
	
	printf("list1에 2를 대입하면 %d\n",poly_eval(list1,2));
	free(list1);
	free(list2);
	free(list3);
}
