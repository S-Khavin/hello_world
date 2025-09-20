 /*The character 'b' is char(’a’ + 1), 'c' is char(’a’ + 2), etc.Use a loop to write out 
a table of characters with their corresponding integer values :
a 97
b 98
...
z 122*/

// This program prints a table of characters with their corresponding integer values

#include "PPP.h";

int main()
// print a table of characters with their corresponding integer values
{
	int i = 0;
	while (char('a' + i) <= 'z')
	{
		cout << char('a' + i) << '\t' << 'a' + i << '\n';
		++i;
	}
}