/*
	Write a function that given two vector<double>s price and weight computes a value (an “index”) that is the sum of all
	price[i]*weight[i]. Make sure to have weight.size()==price.size().
*/

// This program gets prices and weights and outputs the sum of all prince[i]*weight[i] to the screen.

#include "PPP.h"

double compute_index(const vector<double>& price, const vector<double>& weight)
{
	expect([&] {return price.size() == weight.size(); }, "unexpected argument in compute_index");
	double sum = 0;
	for (int i = 0; i < price.size(); ++i)
		sum += price[i] * weight[i];
	return sum;
}

int main() 
{
	try {
		cout << "Enter sequence of prices followed by space : ";
		vector<double> price;
		for (double d;;)
		{
			cin >> d;
			if (d == -1)
				break;
			price.push_back(d);
		}
		cout << '\n';

		cout << "Enter corresponding of weights followed by space : ";
		vector<double> weight;
		for (double d;;)
		{
			cin >> d;
			if (d == -1) 
				break;
			weight.push_back(d);
		}
		cout << '\n';

		double sum = compute_index(price, weight);

		cout << "The computed value == " << sum << '\n';

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