#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define INDEX_SIZE 256

int list[MAX_SIZE];


int binary_search(int key, int low, int high){
	int middle;
	
	if(low<high){
		middle = (low+high) /2;
		if(key == list[middle]){
			return middle;
		}
		else if(key <list[middle]){
			return binary_search(key, low, middle-1);
		}
		else{
			return binary_search(key,middle+1,high);
		}
	}
	return -1;
}

int binary_search_itr(int key, int low, int high){
	int middle;
	while(low<high){
		middle = (low+high)/2;
		if(key == list[middle]){
			return middle;
		}
		else if(key<list[middle]){
			high = middle -1;
		}
		else{
			low = middle +1;
		}
	}
	return -1;
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
	
	if(binary_search(31,0,9) == -1){
		printf("탐색 실패 \n");
	}
	else{
		printf("인덱스 %d에서 키값 탐색\n",binary_search(31,0,9));
	}
	
	return 0;
}
