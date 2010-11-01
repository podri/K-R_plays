/*
* Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
* (including an optional 0x or 0X) into its equivalent integer value. The allowable digits
* are 0 through 9, a through f, and A through F.
*/

#include <stdio.h>
#define MAXCH 10

int gethexnum(char s[]);
unsigned long int htoi(char s[]);

int main(){
	char hex_s[MAXCH];
	printf("The hexa number is:\n");
	gethexnum(hex_s);
	
	printf("The number in decimal:\n%lu\n", htoi(hex_s));
	return 0;
}

int gethexnum(char s[]){
	int i,c;
	for (i=0; i <= MAXCH && (c=getchar())!='\n'; ++i)
		s[i] = c;
	s[i] = '\0';
	if (i > MAXCH) return (-1);
		else return i;
}
/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}
/*ASCII only*/
unsigned long int htoi(char s[]){
	int c,i=0;
	long int n=0;
	int max_digit = 8;	//by 32 bit the max hexa is ffffffff
	if (s[0]=='0' && (s[1]=='x' || s[1]=='X')) {
			i=2;
			max_digit += 2;
	}
	while ((c=lower(s[i])) != '\0'){
		if (c >= '0' && c <= '9') n = n*16 + c-'0';
		else if (c >= 'a' && c <= 'f') n = n*16 + c-'a'+10;
		else return 0;	//by wrong digit
		++i;
		if (i > max_digit) return 0;
	}
	return n;
}
