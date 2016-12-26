#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct unix_node{
	char key[121];
	struct unix_node *child[100];
};

typedef struct unix_node node;
node *temp,*current;
node *rootnode=NULL;

void create_node(char *key){
	temp = (node*)malloc(sizeof(node));
	strcpy(temp->key,key);
	int i;
	for(i=0;i<100;i++){
		temp->child[i] = NULL;
	}
}

void insert(node ** rootnode,char *key){
		int l=strlen(key);
		int j;
		for(j=0;j<100;j++){
			if((*rootnode)->child[j] == NULL){
				int i;
				char temporary[121];int k=0;
				for(i=1;i<l;i++){
					if(key[i]=='/'){
						break;
					}
					else{
						temporary[k]=key[i];
						k++;
					}
				}
				temporary[k]='\0';
				create_node(temporary);

				(*rootnode)->child[j]=temp;
				break;
			}
			else if(strcmp(key,(*rootnode)->child[j]->key)==0){
				int i;
				char temporary[121];int k=0;
				for(i=1;i<l;i++){
					if(key[i]=='/'){
						break;
					}
					else{
						temporary[k]=key[i];
						k++;
					}
				}
				temporary[k]='\0';
				insert(&((*rootnode)->child[j]),temporary);
			}
		}
		/*if(count == 5){*/

}

void search(node *snode,char *k){
	int i,flag=1;
  	char * token;
  	token=strtok(k,"/");
  	current=rootnode;

  while(token != NULL){

  for(i=0;i<100;i++){
    if(current->child[i] != NULL && strcmp(current->child[i]->key,token)==0){
      current=current->child[i];
      break;
    }
    else if(current->child[i] == NULL){
      flag=0;
      break;
    }
  }

  token=strtok(NULL,"/");
  }
  if(flag==1)printf("YES\n");
  else printf("NO\n");
	
}
	

int main(){
	create_node("/");
	rootnode=temp;
	int N;
	scanf("%d",&N);
	while(N--){
		char str[125];
		scanf("%s",str);
		insert(&rootnode,str);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		char str[125];
		scanf("%s",str);
		search(rootnode,str);
	}
	return 0;
}