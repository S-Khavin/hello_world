/*
	An int can hold integers only up to a maximum number. Find
	an approximation of that maximum number by using
	fibonacci().

	This program creates a vector of fibonacci upto maximum number that the integer can hold and outputs it.
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

void fibonacci(int x, int y, vector<int>& v)
{
	v.push_back(x);
	v.push_back(y);

	for (int i = 2; (v[i - 1] + v[i - 2]) > 0; ++i)
		v.push_back(v[i - 1] + v[i - 2]);
}

int main()
{
	try {
		vector<int> fibo;
		fibonacci(1, 2, fibo);
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