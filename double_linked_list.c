#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node * prev;
	int data;
	struct node * next;
}*h,*temp,*temp1,*temp2,*temp3;

int count=0;

void create_node(){
	int val;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->next=NULL;
	printf("Enter value of node: ");
	scanf("%d",&val);
	temp->data=val;
	count++;
}

void insert_first(){
	if(h==NULL){
		create_node();
		h=temp;
		temp1=h;
	}

	else{
		create_node();
		temp->next=h;
		h->prev=temp;
		h=temp;
	}
}

void insert_last(){
	if(h==NULL){
		create_node();
		h=temp;
		temp1=h;
	}
	else{
		create_node();
		temp1->next=temp;
		temp->prev=temp1;
		temp1=temp;
	}
}

void insert_random(){
	int pos;
	printf("Enter position at which node to be inserted: ");
	scanf("%d",&pos);
	temp2=h;
	if((pos<1) || (pos>=count+1)){
		printf("Position is out of range\n");
		return;
	}
	if((h==NULL) && (pos!=1)){
		printf("Empty list cannot insert at other than first position\n");
		return;
	}
	if((h==NULL) && (pos!=1)){
		create_node();
		h=temp;
		temp1=h;
		return;
	}
	else{
		int i;
		for(i=2;i<pos;i++){
			temp2=temp2->next;
		}
		create_node();
		temp->prev=temp2;
		temp->next=temp2->next;
		temp2->next->prev=temp;
		temp2->next=temp;
	}

}


void delete_node(){
	int i,pos;
	printf("Enter position to be deleted\n");
	scanf("%d",&pos);
	temp2=h;
	if((pos<1) || (pos>=count+1)){
		printf("Position out of range\n");
		return;
	}
	if(h==NULL){
		printf("Empty list\n");
		return;
	}
	else{
		for(i=1;i<pos;i++){
			temp2=temp2->next;
		}
		if(i==1){
			if(temp2->next==NULL){
				printf("Node deleted\n");
				free(temp2);
				temp=h=NULL;
				return;
			}
		}

		if(temp2->next==NULL){
			temp2->prev->next=NULL;
			free(temp2);
			printf("Node deleted\n");
			return;
		}
		temp2->next->prev=temp2->prev;
		if(i!=1){
			temp2->prev->next=NULL;
		}
		else if(i==1){
			h=temp2->next=temp2->prev;
		}
		printf("Node deleted\n");
		free(temp2);
	}
	count--;

}

void display(){
	temp2=h;
	if(temp2==NULL){
		printf("Empty list\n");
		return;
	}
	printf("Displayed link list\n");
	 for(temp2=h;temp2->next!=NULL;temp2=temp2->next){
	 	printf(" %d ",temp2->data);
	 }
	 printf(" %d ",temp2->data);
}

void display_rev(int i){
	if(temp2!=NULL){
		i=temp2->data;
		temp2=temp2->next;
		display_rev(i);
		printf(" %d ",i);
	}
}

void search(){
	int val,count=0;
	temp2=h;
	if(temp2==NULL){
		printf("Empty list\n");
		return;
	}
	printf("Enter value to search: ");
	scanf("%d",&val);
	for(temp2=h;temp2!=NULL;temp2=temp2->next){
		if(temp2->data==val){
			printf("data found at %d position\n",count+1);
			return;
		}
		else{
			count++;
		}
		
	}
	printf("%d element not found in list\n",val);
}


void update(){
	int old_value,new_value;
	printf("enter node data to be update: ");
	scanf("%d",&old_value);
	printf("Enter new value of node: ");
	scanf("%d",&new_value);
	temp2=h;
	if(temp2==NULL){
		printf("List is empty\n");
		return;
	}
	for(temp2=h;temp2!=NULL;temp2=temp2->next){
		if(temp2->data==old_value){
			temp2->data=new_value;
			display();
			return;
		}

	}
	printf("%d element not found in list\n",old_value);
}

void sorted(){
	int i,j,x;
	temp2=h;
	temp3=h;
	if(temp2==NULL){
		printf("list is empty\n");
		return;
	}

	for(temp2=h;temp2!=NULL;temp2=temp2->next){
		for(temp3=temp2->next;temp3!=NULL;temp3=temp3->next){
			if((temp2->data)>(temp3->data)){
				x=temp2->data;
				temp2->data=temp3->data;
				temp3->data=x;
			}
		}
	}
	display();
}


int main(){
	int num_queries;
	scanf("%d",&num_queries);
	while(num_queries--){
		char query[16];
		printf("Enter query\n");
		scanf("%s",query);
		if(strcmp(query,"insert_first")==0){
			insert_first();
		}
		else if(strcmp(query,"insert_last")==0){
			insert_last();
		}
		else if(strcmp(query,"insert_position")==0){
			insert_random();
		}
		else if(strcmp(query,"delete_node")==0){
			delete_node();
		}
		else if(strcmp(query,"update_val")==0){
			update();
		}
		else if(strcmp(query,"search")==0){
			search();
		}
		else if(strcmp(query,"display")==0){
			display();
		}
		else if(strcmp(query,"display_rev")==0){
			display_rev(temp2->data);
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