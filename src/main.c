#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode** head, int item) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = item;
    p->link = *head;
    *head = p;
    return *head;
}

void insertion_sort(ListNode** head) {
    ListNode *sorted = NULL;
	ListNode *current = *head;
	
	while(current !=NULL){
		ListNode* next = current->link;
		
		if(sorted == NULL || sorted->data >current->data){
			current->link = sorted;
			sorted = current;
		}
		else{
			ListNode* pointer = sorted;
			while(pointer->link !=NULL && pointer->link->data < current->data){
				pointer = pointer->link;
			}
			current->link = pointer->link;
			pointer->link = current;
		}
		current = next;
	}
	*head = sorted;
}

int main() {
    ListNode* head = NULL;
    
    insert_first(&head, 10);
    insert_first(&head, 40);
    insert_first(&head, 30);
    insert_first(&head, 50);
    insert_first(&head, 20);
	

    insertion_sort(&head);

    for (ListNode* p = head; p != NULL; p = p->link) {
        printf("%d ", p->data);
    }
    printf("\n");

    return 0;
}
