// 원형 연결 리스트
// 마지막 노드의 link가 NULL이 아닌 첫 번째 노드 주소가 되는 리스트
// 장점 1. 하나의 노드에서 다른 모든 노드로의 접근이 가능 (기존 단순 연결 리스트는 헤드 처음부터 마지막까지 거쳐야 함)


#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
}ListNode;

void insert_first(element);
void insert_last(element);
void print_list(void);
//void delete_node(element);

ListNode * head = NULL;

int main(void)
{
	//ListNode * head = NULL;
	int x, d;

	do{
		printf("Circular---1. 맨 앞 삽입, 2.마지막 삽입, 3. 출력, 4. 노드 삭제 \nInput : ");
		scanf("%d", &x); 
		switch(x){
			case 1:
				printf(" 데이터 입력 : "); 
				scanf("%d", &d);
				insert_first(d);
				printf("\n");
				break;
			case 2:
				printf(" 데이터 입력 : ");
				scanf("%d", &d);
				insert_last(d);
				printf("\n");
				break;
			case 3:
				print_list();
				break;
			/*case 4:
				printf(" 삭제할 데이터 : "); 
				scanf("%d", &d);
				delete(d);
				printf("\n"); 
				break;*/
			default:
				return;

		}

	}while(1);

	return 0;

}
// 원형 연결 리스트 처음에 삽입하는 함수 
void insert_first(element data){
	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
	node -> data = data;
	if(head == NULL){	// head가 비어있을 때
		head = node;
		node -> link = head;
	}
	else{
		node -> link = head -> link;
		head -> link = node;
	}
}
// 원형 연결 리스트 마지막에 삽입하는 함수
// 원형 연결 리스트는 시작과 끝이 불분명
void insert_last(element data){
	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
	node -> data = data;
	if (head == NULL){
		head = node;
		node -> link = head;
	}
	else{
		node -> link = head -> link;
		head -> link = node;
		head = node;	
	}
}
void print_list(){
	ListNode * p;
	if (head == NULL)
		return;		// 리스트가 비어있으면 노드가 없으므로
	p = head -> link;
	do{
		printf("%d -> ", p -> data);
		p = p -> link;
	} while(p != head);

	printf("%d -> \n\n", p -> data);	// 마지막 노드의 데이터 출력
}


