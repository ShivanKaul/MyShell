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
#define MAX_FILENAME 50 // we specify the max filename size
#define EXPERIMENTER_TITLE_MAX 20 // the name of the experimenter has to be < this
#define MAX_EXPERIMENTS 20 // max number of experiments by one experimenter
#define ASCII_CODE_FOR_COMMA 44 // ASCII code for a comma

/*
 * Calculates the average. This function sums over all the floats
 * provided in the numbers array, and then divides the sum by the size
 * to give the average.
 */
float calculate_average(int numbers[], int size) {
	int i;
	float sum = 0;
	for (i = 0; i < size; i++) {
		sum += numbers[i];
	}
	float average = sum/size;
	return average;
}

int main (int argc, char *argv[]) {
	if (argc != 2) /* argc should be 2 for correct execution */
	{
		printf("Error: please enter CSV filename.\n");
		return EXIT_FAILURE;
	}
	else {
		// try to open the file (we assume that the filename has been
		// entered as the first argument.
		// On the discussion board the prof said we can assume
		// that the data we're given is correctly formatted.
		FILE *file = fopen(argv[1], "r");
		/* fopen returns 0, the NULL pointer, on failure */
		if ( file == 0 )
		{
			printf( "Could not open CSV file.\n" );
			return EXIT_FAILURE;
		}
		else {
			setbuf(stdout, NULL); // I was having problems with the buffer not printing, so turning that off.

			/* The file is now opened.
			 * The file is looped over using the while (x!=EOF) condition, and the first step we perform is check if
			 * the next char is the end of the file.
			 */
			int x;

			while (x != EOF) { // This is the loop for the
				// if we have reached the end of file ...
				if (( x = fgetc(file)) == EOF) {
					break; // ... then break out of the loop
				}

				// Until the first comma is seen, print the chars. This will print the experimenter's name.
				while (x != ASCII_CODE_FOR_COMMA) // Check if current file pointer is at a comma
				{
					printf("%c", x);
					x=fgetc(file); // move on to next char
				}

				// Print a space after the name
				printf(" ");

				/*
				 * We will be parsing the floats from the csv file into an int array
				 */
				int counter = 0;
				int numbers[MAX_EXPERIMENTS];
				// get the first number
				fscanf (file, "%i", &numbers[counter]);
				counter++;
				// get all the numbers from a record
				while  (( x = fgetc(file)) != '\n' ) { // while we haven't reached a newline
					// ... get the int
					fscanf (file, "%i", &numbers[counter]);
					counter++;
				}

				// the number of data points is given by the counter
				int size = counter;
				// we call the function average with the floats and the size to get the average
				float average = calculate_average(numbers, size);
				// print the answer rounded up to 2 decimal places
				printf("%.2f\n", average);
			}
			close(file);
		}
	}
}
