#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
	element data;
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




void insert_last(ListType* plist, element data){
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if(temp == NULL) error("메모리 할당 에러");
	temp->data = data;
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



void poly_print(ListType* plist){
	ListNode* p = plist->head;
	
	for(; p; p = p->link){
		printf("%d-> ",p->data);
	}
	printf("NULL\n");
}

void insert(ListNode* pre, element data){
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if(temp == NULL) error("메모리 오류");
	temp->data = data;
	temp->link = pre->link;
	pre->link = temp;
}



void merge(ListType* list1, ListType* list2, ListType* list3){
	ListNode* a =list1->head;
	ListNode* b =list2->head;
	while(a&&b){
		if(a->data >= b->data){
			if(list3->tail ==NULL){
				insert_last(list3,b->data);
				b=b->link;
				insert_last(list3,a->data);
				a=a->link;
				poly_print(list3);
			}
			else{
				ListNode *p =list3->head; // 이 밖에 선언하면 head가 NULL로 읽힘
				if(list3->tail->data < b->data){// list3안 데이터들이 삽입할 데이터보다 작음
					insert_last(list3,b->data);
					b=b->link;
					insert_last(list3,a->data);
					a=a->link;
					poly_print(list3);
				}
				else{
					//p를 통해 삽입할 데이터보다 작은 노드에 접근
					while(p->data <= b->data && p->link != NULL){
						p=p->link;
					}
					//pre를 통해 p이전의 노드를 가리킴
					ListNode* pre = list3->head;
					while(pre->link != p){
						pre = pre->link;
					}
					insert(pre,b->data);
					b=b->link;
					insert_last(list3,a->data);
					a=a->link;
					poly_print(list3);
				}
			}
		}
		else{
			if(list3->tail ==NULL){
				insert_last(list3,a->data);
				a=a->link;
				insert_last(list3,b->data);
				b=b->link;
			}
			else{
				ListNode *p =list3->head;
				if(list3->tail->data < a->data){
					insert_last(list3,a->data);
					a=a->link;
					insert_last(list3,b->data);
					b=b->link;
				}
				else{
					while(p->data <= a->data && p->link != NULL){
						p=p->link;
					}
					ListNode* pre = list3->head;
					while(pre->link != p){
						pre = pre->link;
					}
					insert(pre,a->data);
					a=a->link;
					insert_last(list3,b->data);
					b=b->link;
				}
			}
		}
	}
}



int main(void){
	ListType *list1, *list2, *list3;
	
	list1 = create();
	list2 = create();
	list3 = create();
	
	insert_last(list1,10);
	insert_last(list1,20);
	insert_last(list1,30);
	
	insert_last(list2,1);
	insert_last(list2,2);
	insert_last(list2,34);
	
	merge(list1,list2,list3);
	poly_print(list3);
	
	free(list1);
	free(list2);
	free(list3);
}