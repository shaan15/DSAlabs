#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct treenode{
	int key;
	struct treenode *left;
	struct treenode *right;
};
typedef struct treenode node;
node *root=NULL;

/*node **newnode(int val){
	node **temp = (node**)malloc(sizeof(node*));
	*temp->key = val;
	*temp->left = *temp->right = NULL;
	return temp;
}*/

void inorder(){
	if(root!=NULL){
	inorder(root->left);
	printf("%d ",root->key);
	inorder(root->right);
}
printf("\n");

}

void preorder(){
	if(root!=NULL){
		printf("%d ",root->key);
		preorder(root->left);
		preorder(root->right);
	}
	printf("\n");
}

void postorder(){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->key);
	}
	printf("\n");
}

void insert(int data){
	if(root==NULL){
		root = (node*)malloc(sizeof(node));
		root->left=NULL;
		root->right=NULL;
		root->key=data;

		printf("new node made: %d\n",root->key);

	}
	else if(root->key == data){
			printf("Already Exists\n");
		}
	else if(data < root->key){
		printf("Enter left subtree\n");
		insert(root->left,data);

	}
	else{ 
		printf("Enter right subtree\n");
		insert(root->right,data);
		}
	
}


/*void insert_node(node *tree,int z){
	int y=NULL;
	int x=tree->root;
	while(x!=NULL){
		y=x;
		if(z->key < x->key){
			x=x->left;
		}
		else{
			x=x->right;
		}
		z->parent=y;
		if(y==NULL){
			tree->root=z;
		}
		else if(z->key < y->key){
			y->left=z;
		}
		else{
			y->right=z
		}
	}
}*/

void search(int k){
	if(root == NULL){
		printf("Doesnt exist\n");
	}
	else if(k == root->key){
		printf("Found\n");
		}
	else if(k < root->key){
		search(root->left,k);
		}
	else{
		search(root->right,k);
		}
}

void delete_node(int k){
	if(root == NULL){
		printf("Doesnt exist\n");
	}
	
	else if(root->key == k){
			if(root->left == NULL){
				root = root->right;
			}
			else if(root->right == NULL){
				root = root->left;
			}
			else{
				node *temp = root->right;
				while(temp->left != NULL){
					temp = temp->left;
				}
				root = temp;
			}
		}
	else if(k < root->key){
		delete_node(root->left,k);
	}
	else{
		delete_node(root->right,k);
	}
}



int tree_max(node *snode){
	while(snode->right != NULL){
		snode = snode->right;
	}
	return snode->key;
}

int tree_min(node *snode){
	while(snode->left != NULL){
		snode = snode->left;
	}
	return snode->key;
}

int left_size(node *root){
	if(root == NULL){
		return 0;
	}
	return(1+left_size(root->left)+left_size(root->right));
}

int k_smallest(node *root,int k){
	if(root == NULL){
		return 0;
	}

	int size_left = left_size(root->left);

	if(size_left == k-1){
		return root->key;
	}
	else if(size_left > k-1){
		return k_smallest(root->left, k);
	}
	else{
		return k_smallest(root->right,(k-size_left-1));
	}
}

/* void tree_succes->sor(struct node *snode){
 	if(snode->right != NULL){
 		return tree_min(snode->right);
 	}

 }*/

 int main(){
 	int T;
 	scanf("%d",&T);
 	while(T--){
 		char str[12];
 		scanf("%s",str);
 		if(strcmp(str,"insert")==0){
 			int val;
 			scanf("%d",&val);
 			insert(&rootnode,val);
 		}
 		else if(strcmp(str,"delete")==0){
 			int val;
 			scanf("%d",&val);
 			delete_node(&rootnode,val);
 		}
 		else if(strcmp(str,"min")==0){
 			tree_min(&rootnode);
 		}
 		else if(strcmp(str,"max")==0){
 			tree_max(&rootnode);
 		}
 		else if(strcmp(str,"inorder")==0){
 			inorder(rootnode);
 		}
 		else if(strcmp(str,"preorder")==0){
 			preorder(rootnode);
 		}
 		else if(strcmp(str,"postorder")==0){
 			postorder(rootnode);
 		}
 		else if(strcmp(str,"search")==0){
 			int val;
 			scanf("%d",&val);
 			search(rootnode,val);
 		}
 		else if(strcmp(str,"kth")==0){
 			int k;
 			scanf("%d",&k);
 			k_smallest(rootnode,k);
 		}
 		else{
 			printf("invalid query\n");
 		}
 	}
 	return 0;
 }

