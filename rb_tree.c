#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	int data;
  char color[6];
  struct node * left;
  struct node * right;
  struct node * parent;
};
typedef struct node NODE;
NODE *x,*y,*root,*temp,*tail,*temp2,*nil;

void create(int value){
  temp=(NODE *)malloc(sizeof(NODE));
  temp->left=NULL;
  temp->right=NULL;
  temp->parent=NULL;
  temp->data=value;
}

void left_rotate(NODE * x){
  y=x->right;
  x->right=y->left;
  if(y->left != nil) y->left->parent=x;
  y->parent=x->parent;
  if(x->parent == nil) root=y;
  else if(x==x->parent->left) x->parent->left=y;
  else x->parent->right=y;
  y->left=x;
  x->parent=y;
}

void right_rotate(NODE * y){
  x=y->left;
  y->left=x->right;
  if(x->right != nil) x->right->parent=y;
  x->parent=y->parent;
  if(y->parent == nil) root=x;
  else if(y==y->parent->right) y->parent->right=x;
  else y->parent->left=x;
  x->right=y;
  y->parent=x;
}

void insert_fixup(NODE * temp){
  while(strcmp(temp->parent->color,"RED")==0){
    if(temp->parent == temp->parent->parent->left){
      y=temp->parent->parent->right;
      if(strcmp(y->color,"RED")==0){
        strcpy(temp->parent->color,"BLACK");
        strcpy(y->color,"BLACK");
        strcpy(temp->parent->parent->color,"RED"); // case 1
        temp=temp->parent->parent;
      }
      else if(temp == temp->parent->right){
        temp=temp->parent;  //case2
        left_rotate(temp);
				strcpy(temp->parent->color,"BLACK");
				strcpy(temp->parent->parent->color,"RED");
				right_rotate(temp->parent->parent);
			}
			else{
				strcpy(temp->parent->color,"BLACK");
				strcpy(temp->parent->parent->color,"RED");
				right_rotate(temp->parent->parent);
			}
    }
    else{
      y=temp->parent->parent->left;
      if(strcmp(y->color,"RED")==0){
        strcpy(temp->parent->color,"BLACK");
        strcpy(y->color,"BLACK");
        strcpy(temp->parent->parent->color,"RED");
        temp=temp->parent->parent;
      }
      else if(temp == temp->parent->left){
        temp=temp->parent;
        right_rotate(temp);
				strcpy(temp->parent->color,"BLACK");
				strcpy(temp->parent->parent->color,"RED");
				left_rotate(temp->parent->parent);
			}
			else{
				strcpy(temp->parent->color,"BLACK");
				strcpy(temp->parent->parent->color,"RED");
				left_rotate(temp->parent->parent);
			}
    }
  }
  strcpy(root->color,"BLACK");
}

void insert(int value){
  y=nil;
  x=root;
  while(x != nil){
    y=x;
    if(value < x->data) x=x->left;
    else x=x->right;
  }
  create(value);
  temp->parent=y;
  if(y==nil){
    root=temp;
  }
  else if(value < y->data){
    y->left=temp;
  }
  else y->right=temp;

  temp->left=nil;
  temp->right=nil;
  strcpy(temp->color,"RED");
  insert_fixup(temp);
}

void inorder_walk(NODE ** root){
  if((*root)!=nil){
    inorder_walk(&((*root)->left));
    printf("%d %s\n",(*root)->data,(*root)->color);
    inorder_walk(&((*root)->right));
  }
}

NODE * min(NODE ** root){
	NODE * current=(*root);
	while(current->left!=nil){
		current=current->left;
	}
	return current;
}

void rb_transplant(NODE * u,NODE * v){
	if(u->parent == nil) root=v;
	else if(u==u->parent->left) u->parent->left=v;
	else u->parent->right=v;
	v->parent=u->parent;
}

NODE * search(NODE ** root,int value){
  if((*root)==nil || (*root)->data==value){
    return *root;
  }
  if(value < (*root)->data){
    return search(&((*root)->left),value);
  }
  else return search(&((*root)->right),value);
}

void rb_delete_fixup(NODE ** root,NODE * x){
	while(x != (*root) && strcmp(x->color,"BLACK")==0)
	{
		if(x==x->parent->left){
			NODE * w = x->parent->right;
			if(strcmp(w->color,"RED")==0){
				strcpy(w->color,"BLACK");
				strcpy(x->parent->color,"RED");
				left_rotate(x->parent);
				w=x->parent->right;
			}
			else if(strcmp(w->left->color,"BLACK")==0 && strcmp(w->right->color,"BLACK")==0){
				strcpy(w->color,"RED");
				x=x->parent;
			}
			else if(strcmp(w->right->color,"BLACK")==0){
				strcpy(w->left->color,"BLACK");
				strcpy(w->color,"RED");
				right_rotate(w);
				w=x->parent->right;
				strcpy(w->color,x->parent->color);
				strcpy(x->parent->color,"BLACK");
				strcpy(w->right->color,"BLACK");
				left_rotate(x->parent);
				x=(*root);
			}
		}
		else{
			NODE * w = x->parent->left;
			if(strcmp(w->color,"RED")==0){
				strcpy(w->color,"BLACK");
				strcpy(x->parent->color,"RED");
				right_rotate(x->parent);
				w=x->parent->left;
			}
			else if(strcmp(w->right->color,"BLACK")==0 && strcmp(w->left->color,"BLACK")==0){
				strcpy(w->color,"RED");
				x=x->parent;
			}
			else if(strcmp(w->left->color,"BLACK")==0){
				strcpy(w->right->color,"BLACK");
				strcpy(w->color,"RED");
				left_rotate(w);
				w=x->parent->left;
				strcpy(w->color,x->parent->color);
				strcpy(x->parent->color,"BLACK");
				strcpy(w->left->color,"BLACK");
				right_rotate(x->parent);
				x=(*root);
			}
		}
	}
	strcpy(x->color,"BLACK");
}

void rb_delete(NODE ** root,int value){
	NODE * z=search(root,value);
	y=z;
	char y_original_color[6];
	strcpy(y_original_color,y->color);
	if(z->left == nil){
		x=z->right;
		rb_transplant(z,z->right);
	}
	else if(z->right==nil){
		x=z->left;
		rb_transplant(z,z->left);
	}
	else{
		y=min(&(z->right));
		strcpy(y_original_color,y->color);
		x=y->right;
		if(y->parent==z)x->parent=y;
		else{
			rb_transplant(y,y->right);
			y->right=z->right;
			y->right->parent=y;
		}
		rb_transplant(z,y);
		y->left=z->left;
		y->left->parent=y;
		strcpy(y->color,z->color);
	}
	if(strcmp(y_original_color,"BLACK")==0){
		rb_delete_fixup(&(*root),x);
	}
}

int main(){
	int n;
	scanf("%d",&n);

	create(-1);
	nil=temp;
	root=nil;
	strcpy(nil->color,"BLACK");

  while(n--){
		char choice[10];
		scanf("%s",choice);
		if(strcmp(choice,"insert")==0){
			int num;
			scanf("%d",&num);
			insert(num);
		}
		else if(strcmp(choice,"delete")==0){
			int num;
			scanf("%d",&num);
			// inorder_walk(&root);
			// printf("\n");
			rb_delete(&root,num);
		}
	}
  inorder_walk(&root);
	return 0;
}