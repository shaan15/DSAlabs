/*#include<stdio.h>
#include<stdlib.h>

void counting_sort(int,int*,int*,int);

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	int i;
	for(i=0;i<n;i++){
		scanf("%d ",&arr[i]);
	}
	int b[n];
	/*for(i=0;i<n;i++){
		b[i]=0;
	}*/
/*	counting_sort(n,arr,b,n);
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}

void counting_sort(int n,int a[n],int b[n],int k){
	int c[k+1];
	int i;
	for(i=0;i<=k;i++){
		c[i]=0;
	}
	int j;
	for(j=0;j<n;j++){
		c[a[j]]++;
	}
	for(i=1;i<=k;i++){
		c[i]=c[i]+c[i-1];
	}
	for(j=n-1;j>=0;j--){
		b[c[a[j]]-1]=a[j];
		c[a[j]]=c[a[j]]-1;
	}
}*/

#include <stdio.h>
#include <stdlib.h>

void counting_sort(int a[],int b[],int k,int size){
	int c[k+1],i;
	for(i=0;i<=k;i++){
			c[i]=0;
	}

	for(i=0;i<size;i++){
		c[a[i]]++;
	}
	for(i=1;i<=k;i++){
			c[i]+=c[i-1];
	}
	for(i=size-1;i>=0;i--){
		b[c[a[i]]-1]=a[i];
		c[a[i]]--;
	}
}

int main(){
	  int size,i;

	  printf("Enter size of the array: ");
	  scanf("%d",&size);

	  int a[size],b[size];

	  printf("Enter %d elements:(integers only) ",size);
	  for(i=0;i<size;i++)
	    scanf("%d",&a[i]);

		int max=a[0];
		for(i=0;i<size;i++)
	    if(a[i]>max) max=a[i];


	  counting_sort(a,b,max,size);

	  printf("Sorted elements: ");
	  for(i=0;i<size;i++)
	    printf(" %d",b[i]);

	  printf("\n");

	  return 0;
	}