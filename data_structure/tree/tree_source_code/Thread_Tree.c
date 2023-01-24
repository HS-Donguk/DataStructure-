#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TRUE 1
#define FALSE 0

/******구조체 선언******/
typedef struct Node{
	char data;
	struct Node *left_child;
	struct Node *right_child;
	int left_thread;
	int right_thread;
}Node;
typedef struct THTR{
	Node *thtr[100];
	int size;
} Thtr;
/**********************/

/******변수 선언******/
Node *head;
Node *pre;
Node *suc;
int sig = 0;

int level = 1;
/*********************/

/******함수 선언******/
Node *init_Tree(void);	// 구조체 변수를 초기화
void In_order_Traverse_Predecessor(Node *thtr, char data);     //원하는 노드의 중위 선행자를 찾아준다
void In_order_Traverse_Successor(Node *thtr, char data);    // 특ㅈㅇ 데이터를 가진 노드의 중위 후행자를 찾아 suc에 저장
void Find_Suc_Pre(Node *thtr, char data);  
void Input_data(Thtr *tr, char data);   // 노드 추가 함수
// 중위 선행자, 중위 후행자 탐색(트리 구성 후 가능) -> 트리의 모든 링크가 연결된 이후 해당 함수를 사용해 원하는 함수의 중위 선행자 또는 중위 후행자를 찾아 반환 받을 수 있다.
Node *InPred(Node *tr);
Node *InSucc(Node *tr);
//트리 출력
void TinOrder(Node *tr);					
/*********************/

int main (void)
{
	head = init_Tree();

	Thtr tr;
	tr.size = 0;

	head -> left_thread = FALSE;
	head -> right_child = head;
	head -> right_thread = FALSE;

	Input_data(&tr, 'a');
	printf("th.thtr[1] -> data = %c\n", tr.thtr[1]->data);

	Input_data(&tr, 'b');
	printf("tr.thtr[2] -> data = %c\n", tr.thtr[2] -> data);
	
	Input_data(&tr, 'c');
	printf("tr.thtr[3] -> data = %c\n", tr.thtr[3]->data);

	Input_data(&tr, 'd');
	printf("tr.thtr[4] -> data = %c\n", tr.thtr[4]->data);

	Input_data(&tr, 'e');
	printf("tr.thtr[5] -> data = %c\n", tr.thtr[5]->data);

	printf("\n\n");

	suc = InSucc(tr.thtr[2]);
	pre = InPred(tr.thtr[2]);

	printf("InSucc: suc = %c\n", suc->data);
	printf("InPred: pre = %c\n", pre->data);

	Find_Suc_Pre(tr.thtr[1], 'b');
	
	printf("Find_Suc_Pre: suc = %c\n", suc->data);
	printf("Find_Suc_Pre: pre = %c\n", pre->data);

	TinOrder(head);

	return 0;
}
Node *init_Tree(void){
	Node *tr = (Node*)malloc(sizeof(Node));

	tr -> data = 0;		// char 데이터는 0을 저장할 때와 '0'과 다르다.(0 == NULL)
	tr -> left_child = NULL;
	tr -> right_child = NULL;
	tr -> left_thread = FALSE;
	tr -> right_thread = FALSE;

	return tr;
}

