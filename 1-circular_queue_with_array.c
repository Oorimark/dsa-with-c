#include <stdio.h>
#define QUEUE_SIZE 7
int queue[QUEUE_SIZE];
int front = -1, rare = -1;

int isFull(){
	printf("front %d, rare %d \n", front, rare);
	if ((rare + 1) % QUEUE_SIZE == front){
		return (1);
	}; return (0);
}
void enqueue(int x){
	if (front == -1 && rare == -1){
		front = 0;
		rare = 0;
		queue[rare] = x;
	}
	else if (isFull()){
		printf("The queue is full \n");
	}
	else {
		rare = (rare + 1) % QUEUE_SIZE;
		queue[rare] = x;
	}
}

void dequeue(void){
	if (front == -1 && rare == -1){
		printf("The queue is empty \n");
	}
	else{
		printf("Dequeud %d \n", queue[front]);
		front = (front + 1) % QUEUE_SIZE;
	}
}

void peek(void){
	// peek at the front and rare values
	printf("Front --> %d, Rare --> %d", front, rare);
}

void display(void){
	int i = front;
	while (i != rare){
		printf("%d --> %d \n", i, queue[i]);
		i = (i + 1) % QUEUE_SIZE;
	}
	printf("%d --> %d \n", i, queue[i]);
}

void main(void){
	enqueue(5);
	enqueue(2);
	enqueue(1);
	enqueue(20);
	enqueue(21);
	enqueue(19);
	dequeue();
	dequeue();
	enqueue(12);
	enqueue(15);
	enqueue(5);
	enqueue(35);
	display();
	peek();
}	
