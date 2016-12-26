/*include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int key;
	node *left,*right;

}*parent,*root;

struct node *newnode(int val){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->key = val;
	temp->left = temp->right = NULL;
	return temp;
}


void insert_node(node *tree,int z){
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

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *leftChildNode;
    struct TreeNode *rightChildNode;
};

typedef struct TreeNode node;
node *rootNode = NULL;

void insertNode(int i, node *n) {
    if(n == NULL) {
        n = (node*)malloc(sizeof(node));
        n->leftChildNode = NULL;
        n->rightChildNode = NULL;
        n->data = i;
    }
    else 
    if(n->data == i)
        printf("\nThis value already exists in the tree!");
    else
    if(i > n->data)
        insertNode(i, n->rightChildNode);
    else
        insertNode(i, n->leftChildNode);
    }

void searchNode(int i, node *n) {
    if(n == NULL)
        printf("\nValue does not exist in tree!");
    else
    if(n->data == i)
        printf("\nValue found!");
    else
    if(i > n->data)
        searchNode(i, n->rightChildNode);
    else
        searchNode(i, n->leftChildNode);
    }

void deleteNode(int i, node *n) {
    if(n == NULL)
        printf("\nValue does not exist in tree!");
    else
    if(n->data == i) {
        if(n->leftChildNode == NULL)
            n = n->rightChildNode;
        else
        if(n->rightChildNode == NULL)
            n = n->leftChildNode;
        else {
            node *temp = n->rightChildNode;
            while(temp->leftChildNode != NULL)
                temp = temp->leftChildNode;
            n = temp;
        }
    }
    else
    if(i > n->data)
        deleteNode(i, n->rightChildNode);
    else
        deleteNode(i, n->leftChildNode);
    }

void displayPreOrder(node *n) {
    if(n != NULL) {
        printf("%d ", n->data);
        displayPreOrder(n->leftChildNode);
        displayPreOrder(n->rightChildNode);
    }
}

void displayPostOrder(node *n) {
    if(n != NULL) {
        displayPostOrder(n->leftChildNode);
        displayPostOrder(n->rightChildNode);
        printf("%d ", n->data);
    }
}

void displayInOrder(node *n) {
    if(n != NULL) {
        displayInOrder(n->leftChildNode);
        printf("%d ", n->data);
        displayInOrder(n->rightChildNode);
    }
}

int main(void) {
    int ch, num, num1;
    do {
        printf("\nSelect a choice from the menu below.");
        printf("\n1. Insert a node.");
        printf("\n2. Search for a node.");
        printf("\n3. Delete a node.");
        printf("\n4. Display the Binary Search Tree.");
        printf("\nChoice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("\nEnter an element: ");
                    scanf("%d", &num);
                    //printf("YESYES");
                    insertNode(num, rootNode);
                    break;

            case 2: printf("\nEnter the element to be searched for: ");
                    scanf("%d", &num);
                    searchNode(num, rootNode);
                    break;

            case 3: printf("\nEnter the element to be deleted: ");
                    scanf("%d", &num);
                    deleteNode(num, rootNode);
                    break;

            case 4: printf("\nSelect an order for the elements to be display in.");
                    printf("\n1. Pre-order.");
                    printf("\n2. Post-order.");
                    printf("\n3. In-order.");
                    printf("\nChoice: ");
                    scanf("%d", &num1);
                    switch(num1) {
                        case 1: printf("\nPre-order Display: ");
                                displayPreOrder(rootNode);
                                break;

                        case 2: printf("\nPost-order Display: ");
                                displayPostOrder(rootNode);
                                break;

                        case 3: printf("\nIn-order Display: ");
                                displayInOrder(rootNode);
                                break;

                        default: exit(0);
                    }
                    break;

            default: exit(0);
            }
        //printf("%d", rootNode->data);
        printf("\nIf you want to return to the menu, press 1.");
        printf("\nChoice: ");
        scanf("%d", &num);
    } while(num == 1);

    return 0;
}
