#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	long int x;
  	long int y;
  	struct node * next;
};
typedef struct node snode;
snode *first,*first1,*first2,*last,*temp,*temp2,*temp3;

void create(long int x_data,long int y_data){
  	temp=(snode*)malloc(sizeof(snode));
  
    temp->x=x_data;
    temp->y=y_data;
    temp->next=NULL;
  
}

void insertbeg(long int x_data,long int y_data){
  create(x_data,y_data);
  if(first==NULL){
    first=temp;
    last=temp;
  }
  else{
    // snode *temp;
    temp->next=first;
    first=temp;
  }
}

void insertend(long int x_data,long int y_data){
  create(x_data,y_data);
  if(first==NULL){
    first=temp;
    last=temp;
  }
  else{
    last->next=temp;
    last=temp;
  }
}


int compare(snode *temp1,snode *temp2){
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

struct node * merge(struct node *first1,struct node *first2){
  
  struct node *final=NULL;
  if (first1 == NULL)
     return(first2);
  else if (first2==NULL)
     return(first1);

   if(compare(first1,first2)==-1){
      final=first1;
      final->next=merge(first1->next,first2);
      
    }
    else if(compare(first1,first2)==1){
      final=first2;
      final->next=merge(first1,first2->next);
    }
    else{
    	first1=first1->next;
    	final=merge(first1,first2);
    }
    return final;
  
}

void divide(struct node* s,struct node** f, struct node** b)
{
  struct node* m;
  struct node* n;
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


void mergesort(struct node** first)
{
  struct node* h = *first;
  struct node* temp4;
  struct node* temp5;

  if ((h == NULL) || (h->next == NULL))
  {
    return;
  }

  divide(h, &temp4, &temp5);

  mergesort(&temp4);
  mergesort(&temp5);
  *first= merge(temp4,temp5);
}

int main(){
  long int ins;
  scanf("%ld",&ins);
  while(ins!=0){
    long int x_data,y_data;
    scanf("%ld",&x_data);
    scanf("%ld",&y_data);
    if(ins==1 || ins==2 || ins==3){
      insertbeg(x_data,y_data);
    }
    else if(ins==4 || ins==5){
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
    scanf("%ld",&x_data);
    scanf("%ld",&y_data);
    if(ins1==1 || ins1==2 || ins1==3){
      insertbeg(x_data,y_data);
    }
    else if(ins1==4 || ins1==5){
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
