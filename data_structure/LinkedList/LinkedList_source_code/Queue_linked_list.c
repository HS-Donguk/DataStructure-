// Linked List를 이용한 Queue 구현

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
} node;

node* head = NULL;
node* tail = NULL;
node* temp = NULL;
void insert(int);
void delete(); 
void print_queue();
void release();
int main()
{
	int x, d; 
	do{
		printf("Queue---1, 삽입, 2. 삭제, 3. 출력, 4. 끝 \nInput : ");
		scanf("%d", &x);
		switch(x){
			case 1:
				printf("\n 데이터 입력: ");
				scanf("%d", &d);
				insert(d);
				break;
			case 2:
				delete();
				break;
			case 3: 
				print_queue();
				break;
			case 4:
				release();
				return 0;
		}
		printf("\n\n");
	} while(1);
}

void insert(int x){
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = x;
	temp -> next = NULL;
	if (tail != NULL)
		tail -> next = temp;
	tail = temp;	// 새로 입력된 temp는 무조건 tail
	if (head == NULL){  // temp를 삽입할 때 Queue가 Empty이면
		head = temp;
	}

	printf("\n%d가 삽입되었습니다.\n", temp->data);
	print_queue();
	return;
}

void delete(){
	int x;
	if (head == NULL){
		printf("\nQueue is Empty!!!\n");
		return;
	}
	temp = head;	// Queue에서 data를 꺼낼 땐 무조건 head에서 꺼낸다는 의미
	head = head -> next;	// head의 다음 node로 이동
	if(!head)  // head의 위치를 다음 node로 옮겼는데 NULL -> Queue에 node가 head에 있던 data 한 개 였던것.
		tail = NULL;
	x = temp -> data;
	free(temp);
	printf("%d가 삭제되었습니다.\n", x);
	print_queue();

	return;
}

void print_queue(){
	if(head == NULL){
		printf("Queue is Empty!\n");
		return;
	}
	temp = head;
	printf("현재 큐의 내용(Head~Tail) : ");
	while(temp){
		printf("%d ", temp -> data);
		temp = temp -> next;
	}

	return ;
}

void release(){
	while(head){
		temp = head;
		head = head -> next;
		free(temp);
	}
}
