#include <stdio.h>
#define WHITE 0
#define YELLOW 2
#define BLACK 1
#define WIDTH 10
#define HEIGHT 10

int ackermann(int m,int n){
	if(m==0) return n+1;
	else if(n==0) return ackermann(m-1,1);
	else return ackermann(m-1,ackermann(m,n-1));
}
// 위는 18번 아래는 21번

int map[WIDTH][HEIGHT];

void fill(int x,int y){
	if(map[x][y]==0){
		map[x][y]=1;
	}
	fill(x+1,y);
	fill(x-1,y);
	fill(x,y+1);
	fill(x,y-1);
}