#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;


int partition(int list[],int left, int right){
	int pivot, temp;
	int low, high;
	
	low = left;
	high = right +1; // 아래 do-while문에서 한 칸씩 이동해야하기 때문
	pivot = list[left];
	
	do{
		do{
			low++;
		}while(list[low]<pivot);
		do{
			high--;
		}while(list[high]>pivot);
		if(low<high) SWAP(list[low],list[high],temp);
	}while(low<high);
	
	SWAP(list[left],list[high],temp);
	// pivot과 high인덱스에 위치한 요소를 교환
	return high;
	
}

void quick_sort(int list[],int left, int right){
	if(left<right){
		int q = partition(list,left,right);
		quick_sort(list,left,q-1);
		quick_sort(list,q+1,right);
	}
}

int main(){
	int i;
	n =MAX_SIZE;
	srand(time(NULL));
	for(i=0; i<n; i++){
		list[i] = rand() %100;
	}
	quick_sort(list,0,n-1);
	for(i=0; i<n; i++){
		printf("%d ",list[i]);
	}
	printf("\n");
	
	return 0;
}