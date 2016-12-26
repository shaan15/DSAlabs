#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10001

struct snode{
	int data;
	int dist;
	int final;
	char colour[6];
	int integer;
  struct snode * next;
	struct snode * p;
};
typedef struct snode node;
node *temp,*temp2,*temp3;
node * head[MAX_SIZE];
node * tail[MAX_SIZE];


struct stack{
	int arr[MAX_SIZE];
	int top;
};
typedef struct stack STACK;
STACK s;
int flag;

void create(int value){
  	temp=(node *)malloc(sizeof(node));
  	temp->next=NULL;
  	temp->data=value;
	temp->p=NULL;
	temp->dist=0;
	temp->final=0;
	strcpy(temp->colour,"GRAY");
	temp->integer = 0;
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



void pop(STACK *stk){
	if(stk->top==-1){
		return;
	}
	else{
		printf("%d ",stk->arr[stk->top]);
		stk->top--;
	}
}

void push(STACK *stk,int num){
	if(stk->top==MAX_SIZE-1){
		return;
	}
	else{
		stk->top++;
		stk->arr[stk->top]=num;
	}
}


void dfs_visit(node * u,int *t){
		(*t)=(*t)+1;
		u->dist=(*t);

		//push(&s,*t);
		strcpy(u->colour,"GRAY");
		node * temp4 = u->next;
		
		while(temp4 != NULL && (strcmp(u->colour,"BLACK") != 0)){
			temp2 = head[temp4->data];
			if(strcmp(temp2->colour,"WHITE")==0){
				temp2->p=u;
				dfs_visit(temp2,t);
			}
			else if(strcmp(temp2->colour,"GRAY")==0){
				//printf("FAIL\n");
				//return 1;
				flag = 1;
				return;
			}
			temp4 =temp4->next;
		}
		
		strcpy(u->colour,"BLACK");
		(*t)=(*t)+1;
		u->final=(*t);
		if(u->integer == 0){
			u->integer = 1;
		push(&s,u->data);
	}

		
		//printf("%d pushed into stack\n",u->data);
}

void dfs(int n){
	int i;
	for(i=1 ; i<(n+1) ; i++){
		strcpy(head[i]->colour,"WHITE");
		head[i]->p=NULL;
	}
	int t=0;
	for(i=1 ; i<(n+1); i++){
		if(strcmp(head[i]->colour,"WHITE")==0){
			dfs_visit(head[i],&t);
			/*if(dfs_visit(head[i],&t) == 1){
				return 1;
			}*/
		}
	}
	
}

void topological_sort(int n){
	dfs(n);
	if(flag == 1){
		printf("FAIL\n");
		return;
	}
	while(s.top != -1){
		pop(&s);
		//printf("element popped\n");
	}
	printf("\n");

}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		flag = 0;
		s.top = -1;
  		int i,n;
  		scanf("%d",&n);
		for(i=1;i<(n+1);i++){
			create(i);
			head[i]=temp;
			tail[i]=NULL;
		}
		for(i=1;i<(n+1);i++){
			int m;
			scanf("%d",&m);
			/*int arr[m];
			int j;
			for(j=0;j<m;j++){
				scanf("%d",&arr[j]);
				insert_end(&(head[i]->next),&(tail[i]),arr[j]);
			}*/
			while(m--){
				int x;
				scanf("%d",&x);
				insert_end(&(head[i]->next),&(tail[i]),x);
			}
		}
		/*int x,y;
 		scanf("%d %d",&x,&y);
  		while(x!=-1 && y!=-1){
    		insert_end(&(head[x]->next),&(tail[x]),y);
    		scanf("%d %d",&x,&y);
  		}*/

		topological_sort(n);
	}
	return 0;
}
