#include <stdio.h>
#include <stdlib.h> 

typedef struct node{
	struct node *left;
	int data;
	struct node *right;
}node;

node *createnode(int);
int count_nodes(node *);

/*Travelsal Function*/
void preorder(node *);
void inorder(node *);
void postorder(node *);

/*Print tree*/
void print_tree(node *);

int main (void)
{
	struct node *newnode = createnode(25);
    	newnode->left = createnode(27);
    	newnode->right = createnode(19);
    	newnode->left->left = createnode(17);
    	newnode->left->right = createnode(91);
    	newnode->right->left = createnode(13);
    	newnode->right->right = createnode(55);
    /* Sample Tree 1:
     *                25
     *             /    \
     *            27     19
     *           / \     / \
     *         17  91   13 55
     */
	print_tree(newnode);
    	printf("\nNumber of nodes in tree 1 = %d ",count_nodes(newnode));
    	printf("\n");
	
	return 0;
}

node *createnode(int data){
	node *newnode = (node*)malloc(sizeof(newnode));
	newnode -> data = data; 
	newnode -> left = NULL;
	newnode -> right = NULL;

	return (newnode);
}
int count_nodes(node *cnt_node){
	int count = 0;
	if(cnt_node != NULL){
		/*count = 1(root node count) + left subtree count + right subtree count */
		count = 1 + count_nodes(cnt_node -> left) + count_nodes(cnt_node -> right);
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














