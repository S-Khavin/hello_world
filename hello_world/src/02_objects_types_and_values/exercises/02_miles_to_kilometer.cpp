 /* Write a program in C++ that converts from miles to kilometers.Your program should have a reasonable prompt for
the user to enter a number of miles. Hint: A mile is1.609 kilometers */

// This program converts and prints miles in kilometers to the screen.

#include "PPP.h";

int main()
{
	cout << "Please enter number of miles : ";
	double mile = 0;
	cin >> mile;
	cout << mile << " mile == " << mile * 1.609 << " Kilometer\n";
}