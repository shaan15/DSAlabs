#include <stdio.h>

int main(void) {
	char a[100],b[100],* ptr1,*ptr2;
	int i=0,j,k,s=0,l,m,flag=0;
	scanf("%s",a);
	scanf("%s",b);
	ptr1=a;
	while(*(ptr1+i)!='\0')
	{
		j++;
		i++;
	}
	ptr2=b;
	while(*(ptr2+s)!='\0')
	{
		k++;
		s++;
	}

	
	if(j==k)
	{
		for(l=0;a[l]!='\0';l++)
		{
			for(m=0;b[m]!='\0';m++)
			{
				if(a[l]!=b[m])
				{
					flag++;
					break;
					
				}
				
			}
		}
	}
	if(flag==0 && j==k)
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
	return 0;
}
