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


void inorder_inverse(TreeNode *root){
	if(root){
		inorder_inverse(root->right);
		printf("[%d] ",root->key);
		inorder_inverse(root->left);
	}
}

void add_one(TreeNode *root){
	if(root){
		add_one(root->left);
		root->key +=1;
		printf("[%d] ",root->key);
		add_one(root->right);
	}
}


int main(){
	TreeNode * root = NULL;
	TreeNode *temp = NULL;
	
	root = insert_node(root,11);
	root = insert_node(root,3);
	root = insert_node(root,4);
	root = insert_node(root,1);
	root = insert_node(root,56);
	root = insert_node(root,5);
	root = insert_node(root,6);
	root = insert_node(root,2);
	root = insert_node(root,98);
	root = insert_node(root,32);
	root = insert_node(root,23);
	
	printf("이진 탐색 트리 내림차순 중위 순회 결과 \n");
	inorder_inverse(root);
	printf("\n");
	
	printf("노드의 값을 1씩 추가한 중위 순회 결과\n");
	add_one(root);
	printf("\n");
	
	return 0;
}
