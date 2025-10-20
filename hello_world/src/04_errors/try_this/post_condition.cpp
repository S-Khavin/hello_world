 /*Try This
	Find a pair of values so that the precondition of this version of area holds, but the postcondition doesn’t.*/


// This program is to find a pair of values so that the precondition of this version of area holds, but the postcondition doesn’t

#include "PPP.h"

int area(int length, int width)
	// the arguments are positive
{
	expect([&] { return 0 < length && 0 < width; }, "bad arguments to area()");
	int a = length * width;
	expect([&] { return 0 < a; }, "bad area() result");
	return a;
}

int main()
{
	try {
		cout << "Area == " << area(1000000000, 1000000000);
		return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops! unknown exception!\n";
		return 2;
	}
}