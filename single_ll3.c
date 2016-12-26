#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	long int data;
	struct node *next;
};

typedef struct node snode;
snode *newnode,*ptr,*ptr1,*temp,*temp1,*temp2,*prev;
snode *first,*last;

void create_node(long int d){
	newnode=(snode *)malloc(sizeof(snode));
	newnode->next=NULL;
	newnode->data=d;
}

void insert_at_last(long int val){
	if(first!=NULL){
		create_node(val);
		newnode->next=NULL;
		last->next=newnode;
		last=newnode;
	}
	else{
		create_node(val);
		newnode->next=NULL;
		last->next=newnode;
		last=newnode;
	}
}

void Insert(long int val){
	ptr=first;
	ptr1=first;
	long int i=1;
	for(;ptr != NULL && val >= ptr->data;ptr=ptr->next){
		if(val == ptr->data){
			printf("-1\n");
			return;
		}
		else{
			ptr1 = ptr;
			i++;
		}
	}

	create_node(val);
	if(ptr==ptr1){
		first = newnode;
		newnode->next = ptr;
	}
	else{
		ptr1->next = newnode;
		newnode->next = ptr;
	}
	printf("%ld\n",val);
}



void delete_node(long int val){
	temp1 = first;
	long int i=1,pos=-1;
	for(;temp1!=NULL;temp1=temp1->next){
		if(temp1->data == val){
			pos=i;
			break;
		}
		else{
			i++;
		}
	}
	if(pos==-1){
		printf("-1\n");
		return;
	}
	ptr=first;
	ptr1=first;
	long int j=1;
	while(j<pos){
		ptr1=ptr;
		ptr=ptr->next;
		j++;

	}

	if(i==1 && ptr->next==NULL){
		free(ptr);
		ptr=first=NULL;
	}
	else if(i==1){
		first = ptr->next;
		free(ptr);
	}
	else if(ptr->next==NULL){
		ptr1->next=NULL;
		free(ptr);
	}
	else{
		ptr1->next = ptr->next;
		free(ptr);
	}
	printf("%ld\n",val);

}

void Print(long int pos){
	//ptr=first;
	long int i=1;
	while(i<pos && ptr!=NULL){
		ptr=ptr->next;
		i++;
	}
	if(ptr!=NULL){
		printf("%ld\n",ptr->data);
		//return;
	}
	else{
		printf("-1\n");
	}
}

int main(){
	long int T;
	scanf("%ld",&T);
	while(T--){
		first=NULL;
		long int d;
		scanf("%ld",&d);
		while(d!=0){
			insert_at_last(d);
			long int x;
			scanf("%ld",&x);
			d=x;
		}
		long int q;
		scanf("%ld",&q);
		while(q--){
			char query[10];
			long int val;
			scanf("%s %ld",query,&val);
			if(strcmp(query,"Insert")==0){
				Insert(val);
			}
			else if(strcmp(query,"Delete")==0){
				delete_node(val);
			}
			else if(strcmp(query,"Print")==0){
				Print(val);
			}
		}
	}
	return 0;
}