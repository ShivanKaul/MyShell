/*
 ============================================================================
 Name        : MyShell.c
 Author      : Shivan Kaul Sahib
 Version     : 1.0
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
 * Global structures
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
	char pr[] = "prompt";
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
				// if the command is set, then check the second word. If it's
				// prompt (case insensitive), then set the prompt to be the third
				// word. Else, execute the command
				char *args1;
				char *args2;
				args1 = strtok(NULL, " ");
				// temp array to check if second word is prompt
				char *checkargs1 = strdup(args1);
				// sanitize it to lowercase
				for (i = 0; i != '\0'; i++) {
					checkargs1[i] = tolower(checkargs1[i]);
				}
				// If not prompt, then execute the command
				if (strcmp(checkargs1, pr) != 0) {
					system(input);
				}
				// set the prompt
				else {
					args2 = strtok(NULL, " ");
					strcpy(prompt, args2);
					prompt[strlen(prompt)-1]='\0';
				}
			}
		}
	}
	return EXIT_SUCCESS;
}
