#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;

void bubble_sort(int list[], int n){
	int i, j, temp;
	for(i = n-1; i>0; i--){//한번의 pass마다 정렬된 부분의 크기가 1증가
		for(j =0; j<i; j++){//정렬되지 않은 부분이 없을 때까지 = i전까지
			if(list[j]>list[j+1]){
				SWAP(list[j],list[j+1],temp);
			}
		}
	}
}

int main(){
	int i;
	n =MAX_SIZE;
	srand(time(NULL));
	for(i=0; i<n; i++){
		list[i] = rand() %100;
	}
	bubble_sort(list,n);
	for(i=0; i<n; i++){
		printf("%d ",list[i]);
	}
	printf("\n");
	
	return 0;
}
