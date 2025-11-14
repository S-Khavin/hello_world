#include "PPP.h"

int main()
{
	// int digit to its equivalent char digit
	int x = 9;
	int y = '0' + x;
	char ch = y;
	cout << ch << '\n';

	// int digit to its equivalent string
	int z = 29;
	string s = "";
	s += to_string(z);
	cout << s;
}