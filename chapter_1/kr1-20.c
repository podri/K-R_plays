/*Exercise 1-20. Write a program detab that replaces tabs in the input with
 * the proper number of blanks to space to the next tab stop. Assume a fixed
 * set of tab stops, say every n columns.  Should n be a variable or a symbolic parameter? 
 */
#include <stdio.h>
#define TS 4

main()
{
	int c, nspace;
	int nchar = 0;	/* counter for character position in the current line */
	while ((c=getchar()) != EOF){
		nchar++;
		if (c == '\t'){
			nspace = TS - ((nchar - 1) % TS);
			while (nspace-- > 0)
				putchar(' ');
		} 
		else {
			if (c == '\n')
				nchar = 0;
			putchar(c);
		}
	}

}
