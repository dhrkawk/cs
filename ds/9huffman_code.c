#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct TreeNode{
	int weight;
	char ch;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

typedef struct{
	TreeNode *ptree;
	char ch;
	int key;
}element;

typedef struct{
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

HeapType* create(){
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType *h){
	h->heap_size=0;
}

void insert_min_heap(HeapType *h, element item){
	int i;
	i = ++(h->heap_size);
	
	while((i != 1)&&(item.key < h->heap[i/2].key)){
		h->heap[i] = h->heap[i/2];
		i /=2;
	}
	h->heap[i] = item;
}

element delete_min_heap(HeapType *h){
	int parent, child;
	element item, temp;
	
	item = h->heap[1]; // 삭제할 노드는 루트노드
	temp = h->heap[(h->heap_size)--];
	parent =1;
	child =2;
	
	while(child <= h->heap_size){
		if((child<h->heap_size)&&(h->heap[child].key > h->heap[child+1].key)){
			child ++;
		} 
		if(temp.key < h->heap[child].key) break; //최대 heap 만족하면 break
		
		h->heap[parent] =h->heap[child];
		parent = child;
		child *=2;
	}// whlie문을 빠져나오면 parent 위치가 확정됨
	h->heap[parent] = temp;
	return item;
}

TreeNode* make_tree(TreeNode *left, TreeNode *right){
	TreeNode *node = malloc(sizeof(TreeNode));
	node->left = left;
	node->right = right;
	return node;
}

TreeNode* destroy_tree(TreeNode *root){
	if(root == NULL) return;
	destroy_tree(root->left);
	destroy_tree(root->right);
	free(root);
}

int is_leaf(TreeNode* root){
	return !(root->left)&& !(root->right);
}

void print_array(int codes[],int n){
	for(int i=0; i<n;i++){
		printf("%d",codes[i]);
	}
	printf("\n");
}

void print_codes(TreeNode *root, int codes[],int top){
	if(root->left)
	{
		codes[top]=1;
		print_codes(root->left,codes,top+1);
	}
	if(root->right)
	{
		codes[top]=0;
		print_codes(root->right,codes,top+1);
	}
	if(is_leaf(root)){
		printf("%c: ",root->ch);
		print_array(codes,top);
	}
	
}

void huffman_tree(int freq[],char ch_list[],int n){
	TreeNode *node ,*x;
	//node는 문자와 빈도수 구조체를 최소 히프에 담기위한 노드
	//x는 최소값을 가지는 두 노드를 e1,e2에 저장해서 key를 합한 새로운 노드를 담기위한 노드
	HeapType *heap;
	element e,e1,e2;
	int codes[100];
	int top=0;
	
	heap=create();
	init(heap);
	for(int i=0;i<n;i++){
		node = make_tree(NULL,NULL);
		e.ch = node->ch = ch_list[i];
		e.key= node->weight = freq[i];
		e.ptree = node;
		insert_min_heap(heap,e);
	}
	for(int i=1;i<n;i++){
		e1 = delete_min_heap(heap);
		e2 = delete_min_heap(heap);
		
		x = make_tree(e1.ptree,e2.ptree);
		e.key = x->weight = e1.key+e2.key;
		e.ptree = x;
		printf("%d+%d->%d \n",e1.key,e2.key,e.key);
		insert_min_heap(heap,e);
	}
	e = delete_min_heap(heap);
	print_codes(e.ptree,codes,top);
	destroy_tree(e.ptree);
	free(heap);
}


int main(){
	char ch_list[]={'s','i','n','t','e'};
	int freq[] = {4, 6, 8, 12, 15};
	huffman_tree(freq,ch_list,5);
	return 0;
}
