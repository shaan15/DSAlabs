#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10001

int arr[MAX_SIZE];
int parent[MAX_SIZE];
int min;
int max = 1;


int find_set(int i){
	while(i != parent[i]){
		i = parent[i];
	}
	return i;
}

void union_set(int i,int j){
	if(parent[i] != parent[j]){
		int root = find_set(j);
		parent[root] = parent[i];
		arr[parent[i]] += arr[root];
		arr[j]=0;
		return;
	}
	return;
}

void link(int i,int j,int n){
	union_set(i,j);
	min=arr[1];
	//int size = arr[parent[i]]+arr[parent[j]];
	//arr[parent[i]]=size;
	//arr[i] = size;
	//arr[j] = size;
	int k;
	for(k=1;k<(n+1);k++){
		if(arr[k] > max){
			max = arr[k];
		}
		if( arr[k]!=0 && arr[k] < min){
			min = arr[k];
		}
	}
}

int main(){
	int N,Q;
	scanf("%d %d",&N,&Q);
	/*int arr[N+1];
	int final[N+1];*/

	int i=0;
	for(i=1;i<(N+1);i++){
		arr[i] = 1;
		parent[i] = i;
	}
	min = arr[1];
	while(Q--){
		char query[4];
		scanf("%s",query);
		if(strcmp(query,"M")==0){
			int x,y;
			scanf("%d %d",&x,&y);
			link(x,y,N);
		}
		else if(strcmp(query,"Q")==0){
			int x;
			scanf("%d",&x);
			printf("%d\n",arr[parent[x]]);

		}
		else if(strcmp(query,"MIN")==0){
			printf("%d\n",min);
			/*int k;
			for(k=1;k<(N+1);k++){
				if()
			}*/

		}
		else if(strcmp(query,"MAX")==0){
			printf("%d\n",max);

		}
	}
	return 0;
}
