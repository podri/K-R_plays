#include <stdio.h>
/* Exercise 1-9. Write a program to copy its input to its output,
 * replacing each string of one or more blanks by a single blank.
 */
#define BLANK 1
#define NO_BLANK 0
main()
{
    int c, status = NO_BLANK;
    while ((c = getchar()) != EOF){
		if ( c != ' '){
			putchar(c);
			status = NO_BLANK;
		}
		else if (status == NO_BLANK){
				putchar(c);
				status = BLANK;
		}
	}
}
