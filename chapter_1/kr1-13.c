/* Exercise 1-13. Write a program to print a histogram of the lengths
 * of words in its input. It is easy to draw the histogram with the bars horizontal;
 * a vertical orientation is more challenging.
 */
#include <stdio.h>
#define MAXLEN 20
main()
{
    int c, i;
    int nword[MAXLEN];
    for (i = 0; i < MAXLEN; ++i)
        nword[i] = 0;
	int len = 0;	//we use this as a counter for the length of the word
    while ((c = getchar()) != EOF){
   		if ((c >= '0' && c <= '9') || (c >='a' && c <='z') || (c >='A' && c <='Z')){
			++len;	
		}
		else if (len > 0){	/*this is the case of the first non-word character
							  after the last word character*/
			++nword[len - 1];		/*count +1 for this length*/
			len = 0;			/*by non-word zeroed the counter again*/
		}
	}

printf("histogram horizontal:\n");
for (i = 0; i < MAXLEN; ++i){
	printf("%2d : ", i + 1);
	int k;
	for (k=0; k < nword[i]; ++k)
		printf("-");
	printf("\n");
}


printf("\nhistogram vertical:\n");
int max = 0;
for(i = 0; i < MAXLEN; ++i)
	if (nword[i] > max) max = nword[i]; 
int k = 0;
for(k = max; k > 0; --k){
	for(i = 0; i < MAXLEN; ++i)
		if (nword[i] >= k) printf("  |");
		else printf("   ");
	printf("\n");
}
for (i = 0; i < MAXLEN; ++i)
	printf("%3d", i + 1);
printf("\n");

}

