#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10


int list[MAX_SIZE];

int interpol_search(int key, int n){
	int low, high, j;
	
	low = 0;
	high = n-1;
	while((list[high]>key)&&(key>list[low])){
		j = (float)(key-list[low])/(list[high]-list[low])*(high-low) + low;
		if(key > list[j]) low = j+1;
		else if( key< list[j]) low =j -1;
		else low = j;
	}
	if(list[low] ==key) return low;
	else return -1;
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

	
	if(interpol_search(31,9) == -1){
		printf("탐색 실패 \n");
	}
	else{
		printf("인덱스 %d에서 키값 탐색\n",interpol_search(31,9));
	}
	
	return 0;
}