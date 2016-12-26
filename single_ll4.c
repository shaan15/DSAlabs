#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	long int data;
	struct node * next;
};

typedef struct node snode;
snode *newnode,*ptr,*ptr1,*prev,*temp,*temp1,*temp2,*temp3,*temp4;
snode *first, *last;

void create_node(long int d){
	newnode = (snode*)malloc(sizeof(snode));
		newnode->next=NULL;
		newnode->data=d;
		
}

// void insert_node_first(int d){
// 	newnode=create_node(d);
// 	if(first == last && first==NULL){
// 		first=last=newnode;
// 		first->next=NULL;
// 		last->next=NULL;
// }
// 	else{
// 		temp=first;
// 		first=newnode;
// 		first->next=temp;
// }
// }

void insert_node_last(long int d){
	if(first == NULL){
		create_node(d);
		first = newnode;
		last = first;
	}
	else{
		create_node(d);
		newnode->next =NULL;
		last->next=newnode;
		last=newnode;
	}
}

// void insert_node_random(long int pos,long int d){
// 	long int i;
// 	ptr=first;
// 	long int count=0;
// 	while(ptr!=last){
// 		ptr=ptr->next;
// 		count++;
// 	}
// 	if(pos > count+1 || pos<=0){
// 		return;
// 	}
// 	else{
// 	if(pos==1){
// 		insert_node_first(d);
// 	}
// 	else{
// 		for(i=1;i<pos;i++){
// 			prev=ptr;
// 			ptr=ptr->next;
// 		}
// 		temp1 = (snode*)malloc(sizeof(snode));
// 		temp1->data = d;
// 		prev->next=temp1;
// 		temp1->next=ptr;
// 	}
// }
// }

void Insert(long int val){
	ptr=first;
	ptr1=first;

	while(ptr!=NULL && val > ptr->data){
		if(val == ptr->data){
		 	printf("-1\n");
		 	return;
		 }
		else{
			ptr1 = ptr;
			ptr = ptr->next;
		}
	}
	// if(val == ptr->data){
	// 		printf("-1\n");
	// 	return;
	// 	}


	create_node(val);
	if(ptr == ptr1){
		first = newnode;
		newnode->next = ptr;

	}
	else{
		ptr1->next = newnode;
		newnode->next = ptr;
	}
	printf("%ld\n",val);
}

/*long int search_node(long int val){
	temp4=first;
	long int i=1;
	for(;temp4!=NULL;temp4=temp4->next){
		if(temp4->data == val){
			return i;
		}
		else{
			i++;
		}
	}
	return -1;
}
*/
 void delete_repeat(long int val){
 	//long int pos = search_node(val);
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
 	/*if(first==NULL){
 		ptr=ptr->next;
 	}*/
 	long int j;
 	for(j=1;j<pos;j++){
 		ptr1=ptr;
 		ptr=ptr->next;
 	}

 	if(j == 1 && ptr->next == NULL){
 		free(ptr);
 		ptr=first=NULL;
 	}
 	else if(ptr->next == NULL){
 		ptr1->next = NULL;
 		free(ptr);
 	}
 	else if(j==1){
 		first = ptr->next;
 		free(ptr);
 	}
 	else{
 		ptr1->next = ptr->next;
 		free(ptr);
 	}
 	printf("%ld\n",val);
 }

void Print(long int pos){
	ptr=first;
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
	long int q;
	scanf("%ld",&q);
	while(q--){
		char query[16];
		
		scanf("%s",query);
		if(strcmp(query,"Insert")==0){
			long int val;
			scanf("%ld",&val);
			Insert(val);
		}
		else if(strcmp(query,"Delete")==0){
			long int val;
			scanf("%ld",&val);
			delete_repeat(val);
		}
		else if(strcmp(query,"Print")==0){
			long int val;
			scanf("%ld",&val);
			Print(val);
		}
	}
}
	return 0;
}