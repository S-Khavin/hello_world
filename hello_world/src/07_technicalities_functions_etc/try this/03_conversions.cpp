/*
	Try This
	
	Try examples like the ones above converting all combinations of an int, a double, and a char.Use values
	1001, 7.7, and 'x'.Try with implicit conversion and narrow.Write out the results for the cases where the
	program compiles.What errors and warnings did you get ?
*/

#include "PPP.h"

void int_to_double(int x)
{
	double d = narrow<double>(x);
	cout << "int " << x << " == double " << d << '\n';
}

void double_to_int(double d)
{
	int x = narrow<int>(d);
	cout << "double " << d << " == int " << x << '\n';
}

void int_to_char(int x)
{
	char ch = narrow<char>(x);
	cout << "int " << x << " == char " << ch << '\n';
}

void char_to_int(char ch)
{
	int x = narrow<int>(ch);
	cout << "char " << ch << " == int " << x << '\n';
}

void double_to_char(double d)
{
	char ch = narrow<char>(d);
	cout << "double " << d << " == char " << ch << '\n';
}

void char_to_double(char ch)
{
	double d = narrow<double>(ch);
	cout << "char " << ch << " == double " << d << '\n';
}

int main() {
	try {
		int x = 1001;
		double d = 7.7;
		char ch = 'x';

		int_to_double(x);
		//double_to_int(d);		// error: narrowing_error
		//int_to_char(x);		// error: narrowing_error
		char_to_int(ch);		
		//double_to_char(d);		// error: narrowing_error
		char_to_double(ch);

		return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops: unexpected error occured!\n";
		return 2;
	}
}