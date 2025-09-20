 /*Use the example above as a model for a program that converts yen('y'), kroner('k'), and pounds('p') 
 into dollars.If you like realism, you can find conversion rates on the Web.*/

// This program converts yen, kroner, and pounds into dollars.
// suffix 'y' or 'k' or 'p' indicates the currency: yen, kroner, or pounds

#include "PPP.h";

int main()
{
	constexpr double yep_per_dollar = 147.07;	// number of yen per dollar
	constexpr double kroner_per_dollar = 10.05;	// number of kroner per dollar
	constexpr double pounds_per_dollar = 0.74;  // number of pounds per dollar
	double amount = 0;
	char currency = ' ';
	cout << "Please enter an amount followed by currency (y or k or p):\n";
	cin >> amount >> currency;
	if (currency == 'y')
		cout << amount << " yen == " << amount / yep_per_dollar << " dollar\n";
	else if (currency == 'k')
		cout << amount << " kroner == " << amount / kroner_per_dollar << " dollar\n";
	else if (currency == 'p')
		cout << amount << " pounds == " << amount / pounds_per_dollar << " dollar\n";
	else
		cout << "Sorry, I don't know a currency called '" << currency << "'\n";
}