export module foo;			// we are defining a module called "foo"

#include "PPP.h"

int foo = 0;

export void print_foo() 
{ 
	cout << "foo == " << foo << '\n';
};

export void set_foo(int x) 
{
	foo = x; 
}

export int get_foo() 
{ 
	return foo; 
}