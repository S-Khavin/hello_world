/* Do exercise 6, but with three string values. So, if the user enters the values Steinbeck, Hemingway, Fitzgerald, the output
should be Fitzgerald, Hemingway, Steinbeck. */

// This program outputs the given three string in a lexographical sequence to the screen.

#include "PPP.h";

int main()
{
	cout << "Please enter three string value seperated by 'space' : ";
	string string_1;
	string string_2;
	string string_3;
	cin >> string_1 >> string_2 >> string_3;
	string small;
	string middle;
	string large;

	if (string_1 <= string_2 && string_1 <= string_3)
		small = string_1;
	if (string_2 <= string_1 && string_2 <= string_3)
		small = string_2;
	if (string_3 <= string_1 && string_3 <= string_2)
		small = string_3;

	if (small == string_1 && string_2 <= string_3)
		middle = string_2;
	if (small == string_1 && string_2 <= string_3)
		large = string_3;
	if (small == string_1 && string_2 >= string_3)
		middle = string_3;
	if (small == string_1 && string_2 >= string_3)
		large = string_2;

	if (small == string_2 && string_1 <= string_3)
		middle = string_1;
	if (small == string_2 && string_1 <= string_3)
		large = string_3;
	if (small == string_2 && string_1 >= string_3)
		middle = string_3;
	if (small == string_2 && string_1 >= string_3)
		large = string_1;

	if (small == string_3 && string_2 <= string_1)
		middle = string_2;
	if (small == string_3 && string_2 <= string_1)
		large = string_1;
	if (small == string_3 && string_2 >= string_1)
		middle = string_1;
	if (small == string_3 && string_2 >= string_1)
		large = string_2;

	cout << small << ", " << middle << ", " << large << ".\n";

}