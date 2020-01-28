#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struheader.h"

/*******************************************************************************
* structure definition & Finctions definition
*******************************************************************************/
// create start pointer which point to NULL
struct student *start=NULL;

/******************************************************************//**
*Function to create first node
*@param[in] r here r is the roll number of that node
**********************************************************************/
struct student	*create_node(int r, char name[]) {
	struct student *pointer;
	// allocate memory for first node
	pointer = (struct student*)malloc(sizeof(struct student)); 
	if( NULL == pointer )
	{
		printf("Error! Unable to allocate memory\n");
		exit(1);
	}
	pointer->roll = r;
	strcpy(pointer->name, name);
	pointer->next = NULL;
	return pointer;
}

/******************************************************************//**
*Function to add node at last if list is present
**********************************************************************/
void addNodeAtLast( int r, char name[] ) {
	struct student *temp=NULL;

	if( NULL == start ) 
	{
		printf("The list is empty\n");
		return;
	}

	temp = start;

	while( temp->next != NULL )  // go to end of list where NULL is pointed
	{
		temp = temp->next;
	}
	
	temp->next = create_node(r, name); // add node at last
	 temp->next->next = NULL; // give the NULL to next pointer 
}

/******************************************************************//**
*Function to add node at first 
**********************************************************************/
void addNodeAtFirst( int r, char name[] ) {

	struct student *temp=NULL;

	if( start == NULL )
	{
		printf("The list is empty\n");
		start = create_node(r, name);
		return;
	} 
	
	temp = start;
	start = create_node(r, name);
	start->next = temp; 
	
}

/******************************************************************//**
*Function to add node at after the passing roll number structur
*@param[in] r which is roll number after that roll number containing node add one more node 
**********************************************************************/
void addNodeBetween( int r, int r_add, char name[] ) {
	struct student *temp = NULL;
	struct student *temp1 = NULL;
	temp = start;
	while ( temp != NULL ) {
		if (temp->roll == r) {  // check given number in all node			
			temp1 = temp->next;
			temp->next = create_node(r_add, name);
			temp = temp->next;
			temp->next = temp1;
			return;
		}
		temp = temp->next;
	}
		printf("\nNo value found\n");
}

/******************************************************************//**
*Function to sum all the roll number from all the node
**********************************************************************/
int transerv() {
	struct student *temp = start;
	int sum = 0;
	while (temp != NULL ) {
		sum = sum+temp->roll;
		temp = temp->next;
	}
	return sum;
}

/******************************************************************//**
*Function to delete node at first 
**********************************************************************/
void delNodeAtFirst() {
	struct student *temp = NULL;
	temp = start;
	if (start == NULL ) {
		printf("NO First node found");
		return;
	}
	temp = start;
	start = temp->next;
	delFromFile(file_name, "a+", temp->roll);
	free(temp);
	temp = NULL;
	printf("The very first node is deleted from the list\n");
}

/******************************************************************//**
*Function to delete node at last 
**********************************************************************/
void delNodeAtLast() {
	 struct student *temp=NULL, *temp1=NULL;

        if( start == NULL )
        {
                printf("The list is empty @delNodeAtLast\n");
                return;
        }

	
        if( start->next == NULL) // when list have only one node
        {
		delFromFile(file_name, "a+", start->roll);                
		free(start);
                start = NULL;
                printf("The node is deleted\n");
                return;
        }

	temp = start;
        temp1 = start;

       //search for last node last node have NULL pointer to next
        while(temp->next != NULL) { 
            temp1 = temp;
            temp = temp->next;
        }
 
        temp1->next = NULL;
	delFromFile(file_name, "a+", temp->roll);
        free(temp);
	printf("The last node is deleted\n");
}


/******************************************************************//**
*Function to delete node at between
**********************************************************************/
void delNodeBetween( int r ) {
	struct student *temp = NULL;
	struct student *temp1 = NULL, *temp2 = NULL;
	if( start == NULL ) {
		printf("\nList is empty @delNodeBetween");
		return;
	}

	temp = start;

	while ( temp != NULL ) {
	//check if fist node have require roll no
		if (temp->roll == r ) {
			temp1 = temp->next;
			delFromFile(file_name, "a+", temp->roll);
			free(temp);
			start = temp1;
			return;
	//this condition accurs when first node not have required roll no.
		}else if (temp->next->roll == r) {
			temp2 = temp;
			temp = temp->next;
			temp1 = temp->next;
			delFromFile(file_name, "a+", temp->roll);		
			free(temp);
			temp2->next = temp1;
		//this condition accurs when delete node is last
			if (temp1 == NULL ) {
				temp = NULL;
				return;
			}
			temp = temp1;
			return;
		}

		temp = temp->next;
	}
	printf("\nNo value found");

}

