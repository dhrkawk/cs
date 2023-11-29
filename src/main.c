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

int count= 0;

int inorder_count_have_one_child(TreeNode *root){
	if(root!=NULL){
		inorder_count_have_one_child(root->left);
		if(root->left ==NULL && root->right !=NULL){
			count ++;
		}
		else if(root->left !=NULL && root->right ==NULL){
			count ++;
		}
		inorder_count_have_one_child(root->right);
	}
	return count;
}

int main(){
	printf("자식이 하나만 있는 노드의 개수는 %d",inorder_count_have_one_child(root));
	
	return 0;
}