// 중위 선행자는 '특정 노드의 왼쪽 서브트리 가장 왼쪽에 있다' 를 기억
void In_order_Traverse_Predecessor(Node *thtr, char data){  // 특정 데이터를 가진 노드의 중위 선행자를 찾아 pre에 저장
	if(thtr){
		if(thtr -> left_thread == FALSE){ // 해당 링크가 중위 선행자와 연결되어 있지 않을 때만 실행
			In_order_Traverse_Predecessor(thtr -> left_child, data);
		}

		if(sig == 0 && thtr -> data != data){
			pre = thtr;
		//      printf("ptr = %c\n", pre -> data);	
		}
		else if(sig == 0 && thtr -> data == data){
			sig = 1;
		}
		if(thtr -> right_thread == FALSE){
			In_order_Traverse_Predecessor(thtr -> right_child, data);
		}
	}
}	
void In_order_Traverse_Successor(Node *thtr, char data){
	if(thtr){
		if(thtr -> left_thread == FALSE){
			In_order_Traverse_Successor(thtr -> left_child, data);
		}
		if (sig == 0 && thtr -> data == data){  // 특정 데이터를 가진 노드를 찾으면 sig을 1로 바꾸고, 중위 후행자를 받을 준비
			sig = 1;
		}
		else if (sig == 1){	// sig이 1일 때 suc에 노드를 저장
			suc = thtr;

			sig = 0;
		}

		if (thtr -> right_thread == FALSE){
			In_order_Traverse_Successor(thtr -> right_child, data);
		}
	}
}

void Find_Suc_Pre(Node *thtr, char data){
	pre = NULL;
	suc = NULL;

	sig = 0;
	In_order_Traverse_Predecessor(thtr, data);

	sig = 0;
	In_order_Traverse_Successor(thtr, data);

	if (pre == 0){		// 트리의 가장 왼쪽 노드와 가장 오른쪽 노드는 각각 pre와 suc가 없다.
		pre = head;    // 이 때 각각은 head를 가리켜야 한다.
	}

	else if (suc == 0){
		suc = head;
	}
}


void Input_data(Thtr *tr, char data){
	tr -> size++;	// 구조체 배열을 사용하기 때문에 size를 1씩 증가
	int n = tr -> size;

	tr -> thtr[n] = init_Tree();  // 데이터를 새로 저장할 노드에 malloc으로 메모리 할당
	Node *cur = tr -> thtr[n];				     
	
	if (n == 1){
		cur -> data = data;
		cur -> left_child = head;
		cur -> left_thread = TRUE;
		cur -> right_child = head; 
		cur -> right_thread = TRUE;

		level++;  // 루트노드가 level = 1
		head -> left_child = cur;   // head노드의 왼쪽 링크는 항상 root 노드를 가리킨다
	}
	else{
		Node *tmp = tr -> thtr[n/2];   // 항상 i번 째 노드의 부모 노드는 i/2
					       // 항상 i번 째 자식 노드는 2*i(left child), 2*i+1(right child)
					       // n/2는 항상 내림된다(n/2가 1.5라면 1 반환
					       
		if(n % 2 == 0){	// n이 짝수일 땐 부모 노드의 오른쪽에 새로운 노드 형성 
			tmp -> left_child = cur;
			tmp -> left_thread = FALSE;
		}			
		else if(n % 2 != 0){
			tmp -> right_child = cur;
			tmp -> right_thread = FALSE; 
		}

		cur -> data = data;

		Find_Suc_Pre(tr->thtr[1], data);

		cur -> left_child = pre;    // 새로운 노드의 자식 노드는 없기 때문에 링크에 중위 선행자와 후행자를 저장
		cur -> left_thread = TRUE;
		cur -> right_child = suc;
		cur -> right_thread = TRUE;

		if(n == pow(2, level) - 1){ // 2의 제곱승의 -1번 째 노드가 각 레벨의 마지막 노드이다
			level ++;
		}
	}
}

Node *InPred(Node *tr){
	Node *tmp = tr -> left_child;

	if(tr -> left_thread == FALSE){
		while(tmp -> right_thread == FALSE)
			tmp = tmp ->right_child;
	}

	return tmp;
}

Node *InSucc(Node *tr){
	Node *tmp = tr -> right_child;

	if (tr -> right_thread == FALSE){
		while(tmp -> left_thread == FALSE){
			tmp = tmp -> left_child;
		}
	}

	return tmp;
}
void TinOrder(Node *tr){
	Node *tmp = tr;
	
	printf("INORDER : ");
	while(1){
		tmp = InSucc(tmp);
		if(tmp == tr)
			break;
		printf("%c ->", tmp -> data);
	}
	printf("\n");
}





