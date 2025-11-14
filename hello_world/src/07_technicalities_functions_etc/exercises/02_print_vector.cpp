
// Write a function print() that prints a vector of ints to cout.Give it two arguments : a string for “labeling” the output and a vector.


#include "PPP.h"

void print_vector(string s,const vector<int>& v)
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

int main()
{
	try {
		vector<int> values = { 1, 2, 3, 4 };
		print_vector("values", values);
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