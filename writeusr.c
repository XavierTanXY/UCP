/**
 * FILE:	writeusr.c
 * AUTHOR:	Xhien Yi Tan
 * STUDENTID:	18249833
 * UNIT:	COMP1000
 * PURPOSE:	A .c file that writes the corrected word into the user file.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "writeusr.h"

void writeUser( char** usr_array, char* user_file, int* textLength )
{
	/*Declaration*/
	int i;

	/*File Open*/
	FILE* f = fopen( user_file, "w" );
	
	/*Error-checking*/
	if( f == NULL )
	{
		perror( "Failed to open user file" );
	}
	else
	{
		/*Placing the words into the user file*/
		for( i = 0; i < *textLength; i++ )
		{
			fputs( usr_array[i], f );
			fputs( "\n", f );
		}
	}

	fclose( f );
	free( usr_array);
}
