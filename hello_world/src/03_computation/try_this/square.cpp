 /*Implement square() without using the multiplication operator; that is, 
 do the x* x by repeated addition (start a variable result at 0 and add x to it x times).
 Then run some version of “the first program” using that square()*/

// This program computes the square of a number using repeated addition

#include "PPP.h";

int square(int x)
	// return the square of x
{
	int sum = 0;
	for (int i = 1; i <= x; ++i)
		sum += x;
	return sum;
}

int main()
	// calculate and print a table of squares 0-99
{
	for (int i = 0; i < 100; ++i)
		cout << i << '\t' << square(i) << '\n';
}