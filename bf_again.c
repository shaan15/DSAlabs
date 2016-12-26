#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000001

struct treenode{
	long int data;
	long int dist;
	char colour;
  struct treenode * next;
};
typedef struct treenode node;
node *temp,*temp1,*temp3;
node * head[MAX_SIZE];
node * tail[MAX_SIZE];

struct dist_queue{
	node * arr[MAX_SIZE];
	long int head;
	long int tail;
};
typedef struct dist_queue queue;
long int count;

void enqueue(queue *q,node * s){
			(q)->arr[(q)->tail]=(s);
			if((q)->tail==MAX_SIZE-1){
				(q)->tail=0;
			}
			else{
			 (q)->tail++;
			}
	}

node * dequeue(queue *q){
	if((q)->head == (q)->tail){
		return NULL;
	}
	else{
		temp=(q)->arr[(q)->head];
		if((q)->head==MAX_SIZE-1){
			(q)->head=0;
		}
		else{
		 (q)->head++;
		}
		return temp;
	}
}

void create(long int val){
  temp=(node *)malloc(sizeof(node));
  temp->next=NULL;
  temp->data=val;
	temp->dist=-1;
	temp->colour='w';
}

void insert_beg(node ** head,long int x){
  if((*head)==NULL){
    create(x);
    (*head)=temp;
    //*tail)=temp;
  }
  else{
    create(x);
    temp->next=(*head)->next;
    (*head)->next=temp;
    // (*tail)=temp;
  }
}
// void insert_first(long int val){
// 	node *temp;
// 	if(head==NULL){
// 		temp = create_node(val);
// 		head=temp;
// 		tail=head;
// 	}

// 	else{
// 		temp = create_node(val);
// 		temp->next=head;
// 		head->prev=temp;
// 		head=temp;
// 	}
// 	//free(temp);
// 	count++;
// }

void bfs(queue * q,node * s,long int n){
	long int i;
	for(i=0;i<n;i++){
		head[i]->colour='w';
		//head[i]--;
	}
	s->colour='g';
	s->dist=0;
	q->head=q->tail=0;
	enqueue(q,s);
	while(q->head != q->tail){
		temp = dequeue(q);
		//printf("dequeued %d\n",temp->data);
		temp1 = head[temp->data]->next;
		//printf("%d\n",temp1->data );
		while(temp1!=NULL){
			temp3 =	head[temp1->data];
			if(temp3->colour == 'w'){
				temp3->colour='g';
				temp3->dist=temp->dist+1;
				//printf("%d dist is\n",temp3->dist);
				// temp3->p=temp;
				enqueue(q,temp3);
				//printf("enqueued %d",temp3->data);
				count = count + (temp3->dist);
				//printf("count is %ld\n",count);

				
			}
			temp1=temp1->next;
			//printf("%d is the count inside loop\n",count);
		}
		strcpy(temp->colour,"BLACK");
		//count++;
	}
	//printf("count is now %d\n",count);
}

int main(){
	long int n,m,k;
	scanf("%ld %ld %ld",&n,&m,&k);
		queue q;
		/*q.head = -1;
		q.tail = -1;*/
		// node *root=NULL;
/*		head = NULL;
		tail=NULL;*/
		long int j;
		for(j=0;j<n;j++){
			create(j);
			head[j]=temp;
			tail[j]=NULL;
		}
		while(m--){
			long int x,y;
			scanf("%ld %ld",&x,&y);
			insert_beg(&(head[x]),y);
			insert_beg(&(head[y]),x);
		}
		//printf("%d ",temp->data);
		//QUEUE *q;
		while(k--){
			count = 0;
			q.head = 0;
			q.tail = 0;
			long int query;
			scanf("%ld",&query);
			node * s = head[query];
			long int l;
			printf("What\n");
			bfs(&q,s,n);
			/*for(l=0;l<n;l++){
				if(l != query){
					//printf("%d\n", );
					count = count + (head[l]->dist);
					//printf("count is now %d\n",count);
				}
				//count = count + (head[l]->dist);
			}*/
			printf("%ld\n",count);
			temp = NULL;
			temp1 = NULL;
			temp3 = NULL;
			

		}
		/*q.head=0;
		q.tail=0;
		long int city=1;
		node * s=head[city];
		bfs(&q,s,n);*/
		// long int i;
		// long int min=0;
		// for(i=1;i<(n+1);i++){
		// 	if((head[i])->dist < min){
		// 		min = (head[i])->dist;
		// 	}
		// }
	return 0;
}


