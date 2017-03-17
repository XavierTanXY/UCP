/**
 * FILE:	setting.h
 * AUTHOR:	Xhien Yi Tan
 * STUDENTID:	18249833
 * UNIT:	COMP1000
 * PURPOSE:	Forward Declaration of setting.c 
 * 		Typedef struct of Setting
 */
typedef struct
{
	int maxcorrection;
	char *dictionary;
	int autocorrect;
} Setting; 

Setting* readSetting( int* maxCorrect, int* autoCorrect ); 
