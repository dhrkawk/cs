#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;

int sorted[MAX_SIZE];

void merge(int list[],int left, int mid, int right){
	int i,j,k,l;
	i = left; j = mid+1; k= left;
	
	while(i<=mid && j<=right){
		if(list[i]<=list[j]){
			sorted[k++] = list[i++];
		}
		else{
			sorted[k++] = list[j++];
		}
	}
	
	if(i>mid){
		for(l=j; l<=right; l++){
			sorted[k++] = list[l];
		}
	}
	else{
		for(l=i; l<=mid;l++){
			sorted[k++] = list[l];
		}
	}
	
	for(l = left; l<=right; l++){
		list[l]= sorted[l];
	} // sorted는 정렬용으로 사용하는 배열이므로 list에 재복사
}



void merge_sort(int list[],int left, int right){
	int mid;
	if(left<right){
		mid = (left + right) / 2;
		merge_sort(list,left,mid);
		merge_sort(list,mid+1,right);
		merge(list,left,mid, right);
	}
}

int main(){
	int i;
	n =MAX_SIZE;
	srand(time(NULL));
	for(i=0; i<n; i++){
		list[i] = rand() %100;
	}
	merge_sort(list,0,n-1);
	for(i=0; i<n; i++){
		printf("%d ",list[i]);
	}
	printf("\n");
	
	return 0;
}