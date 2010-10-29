#include <stdio.h>
void flush_quote(int mark);
void comment(int com_start);
int main(){
	int c, d ;	
	while ((c = getchar()) != EOF){
		if (c == '\'' || c == '\"') flush_quote(c);
		else if (c != '/' || c == '\\') putchar(c);
		else {
				if ((d = getchar()) != '/' && d != '*')
					{putchar(c);putchar(d);}
				else comment(d);
			 }
	}

}

/*blabla*/
void flush_quote(int mark){
	int ch, bh = '\0';
	putchar(mark);
	while ( !((ch = getchar()) == mark && bh != '\\')){
			putchar(ch);
			bh = ch;}/*  we need only this
	because the outer quoting sign quotes the other type if that is placed
	inner - like: 'bla bla "other" xxx'
	sigle quote without embedded in the other can exist only in comments:
	yes, i'm sure :)*/ 
	putchar(ch);//the end-quote must out too
	return;
}

void comment(int com_start){
	int ch;
	if (com_start == '/')
		while (getchar() != '\n');//in case of "//" to the line-end 
	if (com_start == '*')
		while ( !(getchar() == '*' && getchar() == '/') );/* 2 characters must be checked
															one after the other */
	return;			
}
