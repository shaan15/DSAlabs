#include<stdio.h>
int main(int argc,char *argv[])
{
int areas[]={10,12,13,14,29};
char name[]="zed";
char fulname[]={'z','e','d',' ','s','h','a','w'};
printf("%ld\n",sizeof(int));
printf("%ld\n",sizeof(areas));
printf("first area is %d and second area is %d\n",areas[0],areas[1]);
printf("no of ints %ld\n",sizeof(areas)/sizeof(int));
printf("%ld\n",sizeof(char));
printf("%ld\n",sizeof(name));
printf("no of char %ld\n",sizeof(name)/sizeof(char));
printf("%ld\n",sizeof(fulname));
printf("%ld\n",sizeof(fulname)/sizeof(char));
printf("name=\"%s\" and fulname=\"%s\"\n",name,fulname);
return 0;
} 
