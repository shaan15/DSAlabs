#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	long int data;
	struct node * next;
};

typedef struct node snode;
snode *newnode,*ptr,*ptr1,*prev,*temp,*temp1;
snode *first, *last;

void create_node(long int d){
	//snode *newnode,*ptr,*prev,*temp;
	newnode = (snode*)malloc(sizeof(snode));
		newnode->next=NULL;
		newnode->data=d;
		
}
snode *create_node_again(long int d){
	//snode *newnode,*ptr,*prev,*temp;
	newnode = (snode*)malloc(sizeof(snode));
		newnode->next=NULL;
		newnode->data=d;
		
}



void insert_node_first(int d){
	//snode *temp,*ptr;
	/*temp = (snode*)malloc(sizeof(snode));
	temp->next=NULL;
	temp->data = d;
*/
	/*if(first == NULL){
		first = temp;
		first->next = NULL;
	}
	else{
		temp->next = first;
		first=temp;

	}*/
	newnode=create_node_again(d);
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

void insert_node_last(long int d){
	if(first == NULL){
		create_node(d);
		first = temp;
		last = first;
	}
	else{
		create_node(d);
		temp->next =NULL;
		last->next=temp;
		last=temp;
	}
}

void insert_node_random(long int pos,long int d){
	//snode *newnode,*ptr,*prev,*temp;
	long int i;
	//snode *temp1,*prev,*ptr;
	//newnode=create_node(d);
	ptr=first;
	long int count=0;
	while(ptr!=last){
		ptr=ptr->next;
		count++;
	}
	if(pos > count+1 || pos<=0){
		return;
	}
	else{
	if(pos==1){
		insert_node_first(d);
	}
	else{
		for(i=1;i<pos;i++){
			prev=ptr;
			ptr=ptr->next;
		}
		temp1 = (snode*)malloc(sizeof(snode));
		temp1->data = d;
		prev->next=temp1;
		temp1->next=ptr;
	}
}
}

void Insert(long int val){

	//snode *ptr,*prev;
	//newnode=create_node(d);
	ptr=first;
	ptr1=first;
	//printf("Does not enter\n");
	/*if(first==NULL){
		ptr=ptr->next;
	}*/
	int j=1;
	for(ptr=first;ptr!=NULL && val >= ptr->data;ptr=ptr->next){
		if(val == ptr->data){
			printf("-1\n");
			return;
		}
		else{
			ptr1 = ptr;
			j++;
		}
	}

	create_node(val);
	if(ptr = ptr1){
		first = newnode;
		newnode->next = ptr;

	}
	else{
		ptr1->next = temp;
		temp->next = ptr;
	}
	printf("%ld\n",val);
}
	/*for(;ptr!=NULL;ptr=ptr->next){
		//printf("%ld %ld\n",ptr->data, d );
		if(ptr->data==d){
			//printf("Loop enters\n");
			printf("-1\n");
			return;
		}
	}*/
	/*long int j=1;
	if(first==NULL){
		ptr=ptr->next;*/
	/*for(;ptr!=last;ptr=ptr->next){
		j++;
		//printf("ptr ka data %ld\n",ptr->data);
		if(ptr->data == d){
			printf("Entered if\n");
			printf("-1\n");
			return;
		}
		else if(ptr->data < d){
			printf("entered else if\n");
			insert_node_random(j,d);
			break;


		}

	}*/
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
// printf("%ld\n",d);


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
int search_node(long int val){
	temp=first;
	long int i=1;
	for(;temp!=NULL;temp=temp->next){
		if(temp->data == val){
			return i;
		}
		else{
			i++;
		}
	}
	return -1;
}


/*void delete_node(long int val){
	//snode *ptr,*prev;

	long int i;

		ptr=first;
		long int count=0;
	while(ptr!=last){
		ptr=ptr->next;
		count++;
	}

	if(pos > count || pos<=0){
		//printf("-1\n");
		return;
	}
	else{
		if(pos==1){
			first = ptr->next;
			free(ptr);
			return;
		}
		else{
			for(i=1;i<pos;i++){
				prev = ptr;
				ptr = ptr->next;
			}
			prev->next = ptr->next;
			free(ptr);
		}
	}
}
*/
		/*if(first==NULL){
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
}*/

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
 void delete_repeat(long int val){
 	/*temp=first;
	long int i=1;
	for(;temp!=NULL;temp=temp->next){
		if(temp->data == val){
			umm=i;
			break;
		}
		else{
			i++;
		}
	}*/
 	//snode *ptr,*prev;
 	long int pos = search_node(val);
 	if(pos == -1){
 		printf("-1\n");
 		return;
 	}
 	ptr=first;
 	ptr1=first;
 	/*if(first==NULL){
 		ptr=ptr->next;
 	}*/
 	long int i;
 	for(i=1;i<pos;i++){
 		ptr1=ptr;
 		ptr=ptr->next;
 	}

 	if(i == 1 && ptr->next == NULL){
 		free(ptr);
 		ptr=first=NULL;
 	}
 	else if(ptr->next == NULL){
 		ptr1->next = NULL;
 		free(ptr);
 	}
 	else if(i ==1){
 		first = ptr->next;
 		free(ptr);
 	}
 	else{
 		ptr1->next = ptr->next;
 		free(ptr);
 	}
 	printf("%ld\n",val);
 }
 	/*int count=0;
 	for(;ptr!=last;ptr=ptr->next){
 		count++;
 	}
 	int arr[count+1];
 	arr[0]=ptr->data;
 	long int i=0;
 	long int j=1;
 	for(ptr=ptr->next;ptr!=last;ptr=ptr->next){
 		j++;
 		if(ptr->data == arr[i]){
 			delete_node(j);
 			printf("%ld\n",ptr->data);
 			return;
 		}
 		else{
 			i++;
 			arr[i]=ptr->data;

 		}
 	}

 	printf("-1\n");
 }*/

void Print(long int pos){
	//snode *ptr,*prev,*temp;
	ptr=first;
	/*if(first==NULL){
		ptr=ptr->next;
	}*/
	long int j=1;
	for(;j<pos && ptr!=NULL;ptr=ptr->next){
		j++;
	}
	if(ptr!=NULL){
		printf("%ld\n",ptr->data);
		
	}
	else{
		printf("-1\n");	
		}
}



int main(){
	//snode *ptr,*prev,*temp;
	long int T;
	scanf("%ld",&T);
	while(T--){
	first=NULL;
	long int d;
	scanf("%ld",&d);
	while(d!=0){
		insert_node_last(d);
		long int m;
		scanf("%ld",&m);
		d=m;
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
			delete_repeat(val);
		}
		else if(strcmp(query,"Print")==0){
			Print(val);
		}
	}
}
	return 0;
}