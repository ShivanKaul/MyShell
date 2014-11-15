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
#define MAX_PROMPT_SIZE 30 // maximum length of the prompt
#define MAX_COMMAND_LENGTH 30
/*
 * Array for prompt
 */
char *prompt;
char *input;
char *cmd;
char *args;

int main () {
	// The default prompt is set to be "Super Shell!! "

	prompt = malloc(MAX_PROMPT_SIZE);
	input = malloc(MAX_COMMAND_LENGTH);
	cmd = malloc(MAX_COMMAND_LENGTH);
	args = malloc(MAX_COMMAND_LENGTH);
	//	int parsingArgs = 0;

	strcpy(prompt, "Shell!!");
	//	char newPrompt[] = "Wow?? ";
	//	strcpy(prompt, newPrompt);
	//	printf("%s\n", prompt);


	while (1) {
		// Display prompt
		printf("%s ",prompt);
		// Get user command
		fgets(input, MAX_COMMAND_LENGTH, stdin);
		// Get the length of the command
//		int length_of_input = strlen(input) - 1;
		printf("input is: %s", input);

		// tokenize the whole input string
		char quit[] = "quit\n";
		char *cmd = strtok(input, " ");
		int i;
		for (i = 0; i != '\0'; i++) {
			cmd[i] = tolower(cmd[i]);
		}
		if (strcmp(cmd, quit) == 0) {
			break;
		}
		else {
			char *temp = strdup(input);
			char set[] = "set";
			if (strcmp(cmd, set) != 0) {
				system(input);
			}
			else {
//				int numberOfArgs=0;
				char *args1;
				char *args2;
				args1 = strtok(NULL, " ");
				args2 = strtok(NULL, " ");
//				prompt[strlen(prompt)-1]='\0';
//				strncpy(prompt, args2, strlen(args2)-1);
				strcpy(prompt, args2);
				prompt[strlen(prompt)-1]='\0';
			}
		}
		//		int i;
		//		int args_counter=0;
		//		int cmd_counter=0;
		//		// Examine every char in the command
		//		for (i = 0; i < length_of_input; i++) {
		//			if (input[i] != ' ' && !parsingArgs) {
		//				cmd[cmd_counter] = input[i];
		//			}
		//			else if (parsingArgs) {
		//				args[args_counter] = input[i];
		//			}
		//			else {
		//				parsingArgs = 1;
		//			}
		//		}
	}


	return EXIT_SUCCESS;
}
