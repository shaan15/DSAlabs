#include<stdio.h>
int sorts(int *,int);
int main(){
	int T;
	scanf("%d",&T);

	while(T--)
	{
    	int N;
    	scanf("%d",&N);
    	int arr[N];
    	int i;
    	for(i=0;i<N;i++){
    		scanf("%d", (arr+i));
    	}
    	sorts(arr,N);
    	for(i=0;i<N;i++){
    		printf("%d \n",*(arr+i));
    	}
    }
return 0;
}

int sorts(int *arr,int n)
{
int i=0,j=0,k;
int *ptr1,*ptr2;
for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        {
        	ptr1=arr+i;
			ptr2=arr+j;

            if(*ptr1>*ptr2)
            {
                k=*ptr2;
                *ptr2=*ptr1;
                *ptr1=k;
            }
        }
}
 