/******************************************************************//**
*Function to display all node value (roll)
**********************************************************************/
void displayList( void )
{
	struct student *temp=NULL;
	if( start == NULL )
	{
		printf("The is empty @displayList()\n");
		return;
	}

	temp = start;

	printf("\n\nThe list is\n");
	do
	{
		printf("%d", temp->roll);
		printf(" |%s\n", temp->name);
		temp = temp->next;
	}while(temp != NULL);
	printf("\n\n");
}

/******************************************************************//**
*Function to write into file
**********************************************************************/
void addtofile(char fname[], char mode[], int ro, char name[]) 
{
	FILE *fp;
	fp = fopen(fname, mode); // open file which given fname and in given mode
	fprintf(fp, "%d |", ro); // write ro into file
	fprintf(fp, "%s\n", name); // write name into file
	fclose(fp);
}

/******************************************************************//**
*Function to Display list of operation
**********************************************************************/
void dislist()
{
	printf("\n\t\tWelcome to Linklist Manegment Tool\n");
	createFile();
	printf("\n1) To create node at first ");
	printf("\n2) To create node at last ");
	printf("\n3) To create node  after that value ");
	printf("\n4) To delete node at first ");
	printf("\n5) To delete node at last ");
	printf("\n6) To delete node which value have ");
	printf("\n7) To display list of node ");
	printf("\n8) To display sum of roll number of all nodes");
	printf("\n9) To display from the file");
	printf("\n10 To clear content of File");
	printf("\n11) To exit");
	
}

/******************************************************************//**
*Function to Display list from file
**********************************************************************/
void disfile(char fname[], char mode[])
{
	FILE *fp;
	char cch; // var cch get character from file one by one	
	fp = fopen(fname, mode); // open file which given fname and in given mode
	cch = fgetc(fp);
	while(cch != EOF) {
		printf("%c", cch);
		cch = fgetc(fp);
	} 
	fclose(fp);
}

/******************************************************************//**
*Function to remove from file
**********************************************************************/
void delFromFile(char fname[], char mode[], int ro) 
{
	FILE *fp, *ftemp;
	fp = fopen(fname, mode); // open file which given fname and in given mode
	ftemp = fopen("temp.txt", "w+"); // open temp file
	char cch;
	//cch = fgetc(fp);

	char cdiv, crem;
       cdiv = (ro/10)+48; //int to char 
       crem = (ro%10)+48; // int to char
	
	do {  // check if End of file or not
		cch = fgetc(fp);
		if (cch == EOF) {  // check if End of file or not
			break;
		}
		if (cch == cdiv) {
			 cch= fgetc(fp);
			 if (cch == EOF) {  // check if End of file or not
				 break;
			 }
		       if (cch == crem) {
				printf("loc is %ld", ftell(fp));
				while (cch != '\n') {
					cch = getc(fp);
					if (cch == EOF) {  // check if End of file or not
						break;
					}
				}
			} else {
			 fprintf(ftemp, "%c", cdiv);

			}
		}
				fprintf(ftemp, "%c", cch);

	} while(cch != EOF); 


	fclose(fp);
	fclose(ftemp);
	copyfile();
}

/******************************************************************//**
*Function to copy file from temp to main file
**********************************************************************/
void copyfile() {
	
	FILE *fp, *ftemp;
	char cch;
	fp = fopen(file_name, "w+");
	ftemp = fopen("temp.txt", "r");
	cch = fgetc(ftemp);  // hold the value from file
	while (cch != EOF) { // check if End of file or not
		fprintf(fp, "%c", cch);
		cch = fgetc(ftemp);
	}
	fclose(fp);
	fclose(ftemp);
}

/******************************************************************//**
*Function to clear file content
**********************************************************************/
void clean()
{
	FILE *fp;
	fp  = fopen(file_name, "w");
	fclose(fp);
	printf("\nFile Clear");
}

/******************************************************************//**
*Function to create new file
**********************************************************************/
void createFile()
{	
	printf("\nEnter name of file to create new file ");
	scanf("%s", file_name);	
	FILE *fp, *ftemp;
	fp = fopen(file_name, "a+");
	ftemp = fopen("temp.txt", "w+");
	fclose(fp);
	fclose(ftemp);
}



