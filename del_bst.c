#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define MAX_SIZE 500

struct treenode{
	int key;
	struct treenode *left;
	struct treenode *right;
};
typedef struct treenode node;
node *rootnode=NULL,*temp,*temp2;
int i=0;
//int *arr=(int*)malloc(sizeof(int)*1000000005);
int arr[100000000];



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

node *minimum(node **root){
	node *current=*root;
	while(current->left != NULL){
		current=current->left;
	}
	return current;
}

void delete_node(node **snode,int k){
	if((*snode) == NULL){
		//printf("Doesnt exist\n");
		return;
	}
	if((*snode)->key > k){
		delete_node(&((*snode)->left),k);
	}
	else if ((*snode)->key < k){
		delete_node(&((*snode)->right),k);
	}
	
	else {
			if((*snode)->left == NULL){
				temp = (*snode);
				(*snode) = (*snode)->right;
				free(temp);
				return;
				
			}
			else if((*snode)->right == NULL){
				temp=(*snode);
				(*snode) = (*snode)->left;
				free(temp);
				return;
			}
				temp2 = minimum(&((*snode)->right));
				//node *temp = (*snode)->right;
				(*snode)->key = temp2->key;
				delete_node(&((*snode)->right),temp2->key);
				// while(temp->left != NULL){
				// 	temp = temp->left;
				//}
				//*snode = temp;
		}
}

/*void delete_range(node *root,int l,int u){
	int i;
//	for(i=l+1;i<u;i++){
//		delete_node(&root,i);
//	}
	if(root!=NULL){
		delete_range(root->left,l,u);
		delete_range(root->right,l,u);
		if((root->key > l) && (root->key < u)){
			printf("I HAVE FOUND THIS %d\n", root->key);
			delete_node(&root,root->key);
		}
	}*/

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


void delete_range(node *root,int l,int u){
	if(root == NULL){
	//printf("\n");
	return;
}
/*int i=0;
int *arr=(int*)malloc(sizeof(int)*1000000005);
	if(root!=NULL){
		delete_range(root->left,l,u);
		if((root->key > l) && (root->key < u)){
			//printf("I HAVE FOUND THIS %d\n", root->key);
			arr[i] = root->key;
			i++;
			}
		delete_range(root->right,l,u)*/
	delete_range(root->left,l,u);
	if((root->key > l) && (root->key < u)){
		arr[i] = root->key;
		i++;
	}
	
	delete_range(root->right,l,u);


}

/*void delete_range2(node *root,int l,int u){
	if(root == NULL){
	printf("\n");
	return;
}*/
/*int i=0;
int *arr=(int*)malloc(sizeof(int)*1000000005);*/
	/*if(root->key >= u){
		delete_range(root->left,l,u);
	}
	else if(root->key <= l){
		delete_range(root->right,l,u);
	}
	else{
		arr[i] = root->key;
		i++;
	}
int j;
for(j=0;j<(i+1);j++){
	delete_node(&root,arr[j]);
}

}

void delete_range2(node *root,int l,int u){
	if(root == NULL){
	printf("\n");
	return;
}
*/
	/*if(root->key >= u){
		delete_range(root->left,l,u);
	}
	else if(root->key <= l){
		delete_range(root->right,l,u);
	}
	else{
		arr[i] = root->key;
		i++;
	}*/
/*
		}
		delete_range(root->right,l,u);
		
	}

int j;
for(j=0;j<(i+1);j++){
	delete_node(&root,arr[j]);
}

}*/

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
			int k;
			for(k=0;k<i;k++){
				delete_node(&rootnode,arr[k]);
			}
			i=0;
		}
		else if(strcmp(str,"PRINT")==0){
			int choice;
			scanf("%d",&choice);
			if(choice == 1){
				if(rootnode==NULL){
					printf("\n");
				}
				else{
				inorder(rootnode);
				printf("\n");
			}
		}
			else if(choice == 2){
				if(rootnode==NULL){
					printf("\n");
				}
				else{
				preorder(rootnode);
				printf("\n");
			}
		}
			else if(choice == 3){
				if(rootnode==NULL){
					printf("\n");
				}
				else{
				
				postorder(rootnode);
				printf("\n");
			}
		}
			

	}
	else if(strcmp(str,"END")==0){
			return 0;
		}
		
	}

}