#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct treenode{
	int key;
	struct treenode *left;
	struct treenode *right;
};
typedef struct treenode node;

void insert(node **snode, int data){
	if((*snode)==NULL){
		(*snode) = (node *)malloc(sizeof(node));
		(*snode)->left=NULL;
		(*snode)->right=NULL;
		(*snode)->key=data;

		//printf("new node made: %d\n",(*snode)->key);

	}
	else if(data <= (*snode)->key){
		//printf("Enter left subtree\n");
		insert(&(*snode)->left,data);
	}
	else{ 
		//printf("Enter right subtree\n");
		insert(&(*snode)->right,data);
		}
	
}

int min(int x,int y){
	if(x<=y){
		return x;
	}
	else{
		return y;
	}
}

int height(node *root){
	if(root == NULL){
		return 0;
	}
	else if((root->left == NULL) && (root->right == NULL)){
		return 1;
	}
	else if((root->left) == NULL){
		return height(root->right)+1;
	}
	else if((root)->right == NULL){
		return height(root->left)+1;
	}
	else{
		return min(height(root->left),height(root->right))+1;
	}
}

int lca(node *root,int x,int y){
	if(((x <= root->key) && (y >= root->key)) || ((x >= root->key) && (y <= root->key))){
		return root->key;
	}
	else if((x > root->key) && (y >root->key)){
		return lca(root->right,x,y);
	}
	else{
		return lca(root->left,x,y);
	}

}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		node *rootnode=NULL;
		int n;
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			insert(&rootnode,x);
		}
		printf("%d\n",height(rootnode));
		int q;
		scanf("%d",&q);
		while(q--){
			int m,n;
			scanf("%d %d",&m,&n);
			printf("%d\n",lca(rootnode,m,n));
		}
	}
	return 0;
}

