#include <stdio.h>
#include <stdlib.h>
#include "struheader.h"

#define MAX_LEN_NAME 15

int main ( int argc, char *argv[] ) {
	system("clear");
	
	// var iget for store value which user will choose
	// var iroll for store roll number of node
	// var iro for after that roll number new roll number will add or remove
	int iget, iroll, iro;
	// var cname store name string 
	char cname[MAX_LEN_NAME];
	//var time strore time_t type variable	

	FILE *fp; // var fp is file pointer
  	
	dislist(); // Display the list of operation
	// open file name student_list in append mode r/w
	fp = fopen(file_name, "a+");
	fclose(fp); // close file 
	
	do {

		printf("\nEnter your choise  "); // Get choise from user
		scanf("%d", &iget);

		switch (iget) {
			case 1: // To create node at first
				printf("\nEnter the name  which you want to add  ");
				scanf("%s", cname);
				printf("\nEnter the roll no which you want to add  ");
				scanf("%d", &iroll);
				addNodeAtFirst(iroll, cname);
				// write into file given roll & name in sequence
				addtofile(file_name, "a+", iroll, cname);
				break;

			case 2: // To create node at last
				printf("\nEnter the name  which you want to add  ");
				scanf("%s", cname);
				printf("\nEnter the roll no which you want to add  ");
				scanf("%d", &iroll);
				// write into file given roll & name in sequence
				addtofile(file_name, "a+", iroll, cname);
				addNodeAtLast(iroll, cname);
				break;

			case 3: // To create node  after that value
				printf("\nEnter the name  which you want to add  ");
				scanf("%s", cname);
				printf("\nEnter the roll no which you want to add  ");
				scanf("%d", &iroll);
				printf("\nEnter the roll no after you want to add  ");
				scanf("%d", &iro);
				// write into file given roll & name in sequence
				addtofile(file_name, "a+", iroll, cname);
				addNodeBetween( iro, iroll, cname);
				break;

			case 4: // To delete node at first
				printf("\nDeleting first node..");
				delNodeAtFirst();
				break;

			case 5: // To delete node at last
				printf("\nDeleting last node");
				delNodeAtLast();
				break;

			case 6: // To delete node which value have
				printf("\nEnter the roll no which you want to del  ");
				scanf("%d", &iroll);
				delNodeBetween(iroll);
				break;

			case 7:	// To display list of node
				printf("\nDisplaying\n\n");
				displayList();
				break;

			case 8: // To display sum of roll number of all nodes
				printf("\nSum is %d", transerv());
				break;

			case 9: // To display from the file
				printf("\nIn File\n");
				disfile(file_name, "a+");
				break;
			case 10: // To clear content of File 
				printf("\nClearing file....");
				clean();
				break;
			}
	} while( iget != 11); // To quit if get value is 11
	system("rm temp.txt");
}






