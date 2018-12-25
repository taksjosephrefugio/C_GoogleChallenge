/*
This code takes a string and a number K from the user.
The output of the program is the all caps of the user's string
and there would be dashes between K letters

e.g.
Input: helloworld, 3
Output: HEL-LLO-WOR-LD

Code Written by: TAK'S JOSEPH REFUGIO
Code Written on: Summer 2017
Code Written for: Google Interview Challenge
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FUNCTION PROTOTYPES
char*withoutDashes(char*string);
char*capitalizeString(char*string);
char*solution(char*string, int K);

int main(void)
{
	// char teststring [300000] = "srgtyjhsfbrsy-ergergeg-dsfsgdhsfd";
	// char teststring [300000] = "helloworld";
	char teststring [300000] = "2-4A0r7-4k";
	char*sol1 = withoutDashes(teststring);
	char*sol2 = capitalizeString(sol1);
	char*sol3 = solution(sol2, 3);
	printf("%s\n", sol3);
	return 0;
}

char*withoutDashes(char*string) {
	int numdashes = 0;		// Stores the number of dashes in the input string

	// While loop computes for the number of dashes in the input string
	int ctr = 0;
	while (string[ctr])		// Cycles thru the characters in the input string until NULL terminator
	{
		if (string[ctr] == '-') { numdashes++; }
		ctr++;
	}
	ctr=0;

	// I have no idea why this works
	char*returnString = (char*)malloc(sizeof(char) * (strlen(string)-numdashes)); 

	int dashcount = 0;
	while (string[ctr])
	{
		if (string[ctr] != '-') 
		{ 
			returnString[ctr - dashcount] = string[ctr]; 
			ctr++;
		}
		else
		{
			ctr++;
			dashcount++;
		}
	}
	returnString[ctr - dashcount] = '\0';
	ctr=0;

	return returnString;
}

char*capitalizeString(char*string) {
	char*returnString = (char*)malloc(sizeof(char)*strlen(string));
	int ctr = 0;

	while (string[ctr])
	{
		int intchar = string[ctr];
		if ((intchar >= 97) && (intchar <= 122))
		{
			returnString[ctr] = intchar - 32;
		}
		else
		{
			returnString[ctr] = intchar;
		}
		ctr++;
	}
	returnString[ctr] = '\0';
	ctr=0;	
	return returnString;	
}

char*solution(char*string, int K) {
	int dashputback = strlen(string) / K;
	int firstcharslength = strlen(string) % K;	
	char*returnString = (char*)malloc((strlen(string) + dashputback) * sizeof(char));
	int putbackcount = 0;

	int ctr = 0;
	if (firstcharslength != 0)
	{
		while (ctr < firstcharslength)
		{
			returnString[ctr] = string[ctr];
			ctr++;
		}
		returnString[ctr] = '-';
		putbackcount++;
	}
	

	int charcount=0;
	while (string[ctr])
	{
		charcount++;
		returnString[ctr + putbackcount] = string[ctr];

		if (charcount == K) { 
			putbackcount++;
			returnString[ctr + putbackcount] = '-';
			charcount = 0;
		}
		ctr++;
	}
	returnString[ctr+putbackcount-1] = '\0';
	return returnString;
}
