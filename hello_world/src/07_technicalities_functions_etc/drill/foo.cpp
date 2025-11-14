#include "PPP.h"
#include "foo.h"

int foo = 10;

void print_foo()
{
	cout << "foo == " << foo << '\n';
};

void print(int x)
{
	cout << x << '\n';
}

void set_foo(int x) {
	foo = x;
}

auto bar() -> decltype(random_int(10))
{
	return random_int(10);
}