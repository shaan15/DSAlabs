#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int x;
	int y;
	struct node * next;
}snode;


void insertbeg();
void insertend();
snode * merge();
snode *partition();
snode *quicksort();
int compare();



//snode *first=NULL,*last=NULL;

snode * create(int x_data,int y_data){
	snode * temp=(snode*)malloc(sizeof(snode));
	if(temp==NULL){
		return;
	}
	else{
		temp->x=x_data;
		temp->y=y_data;
		temp->next=NULL;
	}
}

void insertbeg(int x_data,int y_data,snode *first,snode *last){
	newnode=create(x_data,y_data);
	if(first==last && first=NULL){
		first=last=newnode;
		first->next=NULL;
		last->next=NULL;

	}
	else{
		snode *temp;
		temp=first;
		first=newnode;
		first->next=temp;
	}
}

void insertend(int x_data,int y_data,snode *first,snode *last){
	newnode=create(x_data,y_data);
	if(first==last && last==NULL){
		first=last=newnode;
		first->next=NULL;
		last->next=NULL;
	}
	else{
		snode *temp;
		last->next=newnode;
		last=newnode;
		last->next=NULL;
	}
}


snode * partition(struct snode *first,struct snode *last){
	if (newHead != partition)
    {
        struct node *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
 
        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);
 
        // Change next of last node of the left half to pivot
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }
 
    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);
 
    return newHead;
	
}

snode * quicksort(struct snode *first,struct snode *last){
	if((snode *first)<(snode *last)){
		snode *q=partition(first,last);
		quicksort(first,q-1);
		quicksort(q+1,last);
	}
}



int compare(struct snode *temp1,struct snode *temp2){
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

snode * merge(struct snode *first1,struct snode *first2,snode *last2){
	snode *temp1=first1;
	snode *temp2=first2;
	while(temp1!=NULL && temp2!=NULL){
		if(compare(&temp1,&temp2)==-1){
			printf("%d %d ",temp1->x,temp1->y);
			temp1=temp1->next;
			
		}
		else if(compare(&temp1,&temp2)==1){
			printf("%d %d ",temp2->x,temp2->y);
			temp2=temp2->next;
		}
		else{
			printf("%d %d ",temp1->x,temp1->y);
			temp1=temp1->next;
			temp2=temp2->next;

		}

	}
}

int main(){
snode *first=NULL,last=NULL;
  int ins;
  scanf("%d",&ins);
  while(ins!=0){
    x_data,y_data;
    scanf("%d %d",&x,&y);
    if(ins==1){
      insertbeg(x_data,y_data);
    }
    else if(ins==2){
      insertend(x_data,y_data);
    }
    int temp3;
    scanf("%d",&temp3);
    ins=temp3;
  }
  int ins1;
  scanf("%d",&m);
  while(ins1!=0){
    int x_data,y_data;
    scanf("%d %d",&x_data,&y_data);
    if(ins1==1){
      insertbeg(x_data,y_data);
    }
    else if(ins1==2){
      insertend(x_data,y_data);
    }
    int temp3;
    scanf("%d",&temp3);
    ins1=temp3;
  }
  return 0;
}