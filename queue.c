#include <stdio.h>
#define MAX_SIZE 5

struct queue{
	int arr[MAX_SIZE];
	int head;
	int tail;
};
typedef struct queue QUEUE;

void enqueue(QUEUE *q){
	if(q->head==q->tail+1 || (q->head==0 && q->tail==MAX_SIZE-1)){
			printf("Queue overflow\n");
	}
	else{
			int num;
			printf("Enter the number to be added: ");
			scanf("%d",&num);
			q->arr[q->tail]=num;
			if(q->tail==MAX_SIZE-1)q->tail=0;
			else q->tail+=1;
	}
}
void dequeue(QUEUE *q){
	if(q->head==q->tail)printf("Queue underflow\n");
	else{
		printf("Element dequeued is %d\n",q->arr[q->head]);
		if(q->head==MAX_SIZE-1)q->head=0;
		else q->head+=1;
	}
}

int main(){
	QUEUE q;
	q.head=0;
	q.tail=0;
	int n;
	scanf("%d",&n);
	while(n--){
		char choice[8];
		scanf("%s",choice);
		if(strcmp(choice,"insert")==0)enqueue(&q);
		else if(strcmp(choice,"delete")==0)dequeue(&q);
	}
	return 0;
}