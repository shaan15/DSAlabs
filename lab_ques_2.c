
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int len,count=0;
	char *ptr;
	char str[1000];


scanf("%s",str);
ptr=str;
len=strlen(str);



int i=0,j=0;

for(i=0;i<len;i++){
	for(j=i+1;j<len;j++){
		//printf("%c %c\n", *(ptr+i),*(ptr+j));
	if(*(ptr+i)==*(ptr+j)){
		count++;
		break;
	
	}
}

}
if(count==0){
	printf("Yes\n");
}
else{
	printf("no\n");
}
return 0;

}