#include <stdio.h>
/* count lines in input */
main()
{
	int c, spec=0;	
    while ((c = getchar()) != EOF){
        if(c == '\t') {printf("\\t");spec = 1;}
        if(c == '\b') {printf("\\b");spec = 1;}
        if(c == '\\') {printf("\\\\");spec = 1;}
		if(!spec) putchar(c);
		spec = 0;
	}
}

