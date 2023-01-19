/*
first :
   	1 
      /	   \
     2      4
    / \    / \	    
   3   5   6  7
 
 second :
           1
         /    \
        2      4
       / \    / \
     7   5    6  3
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef struct TreeNode{
	struct TreeNode *left;
	int data;
	struct TreeNode *right;
}TreeNode;

TreeNode *newnode(int);
int identical_Trees(TreeNode*, TreeNode*);
void print_tree(TreeNode*, TreeNode*);
void preorder(TreeNode *);
void inorder(TreeNode *);
void postorder(TreeNode *);
int main (void)
{
	TreeNode *root1 = newnode(1);
	TreeNode *root2 = newnode(1);
	
	root1 -> left = newnode(2);
	root2 -> left = newnode(2);

	root1 -> left -> left = newnode(3);
	root2 -> left -> left = newnode(7);

	root1 -> left -> right = newnode(5);
	root2 -> left -> right = newnode(5);

	root1 -> right = newnode(4);
	root2 -> right = newnode(4);

	root1 -> right -> left = newnode(6);
	root2 -> right -> left = newnode(6);

	root1 -> right -> right = newnode(7);
	root2 -> right -> right = newnode(3);
	
	print_tree(root1, root2);

	if (identical_Trees(root1, root2))
		printf("\nBoth tree is identical\n");
	else
		printf("\nTrees are not identical\n");

	return 0;
}
TreeNode *newnode(int data){
	TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
	node -> data = data;
	node -> left = NULL;
	node -> right = NULL;

	return (node);
}
int identical_Trees(TreeNode *first, TreeNode *second){
	return ((first == NULL && second == NULL) ||
		((first != NULL && second == NULL) &&
		 (first -> data == second -> data))) &&
		(identical_Trees(first -> left, second -> left) &&
		identical_Trees(first -> right, second -> right));

}
void preorder(TreeNode *node){
	if(node != NULL){
		printf("[%d] ", node -> data);
		preorder(node -> left);
		preorder(node -> right);
	}
}
void inorder(TreeNode *node){
	if(node != NULL){
		inorder(node -> left);
		printf("[%d] ", node -> data);
		inorder(node -> right);
	}
}
void postorder(TreeNode *node){
	if(node != NULL){
		postorder(node -> left);
		postorder(node -> right);
		printf("[%d] ", node -> data);
	}
}
void print_tree(TreeNode *first, TreeNode *second){
	printf("First Tree \n");
	printf("PREORDER -> ");
        preorder(first);
        printf("\n=====================================================\n");
        printf("INORDER -> ");
        inorder(first);
        printf("\n=====================================================\n");
        printf("POSTORDER -> ");
        postorder(first);
        printf("\n=====================================================\n");

	
	printf("\nSecond Tree\n");
        printf("PREORDER -> ");
        preorder(second);
        printf("\n=====================================================\n");
        printf("INORDEER -> ");
        inorder(second);
        printf("\n=====================================================\n");
        printf("POSTORDER -> ");
        postorder(second);
        printf("\n=====================================================\n");

}
