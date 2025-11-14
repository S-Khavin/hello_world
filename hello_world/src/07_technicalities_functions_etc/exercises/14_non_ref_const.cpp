/*
	Can we declare a non-reference function argument const (e.g., void f(const int);)? What might that mean? Why might we want
	to do that? Why don’t people do that often? Try it; write a couple of small programs to see what works.

	My answer :- 

		Yes! we can declare non-reference function argument const. 
		It means that the value copied (initialized) in function parameter does not needs to be changed within the function. 
		The people don't do that often because we could achive this by passing const-reference which is efficient than above.
*/

#include "PPP.h"

void f(const int x)
{
	cout << "x == " << x << '\n';
}

int f1(const int x)
{
	int y = x + 1;
	return y;
}

int main()
{
	try {
		int a = 1;
		f(a);
		cout << f1(a);
		return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops, unexpected error occured!\n";
		return 2;
	}
}