#include <stdio.h>
int  stack[10];
int top = -1;
int MAXSIZE = 10;

/***************************************************************************//*
*function for check if stack is empty or not
******************************************************************************/
int isempty() 
{
	if (top == -1) {
		return 1;
	} else {
		return 0;
	}

}

/***************************************************************************//*
*function for check if stack is full or not
******************************************************************************/
int isfull() 
{
	if (top == MAXSIZE) {
		return 1;
	} else {
		return 0;
	}
}

/***************************************************************************//*
*function for retrive the data
******************************************************************************/
int pop ()
{
	int data;
	if (!isempty()) {
		data = stack[top];
		top = top - 1;
		return data;
	} else {
		printf("\nStack is empty");
	}
}

/***************************************************************************//*
*function for push the data to the stack
******************************************************************************/
int push (int data) {
	
	if (!isfull()) {
		top = top + 1;
		stack[top]  = data;
	} else {
		printf("\nStack is full");
	}

}

/***************************************************************************//*
*function for display the all elements of stack
******************************************************************************/
int display() {
	int i;
	printf("\n[");
	for (i=0; i<=top; i++) {
		printf(" %d", stack[i]);
	}
	printf(" ]\n");
}


int main() {
	
	
	push(32);
	push(57);
	pop();
	push(60);
	push(9);
	push(4);
	push(3);
	push(12);
	push(23);
	push(87);
	push(41);
	push(45);
	push(478);
	push(42);
	//pop();
	display();
}
			



