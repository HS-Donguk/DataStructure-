#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node* link;
} node;

struct node* head = NULL;

void insert(struct node*);
void print(struct node*);
void delete(struct node*);

int main(void)
{
	int input_data; 
	struct node* temp = NULL;

	printf("음수 값을 입력하면 프로그램을 종료.\n");
	while(1){
		printf("정수 데이터 입력 : ");
		scanf("%d", &input_data);

		if(input_data < 0)
			break; 
		else{
			temp = (struct node*)malloc(sizeof(struct node));
			temp -> data = input_data;
			temp -> link = NULL;
		}
		insert(temp);
	}	
	// 출력하면서 할당된 메모리 영역을 해제
	printf("\n정렬된 데이터\n");
	print(head);	// 리스트 출력
	printf("데이터가 삭제됩니다.\n");
	delete(head);	// 생성된 메모리 모두 해제

}
void insert(struct node* t)
{
	struct node* pos;
	if(head == NULL)	// 데이터가 하나도 없을 때
		head  = t;
	else if(head -> link == NULL){	// 데이터가 하나만 있을 때
		if(head -> data > t -> data)
			head -> link = t;
		else{
			t -> link = head;
			head = t;
		}
	}
	else{	// 데이터가 두 개 이상일 때
		pos = head;
		while(pos != NULL){
			if(pos == head && pos -> data <= t -> data){	// 맨 앞에 삽입
				t -> link = head;
				head = t;  
				break;
			}
			else if(pos -> link == NULL && pos -> data >= t -> data){  // 맨 끝에 삽입
				pos -> link = t;
				break;
			}
			else if(pos -> data >= t -> data && pos -> link -> data < t -> data){	// 가운데 삽입
				t -> link = pos -> link;
				pos -> link = t;
				break;
			}
			else{
				pos = pos -> link;
			}
		}
	}
}

void print(struct node* h){
	while(h != NULL){
		printf("%d ", h->data);
		h = h -> link;
	}

	printf("\n");
}

void delete(struct node *c){
	struct node *tmp;
	while(c != NULL){
		tmp = c;
		c = c -> link;
		delete(tmp);
	}
}






