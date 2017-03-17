/**
 * FILE:	LinkedList.h
 * AUTHOR:	Xhien Yi Tan
 * STUDENTID:	18249833
 * UNIT:	COMP1000
 * PURPOSE:	Forward Declarations of LinkedList.c 
 * 		Typedef struct for LinkedList and LinkedNode
 */
 	
typedef struct LinkedNode
{
	char *data;
	struct LinkedNode *next;
} LinkedNode;

typedef struct 
{
	int size;
	LinkedNode *head;
} LinkedList;

LinkedList* createList( void );
void insertElement( LinkedList *list, char *data );
char* deleteElement( LinkedList *list );
void freeLinkedList( LinkedList *list );
int listLength( LinkedList *list );

