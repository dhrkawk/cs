#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
  return (a > b)? a : b;
}

typedef struct AVLNode{
	int key;
	struct AVLNode *left;
	struct AVLNode *right;
}AVLNode;

AVLNode *rotate_right(AVLNode *parent){
	AVLNode* child = parent -> left;
	parent->left = child-> right;
	child-> right = parent;
	return child;
}

AVLNode *rotate_left(AVLNode *parent){
	AVLNode* child = parent -> right;
	parent->right = child -> left;
	child-> left = parent;
	return child;
}

int get_height(AVLNode *node){
	int height = 0;
	
	if(node !=NULL){
		height = 1+ max(get_height(node->left),get_height(node->right));
	}
	return height;
}

int get_balanced(AVLNode *node){
	if(node ==NULL) return 0;
	return get_height(node->left) - get_height(node->right);
}

AVLNode* create_node(int key){
	AVLNode* node= (AVLNode*)malloc(sizeof(AVLNode));
	node->key= key;
	node->left = NULL;
	node->right = NULL;
	return node;
}

AVLNode* insert(AVLNode *node, int key){
	if(node ==NULL) return (create_node(key));
	
	if(key< node->key){
		node->left = insert(node->left,key);
	}
	else if(key> node->key){
		node->right = insert(node->right,key);
	}
	else return node;
	
	int balance = get_balanced(node);
	// balance >1 이면 왼쪽 자식, balance <-1 이면 오른쪽 자식에 삽입되었고
	// key<node->left->key 이면 자식의 왼쪽에 추가 key>node->right->key 이면 자식의 오른쪽에 추가
	
	if(balance >1 && key< node->left->key){
		return rotate_right(node);
	} // LL
	if(balance <-1 && key> node->right->key){
		return rotate_left(node);
	} //RR
	if(balance >1 && key> node->left->key){
		node->left = rotate_left(node->left);
		return rotate_right(node);
	} //LR
	if(balance <-1 && key< node->right->key){
		node->right = rotate_right(node->right);
		return rotate_left(node);
	} //RL
	
	return node;
	
}

int arr[6];
int k=0;

void inorder(AVLNode *root){
	if(root !=NULL){
		inorder(root->left);
		arr[k++] = root->key;
		inorder(root->right);
	}
}

int main(){
	AVLNode *root = NULL;
	
	root = insert(root,30);
	root = insert(root,20);
	root = insert(root,10);
	root = insert(root,50);
	root = insert(root,40);
	root = insert(root,29);
	
	printf("중위 순회 결과 \n");
	inorder(root);
	for(int i=0; i<6;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
