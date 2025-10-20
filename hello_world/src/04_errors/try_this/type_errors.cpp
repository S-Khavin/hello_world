 /*Try This
	Try to compile those examples and see how the compiler responds.Try thinking of a few more errors yourself and try those.*/


// This program compile those examples and see how the compiler responds

#include "PPP.h"

int area(int length, int width); // calculate area of a rectangle

int main()
{
	int x0 = arena(7, 2); // error: undeclared function
	int x1 = area(7); // error: wrong number of arguments
	int x2 = area("seven", 2); // error: 1st argument has a wrong type
	string x3 = area(1, 2); // error: wrong type declared for the return type int
}