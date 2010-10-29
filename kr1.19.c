#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */
int getline(char line[], int maxline);
/*void reverse_(char s[], int len); - first version */
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
/* reverses the char array - first version 
void reverse_(char s[], int len)
{
	char r[MAXLINE];
	int i = 0;
	len -= 2;
    while (len > -1){
        r[i] = s[len];
		i++; len--;
	}
	r[i] = '\n';
	++i;
	r[i] = '\0';
	i = 0;
	while (s[i] = r[i]) i++;
	
}
*/
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
