#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;

typedef struct{
	int key;
	char name[30];
}record;

void insertion_sort(record list[], int n){
	int i, j;
	record r;
	for(i=1; i<n; i++){
		r = list[i];
		for(j=i-1;j>=0&&list[j].key>r.key;j--){
			list[j+1]= list[j];
		}
		list[j+1] = r;
	}
}

int main(){
	record list[MAX_SIZE] = {{10,"10살"},{30,"30살"},{20,"20살"},{40,"40살"}};
	n= MAX_SIZE;
	insertion_sort(list,n);
	for(int i=0; i<n; i++){
		printf("%s ",list[i].name);
	}
	printf("\n");
	
	return 0;
}
