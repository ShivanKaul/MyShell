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
/*
 * Definitions
 */
#define MAX_PROMPT_SIZE 30 // maximum length of the prompt
#define MAX_COMMAND_LENGTH 30 // maximum length of the command
/*
 * Array for prompt
 */
char *prompt;
char *input;
char *cmd;
char *args;

int main () {

	// Allocating memory
	prompt = malloc(MAX_PROMPT_SIZE);
	input = malloc(MAX_COMMAND_LENGTH);
	cmd = malloc(MAX_COMMAND_LENGTH);
	args = malloc(MAX_COMMAND_LENGTH);

	// The commands to match against
	char set[] = "set";
	char quit[] = "quit\n"; // newline at the end because the user will pass in
	// a carriage return after typing the command. This
	// is not true for set, where we would have arguments
	// afterwards.

	// The default prompt is set to be "Shell!!"
	strcpy(prompt, "Shell!!");

	// The main loop
	while (1) {
		// Display prompt
		printf("%s ",prompt);

		// Get user command
		fgets(input, MAX_COMMAND_LENGTH, stdin);

		// tokenize the input string
		char *cmd = strtok(input, " "); // Get the first word of the input
		int i;
		// sanitize the command to be lowercase, so that we can handle
		// case insensitivity
		for (i = 0; i != '\0'; i++) {
			cmd[i] = tolower(cmd[i]);
		}
		// if the command is quit, exit
		if (strcmp(cmd, quit) == 0) {
			break;
		}
		else {
			if (strcmp(cmd, set) != 0) {
				system(input);
			}
			else {
				char *args1;
				char *args2;
				args1 = strtok(NULL, " ");
				args2 = strtok(NULL, " ");
				strcpy(prompt, args2);
				prompt[strlen(prompt)-1]='\0';
			}
		}
	}
	return EXIT_SUCCESS;
}
