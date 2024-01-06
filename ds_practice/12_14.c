#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;

void insertion_sort(int list[], int n){
	int i, j, key, m;
	for(i=1; i<n; i++){
		key = list[i];
		for(j=i-1;j>=0&&list[j]>key;j--){
			list[j+1] = list[j];
		}
		list[j+1] = key;
		for(m =0; m<i;m++){
			printf("%d ",list[m]);
		}
		printf("    ");
		for(m=i; m<n;m++){
			printf("%d ",list[m]);
		}
		printf("\n");
	}
}

int main(){
	int i;
	n =MAX_SIZE;
	srand(time(NULL));
	for(i=0; i<n; i++){
		list[i] = rand() %100;
	}
	insertion_sort(list,n);
	
	return 0;
}
