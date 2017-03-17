/**
 * FILE:	LinkedList.c
 * AUTHOR:	Xhien Yi Tan
 * STUDENTID:	18249833
 * UNIT:	COMP1000
 * PURPOSE:	A .c file that creates and manages a LinkedList.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"

/*List Creation*/
LinkedList* createList( void )
{
	LinkedList *list = ( LinkedList* )malloc( sizeof( LinkedList ) );
	( *list ).head = NULL;
	list->size = 0;	
	return list;
}

/*Insertion*/
void insertElement( LinkedList *list, char *data  )
{
	LinkedNode *newNode;
	
	newNode = ( LinkedNode* )malloc( sizeof( LinkedNode ) );
	( *newNode ).data = ( char* )malloc( 51 *sizeof( char ) );
	strcpy( (*newNode).data, data );
	newNode->next = list->head;
	( *list ).head = newNode;
	list->size++;

}

/*Deletion*/
char* deleteElement( LinkedList *list )
{
	LinkedNode *temp;
	char* data;

	if( ( *list ).head == NULL )
	{
		printf( "No node" );
	}
	else if ( ( *list).size == 1 )
	{
		data = list->head->data;
		list->head = NULL;
		list->size--;
		free(list->head);
	}
	else
	{
		temp = ( *list ).head;
		list->head = list->head->next;
		data = temp->data;
		list->size--;
		free( temp );

	}

	return data;
}

/*Free LinkedList*/
void freeLinkedList( LinkedList* list )
{
	LinkedNode *node, *nextNode;

	node = ( *list ).head;
	while( node != NULL )
	{
		nextNode = ( *node ).next;
		free( ( *node ).data );
		free( node );
		node = nextNode;
	}
	free( list );
}

/*Getting the length of the list*/
int listLength( LinkedList* list )
{

	int length = 0;

	if( list != NULL )
	{
		length = 1 + listLength( list );
	}
	return length;
}		
