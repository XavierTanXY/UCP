/**
 * FILE:	setting.c
 * AUTHOR:	Xhien Yi Tan
 * STUDENTID:	18249833
 * UNIT:	COMP1000
 * PURPOSE:	A .c file that read the setting file and store its contents in a struct.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "setting.h"
#include "readFile.h"

#define WORDLENGTH 51
#define NAMELENGTH 14
#define VALUELENGTH 1000
#define FALSE 0
#define TRUE !0

Setting* readSetting( int* maxCorrect, int* autoCorrect )
{
	/*Declarations*/
	Setting *setting;
	char *name, *value;
	int correction;
	int nRead, done = 0;

	/*Open File*/
	FILE* f = fopen( "spellrc", "r" );

	/*Allocation*/
	setting = ( Setting* )malloc( sizeof( Setting ) );		
	(*setting).dictionary = ( char* )malloc( WORDLENGTH * sizeof( char ) );

 	name = ( char* )malloc( NAMELENGTH * sizeof( char ) );
	value = ( char* )malloc( VALUELENGTH * sizeof( char ) );

	/*Error-checking*/
	if( f == NULL )
	{
		perror( "Error opening 'spellrc'" );
	}
	else
	{
		do{
			nRead = fscanf( f, "%s = %s", name, value );
		
			if( nRead == EOF )
			{	
				done = 1;
			}
		
			/*Dealing with maxcorrection when name is equal to "maxcorrection", breaking String into int*/
			if( strcmp( name, "maxcorrection" ) == 0 )
			{
		 
				correction = atoi( value );
			
				if( correction < 0 )
				{
					printf( "Number of correction can't be negative" );
				}
				else
				{	
					( *setting ).maxcorrection = correction;
					*maxCorrect = setting->maxcorrection;
				}
			}
		
			/*Dealing with dictionary when name is equal to "dictionary"*/
			else if ( strcmp( name, "dictionary" ) == 0 )
			{	
				if( value == NULL )
				{
					printf( "Dictionary can't be null" );
				}	
				else
				{
					memcpy( ( *setting ).dictionary, value, VALUELENGTH + 1 );
				}	
			}
		
			/*Dealing with autocorrect when name is equal to "autocorrect"*/
			else if( strcmp( name, "autocorrect" ) == 0 )
			{
				if( strcmp( value, "yes" ) == 0 ) 
				{
					( *setting ).autocorrect = TRUE;
				}	
				else if( strcmp( value, "no" ) == 0 )
				{
					( *setting ).autocorrect = FALSE;
				}
				else 
				{
					printf( "The value must be 'yes' or 'no'");
	
				}
					*autoCorrect = ( *setting ).autocorrect; 	
			}
		}while(!done);	
	}

	fclose( f );
	return setting;	
}		
	
