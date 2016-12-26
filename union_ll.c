#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	struct node * next;
	int x;
	int y;
};
typedef node snode;
typedef struct node snode;
snode *newnode,*ptr,*prev,*temp,*temp1;
snode *first1=NULL,*first2=NULL,*last=NULL;

snode * create_node(int x_data,int y_data){
	newnode = (snode*)malloc(sizeof(snode));
	if(newnode==NULL){
		return 0;
	}
	else{
		newnode->x=x_data;
		newnode->y=y_data;
		newnode->next=NULL;
	}
}

void insertbeg(int x_data,int y_data){
	newnode=create_node(x_data,y_data);
	if(first == last && first==NULL){
		first=last=newnode;
		first->next=NULL;
		last->next=NULL;
}
	else{
		temp=first;
		first=newnode;
		first->next=temp;
}
}

void insertend(int x_data,int y_data){
	newnode=create_node(x_data,y_data);
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


void merge(int *arr,int p,int q,int r){
	int i,j,k,s;
	int L[q-p+2],R[r-q+1];
	for(i=p,j=0;i<=q,j<=(q-p);i++,j++){
			L[j]=arr[i];
			//printf("copied to L\n");

	}
	for(s=q+1,k=0;s<=r,k<(r-q+1);s++,k++){
			R[k]=arr[s];
			//printf("copied to R\n");
	}
	L[q-p+1]=1000000;
	R[r-q]=1000000;
	//printf("sentinel declared\n");

	int m=0,n=0,x;
	for(x=p;x<=r;x++){
		if(L[m]<=R[n]){
			arr[x]=L[m];
			m++;
			//printf("L dominates\n");
		}
		else{
			arr[x]=R[n];
			n++;
			//printf("R dominates\n");
		}
	}
	//printf("merging done\n");

}

void merge_sort(int *arr,int start,int end){
	int mid;
	if(start<end){
	mid=(start+end)/2;
	//printf("mid found\n");


	merge_sort(arr,start,mid);
	merge_sort(arr,mid+1,end);
	merge(arr,start,mid,end);
	//printf("Now sorted!");
}
}
	int main(){
		ptr=first;
		int insert,x_data,y_data;
		scanf("%d %d %d",&insert,&a->x,&b->y);
		if(insert==1){
			insertbeg(x_data,y_data);
		}
		else if(insert==2){
			insertend(x_data,y_data);

		}
		if(insert!=0){
			while(insert!=0){
				create_node(x_data,y_data);
				scanf("%d %d %d",&insert,&x_data,&y_data);
				if(insert==1){
					insertbeg(x_data,y_data);
				}
				else if(insert==2){
					insertend(x_data,y_data);

				}
			}
		}
		return 0;

	}



