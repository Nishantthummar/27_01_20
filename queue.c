#include <stdio.h>
int queue[8];
int max = 8;
int enq_pointer = -1;
int deq_pointer = -1;

/***************************************************************************//*
*function for dequeue data which is first enqueue
******************************************************************************/
int dequeue() {
	int data;
	if (deq_pointer <= max) {
		deq_pointer = deq_pointer + 1;
		data = queue[deq_pointer];
		queue[deq_pointer] = 0;
		return data;
	} else {
		printf("\nCould not retrive data because Queue is empty");
	}

}

/***************************************************************************//*
*function for enqueue data
******************************************************************************/
int enqueue(int data) {
	if (enq_pointer <= max) {
		enq_pointer = enq_pointer + 1;
		queue[enq_pointer] = data;
		return 1;
	} else {
		printf("\nCould not enqueue data because Queue is full");
	}
}

/***************************************************************************//*
*function for display all queue element
******************************************************************************/
void display() {
	int i;
	printf("\n[");
	
	for (i=0; i<=enq_pointer; i++) {
		printf(" %d", queue[i]);
	}
	printf(" ]");
}

int main() {
	enqueue(10);
	enqueue(20);
	dequeue();
	enqueue(30);
	enqueue(40);
	dequeue();
	display();
}

