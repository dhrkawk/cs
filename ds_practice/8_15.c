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

int sum=0;

void inoder_sum(TreeNode *root){
	if(root!=NULL){
		inoder_sum(root->left);
		sum +=root->data;
		inoder_sum(root->right);
	}
}


int main(){
<<<<<<< HEAD:src/main.c
	inoder_sum(root);
	printf("합은 %d\n",sum);
}
=======
	int input = 20;
	inorder_print_if_less_than(root,input);
	
	return 0;
}
>>>>>>> 266d800f23f3340b79d87b9a73bd4a8a053e07ab:ds_practice/8_15.c
