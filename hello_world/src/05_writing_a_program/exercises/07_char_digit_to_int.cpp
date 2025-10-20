 /*[7] Write a program that reads digits and composes them into integers. For example, 123 is read as the characters 1, 2, and 3.
The program should output 123 is 1 hundred and 2 tens and 3 ones. The number should be output as an int value. Handle
numbers with one, two, three, or four digits. Hint: To get the integer value 5 from the character '5' subtract '0', that is,
'5'−'0' == 5.*/


// This program reads upto 4 digits and print its integer value and its spelled-out words.

#include "PPP.h"

int convert_string_digit_to_int(string digits) {
	expect([&] { return digits.length(); }, "unexpected argument to convert_string_digit_to_int.");
	for (int i = digits.size() - 1; i >= 0; --i)
		cin.putback(digits[i]);

	int num = 0;
	cin >> num;
	return num;
}

int main(){
	try {
		float test = 0x12;
		cout << test << '\n';
		// reads string of digits (getting sequence of characters is easier using string):
		string digits;
		cin >> digits;

		if (!cin)
			error("unable to read digits in main()");
		if (!(digits.size() <= 4))
			error("numbers upto four digits is expected");

		// converts string digits to integer value and prints:
		int num = convert_string_digit_to_int(digits);
		cout << num;

		// stores each character as integer value (to output each integer seperately):
		vector<int> values;
		for (char ch : digits)
			values.push_back(ch - '0');

		// stores each digits to its corresponding place value:
		int thousand = 0;
		if(values.size() >= 4) thousand = values[values.size() - 4];
		int hundred = 0;
		if (values.size() >= 3) hundred = values[values.size() - 3];
		int ten = 0;
		if (values.size() >= 2) ten = values[values.size() - 2];
		int one = 0;
		if (values.size() >= 1) one = values[values.size() - 1];

		// outputs number with its place value:
		switch (digits.size()) {
		case 4:
			if (thousand)
			{
				cout << thousand;
				if (thousand > 1) cout << " thousands";
				else cout << " thousand";
			}
			[[fallthrough]];
		case 3:
			if (thousand && hundred)
				cout << " and ";
			if (hundred)
			{
				cout << hundred;
				if (hundred > 1) cout << " hundreds";
				else cout << " hundred";
			}
			[[fallthrough]];
		case 2:
			if (hundred && ten)
				cout << " and ";
			if (ten)
			{
				cout << ten;
				if (ten > 1) cout << " tens";
				else cout << " ten";
			}
			[[fallthrough]];
		case 1:
			if (ten && one)
				cout << " and ";
			if (one)
			{
				cout << one;
				if (one > 1) cout << " ones";
				else cout << " one";
			}
			break;
		default:
			error("Sorry, we handle only numbers upto 4 digits");
		}

		cout << '\n';
		return 0;
	}
	catch (exception& e)
	{
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...)
	{
		cerr << "Oops: unknown exception!\n";
		return 2;
	}
}