#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	int n;
	n = rand() % 13; 		//Only allowing 13 characters: [, (, {,  , a, x, }, ), ], r, e, s, t
	if(n == 0)  return '[';
	if(n == 1)  return '(';
	if(n == 2)  return '{';
	if(n == 3)  return ']';
	if(n == 4)  return ')';
	if(n == 5)  return '}';
	if(n == 6)  return 'x';
	if(n == 7)  return 'r';
	if(n == 8)  return 'e';
	if(n == 9)  return 's';
	if(n == 10) return 't';
	if(n == 11) return 'a';
	return ' ';		 	//Each number corresponds to a character that testme() does something with
}

char *inputString()
{
	char s[6];			//Use inputChar() to populate a string that matches the size of "reset" which ends the program in an error
	int i;
	for(i = 0; i < 4; i++){
		s[i] = inputChar();
	}
	return s;
}

void testme()
{
	int tcCount = 0;
	char *s;
	char c;
	int state = 0;
	while(1)
	{
		tcCount++;
		c = inputChar();
		s = inputString();
		printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);
		
		if (c == '[' && state == 0) state = 1;
		if (c == '(' && state == 1) state = 2;
		if (c == '{' && state == 2) state = 3;
		if (c == ' ' && state == 3) state = 4;
		if (c == 'a' && state == 4) state = 5;
		if (c == 'x' && state == 5) state = 6;
		if (c == '}' && state == 6) state = 7;
		if (c == ')' && state == 7) state = 8;
		if (c == ']' && state == 8) state = 9;
		if (s[0] == 'r' && s[1] == 'e' && s[2] == 's' && s[3] == 'e' && s[4] == 't' && s[5] == '\0' && state == 9)
		{
			printf("error ");
			exit(200);
		}
	}
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	testme();
	return 0;
}
