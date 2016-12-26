#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int T;
	char str[100];
	scanf("%d",&T);
	while(T--){
		scanf("%s",str);

	int count=0,pos=0,in,i,j,k,l;
	char *ptr;
	ptr=str;
	l=0;
		for(ptr=str;*ptr!='\0';ptr++,l++){
			//printf("%d",pos);
			if(*ptr=='.'){
				count++;
				pos=l;
			}
		}
		//for(ptr=str;*ptr!='\0';ptr++){
			
			//printf("%d",count);
			if(count>1){
				printf("Error! Wrong input!\n");
			}

			else if(count==0){
				in=atoi(str);
				printf("%d",in);
				printf(".000000\n");
			}
			else{
				if(pos==0){
					printf("0");
				}
				else{
				for(i=0;i<(pos-1);i++){
					printf("%c",str[i]);
				}
				}
				printf(".");
				int flag=0;
				for(j=pos;j<(strlen(str)-1);j++){
					flag++;
				}
				/*for(j=pos;j<(strlen(str)-1);j++){
					for(k=1;k<=flag;k++){

					}
				}*/
				//printf("%d",flag);
				if(flag==0){
					printf("000000\n");
				}
				else if(flag==1){
					printf("%c00000\n",str[pos+1]);
				}
				else if(flag==2){
					printf("%c%c0000\n",str[pos+1],str[pos+2]);
				}
				else if(flag==3){
					printf("%c%c%c000\n",str[pos+1],str[pos+2],str[pos+3]);
				}
				else if(flag==4){
					printf("%c%c%c%c00\n",str[pos+1],str[pos+2],str[pos+3],str[pos+4]);
				}
				else if(flag==5){
					printf("%c%c%c%c%c0\n",str[pos+1],str[pos+2],str[pos+3],str[pos+4],str[pos+5]);
				}
				else{
					printf("%c%c%c%c%c%c\n",str[pos+1],str[pos+2],str[pos+3],str[pos+4],str[pos+5],str[pos+6]);
				}

			}
		//}
}
return 0;
}