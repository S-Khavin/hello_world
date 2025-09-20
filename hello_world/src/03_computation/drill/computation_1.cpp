 /*Write a program that consists of a while - loop that(each time around the loop) reads in two ints and then prints them.Exit
the program when a terminating '|' is entered*/

// This program gets 2 int's in while loop and prints it.

#include "PPP.h";

int main()
	// while loop reads and prints 2 int
{
	constexpr double almost_equal = 1.0 / 100;	// 0.01
	double v1 = 0;
	double v2 = 0;
	cout << "Enter sequence of pair of values followed by space then press 'enter' : \n";
	while (cin >> v1 >> v2)
	{
		cout << '\n' << v1 << ' ' << v2 << '\n';
		if (v1 < v2)
			cout << "The smaller value is : " << v1
			<< "\nThe larger value is : " << v2 << '\n';
		else if (v1 > v2)
			cout << "The smaller value is : " << v2
			<< "\nThe larger value is : " << v1 << '\n';
		else
			cout << "the numbers are equal\n";

		if (v1 != v2 && v1 - v2 < almost_equal)			// checks if the difference is less than 0.01
			cout << "the numbers are almost equal\n\n";
	}
}