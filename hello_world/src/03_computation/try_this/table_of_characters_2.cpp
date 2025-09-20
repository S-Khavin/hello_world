 /*Rewrite the character value example from the previous
TRY THIS to use a for - statement.Then modify your
program to also write out a table of the integer values
for uppercase letters and digits.*/

// This program prints a table of characters of lower case letters, uppercase letters and digits with their corresponding integer values

#include "PPP.h";

int main()
// print a table of characters with their corresponding integer values
{
	constexpr char start_lowercase = 'a';
	constexpr char start_uppercase = 'A';
	constexpr char start_digit = '1';

	// print table of lower case letter with its corresponding integer values
	for (int i = 0; char(start_lowercase + i) <= 'z'; ++i)
		cout << char(start_lowercase + i) << '\t' << start_lowercase + i << '\n';

	// print table of upper case letter with its corresponding integer values
	for (int i = 0; char(start_uppercase + i) <= 'Z'; ++i)
		cout << char(start_uppercase + i) << '\t' << start_uppercase + i << '\n';

	// print table of character digits with its corresponding integer values
	for (int i = 0; char(start_digit + i) <= '9'; ++i)
		cout << char(start_digit + i) << '\t' << start_digit + i << '\n';
}