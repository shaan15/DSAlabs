#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100001

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
	if(i != j){
		int root = find_set(j);
		parent[root] = i;
		int p = find_set(i);
		arr[p] += arr[root];
		if(arr[p]>max){
			max=arr[p];
		}
		return;
	}
	return;
}

// void link(int i,int j,int n){
// 	union_set(i,j);
// 	int size = arr[i]+arr[j];
// 	arr[i] = size;
// 	arr[j] = size;
// 	if(size>max)max=size;
// }

void minimum(n){
	int k;
	min=100000;
	for(k=1;k<(n+1);k++){
		if(arr[find_set(k)] < min){
			min = arr[k];
		}
	}

}

int main(){
	int N,Q;
	scanf("%d %d",&N,&Q);
	/*int arr[N+1];
	int final[N+1];*/

	int i;
	for(i=1;i<(N+1);i++){
		arr[i] = 1;
		parent[i] = i;
	}
	// min = N;
	while(Q--){
		char query[4];
		scanf("%s",query);
		if(strcmp(query,"M")==0){
			int x,y;
			scanf("%d %d",&x,&y);
			union_set(find_set(x),find_set(y));
			// link(x,y,N);
		}
		else if(strcmp(query,"Q")==0){
			int x;
			scanf("%d",&x);
			int num=find_set(x);
			printf("%d\n",arr[num]);

		}
		else if(strcmp(query,"MIN")==0){
			//printf("%d\n",min);
			/*int k;
			for(k=1;k<(N+1);k++){
				if()
			}*/
			minimum(N);
			printf("%d\n",min);

		}
		else if(strcmp(query,"MAX")==0){
			printf("%d\n",max);

		}
	}
	return 0;
}

