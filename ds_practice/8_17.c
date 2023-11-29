#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode{
	element data;
	struct TreeNode *left, *right;
}TreeNode;


TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;

int max =0;
int min =9999;

int inorder_find_max(TreeNode *root){
	if(root!=NULL){
		inorder_find_max(root->left);
		if(root->data > max) max = root->data;
		inorder_find_max(root->right);
	}
	return max;
}

int inorder_find_min(TreeNode *root){
	if(root!=NULL){
		inorder_find_min(root->left);
		if(root->data <min) min = root->data;
		inorder_find_min(root->right);
	}
	return min;
}

int main(){
	printf("노드의 최대값은 %d  ",inorder_find_max(root));
	printf("노드의 최소값은 %d  ",inorder_find_min(root));
	
	return 0;
}
