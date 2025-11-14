/*
	Write two functions that reverse the order of elements in a vector<int>. For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1.
	The first reverse function should produce a new vector with the reversed sequence, leaving its original vector unchanged. The
	other reverse function should reverse the elements of its vector without using any other vectors (hint: swap).
*/

// This program reverse the order of elements using call by value and call by reference

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

vector<int> reverse_v(vector<int> v)
{
	vector<int> rev;
	for (int i = v.size() - 1; i >= 0; --i)
		rev.push_back(v[i]);
	return rev;
}

void reverse_r(vector<int>& v)
{
	//for (int i = 0; i < v.size() / 2; ++i)
	//{
	//	int temp = v[i];
	//	v[i] = v[v.size() - 1 - i];
	//	v[v.size() - 1 - i] = temp;
	//}

	int i = 0;
	int j = v.size() - 1;
	while (i < v.size() / 2)
	{
		int temp = v[i];
		v[i] = v[j];
		v[j] = temp;

		++i;
		--j;
	}
}

int main()
{
	try {
		vector<int> values;
		for (int x; cin >> x;)
			values.push_back(x);

		vector<int> reverse_value = reverse_v(values);
		print_vector("reverse_value", reverse_value);

		reverse_r(values);
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