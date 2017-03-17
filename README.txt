Unix and C Programming ( COMP1000 )
Spell-Checking Assignment

Files I have submitted:
	
* main.( c,h ): This file is the main that runs the whole taks, it accepts one command-line parameter which is the user file.	
* setting.( c,h ): This file reads the setting file and proccess the name and value.
* readFile.( c,h ): This file reads both dictionary and user input file and store its contents into a linked list. 
		    After that transfer the data in the linked list into a new array, which will be used later for spell checking.
* check. ( c,h ): This file performs the actuial spell-checking.
* writeusr. ( c,h ): This file writes the corrected words back into the user input file. 
* LinkedList.( c,h ): This file creates and manages a linked list for storing data.

Non-source files: 

* Makefile: A file that contains all those compile codes and codes for creating an executable program.
* README.txt: this README.txt

Statements:
* The program is simply straightforward for every required tasks. I have completed the whole assignment and I have to put much effort to make it working due to some parts where I am not confident in. Finally, everything is working just fine.

Issues reported by valgrind:
* Source and destrination overlap in memcpy
* Invalid write of size 4
* Invalud read of size 1 

Computer I tested my code on:
* Room Number:	314.218
* Service Tag:	5BPZF2S
