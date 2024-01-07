#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define INDEX_SIZE 256

int list[MAX_SIZE];

typedef struct{
	int key;
	int index;
}itable;

itable index_list[INDEX_SIZE];

int seq_search(int key, int low, int high){
	int i;
	for(i=low;i<=high;i++){
		if(list[i]==key){
			return i;
		}
	}
	return -1;
}

int index_search(int key,int n){
	int i,low,high;
	
	if(key<list[0] || key>list[n-1]) return -1;
	
	for(i=0; i<INDEX_SIZE; i++){
		if(index_list[i].key <=key && index_list[i].key>key) break;
	}
	
	if(i == INDEX_SIZE){
		low = index_list[i-1].index;
		high = n;
	}
	else{
		low = index_list[i].index;
		high = index_list[i+1].index;
	}
	return seq_search(key,low,high);
}


int main(){
	list[0] = 3;
	list[1] = 9;
	list[2] = 15;
	list[3] = 22;
	list[4] = 31;
	list[5] = 55;
	list[6] = 67;
	list[7] = 88;
	list[8] = 91;
	
	index_list[0].key = 3;
	index_list[0].index = 0;

	index_list[1].key = 22;
	index_list[1].index = 3;

	index_list[2].key = 67;
	index_list[2].index = 6;


	
	if(index_search(31,9) == -1){
		printf("탐색 실패 \n");
	}
	else{
		printf("인덱스 %d에서 키값 탐색\n",index_search(31,9));
	}
	
	return 0;
}