#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void check_prime(int,int,int*);

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int arr[n][3];
		int i,j;
		for(i=0;i<n;i++){
			for(j=0;j<3;j++){
				scanf("%d",&arr[i][j]);
			}
		}
		int count_x=0,count_y=0,count_z=0,k;
		for(k=0;k<n;k++){
			count_x += arr[k][0];
			count_y += arr[k][1];
			count_z += arr[k][2];
		}
		//printf("%d %d %d\n",count_x,count_y,count_z);
		int flag1=0,flag2=0,flag3=0;
		check_prime(100,count_x,&flag1);
		//printf("flag1 is %d\n",flag1);
		check_prime(100,count_y,&flag2);
		//printf("flag2 is %d\n",flag2);
		check_prime(100,count_z,&flag3);
		////printf("flag3 is %d\n",flag3);

		if(flag1==1 && flag2==1 && flag3==1){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}

		

		}
		return 0;

	}

void check_prime(int max_size,int key,int *flag){
			int arr[max_size];
			int i,j;
			for(i=0;i<max_size;i++){
				arr[i]=i+2;
			}
			int primes[max_size];
			//int k=0;
			/*arr[0]=-1;
			arr[1]=-1;
			int k=0;
			for(i=2;i<max_size;i++){
				for(j=i+1;j<max_size;j++){
					if(arr[i]!=0 && (arr[j]%arr[i])==0){
						primes[k]=arr[i];
						arr[j]=-1;
						k++;
					}

				}
			}*/
			/*printf("k is %d\n",k);
			for(i=0;i<k;i++){
				//printf("%d\n",arr[i]);
				printf("%d\n",primes[i]);
			}*/
			//int k=0,m;
			//
			for (i=0;i<max_size;i++){
        	if (arr[i]!=-1){
            	for (j=2*arr[i]-2;j<max_size;j+=arr[i])
                	arr[j]=-1;
        }
    }
    		int k=0;
    		for(i=0;i<max_size;i++){
				if(arr[i]!=-1){
					primes[k++]=arr[i];
				}
				//printf("%d ",arr[i]);
			}
			//printf("k is %d\n",k);
			int l;
			*flag=0;
			for(l=0;l<(k+1);l++){
				if(key==primes[l]){
					*flag=1;
					//printf("entered if again\n");
					break;
				}
				else if(key==0){
					*flag=0;
				}
				else if(key==1){
					*flag=0;
				}
				//else{
					//flag=0;
					//printf("entered else now\n");
					//continue;
				//}
			}
		}