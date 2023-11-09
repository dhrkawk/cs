#include <stdio.h>

void insert(int array[],int loc, int value,int items){
	for(int i=items; i>=loc; i--){
		array[i] = array[i-1];
	}
	array[loc-1]=value;
	items++;
}

void delete(int array[],int loc,int items){
	for(int i=loc; i<=items;i++){
		array[i-1] = array[i];
	}
	items--;
}

int main(){
	int arr[9] = {1,2,3,4,5,6,7,8};
	insert(arr,3,11,8);
	for(int i=0;i<9;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	delete(arr,3,9);
	for(int i=0;i<8;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}