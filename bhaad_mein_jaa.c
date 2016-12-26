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
node *rootnode=NULL;



void inorder(node *root){
	if(root!=NULL){
	inorder(root->left);
	printf("%d ",root->key);
	inorder(root->right);
}

}

void preorder(node *root){
	if(root!=NULL){
		printf("%d ",root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->key);
	}
}

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

node * minValueNode( node* a)
{
    node* current = a;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 
/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
 node* delete_node( node* root, int key)
{
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = delete_node(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = delete_node(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
             node *temp = root->right;
            //free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
             node *temp = root->left;
            //free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
         node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

void delete_range(node *root,int l,int u){
	int i;
//	for(i=l+1;i<u;i++){
//		delete_node(&root,i);
//	}
	if(root!=NULL){
		delete_range(root->left,l,u);
		delete_range(root->right,l,u);
		if((root->key > l) && (root->key < u)){
			printf("I HAVE FOUND THIS %d\n", root->key);
			delete_node(root,root->key);
		}
	}

/*if(root == NULL){
	printf("\n");
}
else{
	if(root->key >= u){
		delete_range(root->left,l,u);
	}
	else if(root->key <= l){
		delete_range(root->right,l,u);
	}
	else{
		delete_node(&root,root->key);
	}
}
*/
}

/*void inorder_array(node *root,int l,int u){
	int i=0;
	int arr[1000000005];
	if(root!=NULL){
	inorder_array(root->left,l,u);
	arr[i] = root->key;
	i++;
	inorder_array(root->right,l,u);
}
int j;
for(j=l+1;j<u;j++){
	delete_node(&root,arr[i]);
}

}*/

/*node *min(node **root,int u,int l){
	node *current=*root;
	while(current->left != NULL){
		current=current->left;
	}
	return current;
}

void delete_in_range(node *root,int l,int u){

}*/
int main(){
	while(1){
		char str[7];
		scanf("%s",str);
		if(strcmp(str,"INSERT")==0){
			int choice;
			scanf("%d",&choice);
			insert(&rootnode,choice);
		}
		else if(strcmp(str,"DELETE")==0){
			int l,u;
			scanf("%d %d",&l,&u);
			delete_range(rootnode,l,u);
		}
		else if(strcmp(str,"PRINT")==0){
			int choice;
			scanf("%d",&choice);
			if(choice == 1){
				inorder(rootnode);
				printf("\n");
			}
			else if(choice == 2){
				preorder(rootnode);
				printf("\n");
			}
			else if(choice == 3){
				postorder(rootnode);
				printf("\n");
			}
			

	}
	else if(strcmp(str,"END")==0){
			return 0;
		}
		
	}
}