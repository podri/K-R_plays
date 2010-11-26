/*Exercise 1-12. Write a program that prints its input one word per line.*/
#include <stdio.h>
#define IN    1 /* inside a blank */
#define OUT  0  /* outside a blank */
main()
{
    int c, blank;
	blank = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t'){ 
			if (blank == OUT){
			putchar('\n');
			blank = IN;
			}
		}
        else {
			putchar(c);
			blank = OUT;
        }
    }
}

