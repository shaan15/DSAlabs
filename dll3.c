

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct linknode{
	struct linknode * prev;
	int data;
	struct linknode * next;
};
typedef struct linknode node;
node *head,*tail;

int count=0;

node *create_node(int val){
	node *temp=(node*)malloc(sizeof(node));
	temp->prev=NULL;
	temp->next=NULL;
	temp->data=val;
	return temp;
	//count++;
}


void insert_first(int val){
	node *temp;
	if(head==NULL){
		temp = create_node(val);
		head=temp;
		tail=head;
	}

	else{
		temp = create_node(val);
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
	//free(temp);
	count++;
}

void insert_last(int val){
	node *temp;
	if(head==NULL){
		temp=create_node(val);
		head=temp;
		tail=head;
	}
	else{
		temp=create_node(val);
		// HERE
		temp->prev = tail;
		tail->next = temp;

		// temp->next=tail;
		// tail->prev=temp;
		tail=temp;
	}
	//free(temp);
	count++;
}

/*void delete_node(int pos){
	node *temp2,*temp;
	int i;
	temp2=head;
	// HERE
	if((pos<1) || (pos>count)){
		return;
	}
	if(head==NULL){
		count = 0;
		return;
	}
	else{
		for(i=1;i<pos;i++){
			temp2=temp2->next;
		}
		if(i==1){
			if(temp2->next==NULL){
				free(temp2);
				temp=head=NULL;
				count = 0;
				return;
			}
		}

		if(temp2->next==NULL){
			//here
			temp2->prev->next=NULL;
			
			//free(temp2);
			count--;
			return;
		}
		temp2->next->prev=temp2->prev;
		if(i!=1){
			temp2->prev->next=NULL;
		}
		else if(i==1){
			head=temp2->next=temp2->prev;
		}
		//free(temp2);
	}
	count--;

}*/

void delete_node(int pos){
	node *temp2,*temp;
    int i=1;
    temp2=head;
    while(i<pos && temp2!=NULL){
      temp2=temp2->next;
      i++;
    }
    if(temp2!=NULL){
      if(i==1 && temp2->next==NULL){
        free(temp2);
        temp2=NULL;
        head=NULL;
        tail=NULL;
      }
      else if(temp2->next==NULL){
        tail=temp2->prev;
        // here
        tail->next = NULL;
        // temp2->prev->next=NULL;
        free(temp2);
      }
      else{
        if(i==1){
          head=temp2->next;
          head->prev = NULL;
        }
        else{
          temp2->next->prev=temp2->prev;
          temp2->prev->next=temp2->next;
        }
        free(temp2);
      }
			count--;
			return;
  }
}

void delete_range(int i,int m){
	int j;
	
	//HERE
	for(j = 0; j<m; j++)
		delete_node(i);

	// for(j=i;j<(i+m);j++){
	// 	printf("%d\n", j);
	// 	delete_node(j);
	// }
}

void display(){
	node *temp2;
	temp2=head;
	if(temp2==NULL){
		return;
	}
	// for(temp2=head;temp2->next!=NULL;temp2=temp2->next){
	//  	printf(" %d ",temp2->data);
	//  }

	// HERE  
	 int i;
	 for(i=0; i<count; i++){
	 	printf("%d ", temp2->data);
	 	temp2 = temp2->next;
	 }
	 printf("\n");
}


node * merge1(node *first1,node *first2){
  //node *first1,*first2;
  //node *final=NULL;
  if (first1 == NULL)
     return(first2);
  else if (first2==NULL)
     return(first1);

  if(first1->data < first2->data){
    	first1->next = merge1(first1->next,first2);
    	first1->next->prev = first1;
    	first1->prev = NULL;
    	return first1;
    }
    else{
    	first2->next =  merge1(first1,first2->next);
    	first2->next->prev = first2;
    	first2->prev = NULL;
    	return first2;
    }
  
}





node * merge2(node *first1,node *first2){
  //node *first1,*first2;
  //node *final=NULL;
  if (first1 == NULL)
     return(first2);
  else if (first2==NULL)
     return(first1);

  if(first1->data > first2->data){
    	first1->next = merge2(first1->next,first2);
    	first1->next->prev = first1;
    	first1->prev = NULL;
    	return first1;
    }
    else{
    	first2->next =  merge2(first1,first2->next);
    	first2->next->prev = first2;
    	first2->prev = NULL;
    	return first2;
    }
  
}



node *divide(node *h){
	node *m = h;
	node *n = h;
	while(m->next && m->next->next){
		m = m->next->next;
		n = n->next;
	}
	node *t = n->next;
	n->next = NULL;
	return t;
}
node * mergesort_dsc(node* h)
{
  //node* h = *first;
  //node* temp4;
  //node* temp5;

  if ((h == NULL) || (h->next == NULL))
  {
    return h;
  }

  node * first_last = divide(h);

  h = mergesort_dsc(h);
  first_last = mergesort_dsc(first_last);
  return merge2(h,first_last);
}

node * mergesort_asc(node* h)
{
  //node* h = *first;
  //node* temp4;
  //node* temp5;

  if ((h == NULL) || (h->next == NULL))
  {
    return h;
  }

  node * first_last = divide(h);

  h = mergesort_dsc(h);
  first_last = mergesort_dsc(first_last);
  return merge1(h,first_last);
}


/*void sort_ascend(int u,int l){
	int j;
	for(j=u;j<(u+l+1);j++){
		mergesort_asc()
	}
}

void sort_descend(int u,int l){
	int j;
	for(j=u;j<(u+l+1);j++){

	}
}
*/
void sort_ascend(int u,int l){
	node *first,*last,*temp2,*temp,*temp5,*temp6;
  first=head;
	last=head;
	int i=1;
  while(i<u && last!=NULL){
    first=first->next;
		last=last->next;
    i++;
  }
  while(i<l && last!=NULL){
    last=last->next;
    i++;
  }
	if(first==NULL){
		return;
	}
	if(last==NULL){
		last=tail;
	}

	temp5=first->prev;
	temp6=last->next;

	if(first->prev){
	 first->prev->next=NULL;
	}
	if(first->next){
	 last->next->prev=NULL;
}
	first->prev=NULL;
	last->next=NULL;

	first=mergesort_asc(first);
	if(temp5==NULL){
		head=first;
	}
	else{
		first->prev=temp5;
		temp5->next=first;
	}

	if(temp6!=NULL){
		temp=first;
		temp2=temp;
		while(temp!=NULL){
			temp2=temp;
			temp=temp->next;
		}
		temp2->next=temp6;
		temp6->prev=temp2;
	}
}

void sort_descend(int u,int l){
	node *temp,*temp2,*temp5,*temp6,*first,*last;
  first=head;
	last=head;
	int i=1;
  while(i<u && last!=NULL){
    first=first->next;
		last=last->next;
    i++;
  }
  while(i<l && last!=NULL){
    last=last->next;
    i++;
  }
	if(first==NULL){
		return;
	}
	if(last==NULL){
		last=tail;
	}

	temp5=first->prev;
	temp6=last->next;
	first->prev = NULL;
	last->next = NULL;
	first=mergesort_dsc(first);
	if(temp5==NULL){
		head=first;
	}
	else{
		first->prev=temp5;
		temp5->next=first;
	}

	if(temp6!=NULL){
		temp=first;
		temp2=temp;
		while(temp!=NULL){
			temp2=temp;
			temp=temp->next;
		}
		temp2->next=temp6;
		temp6->prev=temp2;
	}
}






int main(){
	node *temp,*temp2,*temp5,*temp6,*first,*last;
	int q;
	scanf("%d",&q);
	while(q--){
		char str[11];
		scanf("%s",str);
		if(strcmp(str,"INSERTBEG")==0){
			int val;
			scanf("%d",&val);
			insert_first(val);
		}
		else if(strcmp(str,"INSERTEND")==0){
			int val;
			scanf("%d",&val);
			insert_last(val);
		}
		else if(strcmp(str,"DELETENEXT")==0){
			int i,m;
			scanf("%d %d",&i,&m);
			delete_range(i,m);
		}
		else if(strcmp(str,"PRINT")==0){
			display();
			//printf("\ncount: %d\n", count);
		}
		else if(strcmp(str,"SORT")==0){
			int c,u,l;
			scanf("%d %d %d",&c,&u,&l);
			if(c == 1){
				sort_ascend(u,l);
			}
			else if(c == 2){
				sort_descend(u,l);
			}
		}
		
	}
	return 0;
}