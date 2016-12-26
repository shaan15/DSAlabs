#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100010

typedef struct queue{
	int arr[MAX_VERTICES];
	int front;
	int rear;
} queue;

int isempty(queue *q){
	if(q->front == -1)
		return 1;
	else
		return 0;
}

void enqueue(queue *q, int val){
	if(isempty(q))
		q->front = q->rear = 0;
	else
		q->rear += 1;
	q->arr[q->rear] = val;
}

int dequeue(queue *q){
	if(isempty(q))
		return -1;
	int x = q->arr[q->front];
	if(q->front == q->rear)
		q->front = q->rear = -1;
	else
		q->front +=1;
	return x;
}

typedef struct adj_list_node{
	int ver;
	adj_list_node *next;
} adjNode;

typedef struct vertex{
	int color;
	int distance;
	// int index;
	int final;
	int pred_index;
	adjNode *next;
} V;

V *arr[MAX_VERTICES];
V *trans[MAX_VERTICES];
int tim = 0;

void insert_node(int root,  adjNode *z){
	z->next = arr[root]->next;
	arr[root]->next = z;
	// printf("%s\n", "in function insert_node");
}

void create_edge(int a, int b){
	adjNode *new_node = (adjNode *)malloc(sizeof(adjNode));
	new_node->ver = b;
	insert_node(a, new_node);
}

void insert_node_trans(int root,  adjNode *z){
	z->next = trans[root]->next;
	trans[root]->next = z;
}

void create_edge_trans(int a, int b){
	adjNode *new_node = (adjNode *)malloc(sizeof(adjNode));
	new_node->ver = b;
	insert_node_trans(a, new_node);
}

// void create_graph(int x, int y){
// 	create_edge(x, y);
// 	// create_edge(y, x);
// }

void make_transpose(int n){
	int i = 0;
	for(i=0; i<n; i++){
		trans[i] = (V *)malloc(sizeof(V));
		trans[i]->color = 0;
		trans[i]->distance = -1;
		trans[i]->final = -1;
		trans[i]->next = NULL;
		trans[i]->pred_index = -1;
	}
	for(i=0; i<n; i++){
		adjNode *temp = arr[i]->next;
		while(temp != NULL){
			create_edge_trans(temp->ver, i);
			temp = temp->next;
		}
	}
}

void DFS(int);
void DFS_VISIT(int);
void DFS_trans(int);
void DFS_VISIT_trans(int);
int find_maxim(int);

void DFS(int n){
	int i = 0;
	tim = 0;
	for(i=0; i<n; i++){
		if(arr[i]->color == 0){
			DFS_VISIT(i);
		}
	}
}

void DFS_VISIT(int x){
	tim += 1;
	arr[x]->distance = tim;
	arr[x]->color = 1;
	adjNode *temp = arr[x]->next;
	while(temp != NULL){
		if(arr[temp->ver]->color == 0){
			arr[temp->ver]->pred_index = x;
			DFS_VISIT(temp->ver);
		}
		temp = temp->next;
	}
	arr[x]->color = 2;
	tim += 1;
	arr[x]->final = tim;
	printf("%d %d %d\n", x+1, arr[x]->distance, arr[x]->final);
}

int find_maxim(int n){
	int i = 0;
	while(i<n && arr[i]->color == 3)
		i++;
	int maxim;
	if(i<n)
		maxim = i;
	else return -1;
	int x = i+1;
	for(i=x; i<n; i++){
		if(arr[i]->color != 3 && arr[i]->final > arr[maxim]->final)
			maxim = i;
	}

	arr[maxim]->color = 3;
	return maxim;
}

void DFS_trans(int n){
	int i = 0;
	tim = 0;
	for(i=0; i<n; i++){
		int maxim = find_maxim(n);
		printf("maxim = %d\n", maxim+1);
		if(maxim != -1){
			if(trans[maxim]->color == 0){
				DFS_VISIT_trans(maxim);
				printf("\n");
			}
		}
	}
}

void DFS_VISIT_trans(int x){
	tim += 1;
	trans[x]->distance = tim;
	trans[x]->color = 1;
	adjNode *temp = trans[x]->next;
	int maxim;
	while(temp != NULL && arr[temp->ver]->color == 3){
		temp=temp->next;
	}
	if(temp != NULL){
		maxim = temp->ver;
	}
	else{
		trans[x]->color = 2;
		tim += 1;
		trans[x]->final = tim;
		printf("%d->", x+1);
		return;
	}
	while(temp != NULL){
		if(arr[temp->ver]->color != 3){
			if(arr[maxim]->final < arr[temp->ver]->final)
				maxim = temp->ver;
		}
		temp = temp->next;
	}
	arr[maxim]->color = 3;
	if(trans[maxim]->color == 0){
		trans[maxim]->pred_index = x;
		DFS_VISIT_trans(maxim);
	}
	trans[x]->color = 2;
	tim += 1;
	trans[x]->final = tim;
	printf("%d->", x+1);
}

void display(int n){
	int i = 0;
	for(i=0; i<n; i++){
		adjNode *temp = arr[i]->next;
		printf("%d", i+1);
		while(temp != NULL){
			printf("->%d", temp->ver + 1);
			temp = temp->next;
		}
		printf("\n");
	}
}

void display_trans(int n){
	int i = 0;
	for(i=0; i<n; i++){
		adjNode *temp = trans[i]->next;
		printf("%d", i+1);
		while(temp != NULL){
			printf("->%d", temp->ver + 1);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main(){
	int v, e;
	scanf("%d %d", &v, &e);
	int i = 0;
	for(i =0; i<v; i++){
		arr[i] = (V *)malloc(sizeof(V));
		arr[i]->next = NULL;
		arr[i]->color = 0;
		arr[i]->distance = -1;
		arr[i]->final = -1;
		arr[i]->pred_index = -1;
	}
	int x, y;
	while(e--){
		scanf("%d %d", &x, &y);
		create_edge(x-1, y-1);
	}
	display(v);
	DFS(v);
	make_transpose(v);
	display_trans(v);
	DFS_trans(v);
	return 0;
}