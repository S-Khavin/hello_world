// This program computes sum of first N integers from a series of integers

#include "PPP.h"

double sum_upto_n_in_sequence(vector<double> x, int n)
	// the parameter x.size() and n is positive and n less than x.size()
{
	expect([&] { return 0 < x.size() && n <= x.size() && n > 0; }, "bad arguments to sum_upto_n_in_sequence()");
	double sum = 0;
	for (double i = 0; i < n; ++i)
		sum += x[i];

	// Post condition checks if the result is in type double or not
	expect([&] { return typeid(sum).name() == typeid(1.0).name() && sum >= 0; }, "bad sum_upto_n_in_sequence() result");
	return sum;
}


int main()
{
	try {
	cout << "Please enter the number of values you want to sum: ";
	int N = 0;
	cin >> N;
	if (!cin)
		error("Could not read N in main()");
	if (N <= 0)
		error("N cannot be 0");


	cout << "Please enter some integers (press '|' to stop): ";
	vector<double> num_sequence;
	for (double x; cin >> x;)
		num_sequence.push_back(x);


	double sum = sum_upto_n_in_sequence(num_sequence, N);


	cout << "The sum of the first " << N << " numbers ( ";
	for (int i = 0; i < N; ++i)
		cout << num_sequence[i] << " ";
	cout << ") is " << sum << '\n';


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
}