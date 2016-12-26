#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 1001
struct node{
	int data;
  char color;
  struct node * left;
  struct node * right;
  struct node * parent;
};
typedef struct node NODE;
NODE *x,*y,*root,*temp,*nil;
void create(int value){
  temp=(NODE *)malloc(sizeof(NODE));
  temp->left=nil;
  temp->right=nil;
  temp->parent=NULL;
  temp->data=value;
}

void left_rotate(NODE * x){
  y=x->right;
  x->right=y->left;
  if(y->left != nil) {
    y->left->parent=x;
  }
  y->parent=x->parent;
  if(x->parent == nil){
   root=y;
 }
  else if(x==x->parent->left){
   x->parent->left=y;
 }
  else{
   x->parent->right=y;
 }
  y->left=x;
  x->parent=y;
}

void right_rotate(NODE * y){
  x=y->left;
  y->left=x->right;
  if(x->right != nil) {
    x->right->parent=y;
  }
  x->parent=y->parent;
  if(y->parent == nil){
   root=x;
 }
  else if(y==y->parent->right){
    y->parent->right=x;
  }
  else{ 
    y->parent->left=x;
  }
  x->right=y;
  y->parent=x;
}

void insert_fixup(NODE * temp){
  while(temp->parent->color == 'R'){
    if(temp->parent == temp->parent->parent->left){
      y=temp->parent->parent->right;
      if(y->color == 'R'){
        temp->parent->color = 'B';
        y->color = 'B';
        temp->parent->parent->color = 'R';
        temp=temp->parent->parent;
      }
      else if(temp == temp->parent->right){
        temp=temp->parent;
        left_rotate(temp);
        temp->parent->color = 'B';
        temp->parent->parent->color = 'R';
        right_rotate(temp->parent->parent);
      }
      else{
        temp->parent->color = 'B';
        temp->parent->parent->color = 'R';
        right_rotate(temp->parent->parent);
      }
    }
    else{
      y=temp->parent->parent->left;
      if(y->color == 'R'){
        temp->parent->color = 'B';
        y->color = 'B';
        temp->parent->parent->color = 'R';
        temp=temp->parent->parent;
      }
      else if(temp == temp->parent->left){
        temp=temp->parent;
        right_rotate(temp);
        temp->parent->color ='B';
        temp->parent->parent->color ='R';
        left_rotate(temp->parent->parent);
      }
      else{
        temp->parent->color = 'B';
        temp->parent->parent->color = 'R';
        left_rotate(temp->parent->parent);
      }
    }
  }
  root->color = 'B';
}

void insert(int value){
  y=nil;
  x=root;
  while(x != nil){
    y=x;
    if(value < x->data){
     x=x->left;
   }
    else {
      x=x->right;
    }
  }
  create(value);
  temp->parent=y;
  if(y==nil){
    root=temp;
  }
  else if(value < y->data){
    y->left=temp;
  }
  else {
    y->right=temp;
  }
  temp->left=nil;
  temp->right=nil;
  temp->color = 'R';
  insert_fixup(temp);
}
/*void inorder(NODE *root){
  if(root!=NULL){
  inorder(root->left);
  printf("%d %s",root->data,root->color);
  inorder(root->right);
}
}
*/
void enqueue(NODE **queue,NODE *newnode,int *tail){
  queue[*tail] = newnode;
  (*tail)++;
 }
 NODE *dequeue(NODE **queue,int *head){
  (*head)++;
  return queue[*head -1];
  
 }
 NODE **createqueue(int *head,int *tail){
  NODE **queue = (NODE**)malloc(sizeof(NODE*)*MAX_SIZE);
  *head = *tail = 0;
  return queue;
}

void level_order(NODE *root,char colour_node){
    int head,tail;
    NODE ** queue = createqueue(&head,&tail);
    NODE *temp3 = root;
    while(temp3 != nil && temp3 != NULL){
      //printf("hi\n");
      if(temp3->color == colour_node){
        //printf("reached colour\n");
        printf("%d ",temp3->data);
      }
      if(temp3->left != nil){
        enqueue(queue,temp3->left,&tail);
      }
      if(temp3->right != nil){
        enqueue(queue,temp3->right,&tail);
      }
      temp3 = dequeue(queue,&head);
    }
    printf("\n");
}

int main(){
  int Q;
  scanf("%d",&Q);

  create(-1);
  nil=temp;
  nil->color = 'B';
  root=nil;

  while(Q--){
    char query[7];
    scanf("%s",query);
    if(strcmp(query,"INSERT")==0){
      int key;
      scanf("%d",&key);
      insert(key);
    }
    else if(strcmp(query,"PRINT")==0){
      char node_colour;
      getchar();
      scanf("%c",&node_colour);
      level_order(root,node_colour);
    }
  }
  return 0;
}