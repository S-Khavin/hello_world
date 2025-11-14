/*
	[3] Create a module foo with the suffix appropriate to your system :

		int foo = 0;
		export void print_foo() { ... };
		export void set_foo(int x} { foo = x; }
		export int get_foo() { return x; }
	
	Add what it takes to get the ... part to print foo. Write file use.cpp that imports foo and tests it.Get the resulting program 
	to compile and run.
*/

import foo;
#include "PPP.h";

int main() {
	print_foo();
	set_foo(10);
	print_foo();
	int foo = get_foo();
	cout << foo << '\n';
}