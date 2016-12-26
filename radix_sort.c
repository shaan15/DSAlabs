/*#include<stdio.h>
#include<stdlib.h>

void radix_sort(int*,int);
void counting_sort(int*,int,int);

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	radix_sort(arr,d);
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void radix_sort(int n,int arr[n],int d){
	int i;
	for(i=0;i<n;i++){
		if()
	}


}

/*int getMax(int arr[], int n) {

    int mx = arr[0];

    int i;

    for (i = 1; i < n; i++){

        if (arr[i] > mx){

            mx = arr[i];
        }
    }    

    return mx;

}*/

#include <stdio.h>

int find_digit(int num,int index,int d){
  int i,ans;
  for(i=0;i<d-index;i++){
    ans=num%10;
    num=num/10;
  }
  return ans;
}

void counting_sort(int a[],int b[],int size,int digit,int d){
	int c[10],i;
	for(i=0;i<=9;i++){
			c[i]=0;
	}

	for(i=0;i<size;i++){
		c[find_digit(a[i],digit,d)]++;
	}
	for(i=1;i<=9;i++){
			c[i]+=c[i-1];
	}
	for(i=size-1;i>=0;i--){
		b[c[find_digit(a[i],digit,d)]-1]=a[i];
		c[find_digit(a[i],digit,d)]--;
	}
}

void radix_sort(int a[],int b[],int d,int size){
  int i,j;
  for(i=d-1;i>=0;i--){
    counting_sort(a,b,size,i,d);
    for(j=0;j<size;j++){
      a[j]=b[j];
    }
  }
}

int main(){

  int size,i;

  printf("Enter size of the array: ");
  scanf("%d",&size);

  int a[size],b[size];

  printf("Enter %d elements: ",size);
  for(i=0;i<size;i++)
    scanf("%d",&a[i]);

  radix_sort(a,b,3,size);  //remove hard code

  printf("Sorted elements: ");
  for(i=0;i<size;i++)
    printf(" %d",b[i]);

  printf("\n");

  return 0;
}