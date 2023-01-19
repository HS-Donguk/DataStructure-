#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
	struct TreeNode *left_child;
	int data;
	struct TreeNode *right_child;
} TreeNode;
// 	  node1
// 	 /   |
//    node2 node3	
int main (void)
{
	TreeNode *node1, *node2, *node3;

	node1 = (TreeNode*)malloc(sizeof(TreeNode));
	node2 = (TreeNode*)malloc(sizeof(TreeNode));
	node3 = (TreeNode*)malloc(sizeof(TreeNode));

	node1 -> data = 10;	// 첫 번째 노드 설정
	node1 -> left_child = node2;
	node1 -> right_child = node3;

	node2 -> data = 20;	// 두 번째 노드 설정
	node2 -> left_child = NULL;
	node2 -> right_child = NULL;

	node3 -> data = 30;	// 세 번째 노드 설정
	node3 -> left_child = NULL;
	node3 -> right_child = NULL;

	free(node1); free(node2); free(node3);

	return 0;
}
