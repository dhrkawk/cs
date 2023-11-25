#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define SIZE 100

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
}TreeNode;

int top = -1;
TreeNode *stack[SIZE];

void push(TreeNode *p){
	if(top<SIZE-1){
		stack[++top] = p;
	}
}

TreeNode *pop(){
	TreeNode *p = NULL;
	if(top >= 0){
		p = stack[top--];
	}
	return p;
}

void preorder_iter(TreeNode *root){
	push(root);
	while(top>=0){
		TreeNode *stacktop = stack[top];
		TreeNode *temp = pop();
		printf("[%d] ",temp->data);
		temp  = stacktop->right;
		if(temp != NULL){
			push(temp);
		}
		temp = stacktop->left;
		if(temp != NULL){
			push(temp);
		}
	}
}

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;

int main(){
	
	printf("전위 순회=");
	preorder_iter(root);
	printf("\n");
	
}
