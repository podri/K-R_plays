/*
 * Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
 *variables, both signed and unsigned, by printing appropriate values from standard headers
 *and by direct computation. Harder if you compute them: determine the ranges of the various
 *floating-point types.
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	printf("limits from header:\n");
	printf("SCHAR_MIN: %d\n", SCHAR_MIN);
	printf("SCHAR_MAX: %d\n", SCHAR_MAX);
	printf("UCHAR_MAX: %u\n", UCHAR_MAX);
	printf("CHAR_MIN: %d\n", CHAR_MIN);
	printf("CHAR_MAX: %d\n", CHAR_MAX);
	printf("SHRT_MIN: %d\n", SHRT_MIN);
	printf("SHRT_MAX: %d\n", SHRT_MAX);
	printf("USHRT_MAX: %u\n", USHRT_MAX);
	printf("INT_MIN: %d\n", INT_MIN);
	printf("INT_MAX: %d\n", INT_MAX);
	printf("UINT_MAX: %u\n", UINT_MAX);
	printf("LONG_MIN: %ld\n", LONG_MIN);
	printf("LONG_MAX: %ld\n", LONG_MAX);
	printf("ULONG_MAX: %lu\n", ULONG_MAX);
	printf("FLT_MAX: %f\n", FLT_MAX);
	printf("DBL_MAX: %e\n", DBL_MAX);
	printf("LDBL_MAX: %Le\n", LDBL_MAX);

	
    printf("limits by computation:\n");
    char c = 1;
    char d = 0;
    while( c > d ){
		d = c;
        c = c << 1;
        c = c | 01;
//        printf("c: %u d: %u\n",c ,d);
    }
    printf("CHAR_MAX: %u\n", d);
	return 0;
}

