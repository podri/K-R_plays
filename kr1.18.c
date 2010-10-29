#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */
int getline(char line[], int maxline);
void rm_blank(char s[], int len);
/* print the longest input  line */
main()
{
	int length = 0;      
    char line[MAXLINE];     /* current input line */
    while (length = getline(line, MAXLINE) ){  		
            rm_blank(line, length);		
        	printf("%s", line);
	}
    return 0;
}
     

		

/* getline: read a line into s, return length    */
int getline(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
/* delete the spaces on the line-end -> 
 * it replaces the first tailing space with a '\0' */
void rm_blank(char s[], int len)
{
	len -= 2;
    while (s[len] == ' ' || s[len] == '\t')
        --len;
	if (len == -1) s[0] = '\0'; //if the first char on the line was space, then len==-1
	else { len++;
		s[len] = '\n';
		len++;
		s[len] = '\0';
	}
}

