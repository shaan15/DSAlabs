#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void initHeap(char*,char*);
void insert(char*,char*);
void findMin();
void deleteMin(int*,int);
void delete(int*,int);
void min_heapify(char*,int);
void left(int);
void right(int);
void swap(int*,int*);

typedef struct _element{
	char first_name[100];
	char last_name[100];
	int heap_index;
}element;
element *arr[100000];
int heapsize;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		char function[];
		scanf("%s",function);
		if(strcmp(function,"initHeap")==0){
			scanf("%s %s",arr[0]->first_name,arr[0]->last_name);
			heapsize=1;
			
		}
		else if(strcmp(function,"findMin")==0){
			findMin();
		}
		else if(strcmp(function,"deleteMin")==0){
			deleteMin();
		}
		else if(strcmp(function,"delete")==0){
			int i;
			scanf("%d",&i);
			delete(i);
		}
		else{
			insert();
		}

	}
	return 0;
}

min_heapify(int i){
	int l=left(i);
	int r=right(i);
	int smallest;
	if(l<=heapsize && arr[l]<arr[i]){
		smallest=l;
	}
	else{
		smallest=i;
	}
	if(r<=heapsize && arr[r]<arr[smallest]){
		smallest=r;
	}
	if(smallest!=i){
		swap(&arr[i],&arr[smallest]);
		min_heapify(arr,smallest)
	}
}

int left(int i){
	return (2*i);

}
int right(int i){
	return(2*i+1);
}

int parent(int i){
	if(i%2==0){
		return(i/2-1);
	}
	else{
		return(i/2);
	}
}

void swap(int* x,int* y){
	int x_val=*x;
	*x=*y;
	*y=x_val;
}

void insert(){
	scanf("%s %s",arr[heapsize]->first_name,arr[heapsize]->last_name);
	int i=heapsize;
	while(i>0){
	string_compare(arr[parent(i)],arr[i]);
	i=parent(i);
}



}
void findMin(){
	if(heapsize<1){
		printf("-1\n");
	}
	else{
	min_heapify(arr,0,heapsize);
	int min=arr[0];
	printf("%s %s\n",arr[0]->first_name,arr[0]->last_name);
}
}

void deleteMin(){
	if(heapsize<1){
		printf("-1\n");
	}
	else{
	min_heapify(arr,0,heapsize);
	int min=arr[0];
	printf("%s %s\n",arr[0]->first_name,arr[0]->last_name);
	heapsize--;
}
}

void delete(int index){
	if(index<1 || index>heapsize){
		printf("-1\n");
	}
	else{
	swap(arr[index-1],arr[heapsize]);
	printf("%s\n",arr[index-1]);
	heapsize--;
	min_heapify(arr,index-1,heapsize);
}
}

void string_compare(element arr[],int a,int b){
	if(strcmp(arr[a]->first_name,arr[b]->first_name)<0){
		swap(&arr[a],&arr[b]);
	}
	else if(strcmp(arr[a]->first_name,arr[b]->first_name)==0){
		if(strcmp(arr[a]->last_name,arr[b]->last_name)<0){
			swap(&arr[a],&arr[b]);
		}
		else{
			return;
		}
	}
	else{
		return;
	}
}
