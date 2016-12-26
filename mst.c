#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000001

struct treenode{
	long int data;
	long int dist;
	//long int w;
	char colour;
  struct treenode * next;
  struct treenode * parent;
};

typedef struct treenode node;
node *temp,*temp1,*temp3;
node * head[MAX_SIZE];
node * tail[MAX_SIZE];

struct edge_graph{
	int start;
	int end;
	int w;
};

typedef struct edge_graph edge;

struct graph{
	int v;
	int e;
	edge *ed;
};

typedef struct graph graph;
graph * temp4;
edge * array[MAX_SIZE];
int arr_wt[MAX_SIZE];
//edge * lol;
int ed_num = 0;

void create_graph(int v,int e){
	temp4 = (graph *)malloc(sizeof(graph));
	temp4->v = v;
	temp4->e = e;
	//temp4->w = w;
	temp4->ed = (edge *)malloc(sizeof(temp4->ed * sizeof(edge)));
	//return temp4;
}

edge * create_edge(int x,int y,int w){
	edge * tp=(edge *)malloc(sizeof(edge));
	edge->start=x;
	edge->end=y;
	edge->w=w;
	return tp;
}



/*struct edge_tree{
	long int w;
	long start;
	long end;
};
 typedef struct edge_tree edge;


//typedef struct dist_queue queue;
long int count;*/

void create(long int val){
  	temp=(node *)malloc(sizeof(node));
  	temp->next=NULL;
  	temp->data=val;
	temp->dist=-1;
	temp->colour='w';
}

void insert_beg(node ** head,long int x){
  if((*head)==NULL){
    create(x);
    (*head)=temp;
    //*tail)=temp;
  }
  else{
    create(x);
    temp->next=(*head)->next;
    (*head)->next=temp;
    // (*tail)=temp;
  }
}

int find_set(int i){
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
void make_set(int n){
	int i;
	for(i=0;i<n;i++){

	}
}

void swap(int *x,int *y){
	int x_val=*x;
	*x=*y;
	*y=x_val;
}

int partition(int *arr,int p,int r){
	int x=arr[r];
	int i=p-1;
	int j;
	for(j=p;j<r;j++){
		if(arr[j]>=x){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[r]);
	return(i+1);
}

void quicksort(int *arr,int p,int r){
	if(p<r){
		int q=partition(arr,p,r);
		quicksort(arr,p,q-1);
		quicksort(arr,q+1,r);
	}
}

void kruskal(int u, int v){
	int i;
	for(i=0;i<n;i++){
		make_set(i);
	}
	quicksort(arr_wt,0,ed_num);
	int j;
	for(j=0;j<ed_num;j++){
		if(find_set(u) != find_set(v)){
			union_set(u,v);
		}
	}


}

int main(){
	long int T;
	scanf("%ld",&T);
	while(T--){
		edge * lol;
		long int n;
		scanf("%ld",&n);
		long int i;
		for(i=0;i<n;i++){
			create(i);
			head[i]=temp;
			tail[i]=NULL;
		}
		long int q;
		scanf("%ld",&q);
		while(q--){
			long int x,y,w;
			scanf("%ld %ld %ld",&x,&y,&w);
			insert_beg(&(head[x]),y);
			edge * lol = create_edge(x,y,w);
			array[ed_num] = lol;
			arr_wt[ed_num] = lol->w;
			ed_num++;
		}
		kruskal();
	}
}