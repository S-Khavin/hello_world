/*
	Read five names into a vector<string> name, then prompt the user for the ages of the people named and store the ages in a
	vector<double> age. Then print out the five (name[i],age[i]) pairs. Sort the names (sort(name.begin(),name.end())) and print
	out the (name[i],age[i]) pairs. The tricky part here is to get the age vector in the correct order to match the sorted name vector.
	Hint: Before sorting name, take a copy and use that to make a copy of age in the right order after sorting name.

	Do the previous exercise but allow an arbitrary number of names.
*/

// This program get names and age and short them and outputs to the screen

#include "PPP.h"

void print_vector_pair(string s, const vector<string>& v1, const vector<int>& v2)
{
	cout << s << ":-\n";
	for (int i = 0; i < v1.size(); ++i)
		cout << v1[i] << v2[i] << '\n';
}

int main()
{
	try {
		vector<string> name;

		for (string s; ; ) {
			cin >> s;
			if (s == "NoName")
				break;
			name.push_back(s);
		}
		cout << '\n';

		vector<int> age;
		for (string s : name)
		{
			cout << "age of " << s << ": ";
			int x = 0;
			cin >> x;
			age.push_back(x);
		}

		print_vector_pair("name and age", name, age);

		vector<string> copy_name = name;
		//ranges::sort(name.begin(), name.end());	// traditional way to sort
		ranges::sort(name);							// modern way to sort

		vector<int> copy_age;
		
		for (int i = 0; i < name.size(); ++i)
			for (int j = 0; j < copy_name.size(); ++j)
				if (name[i] == copy_name[j])
					copy_age.push_back(age[j]);

		print_vector_pair("name and age", name, copy_age);

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