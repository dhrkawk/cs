#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode{
	element key;
	struct TreeNode *left, *right;
	int is_thread;
}TreeNode;

TreeNode n8 = {11,NULL,NULL};
TreeNode n7 = {10,&n8,NULL};
TreeNode n1 = {1, &n7, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};

TreeNode *root = &n6;

int max(int a, int b)
{
	return a < b ? b : a;
}

int get_height(TreeNode *node){
	int height =0;
	if(node!=NULL){
		height = 1+ max(get_height(node->left),get_height(node->right));
	}
	return height;
}

int isBalanced(TreeNode *node){
	if(node == NULL){
		return 1;
	}
	if(node->left ==NULL || node->right ==NULL){
		return 1;
	}
	int left_height = get_height(node->left);
	int right_height = get_height(node->right);
	if((left_height - right_height)<=1 && (left_height - right_height) >=-1 && isBalanced(node->left) && isBalanced(node->right)){
		return 1;
	}
	return 0;
}

int main(){
	if(isBalanced(root)==1){
		printf("트리는 균형트리\n");
	}
	else{
		printf("트리는 균형트리가 아니다.\n");
	}
	return 0;
}
