/*	
	Try This
	Compile the three examples above to see how the compiler complains.Then add a definition of f() to get a running version.
*/

import std;			// we find the declaration of cout in here

int f(int);

int f(int x) {
	return x * x;
}

int main()
{
	int i = 7;
	std::cout << f(i) << '\n';
}