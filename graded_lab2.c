#include<stdio.h>
#include<stdlib.h>

void merge(int *,int,int,int);
void merge_sort(int*,int,int);

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int arr[n];
		int i;
		int count_even=0,count_odd=0;
		for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
			if(arr[i]%2==0){
				count_even++;
			}
			else{
				count_odd++;
			}
		}
		int even_arr[count_even];
		int odd_arr[count_odd];
		int j;
		int y=0,z=0;
		for(j=0;j<n;j++){
			if(arr[j]%2==0){
				even_arr[y]=arr[j];
				y++;
			}
			else{
				odd_arr[z]=arr[j];
				z++;
			}
		}
		int first=0;
		merge_sort(even_arr,first,count_even-1);
		merge_sort(odd_arr,first,count_odd-1);
		int h=0,g;
		for(h=0;h<count_even;h++){
			printf("%d ",even_arr[h]);
		}
		for(g=(count_odd-1);g>=0;g--){
			printf("%d ",odd_arr[g]);
		}
		printf("\n");


		}
		return 0;

	}

void merge(int *arr,int p,int q,int r){
	int i,j,k,s;
	int L[q-p+2],R[r-q+1];
	for(i=p,j=0;i<=q,j<=(q-p);i++,j++){
			L[j]=arr[i];
			//printf("copied to L\n");

	}
	for(s=q+1,k=0;s<=r,k<(r-q+1);s++,k++){
			R[k]=arr[s];
			//printf("copied to R\n");
	}
	L[q-p+1]=1000000;
	R[r-q]=1000000;
	//printf("sentinel declared\n");

	int m=0,n=0,x;
	for(x=p;x<=r;x++){
		if(L[m]<=R[n]){
			arr[x]=L[m];
			m++;
			//printf("L dominates\n");
		}
		else{
			arr[x]=R[n];
			n++;
			//printf("R dominates\n");
		}
	}
	//printf("merging done\n");

}

void merge_sort(int *arr,int start,int end){
	int mid;
	if(start<end){
	mid=(start+end)/2;
	//printf("mid found\n");


	merge_sort(arr,start,mid);
	merge_sort(arr,mid+1,end);
	merge(arr,start,mid,end);
	//printf("Now sorted!");
}
}