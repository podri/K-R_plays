/* Exercise 1-14. Write a program to print a histogram of the frequencies
 * of different characters in its input.
 */
#include <stdio.h>
main()
{
    int c, i, max=0;
    int ndigit[10];
    int nchar[26];
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;
    for (i = 0; i < 26; ++i)
        nchar[i] = 0;
    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c >= 'a' && c <= 'z')
            ++nchar[c-'a'];
		else if (c >= 'A' && c <= 'Z')
			++nchar[c-'A'];
	//histogram
	for(i = 0; i < 10; ++i)
		if (ndigit[i] > max) max = ndigit[i]; 
	for(i = 0; i < 26; ++i)
		if (nchar[i] > max) max = nchar[i]; 
	int k = 0;
	for(k = max; k > 0; --k){
		for(i = 0; i < 10; ++i)
			if (ndigit[i] >= k) printf(" |");
			else printf("  ");
		for(i = 0; i < 26; ++i)
			if (nchar[i] >= k) printf(" |");
			else printf("  ");
		printf("\n");
	}
    for (i = 0; i < 10; ++i)
        printf(" %d", i);
	for(i = 0; i < 26; ++i)
        printf(" %c", i+'a');
	printf("\n");
	//
}

