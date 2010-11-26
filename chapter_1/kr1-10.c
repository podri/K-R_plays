#include <stdio.h>
/* Exercise 1-10. Write a program to copy its input to its output,
 * replacing each tab by \t, each backspace by \b, and each backslash by \\.
 * This makes tabs and backspaces visible in an unambiguous way.
 */

main()
{
	int c, spec = 0;  
	while ((c = getchar()) != EOF){
		if(c == '\t') {printf("\\t");spec = 1;}
		if(c == '\b') {printf("\\b");spec = 1;}
		if(c == '\\') {printf("\\\\");spec = 1;}
	if(!spec) putchar(c);
	spec = 0;
	}
}
