#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node *left_link;
	int data;
	struct node *right_link;
}node; 

node * head = NULL;
node * tail = NULL;

void insert(node*);
void print_forward();
void print_backward();
void release();

int main (void)
{
	int x;
	node *head = NULL, *tail = NULL, *temp = NULL, *current = NULL;

	printf("음수 값을 입력하면 프로그램 종료.\n");
	while(1){
		printf("Integer Data Input : ");
		scanf("%d", &x);
		if(x < 0)
			break;
		else{
			temp = (node*)malloc(sizeof(node));
			temp -> data = x;
			temp -> left_link = NULL;
			temp -> right_link = NULL;
		}
		insert(temp);
	}
	print_forward();	// 내림차순 출력
	print_backward();	// 오름차순 출력
	release();		// 할당된 메모리 해제 
	printf("\n");
}

void insert(node *t){
	node* current;
	if(head == NULL)	// 데이터 존재하지 않을 때
		head = t, tail = t;
	else{	// 데이터가 한 개 이상일 때
		current = head;
		while(current){
			if(current -> left_link == NULL && current -> data <= t-> data){	// 새로 들어온 t를 맨 앞에 삽입
				head -> left_link = t;
				t -> right_link = head;
				head = t; 
				break;
			}
			else if(current -> right_link == NULL && current -> data >= t -> data){	// 새로 들어온 t를 맨 뒤에 삽입
				current -> right_link = t;
				t -> left_link = current;
				tail = t;
				break;
			}
			else if(current -> data >= t -> data && current -> right_link -> data< t -> data){	// 새로 들어온 t를 가운데 삽입
				t -> right_link = current -> right_link;
				current -> right_link -> left_link = t;
				current -> right_link = t;
				t -> left_link = current;
				break;
			}
			else	// 다음 노드를 찾음
				current = current -> left_link;
		}
	}
}

void print_forward(){	// 오름차순 출력
	node* current = head;
	printf("\n\n sorted data by increasing\n");
	while(current){
		printf("%d ", current -> data);
		current = current -> right_link;
	}
}

void print_backward(){		// 내림차순 출력
	node* current = tail;
	printf("\n\n sorted data by decreasing\n");
	while(current){
		printf("%d ", current -> data);
		current = current -> left_link;
	}
}

void release(void){
	node* current;
	while(head){
		current = head;
		head = current -> right_link;
		free(current);
	}
}




















