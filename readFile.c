/**
 * FILE:	readFile.c
 * AUTHOR:	Xhien Yi Tan
 * STUDENTID:	18249833
 * UNIT:	COMP1000
 * PURPOSE:	A .c file that read both dictionary file and user file and 
  		return the length by reference and also return the array.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "setting.h"
#include "LinkedList.h"
#include "readFile.h"
#define WORDLENGTH 51

char** readFile( char* file, int* txtLength )
{
	/*Declarations*/
	int done = 0;
	int nRead, j, length = 0;
	char *word;
 	char **array;

	/*File Open*/
	FILE* f = fopen( file, "r" );

	/*Create a LinkedList to store those word*/
	LinkedList *list = createList();
	
	/*Allocating word to WORDLENGTH*/
	word  = (char*)malloc( WORDLENGTH * sizeof(char));

	/*Error-checking*/
	if( f == NULL )
	{
		perror( "Error opening file" );
	}
	else
	{
		
		do{
			/*Reading each word and insert into LinkedList*/
			nRead = fscanf( f, "%s", word );
		
			if( nRead == EOF )
			{
				done = 1;
			}
			else	
			{	
				insertElement( list, word );
			}
		}while( !done );
		
		/*Getting the length*/
		length = list->size;
		*txtLength = length;

		/*Create an array and transfer the word in LinkedList into the array*/
		array = (char**)malloc(length * sizeof(char*));
	
		for( j = 0; j < length; j++ )
		{
			array[j] = deleteElement( list );
		}
	}
		
	fclose( f );
	freeLinkedList( list );
	return array;
}
