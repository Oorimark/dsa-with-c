#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node * next;
};
struct node * front = NULL;
struct node * rare = NULL;

void enqueue(int x){
	struct node * new_node = (struct node *) malloc(sizeof(struct node));
	new_node -> value = x;
	new_node -> next = NULL;
	if (rare == NULL){
		front = rare = new_node;
		rare -> next = front;
	} else {
		rare -> next = new_node;
		rare = new_node;
		rare -> next = front;
	}
}

void display(){
	struct node * temp;
	do {
		temp = front -> next;
		printf("Value -> %d \n", front -> value);
		front = temp;
	} while ( front != rare );
}

void dequeue(void){
	struct node * temp;
	temp = front;

	if (front == NULL){
		printf("Queue is empty");
	} else if (front == rare){
		front = rare = NULL;
		free(temp);
	} else {
		front = front -> next;
		rare -> next = front;
		free(temp);
	}
}

void peek(void){
	printf("Front --> %d, Rare --> %d", front -> value, rare -> value);

}

void main(void){
	enqueue(3);
	enqueue(7);
	enqueue(2);
	enqueue(9);
	enqueue(10);
	enqueue(22);
	dequeue();
	dequeue();
	enqueue(13);
	display();
	peek();
}
