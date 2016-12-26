#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min,

int find(int i){
	while(parent[i] != NULL){
		i = parent[i];
	}
	return i;
}

int union_set(int i,int j){
	if(i != j){
		parent[j] = i;
		return 1;
	}
	return 0;
}

int make_matrix(int n){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&mat[i][j]);
			if(mat[i][j] == 0){
				mat[i][j] = 999;
			}
		}
	}
}

int main(){
	int i,j,k,x,y,u,v,n;
}