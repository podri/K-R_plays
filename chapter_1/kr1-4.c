#include <stdio.h>
/* Exercise 1-4. Write a program to print
 * the corresponding Celsius to Fahrenheit table.
 */	
main()
{
  float fahr, celsius;
  float lower, upper, step;
  lower = 0;       /* lower limit of temperatuire scale */
  upper = 100;     /* upper limit */
  step = 10;       /* step size */
  celsius = lower;
  printf(" °C     °F\n");
  printf("----------\n");
  while (celsius <= upper) {
     // celsius = (5.0/9.0) * (fahr-32.0);
	  fahr = (9.0/5.0) * celsius + 32.0;
      printf("%3.0f %6.1f\n", celsius, fahr);
      celsius = celsius + step;
  }
}

