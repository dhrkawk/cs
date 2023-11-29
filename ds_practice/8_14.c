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

void inorder_print_if_less_than(TreeNode* root, int input){
	if(root !=NULL){
		inorder_print_if_less_than(root->left,input);
		if(root->data <input)
		{
			printf("%d보다 작은 노드: %d\n",input,root->data);
		}
		inorder_print_if_less_than(root->right,input);
	}
}

int main(){
<<<<<<< HEAD:src/main.c
	int input = 20;
	inorder_print_if_less_than(root,input);
	
	return 0;
}
=======
	inoder_sum(root);
	printf("합은 %d\n",sum);
}
>>>>>>> 1ad191955758178013b893437a4fe2fae19a4d6c:ds_practice/8_14.c
