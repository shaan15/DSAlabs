#include<stdio.h>
#include<stdlib.h>

struct city{
				int x;
				int y;
				char cityname[25];
			};
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);

		
		int i;
		struct city arr[n];
		for(i=0;i<n;i++){
			scanf("%d %d %s",&arr[i].x,&arr[i].y,arr[i].cityname);
			//gets(arr[i].cityname);
		}
		int j,k,count1=0,count2=1;  
		int min=(abs(arr[0].x - arr[1].x) + abs(arr[0].y - arr[1].y));
		for(j=0;j<n;j++){
			for(k=j+1;k<n;k++){
				if( (abs(arr[j].x - arr[k].x) + abs(arr[j].y - arr[k].y)) < min )
				{
					min=(abs(arr[j].x - arr[k].x) + abs(arr[j].y - arr[k].y));
					count1=j; 
					count2=k;
				}
			}
		}
		//printf("%d\n",min);
		printf("%s %s\n",arr[count1].cityname,arr[count2].cityname);
		//printf("%s",arr[0].cityname);
		return 0;
		

	    }
	    return 0;

	}