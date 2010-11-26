/* Exercise 1-19. Write a function reverse(s) that reverses the
 * character string s. Use it to write a program that reverses
 * its input a line at a time.
 */
#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */
int getline(char line[], int maxline);
void reverse(char s[]); /* reverse the input  line */
main()
{
    char line[MAXLINE];     /* current input line */
    while ( getline(line, MAXLINE) ){  		
            reverse(line);		
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

/* reverse: put the character string reversed into array s */
void reverse(char s[])
{
	int i = 0;
	int j = 0;	
	char r[MAXLINE];
	while (s[i] != '\0') i++; //get the length of the line
	i -= 2;
    while (i > -1){
        r[j] = s[i];
		j++; i--;
	}
	r[j] = '\n';
	++j;
	r[j] = '\0';
	i = 0;
	while (s[i] = r[i]) i++;

}
