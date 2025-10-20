// testing cin putback char and read as int.

#include "PPP.h"

int main()
{
	cin.putback('1');
	cin.putback('2');
	int a = 0;
	cin >> a;
	cout << a << '\n';		// outputs 21, because cin.putback pushes the char into a stack (LIFO).
}