 /*[7] Make a vector holding the ten string values "zero", "one", . . . "nine".Use that in a program that converts a digit to its
corresponding spelled - out value; e.g., the input 7 gives the output seven.Have the same program, using the same input
loop, convert spelled - out numbers into their digit form; e.g., the input seven gives the output 7.*/

// This program converts digits to their corresponding spelled-out values and vice versa.

#include "PPP.h";

int main()
{
	vector<string> spelled_out_numbers = { "zero" ,"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

	// converts a digit to its corresponding spelled - out value
	cout << "Enter a sequence of digit (0 to 9) :-\n";
	for(int digit = 0; cin >> digit; )
		if (digit >= 0 && digit <= 9)
			cout << digit << " == " << spelled_out_numbers[digit] << '\n';
		else
			cout << "Sorry, I don't know spelled - out value for " << digit << '\n';

	// converts a spelled - out value to its corresponding digit
	cout << "Enter a sequence of spelled - out value (one to nine) :-\n";
	int digit = -1;
	string word;
	while (cin >> word)
	{
		for (int i = 0; i < spelled_out_numbers.size(); ++i)
			if (word == spelled_out_numbers[i])
				digit = i;
		if (digit != -1)
			cout << word << " == " << digit << '\n';
		else
			cout << "Sorry, I don't know a digit for the word " << word << '\n';

		digit = -1;
	}
}