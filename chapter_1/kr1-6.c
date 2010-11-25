#include <stdio.h>
/* Exercsise 1-6. Verify that
 * the expression getchar() != EOF is 0 or 1.
 */

/* copy input to output but with wrong statement 
 * test can be like >cat kr1-6.c | ./kr1-6
 */

main()
{
    int c;
    while (c = getchar() != EOF) /*right: ((c=getchar())!=EOF*/
        printf("%d\n", c);
    printf("%d\n", c); /* the last value */
}

