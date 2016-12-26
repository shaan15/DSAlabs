#include<stdio.h>
#include<stdlib.h>
//#include<string.h>

long long int something(long long int *,long long int,long long int,long long int);
//void quicksort(int*,int,int);
long long int partition(long long int *,long long int,long long int);
void swap(long long int *,long long int *);

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long long int N,Q;
		scanf("%lld %lld",&N,&Q);
		long long int arr[N],temp[N];
		long long int i;
		//long long int temp[N];
		for(i=0;i<N;i++){
			scanf("%lld",&arr[i]);
		}

		while(Q--){
			//quicksort(arr,0,N);
			//while(1){
			long long int L,R,k;
			scanf("%lld %lld %lld",&L,&R,&k);
			/*if(k>(R-L)){
				break;
			}*/
			//swap(&arr[k-1],&arr[R]);\
			//printf("Hello!\n");
			int l;
			for(l=0;l<(R-L+1);l++){
				temp[l]=0;
			}

			long long int m=0,j;
			for(j=L;j<(R+1);j++){
				temp[m++]=arr[j];
			}


			int k1;
			/*for(k1=0;k1<m;k1++)
				printf("temp[%d]=%lld \n",k1,temp[k1]);*/
			something(temp,0,m,k);
			// for(k1=0;k1<m;k1++)
			// 	printf("temp[%d]=%lld \n",k1,temp[k1]);
			printf("%lld\n",temp[k-1]);

			//quicksort(temp,L,R);
 			//printf("%d\n",temp[k-1]);

		//}
			/*for(j=0;j<N;j++){
				printf("%d\n",arr[j]);
			}*/
		}
	}
	return 0;

}

long long int something(long long int *arr,long long int p,long long int r,long long int k){
	if(k>0 && k<=(r-p+1)){ 
				long long int pivot;
				pivot=partition(arr,p,r);

				if((pivot-p)==(k-1))
				{
					//printf("\treturn %lld\n",arr[pivot] );

					return arr[pivot];
				}

			else if((pivot-p)>(k-1))
			{
				//printf("\tleft subarrat with pivot = %lld,p=%lld,r=%lld,k=%lld\n",arr[pivot],p,r,k);
				return something(arr,p,pivot,k);
			}
			else
			{
				//printf("\tright subarrat with pivot = %lld",arr[pivot]);
				return something(arr,(pivot-p+1),r,(k-pivot+p-1));
			}
		}
		else
		{
			//printf("r=%lld p=%lld k=%lld\n",r,p,k );
		}
}

/*void quicksort(int *arr,int p,int r){
	if(p<r){
		int q=partition(arr,p,r);
		quicksort(arr,p,q-1);
		quicksort(arr,q+1,r);
	}
}*/
long long int partition(long long int *arr,long long int p,long long int r){
	r--;
	long long int x=arr[r];
	long long int i=p-1;
	long long int j;
	for(j=p;j<r;j++){
		if(arr[j]<=x){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[r]);
	return(i+1);
}

int partition(int *arr,int p,int r){
	//int mid=(p+r)/2;
	//int x=arr[mid];
	int i=p-1; //r
	int j; //0
	for(j=p;j<r;j++){
		if(arr[j]<=x){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[r]);
	return(i+1);
}


void swap(long long int *x,long long int *y){
	long long int x_val=*x;
	*x=*y;
	*y=x_val;
}
