/*
* Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
* (including an optional 0x or 0X) into its equivalent integer value. The allowable digits
* are 0 through 9, a through f, and A through F.
*/

#include <stdio.h>
#define MAXCH 16	//by 64 bit the max hexa is 0xffffffffffffffff

int gethexnum(char s[]);
unsigned long long int htoi(char s[]);

int main(){
	char hex_s[MAXCH+3];
	printf("The hexa number is:\n");
	gethexnum(hex_s);
	printf("The number in decimal:\n%llu\n", htoi(hex_s));
	return 0;
}

int gethexnum(char s[]){
	int i,c;
	for (i=0; i <= MAXCH+1 && (c=getchar())!='\n'; ++i)
		s[i] = c;
	s[i] = '\0';
	return i;
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
unsigned long long int htoi(char s[]){
	int c,i=0;
	long long int n=0;
	int max_digit = MAXCH;
	if (s[0]=='0' && (s[1]=='x' || s[1]=='X')) {
			i=2;
			max_digit += 2;
	}
	while ((c=lower(s[i])) != '\0'){
		if (c >= '0' && c <= '9') n = n*16 + c-'0';
		else if (c >= 'a' && c <= 'f') n = n*16 + c-'a'+10;
		else {
			fprintf(stderr, "Wrong digit in htoi!\n");
			return 0;	//by wrong digit
		}
		++i;
		/*if the number is too long only the max value is returned */
		if (i >= max_digit && s[i]){
			fprintf(stderr, "Input number is too long in htoi!\n");
			return 0;
		}
	}
	return n;
}
