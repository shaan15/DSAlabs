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
node *rootnode=NULL,*temp,*temp2;

/*node **newnode(int val){
	node **temp = (node**)malloc(sizeof(node*));
	*temp->key = val;
	*temp->left = *temp->right = NULL;
	return temp;
}*/

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
	else if((*snode)->key == data){
			printf("Already Exists\n");
		}
	else if(data < (*snode)->key){
		//printf("Enter left subtree\n");
		insert(&(*snode)->left,data);
	}
	else{ 
		//printf("Enter right subtree\n");
		insert(&(*snode)->right,data);
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

void search(node *snode,int k){
	if(snode == NULL){
		printf("Doesnt exist\n");
	}
	else if(k == snode->key){
		printf("Found\n");
		}
	else if(k < snode->key){
		search(snode->left,k);
		}
	else{
		search(snode->right,k);
		}
}

node *minimum(node **root){
	node *current=*root;
	while(current->left != NULL){
		current=current->left;
	}
	return current;
}

// node *maximum(node **root){
// 	node *current = *root;
// 	while(current->right !=NULL){
// 		current = current->right;
// 	}
// 	return current;
// }

// node *max(node **root){
// 	node *current = *root;
// 	while(current->right !=NULL){
// 		current = current->right;
// 	}
// 	printf("");
// }

void delete_node(node **snode,int k){
	if((*snode) == NULL){
		printf("Doesnt exist\n");
	}
	
	else if((*snode)->key == k){
			if((*snode)->left == NULL){
				temp = (*snode);
				(*snode) = (*snode)->right;
				
			}
			else if((*snode)->right == NULL){
				temp=(*snode);
				(*snode) = (*snode)->left;
				//free(temp);
			}
			else{
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
	else if(k < (*snode)->key){
		delete_node(&((*snode)->left),k);
	}
	else{
		delete_node(&((*snode)->right),k);
	}
}



int tree_max(node *snode){
	while(snode->right != NULL){
		snode = snode->right;
	}
	printf("%d\n",snode->key);
}

int tree_min(node *snode){
	while(snode->left != NULL){
		snode = snode->left;
	}
	printf("%d\n",snode->key);
}
/* void tree_succes->sor(struct node *snode){
 	if(snode->right != NULL){
 		return tree_min(snode->right);
 	}

 }*/

/*struct queue{
 	int arr[MAX_SIZE];
 	int head;
 	int tail;
 };
 typedef struct queue QUEUE;
*/
 void enqueue(node **queue,node *newnode,int *tail){
 	queue[*tail] = newnode;
 	(*tail)++;
 }
 node *dequeue(node **queue,int *head){
 	(*head)++;
 	return queue[*head -1];
 	
 }

 // void q_empty(QUEUE *q){
 // 	if(q->head == q->tail){
 // 		return TRUE;
 // 	}
 // 	else{
 // 		return FALSE;
 // 	}
 // }

/*levelorder(node *root){
   q = empty queue
   q.enqueue(root)
   while(q.empty do
     node := q.dequeue()
     visit(node)
     if(root->left != NULL){
     	q.enqueue(node.left);
     }
     if(root->right != NULL){
     q.enqueue(node.right);
 }
 }*/
node **createqueue(int *head,int *tail){
	struct node **queue = (node**)malloc(sizeof(node*)*MAX_SIZE);
	*head = *tail = 0;
	return queue;
}

void levelorder(node *root){
	int head,tail;
	node **queue = createqueue(&head,&tail);
	node *temp3 = root;
	while(temp3){
		printf("%d ", temp3->key);
		if(temp3->left){
			enqueue(queue,temp3->left,&tail);
		}
		if(temp3->right){
			enqueue(queue,temp3->right,&tail);
		}
		temp3 = dequeue(queue,&head);
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
int diameter(node *root,int *height){
	int left_ht=0,right_ht=0,left_dia=0,right_dia=0;
	if(root ==NULL){
		*height = 0;
		return 0;
	}
	
	left_dia = diameter(root->left,&left_ht);
	right_dia = diameter(root->right,&right_ht);
	*height = max(left_ht,right_ht)+1;
	return max((left_ht+right_ht+1),max(left_dia,right_dia));
}
int ht(node *root,int *height){
	int left_ht=0,right_ht=0,left_dia=0,right_dia=0;
	if(root ==NULL){
		*height = 0;
		return 0;
	}
	
	left_dia = diameter(root->left,&left_ht);
	right_dia = diameter(root->right,&right_ht);
	*height = max(left_ht,right_ht)+1;
	return *height;
	}

int height(node *root){
	if(root == NULL){
		return 0;
	}
	else{
		return min((root->left),(root->right))+1;
	}
}
int main(){
	QUEUE q;
	q.head=0;
	q.tail=0;
	int n;
	scanf("%d",&n);
	while(n--){
		char choice[8];
		scanf("%s",choice);
		if(strcmp(choice,"insert")==0)enqueue(&q);
		else if(strcmp(choice,"delete")==0)dequeue(&q);
	}
	return 0;
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

 int main(){
 	int T;
 	scanf("%d",&T);
 	while(T--){
 		char str[10];
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
 			tree_min(rootnode);
 		}
 		else if(strcmp(str,"max")==0){
 			tree_max(rootnode);
 		}
 		else if(strcmp(str,"inorder")==0){
 			inorder(rootnode);
 			printf("\n");
 		}
 		else if(strcmp(str,"preorder")==0){
 			preorder(rootnode);
 			printf("\n");
 		}
 		else if(strcmp(str,"postorder")==0){
 			postorder(rootnode);
 			printf("\n");
 		}
 		else if(strcmp(str,"levelorder")==0){
 			levelorder(rootnode);
 			printf("\n");
 		}
 		else if(strcmp(str,"diameter")==0){
 			int hit = 0;
 			printf("%d\n",diameter(rootnode,&hit));
 		}
 		else if(strcmp(str,"height")==0){
 			int hit = 0;
 			printf("%d\n",ht(rootnode,&hit));
 		}
 		else if(strcmp(str,"search")==0){
 			int val;
 			scanf("%d",&val);
 			search(rootnode,val);
 		}
 		else if(strcmp(str,"kthsmall")==0){
 			int k;
 			scanf("%d",&k);
 			printf("%d\n",k_smallest(rootnode,k));
 		}
 		else{
 			printf("invalid query\n");
 		}
 	}
 	return 0;
 }

