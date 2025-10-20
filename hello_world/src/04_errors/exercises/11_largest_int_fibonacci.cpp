#include "PPP.h"

int largest_fibonacci_int() {
	int x1 = 1;
	int x2 = 1;
	int current_fibo = 0;
	
	while (x1 + x2 >= 0)				// if value overflow int, it becomes negative value.
	{
		current_fibo = x1 + x2;			// The sum of two previous one

		// updating values for next iteration
		x1 = x2;
		x2 = current_fibo;
	}

	expect([&] {return 0 <= current_fibo; }, "bad largest_fibonacci_int() result");
	return current_fibo;
}

int main()
{
	try {
		cout << "The largest fibonacci number that fits in an int == " << largest_fibonacci_int() << '\n';
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