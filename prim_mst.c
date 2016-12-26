#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct treenode{
	int end;
	int w;
	struct treenode *next;
};

typedef struct  treenode node;

struct list{
	struct list *head;
};

typedef struct list adj;

struct graph{
	int v;
	adj * arr;
};

node * create_node(int f,int w){
	node * newnode = (node *)malloc(sizeof(node));
	newnode->end = f;
	newnode->w = w;
	newnode->next = NULL;
	return newnode;
}

graph * create_graph(int v){
	graph * temp = (graph *)malloc(sizeof(graph));
	temp->v = v;
	temp->arr = (adj *)malloc(sizeof(adj) * v);
	int i;
	for(i=0;i<v;i++){
		temp->arr[i]->head = NULL;
	}
	return temp;
}

void make_edge(graph * temp,int start,int final,int wt){
	adj * newnode = 
}