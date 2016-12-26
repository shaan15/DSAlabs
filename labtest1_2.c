#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int checkfunny(char*);

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		char str[1000];
		scanf("%s",str);
		checkfunny(str);
	}
	return 0;

}

int checkfunny(char *s){
	int len=strlen(s);
	char r[1000];
	//char *ptr;
	/*for(ptr=(s+len-1);ptr>=0;ptr--){

	}*/
	int i,k;
	for(i=(len-1),k=0;i>=0,k<len;i--,k++){
		r[k]=s[i];
	}
	//printf("%s\n",r);
	int count=0,j;
	for(j=1;j<len;j++){
		if(abs(s[j]-s[j-1])==abs(r[j]-r[j-1])){
			count++;
		}
		else{
			printf("Not Funny\n");
			return 0;
		}
	}
	printf("Funny\n");
	return 0;


}