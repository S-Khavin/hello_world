/*
	Create a vector of Fibonacci numbers and print them using the function from exercise 2. To create the vector, write a function,
	fibonacci(x, y, v, n), where integers x and y are ints, v is an empty vector<int>, and n is the number of elements to put into v; v[0]
	will be x and v[1] will be y.A Fibonacci number is one that is part of a sequence where each element is the sum of the two
	previous ones.For example, starting with 1 and 2, we get 1, 2, 3, 5, 8, 13, 21, ....Your fibonacci() function should make such
	a sequence starting with its x and y arguments.

	This program creates a vector of fibonacci and outputs it.
*/

#include "PPP.h"

void print_vector(string s, const vector<int>& v)
{
	cout << s << " == {";
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i];
		if (i != v.size() - 1)
			cout << ", ";
	}
	cout << "}\n";
}

void fibonacci(int x, int y, vector<int>& v, int n) 
{
	v.push_back(x);
	v.push_back(y);

	for (int i = 2; i <= n; ++i)
		v.push_back(v[i - 1] + v[i - 2]);
}

int main()
{
	try {
		vector<int> fibo;
		fibonacci(1, 2, fibo, 100);
		print_vector("fibonacci", fibo);
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