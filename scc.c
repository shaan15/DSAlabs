#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct snode{
	int data;
	int dist;
	int final;
	char colour[6];
  struct snode * next;
	struct snode * p;
};
typedef struct snode node;
node *temp,*temp2,*temp3;
node * head[MAX_SIZE];
node * head1[MAX_SIZE];
node * tail[MAX_SIZE];
node * tail

void create(int value){
  	temp=(node *)malloc(sizeof(node));
  	temp->next=NULL;
  	temp->data=value;
	temp->p=NULL;
	temp->dist=0;
	temp->final=0;
	strcpy(temp->colour,"GRAY");
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

void dfs_visit(node * u,int *t){
		(*t)=(*t)+1;
		u->dist=(*t);

		printf("%d\n",*t);

		strcpy(u->colour,"GRAY");
		node * temporary=u->next;

		while(temporary!=NULL){
			temp2=head[temporary->data];
			if(strcmp(temp2->colour,"WHITE")==0){
				temp2->p=u;
				dfs_visit(temp2,t);
			}
			temporary=temporary->next;
		}
		strcpy(u->colour,"BLACK");
		(*t)=(*t)+1;
		u->final=(*t);
}

void dfs(){
	int i;
	for(i=0 ; i<MAX_SIZE ; i++){
		strcpy(head[i]->colour,"WHITE");
		head[i]->p=NULL;
	}
	int t=0;
	for(i=0 ; i<MAX_SIZE ; i++){
		if(strcmp(head[i]->colour,"WHITE")==0) {
			dfs_visit(head[i],&t);
		}
	}
}

void dfs_visit(node * u,int *t){
		(*t)=(*t)+1;
		u->dist=(*t);

		strcpy(u->colour,"GRAY");
		node * temporary=u->next;

		while(temporary!=NULL){
			temp2=head1[temporary->data];
			if(strcmp(temp2->colour,"WHITE")==0){
				temp2->p=u;
				dfs_visit(temp2,t);
			}
			temporary=temporary->next;
		}
		strcpy(u->colour,"BLACK");
		(*t)=(*t)+1;
		u->final=(*t);
}

void dfs(){
	int i;
	for(i=0 ; i<MAX_SIZE ; i++){
		strcpy(head1[i]->colour,"WHITE");
		head1[i]->p=NULL;
	}
	int t=0;
	for(i=0 ; i<MAX_SIZE ; i++){
		if(strcmp(head1[i]->colour,"WHITE")==0) {
			dfs_visit(head1[i],&t);
		}
	}
}

int main(){
  int i,n;
  // printf("Enter number of vertices: ");
  	scanf("%d",&n);
	for(i=0;i<MAX_SIZE;i++){
		create(i);
		head[i]=temp;
		tail[i]=NULL;
	}

	int a,b;
  	scanf("%d %d",&a,&b);
  	while(a!=-1 && b!=-1){
    	insert_end(&(head[a]->next),&(tail[a]),b);
    	insert_end(&(head1[b]->next),&(tail1[b]),a);
    //printf("Enter link(origin destination): ");
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

	dfs();
	for(i=0;i<MAX_SIZE;i++){
		//printf("node %d : %d %d\n",i,head[i]->dist,head[i]->final);
	}
	return 0;
}