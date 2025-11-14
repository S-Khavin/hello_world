
// Write versions of the functions from exercise 5, but with a vector<string>.

// This program reverse the order of elements using call by value and call by reference

#include "PPP.h"

void print_vector(string s, const vector<string>& v)
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

vector<string> reverse_v(vector<string> v)
{
	vector<string> rev;
	for (int i = v.size() - 1; i >= 0; --i)
		rev.push_back(v[i]);
	return rev;
}

void reverse_r(vector<string>& v)
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
		string temp = v[i];
		v[i] = v[j];
		v[j] = temp;

		++i;
		--j;
	}
}

int main()
{
	try {
		vector<string> str;
		for (string s; cin >> s;)
			str.push_back(s);

		vector<string> reverse_str = reverse_v(str);
		print_vector("reverse_value", reverse_str);

		reverse_r(str);
		print_vector("str", str);

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