/*
 ============================================================================
 Name        : MyShell.c
 Author      : Shivan Kaul Sahib
 Version     : 1.0
 Description : Q2 on assignment 3 for COMP 206
 ============================================================================
 */
/*
 * The include files
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
 * Definitions
 */
#define MAX_PROMPT_SIZE 10 // maximum length of the prompt
/*
 * Array for prompt
 */
char *prompt;

int main () {
	// The default prompt is set to be "Super Shell!! "

	prompt = malloc(MAX_PROMPT_SIZE);

	strcpy(prompt, "Super Shell!! ");
	printf("%s\n", prompt);

	char newPrompt[] = "Wow?? ";
	strcpy(prompt, newPrompt);
	printf("%s\n", prompt);


	return EXIT_SUCCESS;
}
