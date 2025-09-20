/*[6] Write a program that performs as a very simple calculator. Your calculator should be able to handle the four basic math
operations – add, subtract, multiply, and divide – on two input values.Your program should prompt the user to enter three
arguments : two double values and a character to represent an operation.If the entry arguments are 35.6, 24.1, and '+', the
program output should be The sum of 35.6 and 24.1 is 59.7.In Chapter 5 and Chapter 6, we look at a much more
sophisticated simple calculator.*/

// [8] Modify the “mini calculator” from exercise 6 to accept(just) single - digit numbers written as either digits or spelled out.

// This program gets two double values and a operator to perform like a operation.

#include "PPP.h";

int main()
{
	/*cout << "Enter two double values and a character to represent an operation : ";
	double v1 = 0;
	double v2 = 0;
	char arithmetic_operator = ' ';
	cin >> v1 >> v2 >> arithmetic_operator;

	switch (arithmetic_operator)
	{
	case '+':
		cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << '\n';
		break;
	case '-':
		cout << "The difference of " << v1 << " and " << v2 << " is " << v1 - v2 << '\n';
		break;
	case '*':
		cout << "The product of " << v1 << " and " << v2 << " is " << v1 * v2 << '\n';
		break;
	case '/':
		cout << "The division of " << v1 << " and " << v2 << " is " << v1 / v2 << '\n';
		break;
	default:
		cout << "I don't know a operation called " << arithmetic_operator << '\n';
		break;
	}*/

	// modified the above to accept(just) single - digit numbers written as either digits or spelled out.
	cout << "Enter two single - digit numbers (written as either digits or spelled out) and a character to represent an operation : ";
	double v1 = -1;
	double v2 = -1;

	string s1;
	string s2;
	char arithmetic_operator = ' ';
	cin >> s1 >> s2 >> arithmetic_operator;

	// converts given string input to its corresponding digit:
	vector<string> spelled_out_numbers = { "zero" ,"one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	vector<string> digit_as_string = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	
	if (s1.size() == 1)
		for (int i = 0; i < digit_as_string.size(); ++i)
			if (s1 == digit_as_string[i])
				v1 = i;
			else;
	else
		for (int i = 0; i < spelled_out_numbers.size(); ++i)
			if (s1 == spelled_out_numbers[i])
				v1 = i;
			else;

	if (s2.size() == 1)
		for (int i = 0; i < digit_as_string.size(); ++i)
			if (s2 == digit_as_string[i])
				v2 = i;
			else;
	else
		for (int i = 0; i < spelled_out_numbers.size(); ++i)
			if (s2 == spelled_out_numbers[i])
				v2 = i;
			else;


	switch (arithmetic_operator)
	{
	case '+':
		cout << "The sum of " << s1 << " and " << s2 << " is " << v1 + v2 << '\n';
		break;
	case '-':
		cout << "The difference of " << s1 << " and " << s2 << " is " << v1 - v2 << '\n';
		break;
	case '*':
		cout << "The product of " << s1 << " and " << s2 << " is " << v1 * v2 << '\n';
		break;
	case '/':
		cout << "The division of " << s1 << " and " << s2 << " is " << v1 / v2 << '\n';
		break;
	default:
		cout << "I don't know a operation called " << arithmetic_operator << '\n';
		break;
	}
}