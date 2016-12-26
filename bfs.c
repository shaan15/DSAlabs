#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100001

struct treenode{
	int data;
	int dist;
	int final;
	char colour[6];
  struct treenode * next;
	struct treenode * p;
};
typedef struct treenode node;
node *temp,*temp1,*temp3;
node * head[MAX_SIZE];
node * tail[MAX_SIZE];

struct queue{
	node * arr[MAX_SIZE];
	int head;
	int tail;
};
typedef struct queue QUEUE;

void enqueue(QUEUE *q,node * s){
			q->arr[q->tail]=s;
			if(q->tail==MAX_SIZE-1)q->tail=0;
			else q->tail+=1;
	}

node * dequeue(QUEUE *q){
	if(q->head == q->tail)return NULL;
	else{
		temp=q->arr[q->head];
		if(q->head==MAX_SIZE-1)q->head=0;
		else q->head+=1;
		return temp;
	}
}

void create(int val){
  temp=(node *)malloc(sizeof(node));
  temp->next=NULL;
  temp->data=val;
	temp->p=NULL;
	temp->dist=-1;
	temp->final=0;
	strcpy(temp->colour,"DULL");
}

void insert_end(node ** head,node ** tail,int x){
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

void bfs(QUEUE * q,node * s,int n){
	int i;
	for(i=1;i<n+1;i++){
		strcpy(head[i]->colour,"WHITE");
	}

	strcpy(s->colour,"GRAY");
	s->dist=0;
	q->head=q->tail=0;
	enqueue(q,s);
	while(q->head != q->tail){
		temp = dequeue(q);
		temp1 = head[temp->data]->next;
		while(temp1!=NULL){
			temp3 =	head[temp1->data];
			if(strcmp(temp3->colour,"WHITE")==0){
				strcpy(temp3->colour,"GRAY");
				temp3->dist=temp->dist+1;
				// temp3->p=temp;
				enqueue(q,temp3);
			}
			temp1=temp1->next;
		}
		strcpy(temp->colour,"BLACK");
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		QUEUE q;
		// node *root=NULL;
/*		head = NULL;
		tail=NULL;*/
		int n,m;
		scanf("%d %d",&n,&m);
		int j;
		for(j=1;j<(n+1);j++){
			create(j);
			head[j]=temp;
			tail[j]=NULL;
		}
		while(m--){
			int x,y;
			scanf("%d %d",&x,&y);
			insert_end(&(head[x]->next),&(tail[x]),y);
			insert_end(&(head[y]->next),&(tail[y]),x);
		}
		//QUEUE *q;
		q.head=0;
		q.tail=0;
		int city=1;
		node * s=head[city];
		bfs(&q,s,n);
		// int i;
		// int min=0;
		// for(i=1;i<(n+1);i++){
		// 	if((head[i])->dist < min){
		// 		min = (head[i])->dist;
		// 	}
		// }
		printf("%d\n",head[n]->dist);
	}
	return 0;
}

