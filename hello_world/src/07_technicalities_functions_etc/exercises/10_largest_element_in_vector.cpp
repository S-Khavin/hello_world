// Write a function maxv() that returns the largest element of a vector argument.

// This program prints the largest element of a vector


#include "PPP.h"

int maxv(vector<int>& v)
{
	expect([&] { return v.size() != 0; }, "unexpected argument to maxv");
	ranges::sort(v);
	return v[v.size() - 1];
}

int main()
{
	try {
		cout << "Enter sequence of values seperated by space (to stop reading press '|') : ";
		vector<int> value;

		for (int x; cin >> x;)
			value.push_back(x);

		int max_value = maxv(value);
		cout << "largest element of the vector == " << max_value << '\n';

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