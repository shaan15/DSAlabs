#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int convert(char *);

int main(){
	int T;
	char n[100];
	scanf("%d",&T);
	while(T--){
		scanf("%s",n);
		convert(n);
	}
	return 0;
}

int convert(char *str){
	int count=0;
	int len=strlen(str);
	int arr[len],i=0,in;
	char arr1[len],arr2[len];
	char *ptr;
	ptr=str;
	int pos =0;
	int pos1;
	for(ptr=str;*ptr!='\0';ptr++){
		if(*ptr=='.'){
			pos1 = pos;
			count++;
		}
		pos++;
	}
	if(count>1){
		printf("Error! Invalid input!");
		return 1;
	}
	/*for(ptr=str;*ptr != '\0';ptr++){
		for(i=0;i<len;i++){
			if(*ptr!='.'){
			in=atoi(ptr);
			in=arr[i];
		}
		else{
			*ptr=arr[i];

		}
		}
	}*/


	else if(count==0){
		in = atoi(str);
		printf("%d\n", in );
	}

	else{
		int n1,n2;
		if(*str == '.'){
			n1 =0;
		}
		else{
			//printf("%d\n", len - pos1 -1 );	
			int zeroes = len - pos1 -1 ;
			int position =0;
			for(i=pos1 +1; str[i] != '\0';i++){
				arr2[position] = str[i];
				position++;
			}
			printf("%s\n", arr2);

			for(i=0 ; i<pos1 ;i++){
				arr1[i] = str[i];
			}
			printf("%s\n",arr1 );
		}
	}

	for(i=0;i<len;i++){
		//printf("%d",arr[i]);
	}
printf("\n");

return 0;
}