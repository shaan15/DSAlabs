#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct queue{
	int arr[MAX_SIZE];
	int head;
	int tail;
};
typedef struct queue QUEUE;

typedef struct S{
	int arr[MAX_SIZE];
	int top;
}node;

node *s,*S1,*S2;



void enqueue(QUEUE *q){
	if(q->head==q->tail+1 || (q->head==0 && q->tail==MAX_SIZE-1)){
		//printf("-1\n");
		return;
	}
	else{
			int num;
			//printf("Enter the number to be added: ");
			scanf("%d",&num);
			printf("%d 1\n",num);
			q->arr[q->tail]=num;
			if(q->tail==MAX_SIZE-1){
				q->tail=0;
			}
			else{
			 q->tail++;
			}
	}
}

/*void dequeue(QUEUE *q){
	if(q->head==q->tail){
		printf("-1 0\n");
	}
	else{
		printf("%d 1\n",q->arr[q->head]);
		if(q->head==MAX_SIZE-1){
			q->head=0;
		}
		else{ 
			q->head++;
		}
	}
}*/



void isempty(QUEUE *q){
	if(q->head==q->tail){
		printf("1 0\n");
	}
	else{
		printf("0 0\n");
	}
}
int pop1(node *S1){
	if(S1->top==-1){
		return 0;
	}
	else{
		S1->top--;
	}
	return(S1->top++);
}
int pop2(node *S2){
	if(S2->top==-1){
		return 0;
	}
	else{
		S2->top--;
	}
return(S2->top++);
}
void push1(node *S1,int num){
	if(S1->top==MAX_SIZE-1){
		return;
	}
	else{
		//int num;
		S1->top++;
		//scanf("%d",&num);
		S1->arr[S1->top]=num;
	}
}
void push2(node *S2,int num){
	if(S2->top==MAX_SIZE-1){
		return;
	}
	else{
		//int num;
		S2->top+=1;
		//scanf("%d",&num);
		S2->arr[S2->top]=num;
	}
}
void front(){
int count=0;
if(S1->top==-1 && S2->top==-1){
printf("-1 %d\n",count);
}
else if(S2->top==-1){
while(S1->top >=0){
int x=pop1(S1);
push2(S2,x);
count+=2; 
}
int y=S2->arr[S2->top];
printf("%d %d\n",y,count);
}
else{
int x=S2->arr[S2->top];
printf("%d %d\n",x,count);
}
}
/*void front(QUEUE *q){
	if(q->head==q->tail){
		printf("-1 0\n");
	//printf("%d\n",q->head);
}
else{
	int count=1;
	int i;
	for(i=q->tail;i<=(q->head);i++){
		s->arr[s->top]=i;
		s->top--;
		printf("Entered loop\n");

	}


	while(s->top>-1 && q->head!=s->top){
		pop1(s);
		count++;
printf("Entered while loop\n");
	}

	printf("%d %d\n",q->head,count);
}
}*/



/*void front(){
int x;
scanf("%d",&x);
	int count=0;
	  while(S1->top=-1) {
    x = pop1(S1);
    push2(S2,x);
    count+=2;
  }
  
  //removing the element
  x = pop2(S2);
  
  while(S2->top=-1) {
    x = pop2(S2);
    push1(S1,x);
    count+=2;
  }
  
  printf("%d %d",x,count);


}*/

void dequeue(){
int x;
scanf("%d",&x);
	int count=0;
	  while(S1->top!=-1) {
    x = pop1(S1);
    push2(S2,x);
    count+=2;
  }
  
  //removing the element
  x = pop2(S2);
  
  while(S2->top!=-1) {
    x = pop2(S2);
    push1(S1,x);
    count+=2;
  }
  
  printf("%d %d",x,count);


}



int main(){
	QUEUE q;
	q.head=0;
	q.tail=0;
	int T;
	scanf("%d",&T);
	while(T--){
		char choice[8];
		scanf("%s",choice);
		if(strcmp(choice,"enqueue")==0){
			enqueue(&q);
		}
		else if(strcmp(choice,"dequeue")==0){
			dequeue();
		}
		else if(strcmp(choice,"front")==0){
			front(&q);
		}
		else if(strcmp(choice,"isempty")==0){
			isempty(&q);
		}
	}
	return 0;
}
