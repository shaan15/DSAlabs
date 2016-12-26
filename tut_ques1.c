#include<stdio.h>
int main(){
	int n1,n2;
	scanf("%d",&n1);
	scanf("%d",&n2);
	int n=n1*n2;
	int i=0,j=0;
	int arr[15];
	/*while(n!=0){
		temp=n%2;
		rev=rev*2+temp;
		n=n/2;
	}
	for(;i>=0;--i){
		printf()
	}
	printf("%d",n);*/
	int count=0;
	while(n1>=0 && i<15){
		if(n1%2==1){
			arr[i]=1;
			i++;
			//printf("Hi\n");
		}
		/*else{
			arr[i]=0;
			i++;
		}*/
		else if(n1%2==0){
			arr[i]=0;
			i++;
			//printf("Heryo");
		}
		else{
			break;
		}
			n1=n1/2;
			count++;
			//printf("Hey\n");
	}
	//printf("%d %d\n",count,i);
	for(j=0;j<count && i<=15;j++){
		//printf("Entered for\n");
		if(arr[j]==1){	
		printf("%d<<%d+",n2,j);
	}
	}
	
	printf("=%d\n",n);
}
