#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left and a pointer to right.*/
typedef struct node{
	struct node * left;
	int data;
	struct node * right;
} node;

node *create_node(int); 
unsigned int getLeafCount(node*);

/*Travelsal Function*/
void preorder(node *);
void inorder(node *);
void postorder(node *);

/*Print tree*/
void print_tree(node *);

int main (void)
{
	node *root = create_node(10);
	root -> left = create_node(20);
	root -> right = create_node(30);
	root -> left -> left = create_node(40);
	root -> left -> right = create_node(50);
	/*sample:
	 		10
		      /    \
		    20      30
		   /   \
	         40    50
	 */
	print_tree(root);

	/*get leaf count*/
	printf("Leaf count of the tree : %d\n", getLeafCount(root));

	return 0;
}

/*allocates a new node with the given data and NULL left and right pointers*/
node *create_node(int data){
	node *newnode = (node*)malloc(sizeof(node));
	newnode -> data = data;
	newnode -> left = NULL;
	newnode -> right = NULL;

	return (newnode);
}

/*Function to get the count of leaf nodes*/
unsigned int getLeafCount(node *node){
	int count = 0;
	if(node -> left == NULL && node -> right == NULL){
		return 1;
	}
	else{
		count = getLeafCount(node -> left) + getLeafCount(node -> right); 
	}

	return count;
}

void preorder(node *node){
        if(node != NULL){
                printf("[%d] ", node -> data);
                preorder(node -> left);
                preorder(node -> right);
        }
}

void inorder(node *node){
        if(node != NULL){
                inorder(node -> left);
                printf("[%d] ", node -> data);
                inorder(node -> right);
        }
}

void postorder(node *node){
        if(node != NULL){
                postorder(node -> left);
                postorder(node -> right);
                printf("[%d] ", node -> data);
        }
}

void print_tree(node *node){
        printf("Tree Print \n");
        printf("PREORDER -> ");
        preorder(node);
        printf("\n=====================================================\n");
        printf("INORDER -> ");
        inorder(node);
        printf("\n=====================================================\n");
        printf("POSTORDER -> ");
        postorder(node);
        printf("\n=====================================================\n");
}


