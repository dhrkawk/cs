
//4-14
int size(Stacktype *s){
	return s->top + 1;
}

//4-15
for(int i=0;i<MAZE_SIZE;i++){
	for(int j=0; j<MAZE_SIZE;j++){
		if(maze[i][j]=='.'){
			printf("(%d, %d)",i,j);
		}
	}
}