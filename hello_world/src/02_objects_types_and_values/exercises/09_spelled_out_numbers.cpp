 /*Write a program that converts spelled - out numbers such as “zero” and “two” into digits, such as 0 and 2. When the user
inputs a number, the program should print out the corresponding digit.Do it for the values 0, 1, 2, 3, and 4 and
write out not a number I know if the user enters something that doesn’t correspond, such as stupid computer!.*/

// This program outputs the spelled-out numbers into digits for 0, 1, 2, 3 and 4 only.

#include "PPP.h";

int main()
{
	cout << "Enter a spelled-out number : ";
	string spelled_out_number;
	cin >> spelled_out_number;

	if (spelled_out_number == "zero")
		cout << "The digit is == 0. \n";
	if (spelled_out_number == "one")
		cout << "The digit is == 1. \n";
	if (spelled_out_number == "two")
		cout << "The digit is == 2. \n";
	if (spelled_out_number == "three")
		cout << "The digit is == 3. \n";
	if (spelled_out_number == "four")
		cout << "The digit is == 4. \n";
	if (spelled_out_number != "zero" && spelled_out_number != "one" && spelled_out_number != "two" && spelled_out_number != "three" && spelled_out_number != "four")
		cout << "not a number I know. \n";
}