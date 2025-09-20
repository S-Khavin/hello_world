 /* Write a program that prompts the user to enter two integer values.Store these values in int variables named val1 and val2.
Write your program to determine the smaller, larger, sum, difference, product, and ratio of these values and report them to the user. */

 /* Modify the program above to ask the user to enter floatingpoint values and store them in double variables. Compare the outputs 
of the two programs for some inputs of your choice. Are the results the same ? Should they be ? What’s the difference ? */

// This program prints the smaller, larger, sum, difference, product, and ratio of two integer on the screen.

#include "PPP.h";

int main()
{
	cout << "Please enter two integer value seperated by 'space' : ";
	double value_1 = 0;
	double value_2 = 0;
	cin >> value_1 >> value_2;

	if (value_1 < value_2)
		cout << "Smaller == " << value_1 << '\n';
	if (value_1 < value_2)
		cout << "Larger == " << value_2 << '\n';

	if (value_1 > value_2)
		cout << "Smaller == " << value_2 << '\n';
	if (value_1 > value_2)
		cout << "Larger == " << value_1 << '\n';

	cout << "Sum == " << value_1 + value_2 
		<< "\nDifference == " << value_1 - value_2 
		<< "\nProduct == " << value_1 * value_2
		<< "\nRatio == " << value_1 / value_2 
		<< '\n';
}

// Are the results the same ? No
// Should they be ? No
// What’s the difference ? The ratio gives the value in approximate precision but in int it the decimal part is not there.