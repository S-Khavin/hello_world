 /* Write a program that prompts the user to enter three integer values, and then outputs the values in numerical sequence
separated by commas.So, if the user enters the values 10 4 6, the output should be 4, 6, 10. If two values are the same, they 
should just be ordered together.So, the input 4 5 4 should give 4, 4, 5. */

// This program outputs the given three integer in a numerical sequence to the screen.

#include "PPP.h";

int main()
{
	cout << "Please enter three integer value seperated by 'space' : ";
	int value_1 = 0;
	int value_2 = 0;
	int value_3 = 0;
	cin >> value_1 >> value_2 >> value_3;
	int small = 0;
	int middle = 0;
	int large = 0;

	if (value_1 <= value_2 && value_1 <= value_3)
		small = value_1;
	if (value_2 <= value_1 && value_2 <= value_3)
		small = value_2;
	if (value_3 <= value_1 && value_3 <= value_2)
		small = value_3;

	if (small == value_1 && value_2 <= value_3)
		middle = value_2;
	if (small == value_1 && value_2 <= value_3)
		large = value_3;
	if (small == value_1 && value_2 >= value_3)
		middle = value_3;
	if (small == value_1 && value_2 >= value_3)
		large = value_2;

	if (small == value_2 && value_1 <= value_3)
		middle = value_1;
	if (small == value_2 && value_1 <= value_3)
		large = value_3;
	if (small == value_2 && value_1 >= value_3)
		middle = value_3;
	if (small == value_2 && value_1 >= value_3)
		large = value_1;

	if (small == value_3 && value_2 <= value_1)
		middle = value_2;
	if (small == value_3 && value_2 <= value_1)
		large = value_1;
	if (small == value_3 && value_2 >= value_1)
		middle = value_1;
	if (small == value_3 && value_2 >= value_1)
		large = value_2;

	cout << small << ", " << middle << ", " << large << ".\n";
	 
}