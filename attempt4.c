#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	long int x;
  	long int y;
  	struct node * next;
};
typedef struct node snode;
snode *first,*first1,*first2,*last,*temp,*temp2,*temp3,*newnode;

snode * create(long int x_data,long int y_data){
  temp=(snode*)malloc(sizeof(snode));
  
    temp->x=x_data;
    temp->y=y_data;
    temp->next=NULL;
  return temp;
}

void insertbeg(long int x_data,long int y_data){
  newnode=create(x_data,y_data);
  if(first==last && first==NULL){
    first=last=newnode;
    first->next=NULL;
    last->next=NULL;

  }
  else{
    // snode *temp;
    temp=first;
    first=newnode;
    first->next=temp;
  }
}

void insertend(long int x_data,long int y_data){
  newnode=create(x_data,y_data);
  if(first==last && last==NULL){
    first=last=newnode;
    first->next=NULL;
    last->next=NULL;
  }
  else{
    last->next=newnode;
    last=newnode;
    last->next=NULL;
  }
}


long int compare(snode *temp1,snode *temp2){
  if((temp1->x)>(temp2->x)){
    return 1;
  }
  else if((temp1->x)<(temp2->x)){
    return -1;
  }
  else{
    if((temp1->y)>(temp2->y)){
      return 1;
    }
    else if((temp1->y)<(temp2->y)){
      return -1;
    }
    else{
      return 0;
    }
  }
}

snode * merge(snode *first1,snode *first2){
  snode *temp1=first1;
  snode *temp2=first2;
  snode *final=NULL;
  
    if(compare(temp1,temp2)==-1){
      final=temp1;
      final->next=merge(temp1->next,temp2);
      
    }
    else if(compare(temp1,temp2)==1){
      final=temp2;
      final->next=merge(temp1,temp2->next);
    }
    else{
    	temp1=temp1->next;
    	final=merge(temp1,temp2);
    }

  
}

void divide(snode* s,snode** f, struct node** b)
{
  snode* m;
  snode* n;
  if (s==NULL || s->next==NULL)
  {
    *f=s;
    *b=NULL;
  }
  else
  {
    m=s;
    n=s->next;

    while (n!= NULL)
    {
      n=n->next;
      if (n!=NULL)
      {
        m=m->next;
        n=n->next;
      }
    }

    *f=s;
    *b=m->next;
    m->next = NULL;
  }
}


void mergesort(struct node** head)
{
  struct node* h = *head;
  struct node* temp4;
  struct node* temp5;

  if ((h == NULL) || (h->next == NULL))
  {
    return;
  }

  divide(h, &temp4, &temp5);

  mergesort(&temp4);
  mergesort(&temp5);
  *head= merge(temp4,temp5);
}

int main(){
  long int ins;
  scanf("%ld",&ins);
  while(ins!=0){
    long int x_data,y_data;
    scanf("%ld %ld",&x_data,&y_data);
    if(ins==1){
      insertbeg(x_data,y_data);
    }
    else if(ins==2){
      insertend(x_data,y_data);
    }
    long int temp3;
    scanf("%ld",&temp3);
    ins=temp3;
  }
  long int ins1;
  scanf("%ld",&ins1);
  while(ins1!=0){
    long int x_data,y_data;
    scanf("%ld %ld",&x_data,&y_data);
    if(ins1==1){
      insertbeg(x_data,y_data);
    }
    else if(ins1==2){
      insertend(x_data,y_data);
    }
    long int temp3;
    scanf("%ld",&temp3);
    ins1=temp3;
  }
  mergesort(&first);
  temp=first;
  while(temp!=NULL){
  	printf("%ld %ld\n",temp->x,temp->y);
  	temp=temp->next;
  }
  return 0;
}
