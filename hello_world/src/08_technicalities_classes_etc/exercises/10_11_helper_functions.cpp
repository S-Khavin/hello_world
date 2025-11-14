/*
	10. Implement leapyear(int).

	11. Design and implement a set of useful helper functions for the Date class with functions such as next_workday() (assume that
	any day that is not a Saturday or a Sunday is a workday) and week_of_year() (assume that week 1 is the week with January 1
	in it and that the first day of a week is a Sunday).
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
	Year y{ 2000 };
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

bool leapyear(int y)
{
	if (y % 4 == 0)
		if (y % 100 != 0) return true;
		else if (y % 400 == 0) return true;
		else return false;
	return false;
}

enum class Day {
	sunday = 1, monday, tuesday, wednesday, thursday, friday, saturday
};

vector<string> day_table = { "no day", "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };

int day_of_year(const Date& d)
{
	int days = 0;
	for (Month m{ Month::jan }; m < d.month(); ++m)
		if (to_int(m) % 2 != 0) days += 31;
		else
			if (m == Month::feb)
			{
				if (leapyear(d.year().y)) days += 29;
				else days += 28;
			}
			else days += 30;
			
	days += d.day();
	return days;
}

string next_workday(const Date& d)
{
	int remainder = day_of_year(d) % 7;
	int day = remainder == 0 ? 7 : remainder;
	cout << day;
	if (day == 6 || day == 7) day = 2;
	else ++day;
	return day_table[day];
}

int week_of_year(const Date& d)
{
	int week_passed = day_of_year(d) / 7;
	if (day_of_year(d) % 7 > 0) return ++week_passed;
	else return week_passed;
}

ostream& operator << (ostream& os, Date d)
{
	return os << d.year() << '/' << d.month() << '/' << d.day();
}

bool operator == (const Date& d1, const Date& d2)
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
	if (leapyear(2000)) cout << "Leap Year" << '\n';
	else cout << "Normal Year" << '\n';

	cout << next_workday(Date{ Year{2004}, Month { 2 }, 3 }) << '\n';

	cout << week_of_year(Date{ Year{2004}, Month { 2 }, 4 }) << '\n';
}
catch (Date::Invalid) {
	error("f(): invalid date");
}


int main()
try {
	f();
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 2;
}
catch (...) {
	cerr << "Oops! unknown exception!\n";
	return 2;
}