#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 500

struct treenode{
	int key;
	struct treenode *left;
	struct treenode *right;
};
typedef struct treenode node;

/*node **newnode(int val){
	node **temp = (node**)malloc(sizeof(node*));
	*temp->key = val;
	*temp->left = *temp->right = NULL;
	return temp;
}*/

void insert(node **snode, int data){
	if((*snode)==NULL){
		(*snode) = (node *)malloc(sizeof(node));
		(*snode)->left=NULL;
		(*snode)->right=NULL;
		(*snode)->key=data;

		//printf("new node made: %d\n",(*snode)->key);

	}
	/*else if((*snode)->key == data){
			printf("Already Exists\n");
		}*/
	else if(data < (*snode)->key){
		//printf("Enter left subtree\n");
		insert(&(*snode)->left,data);
	}
	else{ 
		//printf("Enter right subtree\n");
		insert(&(*snode)->right,data);
		}
	
}


void preorder(node *root){
	if(root!=NULL){
		printf("%d ",root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		node *rootnode=NULL;
		int N;
		scanf("%d",&N);
		int arr[N];
		int i=0;
		for(i=0;i<N;i++){
			scanf("%d",&arr[i]);
			insert(&rootnode,arr[i]);

		}
		preorder(rootnode);
		printf("\n");
	}
}