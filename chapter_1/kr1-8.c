#include <stdio.h>
/*Exercise 1-8. Write a program to count blanks, tabs, and newlines.*/
main()
{
    int c, bl, t, nl;
    nl = 0;
	bl = 0;
	t = 0;
    while ((c = getchar()) != EOF){
        if (c == '\n')
            ++nl;
		if (c == ' ')
			++bl;
		if (c == '\t')
			++t;
	}
    printf("number of newlines: %d\n", nl);
    printf("number of blanks: %d\n", bl);
    printf("number of tabs: %d\n", t);
}

