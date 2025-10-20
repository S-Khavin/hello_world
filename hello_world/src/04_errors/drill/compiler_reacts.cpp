// This program demonstrates how the compiler reacts to various errors.

#include "PPP.h"

int main()
try {
	// 1 
	cout << "Success!\n";


	// 2
	cout << "Success!\n";


	// 3
	cout << "Success" << "!\n";


	// 4
	cout << "Success!" << '\n';


	// 5
	int res = 7;
	vector<int> v(10);
	v[5] = res;
	cout << "Success!\n";


	// 6
	vector<int> v6(10);
	v6[5] = 7;
	if (v6[5] == 7)
		cout << "Success!\n";


	// 7
	if (1 + 1 == 2)
		cout << "Success!\n";
	else
		cout << "Fail!\n";


	// 8
	bool c = false;
	if (!c)
		cout << "Success!\n";
	else
		cout << "Fail!\n";


	// 9
	string s = "ape";
	bool c9 = "fool" > s;
	if (c9)
		cout << "Success!\n";


	// 10
	string s10 = "fool";
	if (s10 == "fool")
		cout << "Success!\n";


	// 11
	string s11 = "ape";
	if (s11 == "ape")
		cout << "Success!\n";


	// 12
	string s12 = "ape";
	if (s12 + "fool" == "apefool") 
		cout << "Success!\n";


	// 13
	vector<char> v13(5);
	for (int i = 0; i < v13.size(); ++i)
		cout << "Success!\n";


	// 14
	vector<char> v14(5);
	for (int i = 0; i < v14.size(); ++i)
	cout << "Success!\n";


	// 15
	string s15 = "Success!\n";
	for (int i = 0; i < s15.size(); ++i)
		cout << s15[i];


	// 16
	if (true) 
		cout << "Success!\n";
	else 
		cout << "Fail!\n";


	// 17
	int x = 2000;
	char c17 = x;
	if (c17 == char(2000))
		cout << "Success!\n";


	// 18
	string s18 = "Success!\n";
	for (int i = 0; i < s18.size(); ++i)
		cout << s18[i];


	// 19
	vector<int> v19(5);
	for (int i = 0; i < v19.size(); ++i)
		cout << "Success!\n";


	// 20
	int i = 0;
	int j = 9;
	while (i < 10)
		++i;
	if (j < i)
		cout << "Succes2s!\n";


	// 21
	int x21 = 2; 
	double d = 5.0 / x21 + 2; 
	if (d == 2 * x21 + 0.5) 
		cout << "Success!\n";



	// 22
	string s22 = "Success!\n";
	for (int i = 0; i < s22.size(); ++i)
		cout << s22[i];


	// 23
	i = 0;
	while (i < 10)
		++i;
	if (j < i)
		cout << "Success!\n";


	// 24
	int x24 = 4;
	double d24 = 10 / x24 + 6;
	if (d24 = 2 * x24 + 0.5)
		cout << "Success!\n";


	// 25
	cout << "Success!\n";

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	return 2;
}