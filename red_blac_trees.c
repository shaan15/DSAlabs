#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct treenode{
	int key;
	char colour[6];
	struct treenode *left,*right,*parent;
};

typedef struct treenode node;
node *root,*x,*y,*temp,*tnil;

void create(int val){
  node *temp=(node *)malloc(sizeof(node));
  temp->left=tnil;
  temp->right=tnil;
  temp->parent=tnil;
  temp->key=val;
}

void left_rotate(node *x){
	//node *y;
	y=x->right;
	x->right = y->left;
	if(y->left != tnil){
		y->left->parent = x;
	}
	y->parent = x->parent;
	if(x->parent == tnil){
		root = y;
	}
	else if(x == x->parent->left){
		x->parent->left = y;

	}
	else{
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

void right_rotate(node *y){
	//node *x;
	x = y->left;
	y->left = x->right;
	if(x->right != tnil){
		x->right->parent = y;
	}
	x->parent = y->parent;
	if(y->parent == tnil){
		root = x;
	}
	else if(y == y->parent->left){
		y->parent->left = x;
	}
	else{
		y->parent->right = x;
		
	}
	x->right = y;
	y->parent = x;
}

/*void insert_fixup(node *z){
	node *y=NULL;
	while((z->parent != NULL) && (z->parent->colour == 'r')){
		if((z->parent->parent->left != NULL) && (z->parent->key == z->parent->parent->left->key)){
			if(z->parent->parent->right != NULL){
				y = z->parent->parent->right;
			}
			if((y != NULL) && (y->colour == 'r')){
				z->parent->colour = 'b';
				y->colour = 'b';
				z->parent->parent->colour = 'r';
				if(z->parent->parent != NULL){
					z = z->parent->parent;
				}
			}
			else{
				if((z->parent->right != NULL) && (z->key == z->parent->right->key)){
					z = z->parent;
					left_rotate(z);
				}
				z->parent->colour = 'b';
				z->parent->parent->colour = 'r';
				right_rotate(z->parent->parent);
			}
		}
		else{
			if(z->parent->parent->left != NULL){
				y =z->parent->parent->left;
			}
			if((y != NULL) && (y->colour == 'r')){
				z->parent->colour = 'b';
				y->colour = 'b';
				z->parent->parent->colour = 'r';
				if(z->parent->parent != NULL){
					z = z->parent->parent;
				}
			}
			else{
				if((z->parent->left != NULL) && (z->key == z->parent->left->key)){
					z = z->parent;
					right_rotate(z);
				}
				z->parent->colour = 'b';
				z->parent->parent->colour = 'r';
				left_rotate(z->parent->parent);
			}
		}
	}
	root->colour = 'b';
}*/
void insert_fixup(node * temp){
  while(strcmp(temp->parent->colour,"RED")==0){
    if(temp->parent == temp->parent->parent->left){
      y=temp->parent->parent->right;
      if(strcmp(y->colour,"RED")==0){
        strcpy(temp->parent->colour,"BLACK");
        strcpy(y->colour,"BLACK");
        strcpy(temp->parent->parent->colour,"RED"); // case 1
        temp = temp->parent->parent;
      }
      else if(temp == temp->parent->right){
        temp=temp->parent; 
        left_rotate(temp);
				strcpy(temp->parent->colour,"BLACK");
				strcpy(temp->parent->parent->colour,"RED");
				right_rotate(temp->parent->parent);
			}
			else{
				strcpy(temp->parent->colour,"BLACK");
				strcpy(temp->parent->parent->colour,"RED");
				right_rotate(temp->parent->parent);
			}
    }
    else{
      y=temp->parent->parent->left;
      if(strcmp(y->colour,"RED")==0){
        strcpy(temp->parent->colour,"BLACK");
        strcpy(y->colour,"BLACK");
        strcpy(temp->parent->parent->colour,"RED");
        temp=temp->parent->parent;
      }
      else if(temp == temp->parent->left){
        temp=temp->parent;
        right_rotate(temp);
				strcpy(temp->parent->colour,"BLACK");
				strcpy(temp->parent->parent->colour,"RED");
				left_rotate(temp->parent->parent);
			}
			else{
				strcpy(temp->parent->colour,"BLACK");
				strcpy(temp->parent->parent->colour,"RED");
				left_rotate(temp->parent->parent);
			}
    }
  }
  strcpy(root->colour,"BLACK");
}
/*int search(node *root,int k){
if(root == NULL){
	printf("Doesnt exist\n");
}
else if(k == root->key){
	return 1;
	}
else if(k < root->key){
	search(root->left,k);
	}
else{
	search(root->right,k);
	}
return 0;
}*/

node *search(node ** root,int val){
	node *x,*y;
  if((*root)== NULL || (*root)->key==val){
    return *root;
  }
  if(val < (*root)->key){
    return search(&((*root)->left),val);
  }
  else return search(&((*root)->right),val);
}

void insert(int val){
  //node *x,*y,*temp;
  y = tnil;
  x = root;
  while(x != tnil){
    y=x;
    if(val < x->key) x=x->left;
    else x = x->right;
  }
  create(val);
  temp->parent=y;
  if(y==tnil){
    root=temp;
  }
  else if(val < y->key){
    y->left=temp;
  }
  else y->right=temp;

  temp->left = tnil;
  temp->right = tnil;
  strcpy(temp->colour,"RED");
  insert_fixup(temp);
}

//void insert(int val){
/*	node *x,*y;
	node *z = (node*)malloc(sizeof(node));
	z->key = val;
	z->left = NULL;
	z->right = NULL;
	z->colour = 'r';
	x = root;
	if(search(root,val) == 1){
		return;
	}
	//bst_insert(&root,int val);
	if(root == NULL){
		root = z;
		root->colour = 'b';
		return;
	}
	while(x != NULL){
		y = x;
		if(z->key < x->key){
			x = x->left;
		}
		else{
			x = x->right;
		}
	}
	z->parent = y;
	if(y == NULL){
		root = z;
	}
	else if(z->key < y->key){
		y->left = z;
	}
	else{
		y->right = z;
	}
	insert_fixup(z);
	}
*/

/*void bst_insert(node **snode, int data){
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
		bst_insert(&(*snode)->left,data);
	}
	else{ 
		//printf("Enter right subtree\n");
		bst_insert(&(*snode)->right,data);
		}
	
}*/

void inorder(node ** temp1){
	//node *temp = root;
	if((*temp1) != tnil){
		inorder(&((*temp1)->left));
		printf("%d %s\n",(*temp1)->key,(*temp1)->colour);
		inorder(&((*temp1)->right));
	}
}

void preorder(node **temp1){
	//node *temp = root;
	if((*temp1) != tnil){
		printf("%d %s\n",(*temp1)->key,(*temp1)->colour);
		preorder(&((*temp1)->left));
		preorder(&((*temp1)->right));
	}
}

void postorder(node **temp1){
	//node *temp = root;
	if((*temp1) != NULL){
		postorder(&((*temp1)->left));
		postorder(&((*temp1)->right));
		printf("%d %s\n",(*temp1)->key,(*temp1)->colour);
	}
}

node *min(node **root){
	node *temp2 = (*root);
	while(temp2->left != NULL){
		temp2 = temp2->left;
	}
	return temp2;
}

/*node *successor(node *temp){
	node *x;
	if(temp->right != NULL){
		return min(temp->right);
	}
	x = temp->parent;
	while(x != NULL && temp == x->right){
		temp = x;
		x = x->parent;
	}
	return x;
}*/
void transplant(node * u,node * v){
	if(u->parent == tnil) root=v;
	else if(u==u->parent->left) u->parent->left=v;
	else u->parent->right=v;
	v->parent=u->parent;
}
/*void delete_fixup(node *x){
	while (x != root && x->colour == 'b'){
		node *w = NULL;
		if((x->parent->left != NULL) && (x == x->parent->left)){
			w = x->parent->right;
			if ((w != NULL) && (w->colour == 'r')){
				w->colour = 'b';
				x->parent->colour = 'r';
				left_rotate(x->parent);
				w = x->parent->right;
			}
			if((w!=NULL) && (w->right!=NULL) && (w->left!=NULL) && (w->left->colour == 'b') && (w->right->colour == 'b')){
				w->colour = 'r';
				x = x->parent;
			}
			else if((w!=NULL) && (w->right->colour == 'b')){
				w->left->colour = 'b';
				w->colour = 'r';
				right_rotate(w);
				w = x->parent->right;
			}
			if(w!=NULL){
				w->colour = x->parent->colour;
				x->parent->colour = 'b';
				w->right->colour = 'b';
				left_rotate(x->parent);
				x = root;
			}
		}
		else if(x->parent!=NULL){
			w = x->parent->left;
			if ((w!=NULL) && (w->colour == 'r')){
				w->colour = 'b';
				x->parent->colour = 'r';
				left_rotate(x->parent);
				if(x->parent!=NULL){
					w = x->parent->left;
				}
			}
			if((w!=NULL) && (w->right!=NULL) && (w->left!=NULL) && (w->right->colour == 'b') && (w->left->colour == 'b')){
				x = x->parent;
			}
			else if((w!=NULL) && (w->right!=NULL) && (w->left!=NULL) && (w->left->colour == 'b')){
				w->right->colour = 'b';
				w->colour = 'r';
				right_rotate(w);
				w = x->parent->left;
			}
			if(x->parent!=NULL){
				w->colour = x->parent->colour;
				x->parent->colour = 'b';
			}
			if(w->left!=NULL){
				w->left->colour = 'b';
			}
			if(x->parent !=NULL){
				left_rotate(x->parent);
			}
			x = root;
		}
	} 
	x->colour = 'b';

}
*/
void delete_fixup(node ** root,node * x){
	while(x != (*root) && strcmp(x->colour,"BLACK")==0)
	{
		if(x==x->parent->left){
			node * w = x->parent->right;
			if(strcmp(w->colour,"RED")==0){
				strcpy(w->colour,"BLACK");
				strcpy(x->parent->colour,"RED");
				left_rotate(x->parent);
				w=x->parent->right;
			}
			else if(strcmp(w->left->colour,"BLACK")==0 && strcmp(w->right->colour,"BLACK")==0){
				strcpy(w->colour,"RED");
				x=x->parent;
			}
			else if(strcmp(w->right->colour,"BLACK")==0){
				strcpy(w->left->colour,"BLACK");
				strcpy(w->colour,"RED");
				right_rotate(w);
				w=x->parent->right;
				strcpy(w->colour,x->parent->colour);
				strcpy(x->parent->colour,"BLACK");
				strcpy(w->right->colour,"BLACK");
				left_rotate(x->parent);
				x=(*root);
			}
		}
		else{
			node * w = x->parent->left;
			if(strcmp(w->colour,"RED")==0){
				strcpy(w->colour,"BLACK");
				strcpy(x->parent->colour,"RED");
				right_rotate(x->parent);
				w=x->parent->left;
			}
			else if(strcmp(w->right->colour,"BLACK")==0 && strcmp(w->left->colour,"BLACK")==0){
				strcpy(w->colour,"RED");
				x=x->parent;
			}
			else if(strcmp(w->left->colour,"BLACK")==0){
				strcpy(w->right->colour,"BLACK");
				strcpy(w->colour,"RED");
				left_rotate(w);
				w=x->parent->left;
				strcpy(w->colour,x->parent->colour);
				strcpy(x->parent->colour,"BLACK");
				strcpy(w->left->colour,"BLACK");
				right_rotate(x->parent);
				x=(*root);
			}
		}
	}
	strcpy(x->colour,"BLACK");
}

void delete_rb(node ** root,int val){
	node *x,*y,*temp;
	node * z=search(root,val);
	y=z;
	char y_original_colour[6];
	strcpy(y_original_colour,y->colour);
	if(z->left == tnil){
		x=z->right;
		transplant(z,z->right);
	}
	else if(z->right==tnil){
		x=z->left;
		transplant(z,z->left);
	}
	else{
		y=min(&(z->right));
		strcpy(y_original_colour,y->colour);
		x=y->right;
		if(y->parent==z)x->parent=y;
		else{
			transplant(y,y->right);
			y->right=z->right;
			y->right->parent=y;
		}
		transplant(z,y);
		y->left=z->left;
		y->left->parent=y;
		strcpy(y->colour,z->colour);
	}
	if(strcmp(y_original_colour,"BLACK")==0){
		delete_fixup(&(*root),x);
	}
}

/*node* delete_rb(int val){
	node *x = NULL;
	node *y = NULL;
	node *z;
	z = root;
	if((z->left == NULL ) && (z->right == NULL) && (z->key == val)){
		root = NULL;
		return;
	}
	while(z->key != val && z!=NULL){
		if(val < z->key){
			z=z->left;
		}
		else{
			z=z->right;
		}
		if(z == NULL){
			return;
		}
	}
	if((z->left==NULL)||(z->right==NULL)){
		y = z;
	}
	else{
		y = successor(z);
	}
	if(y->left!=NULL){
		x = y->left;
	}
	else{
		if(y->right !=NULL){
			x = y->right;
		}
	}
	if((x!=NULL) && (y->parent !=NULL)){
		x->parent = y->parent;
	}
	if((y !=NULL) && (x!=NULL) && (y->parent==NULL)){
		root = x;
	}
	else if (y == y->parent->left){
		y->parent->left = x;
	}
	else{
		y->parent->right = x;
	}
	if (y != z){
		z->key = y->key;
	}
	if((y!=NULL) && (x!=NULL) && (y->colour == 'b')){
		delete_fixup(x);
	}
	return y;

}*/

int main(){
	/*int T;
	scanf("%d",&T);
	while(T--){*/
		//node *rootnode = NULL;
		//node *x,*y,*temp=NULL,*root=NULL;
		int q;
		scanf("%d",&q);
		create(-1);
		tnil = (node*)malloc(sizeof(tnil))
		tnil = temp;
		root = tnil;
		strcpy(tnil->colour,"BLACK");
		while(q--){
			char str[10];
			scanf("%s",str);
			if(strcmp(str,"insert")==0){
				int val;
				scanf("%d",&val);
				insert(val);
			}
			else if(strcmp(str,"delete")==0){
				int val;
				scanf("%d",&val);
				delete_rb(&root,val);
			}
			else if(strcmp(str,"search")==0){
				int val;
				scanf("%d",&val);
				search(&root,val);
			}
			else if(strcmp(str,"min")==0){
				min(&root);
			}
			else if(strcmp(str,"inorder")==0){
				inorder(&root);
			}
			else if(strcmp(str,"preorder")==0){
				preorder(&root);
			}
			else if(strcmp(str,"postorder")==0){
				postorder(&root);
			}
		}
	return 0;
}