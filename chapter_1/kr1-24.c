/* Exercise 1-24. Write a program to check a C program for rudimentary syntax
 * errors like unmatched parentheses, brackets and braces. Don't forget about
 * quotes, both single and double, escape sequences, and comments.
 * (This program is hard if you do it in full generality.)

 * The main idea of this little program is that
 * we use different dummy stacks for the 3 types of parentheses
 * the begin of the mark is sored as a negativ line number
 * the end of the mark is stored as a positiv line number
 *  --- quotes and comments are not handled yet ---
 */
#include <stdio.h>
#define MAXI 1024 //the max numbers of open parentheses
int line = 1; //the line number

//the stacks for the parentheses
int parenthes[MAXI];
int bracket[MAXI];
int brace[MAXI];
//
int end = 0;
//the levels of the stacks
int level_par = 0;
int level_bracket = 0;
int level_brace = 0;

void stack_init(int stack[]);
//the counting functions 
void count_par(int c);
void count_bracket(int c);
void count_brace(int c);
//the above functions call this general one with the right parameters
void count_mark(int mark, int s, int stack[], int *plevel);

//at the end this one lists the errors
void print_out(int err, int stack[], int mark);

int main(){
	int c;	
	stack_init(parenthes);
	stack_init(bracket);
	stack_init(brace);
	while ((c = getchar()) != EOF && !end ){
		if (c == '(' || c == ')') count_par(c);
		else if (c == '[' || c == ']') count_bracket(c);
		else if (c == '{' || c == '}') count_brace(c);
		if (c == '\n') line++;
	}
	
	print_out(level_par, parenthes, '(');
	print_out(level_bracket, bracket, '[');
	print_out(level_brace, brace, '{');
}

void stack_init(int stack[]){
	int i;	
	for (i = 0; i < MAXI; i++) stack[i] = 0;
	return;
}

//these functions give the type,the sign(+1 or -1) and stack to count_mark
void count_par(int c){
	int s = (c == '(') ? -1 : 1;
	count_mark(c, s, parenthes, &level_par);
}

void count_bracket(int c){
	int s = (c == '[') ? -1 : 1;
	count_mark(c, s, bracket, &level_bracket);
}

void count_brace(int c){
	int s = (c == '{') ? -1 : 1;
	count_mark(c, s, brace, &level_brace);
}

/*
 * count_mark counts and stores the unmatching parentheses
 *    mark: the type of the parenthes
 *       s: the sign
 *   stack: pointer to the appropriate stack for the parenthes
 *  plevel: pointer to the level of the stack
 */
void count_mark(int mark, int s, int stack[], int *plevel){
	int level = *plevel;
	if ( level == 0 && stack[level] == 0){
			stack[level] = (s * line);

	} else if ((s * stack[level]) > 0){ 
			++(*plevel);
			level = *plevel;
			stack[level] = (s * line);
	} else {
			stack[level] = 0;
			if (level != 0){
				--(*plevel);
				level = *plevel;
			}
	}
	//if we reach the maximum numbers of open parentheses
	if (level == MAXI - 1) { end = 1; print_out(MAXI, stack, mark);} 
}
void print_out(int err, int stack[], int mark){

	if (err == MAXI){
		printf("We have reached the max numbers of open %c !\n", mark);
		printf("The current situation is the following:\n");
		return;
	}
	int i = 0;
	while (stack[i] != 0){
		if (stack[i] < 0) stack[i] = - stack[i]; //change the linenumber to pos.
		//the [ ] and { } are not following each other in ASCII
		else if (mark > 40) mark +=2; else mark++;
		printf("unmatched %c at line %d\n", mark, stack[i]);
		i++;
	}
}
