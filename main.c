/**
 * FILE:	main.c
 * AUTHOR:	Xhien Yi Tan
 * STUDENTID:	18249833
 * UNIT:	COMP1000
 * PURPOSE:	A .c file accept one command-line parameter call those functions to perform the required task
 */
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "setting.h"
#include "readFile.h"
#include "check.h"
#include "writeusr.h"
	
int main ( int argc, char* argv[] )
{
	/*Declarations*/
	char **array, **usr_array;
	int  dictLength, textLength=0, maxCorrection, autoCorrect;
	Setting* setting;
	ActionFunc action;
	
	if( argv[1] == NULL )
	{
		printf( "No file is detected, Please input a file to be corrected\n" );
	}
	else
	{
		/*Read the settings file and get the value for maxCorrection and autoCorrect by reference for later use*/
		setting = readSetting( &maxCorrection, &autoCorrect );

		/*Read the dictrionary file and get the length of it by reference*/
		array = readFile( setting->dictionary, &dictLength );
	
		/*Read the user file which comes from the command-line parammeter and get the length of it by reference*/
		usr_array = readFile( argv[1], &textLength );

		/*
  				When autoCorrect is No points to a falseFunction where the user 
				will be presented with the original word and the corrected version, 
				and also asked to choose between them.
				When autoCorrect is Yes, points to a trueFunction .
		*/
		if( autoCorrect == 0)
		{
			printf("AutoCorrect is Off\n");
			action = &falseFunc;		
		}
		else
		{
			printf("AutoCorrect is On\n");
			action = &trueFunc;
		}

		/*A fucntion that perform the actual spell-checking*/
		check( usr_array, textLength, array, dictLength, maxCorrection, action );
	
		/*A function that write the user array back to the user file after spell-checking*/
		writeUser( usr_array, argv[1], &textLength );

		printf("Correction Done!\n");
	}
	return 0;
}

/*A function that returns TRUE when the autoCorrection is on*/
int trueFunc(char* word, char* suggestion)
{
	int result ;
	if( suggestion == NULL )
	{
		result = FALSE;
	
	}
	else
	{
		result = TRUE;		 
	}
return result;
}

/**
 *A function that returns FALSE when the autoCorrection is off,
 *The user will be presented with the original word, 
 *the corrected version and choose between them.
 */ 
int falseFunc(char* word, char* suggestion)
{
	int response, result;
	if ( suggestion == NULL )
	{ 
		result = FALSE;
	}
	else
	{
		printf( "The original word is '%s', The suggestion is '%s'\n", word, suggestion );
		printf( "Do you want the word to be corrected ?\n" );
		printf( "Please enter '1' for YES\nPlease enter '0' for NO\n" );
		scanf( "%d", &response );
		
		if( response == 0 )
		{
			result = FALSE;
		}
		else
		{
			result = TRUE;
		}
	}
	return result;	
}

