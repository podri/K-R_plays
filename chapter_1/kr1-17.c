/*Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.*/
#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */
int getline(char line[], int maxline);
void copy(char to[], char from[]);
/* print the longest input  line */
main()
{
    int len;             /* current line length */
    int found;             /* variable to mark whether found a line longer than 80 characters*/
    char line[MAXLINE];     /* current input line */
    found = 0;
    while ((len = getline(line, MAXLINE)) > 0){
        if (len > 80) {
			if (found == 0)
				printf("The lines longer than 80 characters:\n");
			printf("%s", line);
			found = 1;
        }
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
