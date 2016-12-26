#include<stdio.h>
#include<stdlib.h>

void quicksort(int*,int,int);
int partition(int*,int,int);
void swap(int*,int*);
int randomize(int*,int,int);
//int max(int*,int*,int*);
//int min(int*,int*,int*);
int mid(int*,int*,int*);

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int arr[n];
		int i;
		for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		quicksort(arr,0,n-1);
		for(i=0;i<n;i++){
			printf("%d ",arr[i]);
		}
		printf("\n");
	}

}

void quicksort(int *arr,int p,int r){
	int q;
	if(p<r){
		q=partition(arr,p,r);
		quicksort(arr,p,q-1);
		quicksort(arr,q+1,r);
	}
}

int partition(int *arr,int p,int r){
	int x_median=randomize(arr,p,r);
	int temp,k;
	/*for(k=p;k<r;k++){
		if(arr[k]==median){
			temp=k;
			break;
		}

	}*/
	int median=arr[x_median];
	swap(&arr[x_median],&arr[r]);
	int i=p-1;
	int j;
	for(j=p;j<r;j++){
		if(arr[j]<=median){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[r]);
	return(i+1);
}

int randomize(int *arr,int p,int r){
	int median;
	int x=p+rand()%(r-p+1);
	int y=p+rand()%(r-p+1);
	int z=p+rand()%(r-p+1);
	//int a=min(&x,&y,&z);
	/*int x=p;
	int y=(p+r)/2;
	int z=r;*/
	int middle=mid(&x,&y,&z);
	//int c=max(&x,&y,&z);
/*	if(a==b && b==c){
		median=a;
	}
	else if(a==b && b!=c){
		if((c-a+1)%2==1){
			median=arr[a+((c-a+1)/2)];
		}
		else{
			median=((arr[a+(c-a+1)/2]+arr[a+((c-a+1)/2)+1])/2);
		}
	}
	else if(b==c && a!=b){
		if((c-a+1)%2==1){
			median=arr[a+((c-a+1)/2)];
		}
		else{
			median=(arr[a+(c-a+1)/2]+arr[a+((c-a+1)/2)+1])/2;
		}

	}
	else{
		int med1,med2;
		if((b-a+1)%2==1){
			med1=arr[a+((b-a+1)/2)];
		}
		else{
			med1=(arr[a+(b-a+1)/2]+arr[a+((b-a+1)/2)+1])/2;
		}
		if((c-b+1)%2==1){
			med2=arr[b+((c-b+1)/2)];
		}
		else{
			med2=(arr[b+(c-b+1)/2]+arr[b+((c-b+1)/2)+1])/2;
		}
		if((med2-med1+1)%2==1){
			median=arr[med1+((med2-med1+1)/2)];
		}
		else{
			median=(arr[med1+(med2-med1+1)/2]+arr[med1+((med2-med1+1)/2)+1])/2;
		}



	}
	return median;*/
	return middle;
}

	


void swap(int *x,int *y){
	int x_val=*x;
	*x=*y;
	*y=x_val;
}

/*int max(int* a,int* b,int* c){
	int max=*a;
	if(*b>max){
		max=*b;
	}
	if(*c>max){
		max=*c;
	}
	return max;
}

int min(int* a,int* b,int* c){
	int min=*a;
	if(*b<max){
		min=*b;
	}
	if(*c<min){
		min=*c;
	}
	return min;
}*/

int mid(int* a,int* b,int* c){
	int mid=*a;
	if (*a>*b) {
  if (*b>*c) {
    mid=*b;
  } else if (*a>*c) {
    mid=*c;
  } else {
    mid=*a;
  }
}
 else {
  if (*a>*c) {
    mid=*a;
  } else if (*b>*c) {
    mid=*c;
}
 else {
    mid=*b;
  }
}
return mid;
}