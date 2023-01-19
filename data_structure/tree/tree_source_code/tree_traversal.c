#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
	
typedef struct TreeNode{	// 노드에 대한 구조체 정의
	int data;
	struct TreeNode *left_child;
	struct TreeNode *right_child;
}TreeNode;

void preorder(TreeNode *);
void inorder(TreeNode *);
void postorder(TreeNode *);

//		15
//	  4	     20
//	1   3	    16  25

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {3, NULL, NULL};
TreeNode n3 = {4, &n1, &n2};
TreeNode n4 = {16, NULL, NULL};
TreeNode n5 = {25, NULL, NULL};
TreeNode n6 = {20, &n4, &n5};
TreeNode n7 = {15, &n3, &n6};
TreeNode *root = &n7;

int main (void)
{
	printf("PREORDER -> ");
	preorder(root);
	printf("\n=====================================================\n");
	printf("INORDER -> ");
	inorder(root);
	printf("\n=====================================================\n");
	printf("POSTORDER -> ");
	postorder(root);
	printf("\n=====================================================\n");

	return 0;

}

void preorder(TreeNode * node){		// 전위 순회 함수
	if(node != NULL){
		printf("[%d] ", node -> data);	// 노드 데이터 출력
		preorder(node -> left_child);	// 왼쪽 서브트리 순회
		preorder(node -> right_child);	// 오른쪽 서브트리 순회
	}
}
void inorder(TreeNode * node){		// 중위 순회 함수
	if(node != NULL){
		inorder(node -> left_child);	// 왼쪽 서브트리 순회
		printf("[%d] ", node -> data);	// 노드 데이터 출력
		inorder(node -> right_child);	// 오른쪽 서브트리 순회
	}
}
void postorder(TreeNode * node){	// 후위 순회 함수
	if(node != NULL){
		postorder(node -> left_child);	// 왼쪽 서브트리 순회
		postorder(node -> right_child);	  // 오른쪽 서브트리 순회
		printf("[%d] ", node -> data);	// 노드 데이터 출력
	}
}


