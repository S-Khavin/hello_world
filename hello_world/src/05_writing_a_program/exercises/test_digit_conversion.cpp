#include "PPP.h"

int convert_string_digit_to_int(string digits) {

	bool isHex = false;
	digits = tolower(digits);
	cout << "digits == " << digits;
	if (digits.find("A") || digits.find("B") || digits.find("C") || digits.find("D") || digits.find("E") || digits.find("F"))
		isHex = true;

	for (int i = digits.size() - 1; i >= 0; --i)
		cin.putback(digits[i]);

	int num = 0;
	cin >> num;
	return num;
}

int main()
{
	//string digits = "123";
	//int value = convert_string_digit_to_int(digits);
	float test = 0xa;
	cout << test << '\n';
}