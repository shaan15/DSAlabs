#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 10

struct node{
	int data;
	int dist;
	int final;
	char color[6];
  struct node * next;
	struct node * p;
};
typedef struct node NODE;
NODE *temp,*temp2,*temp3;
NODE * head[MAX_SIZE];
NODE * tail[MAX_SIZE];

struct queue{
	NODE * arr[MAX_SIZE];
	int head;
	int tail;
};
typedef struct queue QUEUE;

void enqueue(QUEUE *q,NODE * s){
			q->arr[q->tail]=s;
			if(q->tail==MAX_SIZE-1)q->tail=0;
			else q->tail+=1;
	}

NODE * dequeue(QUEUE *q){
	if(q->head == q->tail)return NULL;
	else{
		temp=q->arr[q->head];
		if(q->head==MAX_SIZE-1)q->head=0;
		else q->head+=1;
		return temp;
	}
}

void create(int value){
  temp=(NODE *)malloc(sizeof(NODE));
  temp->next=NULL;
  temp->data=value;
	temp->p=NULL;
	temp->dist=0;
	temp->final=0;
	strcpy(temp->color,"DULL");
}

void insert_end(NODE ** head,NODE ** tail,int x){
  if(*head==NULL){
    create(x);
    *head=temp;
    *tail=temp;
  }
  else{
    create(x);
    temp->next=NULL;
    (*tail)->next=temp;
    (*tail)=temp;
  }
}

void bfs(QUEUE * q,NODE * s){
	int i;
	for(i=0;i<MAX_SIZE;i++){
		strcpy(head[i]->color,"WHITE");
		// temp=head[i]->next;
		// while(temp!=NULL){
		// 	strcpy(temp->color,"WHITE");
		// }
	}
	strcpy(s->color,"GRAY");
	s->dist=0;
	q->head=q->tail=0;
	enqueue(q,s);
	while(q->head != q->tail){
		temp = dequeue(q);
		temp2 = head[temp->data]->next;
		while(temp2!=NULL){
			temp3 =	head[temp2->data];
			if(strcmp(temp3->color,"WHITE")==0){
				strcpy(temp3->color,"GRAY");
				temp3->dist=temp->dist+1;
				temp3->p=temp;
				enqueue(q,temp3);
			}
			temp2=temp2->next;
		}
		strcpy(temp->color,"BLACK");
	}
}

void dfs_visit(NODE * u,int *t){
		(*t)=(*t)+1;
		u->dist=(*t);

		printf("%d\n",*t);

		strcpy(u->color,"GRAY");
		NODE * temporary=u->next;

		while(temporary!=NULL){
			temp2=head[temporary->data];
			if(strcmp(temp2->color,"WHITE")==0){
				temp2->p=u;
				dfs_visit(temp2,t);
			}
			temporary=temporary->next;
		}
		strcpy(u->color,"BLACK");
		(*t)=(*t)+1;
		u->final=(*t);
}

void dfs(){
	int i;
	for(i=0 ; i<MAX_SIZE ; i++){
		strcpy(head[i]->color,"WHITE");
		head[i]->p=NULL;
	}
	int t=0;
	for(i=0 ; i<MAX_SIZE ; i++){
		if(strcmp(head[i]->color,"WHITE")==0) dfs_visit(head[i],&t);
	}
}

int main(){
  int i,n;
  // printf("Enter number of vertices: ");
  // scanf("%d",&n);
	for(i=0;i<MAX_SIZE;i++){
		create(i);
		head[i]=temp;
		tail[i]=NULL;
	}

	int a,b;
  printf("Enter link(origin destination): ");
  scanf("%d %d",&a,&b);
  while(a!=-1 && b!=-1){
    insert_end(&(head[a]->next),&(tail[a]),b);
    printf("Enter link(origin destination): ");
    scanf("%d %d",&a,&b);
  }

	for(i=0;i<MAX_SIZE;i++){
		printf("Edges adjacent to %d are: ",i);
		temp=head[i]->next;
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}

	//BFS
	QUEUE q;
	q.head=0;
	q.tail=0;

	printf("Choose s(enter a valid integer): ");
	scanf("%d",&n);
	NODE * s=head[n];
	bfs(&q,s);
	for(i=0;i<MAX_SIZE;i++){
		printf("Distance of %d from %d is : %d\n",i,n,head[i]->dist);
	}

	//DFS
	dfs();
	for(i=0;i<MAX_SIZE;i++){
		printf("node %d : %d %d\n",i,head[i]->dist,head[i]->final);
	}
	return 0;
}