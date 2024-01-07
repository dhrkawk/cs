#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;

int sorted[MAX_SIZE];

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
	list[0] = 1;
	list[1] = 2;
	list[2] = 3;
	list[3] = 5;
	list[4] = 6;
	list[5] = 8;
	list[6] = 9;
	list[7] = 10;

	
	if(binary_search_itr(5,0,7) == -1){
		printf("탐색 실패 \n");
	}
	else{
		printf("인덱스 %d에서 키값 탐색\n",binary_search_itr(5,0,7));
	}
	
	return 0;
}