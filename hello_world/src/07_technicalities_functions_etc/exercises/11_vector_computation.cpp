/*
	Write a function that finds the smallest and the largest element of a vector argument and also computes the mean and the
	median. Do not use global variables. Either return a struct containing the results or pass them back through reference
	arguments. Which of the two ways of returning several result values do you prefer and why?
*/

// This program finds the smallest, largest, mean and median from a sequence of data.

#include "PPP.h"

struct Stats {
	double min;
	double max;
	double mean;
	double median;
};

Stats compute_vector(vector<double>& v)
{
	ranges::sort(v);	// sort v for further computation
	
	Stats s;

	// find min and max
	s.min = v[0];
	s.max = v[v.size() - 1];

	// calculates mean
	double sum = 0;
	for (const double& d : v)
		sum += d;
	double mean = sum / v.size();
	s.mean = mean;

	// calculates median
	if (v.size() % 2 != 0)
		s.median = v[v.size() / 2];
	else
	{
		double numerator = v[v.size() / 2 - 1] + v[v.size() / 2];
		s.median = numerator / 2;
	}

	return s;
}

int main() {
	try {
		cout << "Enter sequence of floating-point values followed by '|' and press 'Enter' :-\n";
		vector<double> values;
		for (double d; cin >> d; )
			values.push_back(d);

		Stats s = compute_vector(values);

		cout << "Smallest == " << s.min << '\n'
			<< "Largest == " << s.max << '\n'
			<< "Mean == " << s.mean << '\n'
			<< "Median == " << s.median << '\n';
		
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