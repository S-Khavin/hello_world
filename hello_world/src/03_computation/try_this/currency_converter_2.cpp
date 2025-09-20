/*Rewrite your currency converter program from the previous TRY THIS to use a switch-statement. 
Add a conversion from Swiss francs. Which version of the program is easier to write, understand,
and modify? Why?*/

// This program converts yen, kroner, pounds and swiss francs into dollars.
// suffix 'y' or 'k' or 'p' or 's' indicates the currency: yen, kroner, pounds or swiss francs

#include "PPP.h";

int main()
{
	constexpr double yep_per_dollar = 147.07;			// number of yen per dollar
	constexpr double kroner_per_dollar = 10.05;			// number of kroner per dollar
	constexpr double pounds_per_dollar = 0.74;			// number of pounds per dollar
	constexpr double swiss_francs_per_dollar = 0.80;	// number of swiss francs per dollar
	double amount = 0;
	char currency = ' ';
	cout << "Please enter an amount followed by currency (y or k or p or s):\n";
	cin >> amount >> currency;

	switch (currency) {
	case 'y':
		cout << amount << " yen == " << amount / yep_per_dollar << " dollar\n";
		break;

	case 'k':
		cout << amount << " kroner == " << amount / kroner_per_dollar << " dollar\n";
		break;

	case 'p':
		cout << amount << " pounds == " << amount / pounds_per_dollar << " dollar\n";
		break;

	case 's':
		cout << amount << " swiss francs == " << amount / swiss_francs_per_dollar << " dollar\n";
		break;

	default:
		cout << "Sorry, I don't know a currency called '" << currency << "'\n";
	}
}

// Which version of the program is easier to write, understand, and modify ? Why ?
//The switch version is easier to write, understand, and modify because of its readability.