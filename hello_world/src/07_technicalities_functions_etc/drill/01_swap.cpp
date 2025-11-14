/*
 [1] Write three functions swap_v(int, int), swap_r(int&, int&), and swap_cr(const int&, const int&).Each should have the body

 Click here to view code image
	{ int temp; temp = a, a = b; b = temp; }
 
 where a and b are the names of the arguments.
 
 Try calling each swap like this
 
	int x = 7;
	int y = 9;
	swap_ ? (x, y); // replace ? by v, r, or cr
	swap_ ? (7, 9);
	const int cx = 7;
	const int cy = 9;
	swap_ ? (cx, cy);
	swap_ ? (7.7, 9.9);
	double dx = 7.7;
	double dy = 9.9;
	swap_ ? (dx, dy);
	swap_ ? (7.7, 9.9);

 Which functions and calls compiled, and why ? After each swap that compiled, print the value of the arguments after the call to
 see if they were actually swapped. If you are surprised by a result, consult §7.5.
*/

#include "PPP.h"

void swap_v(int a, int b)					// call by value
{
	int temp; temp = a, a = b; b = temp;
}

void swap_r(int& a, int& b)					// call by reference
{
	int temp; temp = a, a = b; b = temp;
}


void swap_cr(const int& a, const int& b)	// call by const reference
{
	int temp; 
	temp = a;
	//a = b; 
	//b = temp;
}


void print_after_swap(int x, int y, string str)
{
	cout << str << ":\n"
		<< "x == " << x
		<< "\ny == " << y << "\n\n";
}

int main() {
	try {
		int x = 7;
		int y = 9;

		swap_v(x, y);						// copy is sent
		print_after_swap(x, y, "swap_v(x, y)");

		swap_r(x, y);						// actual x and y is also changed
		print_after_swap(x, y, "swap_r(x, y)");

		swap_cr(x, y);						// error in swap_cr
		print_after_swap(x, y, "swap_cr(x, y)");

		swap_v(7, 9);	// check in book what happens to 7, 9

		// swap_r(7, 9);	// 'void swap_r(int &,int &)': cannot convert argument 1 from 'int' to 'int &'

		// swap_cr(7, 9);

		const int cx = 7;
		const int cy = 9;

		swap_v(cx, cy);
		print_after_swap(cx, cy, "swap_v(cx, cy)");

		// swap_r(cx, cy);		// 'void swap_r(int &,int &)': cannot convert argument 1 from 'const int' to 'int &'
		// print_after_swap(cx, cy, "swap_r(cx, cy)");	

		swap_cr(cx, cy);
		print_after_swap(cx, cy, "swap_cr(cx, cy)");

		swap_v(7.7, 9.9);
		print_after_swap(cx, cy, "swap_v(7.7, 9.9)");

		//swap_r(7.7, 9.9);		// 'void swap_r(int &,int &)': cannot convert argument 1 from 'double' to 'int &'
		//print_after_swap(cx, cy, "swap_r(7.7, 9.9)");

		swap_cr(7.7, 9.9);
		print_after_swap(cx, cy, "swap_cr(7.7, 9.9)");

		double dx = 7.7;
		double dy = 9.9;

		swap_v(dx, dy);
		print_after_swap(dx, dy, "swap_v(dx, dy)");

		//swap_r(dx, dy);				// 'void swap_r(int &,int &)': cannot convert argument 1 from 'double' to 'int &'
		//print_after_swap(dx, dy, "swap_r(dx, dy)");

		swap_cr(dx, dy);				// no error: allows to convert 'double' to 'const int&'
		print_after_swap(dx, dy, "swap_cr(dx, dy)");

		swap_v(7.7, 9.9);
		print_after_swap(7.7, 9.9, "swap_v(7.7, 9.9)");
	
		//swap_r(7.7, 9.9);
		//print_after_swap(7.7, 9.9, "swap_r(7.7, 9.9)");

		swap_cr(7.7, 9.9);
		print_after_swap(7.7, 9.9, "swap_cr(7.7, 9.9)");


		return 0;
	}
	catch (exception& e)
	{
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...)
	{
		cerr << "Oops, unknown exception!\n";
		return 2;
	}
}

// Which functions and calls compiled, and why ?
	// swap_v and swap_r compiled because it does not have any const argument
	// swap_cr doesn't compile because it try's to change const reference variable

