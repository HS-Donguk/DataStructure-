// Linked List를 이용한 stack구현
//1. 리스트의 구조체 선언
//2. init : 스택의 초기화 함수
//3. is_empty : 스택이 비어있는지 검사하는 함수 
//4. push : 스택에 삽입하는 함수
//5. pop : 스택에서 삭제하는 함수
//6. print_stack : 스택을 출력하는 함수
#include <stdio.h> 
#include <stdlib.h>
typedef struct node{
	int data;
	struct node* link;
} node;
typedef struct stack{
	node* top;	// 스택의 top을 나타내는 pointer 
}stack;

void init(stack *);
int is_empty(stack *);
void push(stack*, int);
int pop(stack *);
void print_stack(stack *);
void release(stack *);

int main(void)
{
	int x, d; 
	stack s;
	do{
		printf("Stack---1. 삽입, 2. 삭제, 3. 출력, 4. 끝 \nInput :  "); 
		scanf("%d", &x);
		switch(x){
			case 1:
				printf("\n 데이터 입력: ");
				scanf("%d", &d);
				push(&s, d);
				break;
			case 2:
				pop(&s);
				break;
			case 3:
				print_stack(&s);
				break;
			case 4: 
				release(&s);
				return 0;
			default:
				break;
		}
	} while(1);
}
void init(stack *s){
	s -> top = NULL;
}

int is_empty(stack *s){
	return s->top == NULL;
}

void push(stack *s, int data){
	node *temp = (node*)malloc(sizeof(node));
	temp -> data = data;
	temp -> link = s -> top;
	s -> top = temp;
}

int pop(stack *s){
	if(is_empty(s)){	// stack이 비어있는지 check
		printf("Stack is Empty\n"); 
	}	
	else{
		node * temp = s -> top;		// temp포인터를 top 노드를 가리키도록 함.
		int data = temp -> data;	// 삭제한 값 반환을 위해 data에 tmep data 삽입
		s -> top = s -> top -> link;	// top노드는 기존의 top노드가 가키키는 노드가 됨
		free(temp);
		return data;
	}
}

void print_stack(stack *s){
	node *p = s -> top;
	while(p != NULL){
		printf("%d -> ", p -> data);
		p = p -> link;
	}
	printf("NULL \n\n");
}

void release(stack *s){
	node *tmp;
	while(tmp){
		tmp = s -> top;
		s -> top = s -> top -> link;
		free(tmp);	
	}
}







