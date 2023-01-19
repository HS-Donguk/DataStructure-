#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node* get_NewNode(int);
node* generate_BinaryTree();
node* clone_BinaryTree(node*);
void preorder(node *);
void inorder(node *);
void postorder(node *);


int main(void){
	node *clone; 
	node *root = generate_BinaryTree();

	printf("Original Tree\n");
	printf("PREORDER -> ");
	preorder(root);
	printf("\n=====================================================\n");
	printf("INORDER -> ");
	inorder(root);
	printf("\n=====================================================\n");
	printf("POSTORDER -> ");
	postorder(root);
	printf("\n=====================================================\n");
	
	clone = clone_BinaryTree(root);
	printf("\nClnoe Tree\n");
	printf("PREORDER -> ");
	preorder(clone);
	printf("\n=====================================================\n");
	printf("INORDER -> ");
	inorder(clone);
	printf("\n=====================================================\n");
	printf("POSTORDER -> ");
	postorder(clone);
	printf("\n=====================================================\n");

}
/*
구현할 트리 모형
            13
           / \
         31    42
        / \   /  \
       4  50  10  -7
      / \
     18  9
*/


node* get_NewNode(int data){
	/*새로운 노드를 위한 동적할당*/
	node *newNode = (node*)malloc(sizeof(node));
	/*새로운 노드에 데이터 저장*/
	newNode -> data = data;
	newNode -> left = NULL;
	newNode -> right = NULL;
}

node* generate_BinaryTree(){
	// Root Node
	node *root = get_NewNode(13);
	node *first_root = root;	// 루트노드에서 오른쪽 서브트리로 가기위한 초기화
		
	root -> left = get_NewNode(31);
	root -> right = get_NewNode(42);

	root = root -> left;
	root -> left = get_NewNode(4);
	root -> right = get_NewNode(50);

	root = root -> left;
	root -> left = get_NewNode(18);
	root -> right = get_NewNode(9);
	
	root = first_root;
	root -> right = get_NewNode(42);

	root = root -> right;
	root -> left = get_NewNode(10);
	root -> right = get_NewNode(-7);

	return first_root;
}

node* clone_BinaryTree(node *first_root){
	if(first_root == NULL)
		return NULL;
	/* 복사를 위한 노드 생성후 루트노드의 데이터값 저장 */
	node *newNode = get_NewNode(first_root -> data);
	/*재귀적으로 왼쪽 서브트리와 오른쪽 서브트리를 복사*/
	newNode -> left = clone_BinaryTree(first_root -> left); 
	newNode -> right = clone_BinaryTree(first_root -> right); 
	/*복사된 트리를 반환*/
	return newNode;
}

void preorder(node * node){		// 전위 순회 함수
	if(node != NULL){
		printf("[%d] ", node -> data);	// 노드 데이터 출력
		preorder(node -> left);	// 왼쪽 서브트리 순회
		preorder(node -> right);	// 오른쪽 서브트리 순회
	}
}
void inorder(node * node){		// 중위 순회 함수
	if(node != NULL){
		inorder(node -> left);	// 왼쪽 서브트리 순회
		printf("[%d] ", node -> data);	// 노드 데이터 출력
		inorder(node -> right);	// 오른쪽 서브트리 순회
	}
}
void postorder(node * node){	// 후위 순회 함수
	if(node != NULL){
		postorder(node -> left);	// 왼쪽 서브트리 순회
		postorder(node -> right);	  // 오른쪽 서브트리 순회
		printf("[%d] ", node -> data);	// 노드 데이터 출력
	}
}

