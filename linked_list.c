#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int data;
	struct node * next;
};

typedef struct node snode;
snode *newnode,*ptr,*prev,*temp;
snode *first=NULL, *last=NULL;

snode * create_node(int d){
	newnode = (snode*)malloc(sizeof(snode));
	if(newnode==NULL){
		printf("Memory not allocated!\n");
		return 0;
	}
	else{
		newnode->data=d;
		newnode->next=NULL;
	}
}

void insert_node_first(){
	int d;
	printf("Enter value for node\n");
	scanf("%d",&d);
	newnode=create_node(d);
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

void insert_node_last(){
	int d;
	printf("Enter value for node\n");
	scanf("%d",&d);
	newnode=create_node(d);
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

void insert_node_random(){
	int pos,d;
	printf("Enter value for node\n");
	scanf("%d",&d);
	newnode=create_node(d);
	printf("Enter the position\n");
	scanf("%d",&pos);
	ptr=first;
	int count;
	while(ptr!=NULL){
		ptr=ptr->next;
		count++;
	}
	if(pos==1){
		insert_node_first();
	}
	else if(pos>1 && pos<=count){
		ptr=first;
		int i;
		for(i=1;i<pos;i++){
			prev=ptr;
			ptr=ptr->next;
		}
		prev->next=newnode;
		newnode->next=ptr;
	}
	else{
		printf("Position out of range\n");
	}
}

void delete_node(){
	int pos,i,count=0;
	if(first==NULL){
		//ISEMPTY;
		printf("No node to delete\n");
	}
	else{
		printf("Position of value to be deleted: ");
		scanf("%d",&pos);
		ptr=first;
		if(pos==1){
			first=ptr->next;
		}
		else{
			while(ptr!=NULL){
				ptr=ptr->next;
				count++;
			}
			if(pos>0 && pos<=count){
				ptr=first;
				for(i=1;i<pos;i++){
					prev=ptr;
					ptr=ptr->next;

				}
				prev->next=ptr->next;
			}
			else{
				printf("Position out of range\n");
			}
			free(ptr);
		}

	}
}

void update_val(){
	int old_value,new_value,flag=0;
	if(first==NULL){
		//ISEMPTY;
		printf("No node in list to update\n");

	}
	else{
		printf("Value to be udated: ");
		scanf("%d",&old_value);
		printf("Enter new value: ");
		scanf("%d",&new_value);
		for(ptr=first;ptr!=NULL;ptr=ptr->next){
			if(ptr->data==old_value){
				ptr->data=new_value;
				flag=1;
				break;
			}
		}
		if(flag=1){
			printf("Updated\n");
		}
		else{
			printf("Value not found in list\n");
		}
	}
}

void search(){
	int flag=0,key,pos=0;
	if(first=NULL){
		//ISEMPTY;
		printf("No node in list\n");

	}
	else{
		printf("Enter value to be searched: ");
		scanf("%d",&key);
		for(ptr=first;ptr!=NULL;ptr=ptr->next){
			pos++;
			if(ptr->data==key){
				flag=1;
				break;

			}
		}
		if(flag=1){
			printf("element %d found at %d position\n",key,pos);
		}
		else{
			printf("Element %d not found in list\n",key);
		}
	}
}

void display(){
	if(first==NULL){
		//ISEMPTY;
		printf("No node in the list to delete\n");
	}
	else{
		for(ptr=first;ptr!=NULL;ptr=ptr->next){
			printf("%d ",ptr->data);
		}
	}
}

void display_rev(snode *ptr){
	int val;
	if(ptr==NULL){
		//ISEMPTY;
		printf("List is empty\n");
	}
	else{
		if(ptr!=NULL){
			val=ptr->data;
			display_rev(ptr->next);
			printf("%d ",val);
		}
	}
}

void sorted(){
	snode *n;
	int t;
	if(first==NULL){
		printf("No element to sort\n");
	}
	else{
		for(ptr=first;ptr!=NULL;ptr=ptr->next){
			for(n=ptr->next;n!=NULL;n=n->next){
				if((ptr->data)>(n->data)){
					t=ptr->data;
					ptr->data=n->data;
					n->data=t;
				}
			}
		}
		printf("Sorted list: ");
	for(ptr=first;ptr!=NULL;ptr=ptr->next){
		printf("%d ",ptr->data);
	}
	
	}
}

int main(){
	int num_queries;
	scanf("%d",&num_queries);
	while(num_queries--){
		char query[16];
		printf("Enter query\n");
		scanf("%s",query);
		if(strcmp(query,"insert_first")==0){
			insert_node_first();
		}
		else if(strcmp(query,"insert_last")==0){
			insert_node_last();
		}
		else if(strcmp(query,"insert_position")==0){
			insert_node_random();
		}
		else if(strcmp(query,"delete_node")==0){
			delete_node();
		}
		else if(strcmp(query,"update_val")==0){
			update_val();
		}
		else if(strcmp(query,"search")==0){
			search();
		}
		else if(strcmp(query,"display")==0){
			display();
		}
		else if(strcmp(query,"display_rev")==0){
			display_rev(first);
		}
		else if(strcmp(query,"sort")==0){
			sorted();
		}
		else{
			printf("Invalid query\n");
		}
	}
	return 0;
}