/*
	Design and implement a Money class for calculations involving dollars and cents where arithmetic has to be accurate to the
	last cent using the 4/5 rounding rule (.5 of a cent rounds up; anything less than .5 rounds down). Represent a monetary
	amount as a number of cents in a long int, but input and output as dollars and cents, e.g., $123.45. Do not worry about
	amounts that don’t fit into a long int.

	Refine the Money class by adding a currency (given as a constructor argument). Accept a floating-point initializer as
	long as it can be exactly represented as a long int. Don’t accept illegal operations. For example, Money*Money doesn’t make
	sense, and USD1.23+DKK5.00 makes sense only if you provide a conversion table defining the conversion factor between U.S.
	dollars (USD) and Danish kroner (DKK).
*/

#include "PPP.h"

class Invalid_Currency {};
enum class Currency {
	INR, USD, DKK
};

vector<string> currency_tbl = { "INR", "USD", "DKK" };

vector<double> conversion_tbl = { 1, 88.57, 13.75 };

int to_int(Currency c)
{
	return static_cast<int>(c);
}

ostream& operator<<(ostream& os, Currency m)
{
	return os << currency_tbl[to_int(m)];
}


istream& operator>>(istream& is, Currency& m)
{
	string currency;
	is >> currency;
	if (currency.size() != 3) throw Invalid_Currency{};

	for (int i = 0; i < currency_tbl.size(); ++i)
		if (currency == currency_tbl[i])
		{
			m = Currency{ i };
			return is;
		}
	throw Invalid_Currency{};
}


class Money {
public:
	class Invalid {};
	Money(Currency currency, double amount);
	Money() {};

	bool is_valid_range(double amount) const;
	double amount() const { return double(c) / 100; }
	Currency currency() const { return cy; }

private:
	long int c = 0;		// default member initializer
	Currency cy;
};

bool Money::is_valid_range(double amount) const
{
	long int temp = amount;
	return 0 <= temp;
}

Money::Money(Currency currency, double amount)
	: cy {currency}
{
	c = round(amount * 100);
	if (!is_valid_range(c)) throw Invalid{};
}

ostream& operator<<(ostream& os, Money m)
{
	return os << currency_tbl[to_int(m.currency())] << m.amount();
}

Money operator+(Money& a, Money& b)
{
	double a_to_inr = a.amount() * conversion_tbl[to_int(a.currency())];
	double b_to_inr = b.amount() * conversion_tbl[to_int(b.currency())];
	double total = a_to_inr + b_to_inr;
	return Money{ a.currency(), total / conversion_tbl[to_int(a.currency())]};
}

Money operator-(Money& a, Money& b)
{
	double a_to_inr = a.amount() * conversion_tbl[to_int(a.currency())];
	double b_to_inr = b.amount() * conversion_tbl[to_int(b.currency())];
	if (a_to_inr < b_to_inr) error("unable to perform, subtracting more than money you have");
	double total = a_to_inr - b_to_inr;
	return Money{ a.currency(), total / conversion_tbl[to_int(a.currency())] };
}

istream& operator>>(istream& is, Money& m)
{
	string amount;
	is >> amount;			// reads amount as whole string eg: INR24.5

	// convert first three character in amount as Currency type
	if (!(amount.size() > 2)) throw Money::Invalid{};
	for (char i = 2; i >= 0; --i)
		is.putback(amount[i]);
	Currency temp;
	is >> temp;

	// convert character after Curreny in amount as double
	for (char i = amount.size() - 1; i >= 3; --i)
		is.putback(amount[i]);
	double d = 0;
	is >> d;

	m = Money{ temp, d };
	return is;
}

int main()
{
	try {
		//Money m1;
		//Money m2;

		//cout << "Enter money1 : ";
		//cin >> m1;
		//cout << "Enter money2 : ";
		//cin >> m2;
		//Money total = m1 + m2;
		//Money difference = m1 - m2;
		//cout << "total amount == " << total << '\n';
		//cout << "remaining == " << difference << '\n';

		Money m1 = { Currency::INR, double(22)/7 };
		cout << m1 << '\n';
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 2;
	}
	catch (...) {
		cerr << "Oops! unknown exception!\n";
		return 2;
	}
}