#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	long int data;
	struct node * next;
};

typedef struct node snode;
snode *newnode,*ptr,*prev,*temp;
snode *first=NULL, *last=NULL;

snode * create_node(long int d){
	//snode *newnode,*ptr,*prev,*temp;
	newnode = (snode*)malloc(sizeof(snode));

		newnode->data=d;
		newnode->next=NULL;
}

/*void sorted(){
	snode *n,*newnode,*ptr,*prev,*temp;
	long int t;
	for(ptr=first;ptr!=NULL;ptr=ptr->next){
		for(n=ptr->next;n!=NULL;n=n->next){
			if((ptr->data)>(n->data)){
				t=ptr->data;
				ptr->data=n->data;
				n->data=t;
			}
		}
	}
	
}*/
void insert_node_random(long int pos,long int d){
	//snode *newnode,*ptr,*prev,*temp;
	newnode=create_node(d);
	ptr=first;
	long int count=0;
	while(ptr!=last){
		ptr=ptr->next;
		count++;
	}
	if(pos==1){
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
	else if(pos>1 && pos<=count){
		ptr=first;
		long int i;
		for(i=1;i<pos;i++){
			prev=ptr;
			ptr=ptr->next;
		}
		prev->next=newnode;
		newnode->next=ptr;
	}
}

void Insert(long int d){
	//snode *newnode,*ptr,*prev,*temp;
	//newnode=create_node(d);
	ptr=first;
	//printf("Does not enter\n");
	if(first==NULL){
		ptr=ptr->next;
	}
	/*for(;ptr!=NULL;ptr=ptr->next){
		//printf("%ld %ld\n",ptr->data, d );
		if(ptr->data==d){
			//printf("Loop enters\n");
			printf("-1\n");
			return;
		}
	}*/
	long int j=1;
	if(first==NULL){
		ptr=ptr->next;
	}
	for(;ptr!=NULL;ptr=ptr->next){
		j++;
		if(d > ptr->data){
			insert_node_random(j,d);


		}

	}
	/*if(first == last && first==NULL){
		first=last=newnode;
		first->next=NULL;
		last->next=NULL;
}
	else{
		temp=first;
		first=newnode;
		first->next=temp;
}*/
//sorted();
printf("%ld\n",d);

}

/*void Insert(){
	int d;
	printf("Enter value for node\n");
	scanf("%d",&d);
	newnode=create_node(d);
	ptr=first;
	for(ptr=first;ptr!=NULL;ptr=ptr->next){
		if(ptr->data==d){
			printf("-1\n");
			return;
		}
	}
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
	sorted();
	printf("%d",d);
}*/

/*void Insert(){
	int pos,d;
	scanf("%d",&d);
	newnode=create_node(d);
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

}*/


void delete_node(long int pos){
	//snode *newnode,*ptr,*prev,*temp;
	long int i,count=0;

		ptr=first;
		if(first==NULL){
		ptr=ptr->next;
	}
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
		if(first==NULL){
		ptr=ptr->next;
	}	free(ptr);
		}
}

/*void Delete(long int val){
	//snode *newnode,*ptr,*prev,*temp;
	ptr=first;
	if(first==NULL){
		ptr=ptr->next;
	}
	long int pos;
	int j=1;
	for(;ptr!=NULL;ptr=ptr->next){
		j++;
		if((ptr->data) == val){
			delete_node(j);
			printf("%ld",val);
			return;
			
		}
	}
	printf("-1\n");


}*/
 void delete_repeat(){
 	ptr=first;
 	if(first==NULL){
 		ptr=ptr->next;
 	}
 	int count=1;
 	for(;ptr!=last;ptr=ptr->next){
 		count++;
 	}
 	int arr[count+1];
 	arr[0]=ptr->data;
 	long int i=0;
 	long int j=0;
 	for(ptr=ptr->next;ptr!=NULL;ptr=ptr->next){
 		j++;
 		if(ptr->data==arr[i]){
 			delete_node(j);
 			printf("%ld ",ptr->data);
 		}
 		else{
 			i++;
 			arr[i]=ptr->data;

 		}
 	}
 	printf("\n");
 }

void Print(long int pos){
	snode *newnode,*ptr,*prev,*temp;
	if(first==NULL){
		ptr=ptr->next;
	}
	long int j=1;
	for(;ptr!=NULL;ptr=ptr->next){
		j++;
		if(j==pos){
			printf("%ld\n",ptr->data);
			return;
		}
	}
	printf("-1\n");


}

/*void search(){
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
}*/

/*oid display(){
	if(first==NULL){
		//ISEMPTY;
		printf("No node in the list to delete\n");
	}
	else{
		for(ptr=first;ptr!=NULL;ptr=ptr->next){
			if(ptr=key){
			printf("%d ",ptr->data);
		}
		}
	}
}*/

int main(){
	snode *newnode,*ptr,*prev,*temp;
	long int T;
	while(T--){
	ptr=first;
	long int d;
	scanf("%ld",&d);
	if(d!=0){
		while(d!=0){
			create_node(d);
			scanf("%ld",&d);
		}
	}
	/*while(ptr->data!=0){
		long int d;
		scanf("%ld",&d);
		create_node(d);
		ptr=ptr->next;
	}*/
	long int q;
	scanf("%ld",&q);
	while(q--){
		char query[16];
		long int val;
		scanf("%s %ld",query,&val);
		if(strcmp(query,"Insert")==0){
			Insert(val);
		}
		else if(strcmp(query,"Delete")==0){
			delete_repeat();
		}
		else if(strcmp(query,"Print")==0){
			Print(val);
		}
	}
}
	return 0;
}