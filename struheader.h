#ifndef STRUHEADER_H_
#define STRUHEADER_H_

/*******************************************************************************
			Preprocessor Declaration
*******************************************************************************/
#define SUCCESS 0
#define FAIL 1

/*******************************************************************************
			 Global Structure Definitions
*******************************************************************************/
#define MAX_LEN_NAME 15
char file_name[MAX_LEN_NAME];
struct student {
	char name[MAX_LEN_NAME];
	int roll;
	struct student *next;
};

/*******************************************************************************
* Functions Prototype Declarations
*******************************************************************************/
struct student *create_node();
void addNodeAtLast();
void addNodeAtFirst();
void addNodeBetween( );
int transerv();
void delNodeAtFirst();
void delNodeAtLast();
void delNodeBetween( int );
void displayList( void ); 
void addtofile();
void dislist();
void disfile();
void copyfile();
void delFromFile();
void clean();
void createFile();


#endif /*STRUHEADER_H_*/

