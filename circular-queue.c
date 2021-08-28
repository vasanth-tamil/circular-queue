#include <stdio.h>
#include <string.h>

#define SIZE 5
#define TRUE 1
#define FALSE 0

/*
	(init) front = rear = NULL
	(isFull) front = 1 && rear = size || rear+1 == front 
	(isEmpty) front = NULL
	(add)
		if isFull() : "Circular Queue Is Full"
		else :
			if rear == size 
				rear = 1
			else
				rear+1
			d[rear] = value 
	
	(delete)
		if isEmpty() : "Circular Queue Is Empty"
		else :
			if front == size
				d[front] = 0
				front=1
			else
				d[front] = 0
				front-1

*/

struct _CircularQueue{
	int front;
	int rear;
	int data[SIZE];
};

typedef struct _CircularQueue CircularQueue;

CircularQueue circularqueue;

// isEmpty
int isEmpty(){
	if(circularqueue.front == 0) return TRUE;
	return FALSE;
}

// isFull
int isFull(){
	if(circularqueue.front == 1 && circularqueue.rear == SIZE || circularqueue.front == circularqueue.rear+1) return TRUE;
	return FALSE;
}

// add
void add(int value){
	if(isEmpty()){
		circularqueue.front = 1;
		circularqueue.rear = 1;

		circularqueue.data[circularqueue.rear] = value;
	}
	else{
		if(isFull()) printf("CircularQueue Is Full Not Add Value\n");
		else{
			if(circularqueue.rear == SIZE){
				// reset value of rear 
				circularqueue.rear = 1;
			}
			else{
				// add value in circular queue
				circularqueue.rear++;
			}

			// add value 
			circularqueue.data[circularqueue.rear] = value;
		}
	}
}

// delete
int delete(){
	int delete_data;

	if(isEmpty()) printf("CircularQueue Is Empty Not Delete Value\n");
	else{
		if(circularqueue.front == circularqueue.rear){
			// queue is empty
			circularqueue.front = 0;
			circularqueue.rear = 0;
		}
		else if(circularqueue.front == SIZE){
			delete_data = circularqueue.data[circularqueue.front];

			// delete data
			circularqueue.data[circularqueue.front] = 0;
			
			// decrease value
			circularqueue.front = 1;
		}
		else{
			delete_data = circularqueue.data[circularqueue.front];

			// delete value
			circularqueue.data[circularqueue.front] = 0;
			
			// increate front value
			circularqueue.front++;
		}
		return delete_data;
	}
}

// print value
void print(){
	if(!isEmpty()){
		int front = circularqueue.front;
		int rear = circularqueue.rear;

		// printf("front: %d, rear: %d, size: %d\n", front, rear, SIZE);

		for(int index=1; index<=SIZE; index++) printf("%-5d\t", circularqueue.data[index]);

		printf("\n");
	}
}

int main(){
	// initialize circular queue
	circularqueue.front = 0;
	circularqueue.rear = 0;

	// printf("isEmpty() %d\n", isEmpty());
	// printf("front = %d, rear = %d\n", circularqueue.front, circularqueue.rear);
	
	add(10);
	add(20);
	add(40);
	add(50);
	add(60); // rear
	
	print();

	delete();
	delete();

	print();

	add(78);
	add(90);
	
	print();

	delete();
	delete();
	delete();

	print();

	printf("isEmpty() %d\n", isEmpty());
	printf("isFull() %d\n", isFull());
	delete();
	delete();

	print();

	delete();
	delete();
	delete();
	printf("isEmpty() %d\n", isEmpty());

	add(70);
	add(90);
	add(40);
	add(23);
	add(234);

	print();

	add(44);
	add(45);
	printf("isFull() %d\n", isFull());


	return 0;
}