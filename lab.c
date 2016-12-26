#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int N,i,j;
	printf("Input: ");
	scanf("%d",&N);
	char arr[N][N];
	char str[N];
	int num=N*N;
	printf("Enter N characters\n");
	/*char **arr=(char**)malloc(sizeof(char*)*N);
	for(k=0;k<N;k++){
	arr[k]=(char*)malloc(sizeof(char)*N);
}*/
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf(" %c",&arr[i][j]);
		}
	}
	/*for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%c",arr[i][j]);
		}
	}*/


	printf("Enter input text: ");
	scanf("%s",str);
	if(strlen(str)!=N){
		return 1;
	}
	int k,flag=0,flag1;
	for(i=0;i<N;i++){
		flag=1;
		k=0;
		if(arr[i][0]==str[k]){
							//printf("%c    %c \n",arr[i][1], str[k+1] );

			for(j=1;j<N;j++){
				if(arr[i][j]!=str[++k]){
					//printf("Flag is 1\n");
					flag=0;
					break;
				}
				//else{
				///	flag=0;
				//}
			}
		}
		else
			flag=0;
		//printf("My control %d\n",flag );
		if(flag==1){
			//printf(" INside %d\n",flag );
			printf("Yes\n");
			return 0;
		
		}
	}

	for(j=0;j<N;j++){
		flag1=1;
		k=0;
		//printf("%c    %c\n",arr[0][j],str[k] );
		if(arr[0][j]==str[k])
		{
			for(i=1;i<N;i++)
			{
				//printf("%c    %c \n",arr[i][j], str[k+1] );
				if(arr[i][j]!=str[++k])
				{
					flag1=0;
					break;
				}
				/*else{
					flag1=0;
				}*/
			}

		}
		else
			flag1=0;
		if(flag1==1){
				printf("Yes\n");
				return 0;
			}

	}
	/*if(flag==0 || flag1==0){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}*/
		/*if(flag1==1)
		printf("No\n");*/
		printf("Nope \n");
		return 0;
}