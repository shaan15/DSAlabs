#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int ladoos = 0;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int act;
		char origin[11];
		scanf("%d %s",&act,origin);
		while(act--){
			char query[15];
			scanf("%s",query);
			if(strcmp("CONTEST_WON",query)==0){
				int rank;
				scanf("%d",&rank);
				if(rank <= 20){
					int bonus;
					bonus = 20-rank;
					ladoos = ladoos + 300 + bonus;
				}
				else{
					ladoos = ladoos + 300;
				}
			}
			else if(strcmp("TOP_CONTRIBUTOR",query)==0){
				ladoos = ladoos + 300;
			}
			else if(strcmp("BUG_FOUND",query)==0){
				int intensity;
				scanf("%d",&intensity);
				ladoos = ladoos + intensity;
			}
			else if(strcmp("CONTEST_HOSTED",query)==0){
				ladoos = ladoos + 50;
			}
		}
		int months;
		if(strcmp("INDIAN",origin)==0){
			months = ladoos/200;
		}
		else if(strcmp("NON_INDIAN",origin)==0){
			months = ladoos/400;
		}
		printf("%d\n",months);
		ladoos = 0;
	}
	return 0;
}