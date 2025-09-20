 /* Write a program that doesn’t do anything, but declares a number of variables with legal and illegal names
(such as int double = 0;), so that you can see how the compiler reacts. */

// This is a simple program to exercise legal and illegal names

#include "PPP.h";

int main()
{
	// legal names
	int count = 0;
	double length_in_cm = 2.54;
	string name = "Khavin";
	char letter = 's';

	// illegal names
	int 2count = 0;
	int length in cm = 2.54;
	string string = "Khavin";
	char #letter = 's';
}