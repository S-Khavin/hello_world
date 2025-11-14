/*
	Drill

			Write Day, Month, and their associated functions as described above. Complete the final version of Date with default constructor,
		is_valid(), Month, Year, etc. Define a Date called today initialized to February 2, 2020. Then, define a Date called tomorrow and give it a
		value by copying today into it and increasing its day by one using add_day(). Finally, output today and tomorrow using a << defined as
		in §9.6 and §9.7.
			Your check for a valid date, is_valid(), may be very simple. Feel free to ignore leap years. However, don’t accept a month that is not
		in the [1,12] range or a day of the month that is not in the [1,31] range. Test each version with at least one invalid date (e.g., 2004,
		13, -5).
*/

#include "PPP.h"

enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

vector<string> month_tbl = { "Not a month", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int to_int(Month m)
{
	return static_cast<int>(m);
}

Month int_to_month(int x) 
	// checked conversion
{
	if (x < to_int(Month::jan) || to_int(Month::dec) < x)
		error("bad month");
	return Month{ x };
}

ostream& operator<<(ostream& os, Month m)
{
	return os << month_tbl[to_int(m)];
}

Month operator++(Month& m)
{
	m = (m == Month::dec ? Month::jan : Month{ to_int(m) + 1 });
	return m;
}

struct Year {
	int y;
};

ostream& operator<<(ostream& os, Year y)
{
	return os << y.y;
}

class Date {
public:
	class Invalid {};					// to be used as exception
	Date() {};
	Date(Year y, Month m, int d);
	Date(Year y);
	bool is_valid();

	Year year() const { return y; }
	Month month() const { return m; }
	int day() const { return d; }

	void add_day(int n);
	void add_month(int n);
	void add_year(int n);
private:
	Year y { 2000 };
	Month m = { Month::jan };
	int d = 1;
};

Date::Date(Year yy, Month mm, int dd)
	: y{ yy }, m{ mm }, d{ dd }
{
	if (!is_valid())
		throw Invalid{};
}

Date::Date(Year yy) 
	: y{ yy }
{
}

bool Date::is_valid()
{
	bool isMonth = 0 < to_int(m) && to_int(m) < 13;
	bool isDay = 0 < d && d < 32;
	return isMonth && isDay;
}

void Date::add_day(int n)
{
	d += n;
}

void Date::add_month(int n)
{
	m = Month{ to_int(m) + n };
}

void Date::add_year(int n)
{
	y = Year{ y.y + n };
}

ostream& operator << (ostream& os, Date& d)
{
	return os << d.year() << '/' << d.month() << '/' << d.day();
}

bool operator == (const Date& d1,const Date& d2)
{
	return d1.day() == d2.day()
		&& d1.month() == d2.month()
		&& d1.year() == d2.year();
}

bool operator != (const Date& d1, const Date& d2)
{
	return !(d1 == d2);
}

void f()
try {
	Date today{ Year{2004}, Month { 2 }, 3 };
	Date tomorrow{ today };
	tomorrow.add_day(1);
	cout << "today == " << today
		<< "\ntomorrow == " << tomorrow << '\n';
}
catch (Date::Invalid) {
	error("f(): invalid date");
}


int main()
try {
	f();
	return 0;
}
catch (exception& e){
	cerr << "error: " << e.what() << '\n';
	return 2;
}
catch (...) {
	cerr << "Oops! unknown exception!\n";
	return 2;
}