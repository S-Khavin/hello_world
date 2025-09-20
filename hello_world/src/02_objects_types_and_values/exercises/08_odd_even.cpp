 /* Write a program to test an integer value to determine if it is odd or even.As always, make sure your output is clear and
complete.In other words, don’t just output yes or no. Your output should stand alone, like The value 4 is an even number.
Hint : See the remainder(modulo) operator in §2.4. */

// This program determine whether the given integer value is odd or even

#include "PPP.h"

int main()
{
	cout << "Enter a integer value : ";
	int value = 0;
	cin >> value;

	if (value % 2 == 0)
		cout << "The value " << value << " is an even number.\n";
	if (value % 2 != 0)
		cout << "The value " << value << " is an odd number.\n";
}