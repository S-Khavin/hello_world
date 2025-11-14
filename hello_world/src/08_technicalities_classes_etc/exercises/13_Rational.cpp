/*
	Design and implement a rational number class, Rational. A rational number has two parts : a numerator and a
	denominator, for example, 5 / 6 (five - sixths, also known as approximately .83333).Look up the definition if you need to.
	Provide assignment, addition, subtraction, multiplication, division, and equality operators. Also, provide a conversion to
	double. Why would people want to use a Rational class ?
*/

#include "PPP.h"

class Rational {
public:
	class Invalid {};
	Rational(int numerator, int denominator);
	Rational(int numerator);
	int numerator() const { return n; }
	int denominator() const { return d; }
	double to_double() const { return double(n) / d; }

private:
	int n = 0;
	int d = 1;
};

Rational::Rational(int numerator, int denominator)
	: n{numerator}, d{denominator}
{
	if (denominator == 0) throw Invalid{};
}

Rational::Rational(int numerator)
	: n{numerator}
{
}

Rational common_denominator_fraction(Rational& a, int lcm)
{
	int factor_a = lcm / a.denominator();
	return Rational { a.numerator() * factor_a, a.denominator() * factor_a };
}

int find_lcm(Rational& a, Rational& b)
{
	int n = a.denominator() * b.denominator();
	int d = gcd(a.denominator(), b.denominator());
	return n / d;
}
Rational operator+(Rational a, Rational b)
{
	if (a.denominator() == b.denominator())
		return Rational { a.numerator() + b.numerator() , a.denominator() };

	int leastcm = find_lcm(a, b);

	Rational adjust_a = common_denominator_fraction(a, leastcm);
	Rational adjust_b = common_denominator_fraction(b, leastcm);
	
	return Rational{ adjust_a.numerator() + adjust_b.numerator() , adjust_a.denominator() };
}

Rational operator-(Rational& a, Rational& b)
{
	if (a.denominator() == b.denominator())
		return Rational{ a.numerator() - b.numerator() , a.denominator() };

	int leastcm = find_lcm(a, b);

	Rational adjust_a = common_denominator_fraction(a, leastcm);
	Rational adjust_b = common_denominator_fraction(b, leastcm);

	return Rational{ adjust_a.numerator() - adjust_b.numerator() , adjust_a.denominator() };
}

Rational operator*(Rational& a, Rational& b)
{
	int n = a.numerator() * b.numerator();
	int d = a.denominator() * b.denominator();
	return Rational{ n, d };
}

Rational operator/(Rational& a, Rational& b)
{
	int n = a.numerator() * b.denominator();
	int d = a.denominator() * b.numerator();
	return Rational{ n, d };
}

bool operator==(Rational& a, Rational& b)
{
	return a.numerator() * b.denominator() == b.numerator() * a.denominator();
}

ostream& operator<<(ostream& os, Rational r)
{
	if (r.numerator() == 0)
		return os << r.numerator();
	return os << r.numerator() << '/' << r.denominator();
}

double operator*(Rational a, double b)
{
	return double(a.numerator()) / a.denominator() * b;
}

int main() {
	try {
		//Rational f1{ 1, 3 };
		//Rational f2{ 1, 3 };
		//Rational f3{ 1, 3 };
		//cout << (f1 + f2 + f3) * double(1000000);

		//Rational f2 = f1;
		//cout << f1 << '\n';
		//cout << "double conversion == " << f1.to_double() << '\n';

		//double x = 1.0 / 3;
	/*	cout << "sum 1 == " << 0.9999999 * 1;
		cout << "sum 2 == " << 0.9999999 * 10000000;
		cout << 3.0 / 3;*/

	/*	double x = 1 / 3.0;
		double sum = 1 / 3.0 + 1 / 3.0 + 0.4;*/

	/*	Rational r{ 1, 3 };
		cout << "d == " << d
			<< "\nr == " << */

		Rational r{ 22, 7 };
		cout << r.to_double();
		return 0;
	}
	catch (Rational::Invalid) {
		error("main(): invalid fraction");
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