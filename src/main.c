#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode{
	element key;
	struct TreeNode *left, *right;
	int is_thread;
}TreeNode;


TreeNode *search(TreeNode * node, int key){
	if(node ==NULL) return NULL;
	if(key == node->key) return node;
	else if(key < node->key){
		return search(node->left,key);
	}
	else{
		return search(node->right,key);
	}
}

TreeNode *search_itr(TreeNode *node, int key){
	while(node != NULL){
		if(key==node->key) return node;
		else if(key<node->key){
			node = node->left;
		}
		else{
			node = node->right;
		}
	}
	return NULL;
}

TreeNode *new_node(int item){
	TreeNode *temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode *insert_node(TreeNode *node, int key){
	if(node == NULL) return new_node(key);
	
	if(key <node->key){
		node->left = insert_node(node->left,key);
	}
	else if(key > node->key){
		node->right = insert_node(node->right,key);
	}
	return node;
}

TreeNode * min_value_node(TreeNode *node){
	TreeNode *current = node;
	while(current->left !=NULL){
		current = current->left;
	}
	return current;
}

TreeNode *delete_node(TreeNode *root, int key){
	if(root ==NULL) return root;
	if(key< root->key){
		root->left = delete_node(root->left,key);
	}
	else if (key>root->key){
		root->right = delete_node(root->right,key);
	}
	else{
		if(root->left ==NULL){ // CASE1 or CASE2
			TreeNode * temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right ==NULL){
			TreeNode *temp = root->left;
			free(root);
			return temp;
		}
		//CASE3
		
		TreeNode *temp = min_value_node(root->right);
		root->key = temp ->key;
		root->right = delete_node(root->right,temp->key);
	}
	return root;
}


void inorder(TreeNode *root){
	if(root){
		inorder(root->left);
		printf("[%d] ",root->key);
		inorder(root->right);
	}
}


int main(){
	TreeNode * root = NULL;
	TreeNode *temp = NULL;
	
	root = insert_node(root,30);
	root = insert_node(root,20);
	root = insert_node(root,10);
	root = insert_node(root,40);
	root = insert_node(root,50);
	root = insert_node(root,60);
	
	printf("이진 탐색 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n");
	if(search(root,30)!=NULL){
		printf("트리에 30이 있음\n");
	}
	else{
		printf("트리에 30이 없음\n");
	}
	return 0;
}