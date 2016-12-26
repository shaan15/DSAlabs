#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10001

struct treenode{
	int data;
	struct treenode *next;
	//struct treenode *parent;
};
typedef struct treenode node;
node *temp,*temp1,*temp2;
node *head[MAX_SIZE];
node *tail[MAX_SIZE];

struct edge{
	int start;
	int end;
	int w;
};

typedef struct edge edge;

struct graph{
	int v;
	int e;
	edge * ed;
};

int parent[MAX_SIZE];
typedef struct graph graph;
//edge *newedge;
edge * array[MAX_SIZE];
int arr_wt[MAX_SIZE];
int ed_num = 1;
int weight_sum = 0;

void create_node(int val){
	temp = (node *)malloc(sizeof(node));
	temp->next = NULL;
	temp->data = val;
	//temp->parent  = NULL;
}

edge * create_edge(int x,int y,int w){
	edge * newedge = (edge *)malloc(sizeof(edge));
	newedge->start = x;
	newedge->end = y;
	newedge->w = w;
	return newedge;

}

void insert_beg(node ** head,int x){
	if((*head) == NULL){
		create_node(x);
		(*head) = temp;
	}
	else{
		create_node(x);
		temp->next = (*head)->next;
		(*head)->next = temp;
	}
}

void swap(int *x,int *y){
	int x_val=*x;
	*x=*y;
	*y=x_val;
}

void swap1(edge **a,edge **b){
	edge* a_val=*a;
	*a=*b;
	*b=a_val;
}

int partition(int *arr,edge * A[],int p,int r){
	int x=arr[r];
	int i=p-1;
	int j;
	for(j=p;j<r;j++){
		if(arr[j]>=x){
			i++;
			swap(&arr[i],&arr[j]);
			swap1(&A[i],&A[j]);
			/*edge *tmp;
			tmp=A[i];
			A[i]=A[j];
			A[j]=tmp;*/
		}
	}
	swap(&arr[i+1],&arr[r]);
	swap1(&A[i+1],&A[r]);
	return(i+1);
}

void quicksort(int *arr,edge * A[],int p,int r){
	if(p<r){
		int q=partition(arr,A,p,r);
		quicksort(arr,A,p,q-1);
		quicksort(arr,A,q+1,r);
	}
}


int find_set(int i){
	while(i != parent[i]){
		i = parent[i];
	}
	return i;
}

int union_set(int i,int j){
	if(parent[i] != parent[j]){
		int root = find_set(j);
		parent[root] = i;
		return 1;
	}
	return 0;
}
/*int make_set(int i){
	int j;

}*/

void kruskal(int v,int e){
	/*graph * A = (graph *)malloc(sizeof(graph));
	A->v = v;
	A->e = e;
	A->ed = (edge *)malloc(sizeof(A->ed)*sizeof(edge));
	int i;*/
	int i;
	edge current;
	//printf("hi before loop\n");
	for(i=1;i<(v+1);i++){
		parent[i] = i;
		//printf("hi in loop\n");
	}
	//printf("hi\n");
	quicksort(arr_wt,array,1,ed_num);
	for(i=1;i<=ed_num;i++){printf("%d ",arr_wt[i]);}
		printf("\n");
	printf("%d %d %d\n",array[i]->start,array[i]->end,array[i]->w);
	int j;
	//printf("%d",ed_num);
	for(j=1;j<ed_num;j++){
		//printf("%d\n",j);
		current = *array[j];
		//printf("hi!");
		int start = current.start;
		int end = current.end;
		//printf("%d %d %d\n", start, end, current.w);
		if(find_set(start) != find_set(end)){
			union_set(find_set(start),find_set(end));
			weight_sum = weight_sum + current.w;
			//printf("Weight sum: %d\n",weight_sum);
		}
	}
	printf("%d\n",weight_sum);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		edge * lol;
		int v,e;
		scanf("%d %d",&v,&e);
		int i;
		/*for(i=1;i<(v+1);i++){mmj
			create_node(i);
			head[i] = temp;
			tail[i] = NULL;*/
		//}
		for(i = 0; i<e; i++){
			int x,y,w;
			scanf("%d %d %d",&x,&y,&w);
			//insert_beg(&(head[x]),y);
			edge * lol = create_edge(x,y,w);
			array[ed_num] = lol;
			arr_wt[ed_num] = lol->w;
			ed_num++;

		}
		kruskal(v,e);
		weight_sum = 0;
		ed_num = 1;
	}
}

