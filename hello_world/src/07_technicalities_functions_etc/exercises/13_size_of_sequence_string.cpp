/*
	Write a function that takes a vector<string> argument and returns a vector<int> containing the number of characters in
	each string. Also find the longest and the shortest string and the lexicographically first and last string. How many separate
	functions would you use for these tasks? Why?
*/

/* 
	This program takes strings and gives numbers containing the number of characters in each
	it also finds the longest, shortest, lexicographically first, lexicographically last.
*/

#include "PPP.h"

struct Stats {
	vector<string> longest;		// using vector because more than one same length names could be found.
	vector<string> shortest;
	string lex_first;
	string lex_last;
};

vector<int> generate_no_of_characters_in_each_string(const vector<string>& v)
{
	expect([&] {return v.size() != 0; }, "unexpected argument in generate_no_of_characters_in_each_string()");
	vector<int> values;
	for (string s : v)
		values.push_back(s.size());

	return values;
}

Stats compute_stats(vector<string>& v)
{
	expect([&] {return v.size() > 1; }, "unexpected argument in compute_stats(), v's length must be greater than 1");
	Stats stats;
	vector<int> values = generate_no_of_characters_in_each_string(v);
	ranges::sort(values);

	for (string s : v)
	{
		if (values[0] == s.size()) stats.shortest.push_back(s);
		if (values[values.size() - 1] == s.size()) stats.longest.push_back(s);
	}

	ranges::sort(v);
	stats.lex_first = v[0];
	stats.lex_last = v[v.size() - 1];

	return stats;
}

int main()
{
	try {
		vector<string> str;
		for (string s;;)
		{
			cin >> s;
			if (!cin) error("unable to read sequence of vector\n");
			if (s == "NoName") break;
			str.push_back(s);
		}

		Stats stats = compute_stats(str);

		cout << "longest == ";
		for (string s : stats.longest)
			cout << s << " ";
		cout << '\n';

		cout << "shortest == ";
		for (string s : stats.shortest)
			cout << s << " ";
		cout << '\n';

		cout << "lexicographically first == " << stats.lex_first
			<< "\nlexicographically last == " << stats.lex_last << '\n';

		return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops, unexpected error occured!\n";
		return 2;
	}
}