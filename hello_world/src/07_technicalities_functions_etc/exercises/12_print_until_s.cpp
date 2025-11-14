/*
	Improve print_until_s() from §7.4.2. Test it. What makes a good set of test cases? Give reasons. Then, write a print_until_ss()
	that prints until it sees a second occurrence of its quit argument.
*/

// This program outputs elements in vector upto the gives string.

#include "PPP.h"

void print_until_s(const vector<string>& v, string quit)	 // before the vector string is sent as "call by value"
// print until the string called "quit" is found
{
	expect([&] {return v.size() != 0; }, "unexpected argument in print_until_s");
	for (string s : v) {
		if (s == quit) {
			cout << quit << '\n';
			return;
		}
		cout << s << '\n';
	}
	cout << "Reached end in sequence, " << quit << " is not there\n";
}

void print_until_ss(const vector<string>& v, string quit)
// print until the second occurence of string called "quit" is found
{
	expect([&] {return v.size() != 0; }, "unexpected argument in print_until_ss");
	bool checked_first = false;
	for (string s : v) {
		if (s == quit)
		{
			cout << s << '\n';
			if (checked_first == true) return;
			checked_first = true;
		}
		cout << s << '\n';
	}

	if (!checked_first)
		cout << "Reached end in sequence, " << quit << " first occurence is even not there\n";
	else
		cout << "Reached end in sequence, " << quit << " second occurence of is not there\n";
}

int main()
{
	try {
		cout << "Enter sequence of string and enter NoName to finish reading :-\n";
		vector<string> str;
		for (string s;;)
		{
			cin >> s;
			if (!cin) error("unable to read sequence of vector\n");
			if (s == "NoName") break;
			str.push_back(s);
		}

		cout << "Enter the quit string to print upto : ";
		string quit;
		cin >> quit;
		if (!cin) error("unable to read quit string in main()\n");
		
		print_until_s(str, quit);
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

/* 
	Testcase:-

		positive:-
			v = bottle fan food bag NoName
			s = food

		negative:-
			v = empty
			s = empty

			v = bottle fan food bag NoName
			s = empty

			v = empty
			s = food

			v = 12 13 14 15 16 NoName
			s = 15

			v = 12 13 14 15 16 NoName
			s = 20

			v = bottle fan food bag NoName
			s = bottle

			v = bottle fan food bag NoName
			s = table

			v = this is just for testing NoName
			s = also this
*/