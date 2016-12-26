#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
//graph * temp;

void create(int v,int e){
	graph * temp = (graph *)malloc(sizeof(graph));
	temp->v = v;
	temp->e = e;
	temp->ed = (edge *)malloc(sizeof(temp->e * sizeof(edge)));
	return temp;
}

