#include<stdio.h>
#include<stdlib.h>

void swap(int* , int*);

int main()
{
	
	int T;
	scanf("%d",&T);

	while(T--)
	{
    	int n;
    	scanf("%d",&n);
    	int arr[n];
    	int i,k,c,l;
    	for(i=0;i<n;i++)
    		scanf("%d", (arr+i));

    	int min=arr[0];
    	for(l=1;l<(n-1);l++)
    	{
    		for(k=l+1;k<(n-1);k++)
    		{
    			if(arr[k]<min)
    			{
    				min=arr[k];
    			}
    		}
    		if(min!=l)
    		{
    			swap(arr+l,arr+min);
			}
    	}

    	for(c=0;c<n;k++)
    		printf("%d ",*(arr+c));
    }
	

	return 0;
//hiya

}

void swap(int* x, int* y)
{
	int x_val = *x;
	*x = *y;
	*y = x_val;
}
