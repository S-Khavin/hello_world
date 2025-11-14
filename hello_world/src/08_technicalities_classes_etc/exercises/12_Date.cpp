/*
	Change the representation of a Date to be the number of days since January 1, 1970 (known as day 0), represented as a long
	int (that is, an int that can hold much larger integers than plain int), and re-implement the Date member functions from §8.4.2.
	Be sure to reject dates outside the range we can represent that way (feel free to reject days before day 0, i.e., no negative
	days).
*/

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

bool operator<(Year& y1, Year& y2)
{
	return y1.y < y2.y;
}

Year operator++(Year& y)
{
	y = Year{ ++y.y };
	return y;
}

bool leapyear(int y)
{
	if (y % 4 == 0)
		if (y % 100 != 0) return true;
		else if (y % 400 == 0) return true;
		else return false;
	return false;
}

class Date {
public:
	class Invalid {};					// to be used as exception
	Date() {};
	Date(Year y, Month m, int d);
	Date(Year y);
	bool is_valid(Year y, Month m, int d);
	long int days() const { return days_since_1970; }

	Year year() const { 
		int year = 1970;
		for (int i = 1; days_since_1970 - i >= (leapyear(year) ? 366 : 365); i += 365)
		{
			if (leapyear(year)) ++i;
			++year;
		}
		return Year{ year };
	};

	Month month() const {
		long int days = days_since_1970;
		int year = 1970;

		while (true)
		{
			int days_in_year = leapyear(year) ? 366 : 365;
			if (days < days_in_year) break;
			days -= days_in_year;
			++year;
		}

		if (days == 0) return Month::dec;

		Month month = Month::jan;

		while (true)
		{
			int days_in_months;
			if (month == Month::feb)							// special case of february
			{
				days_in_months = 28;
				if (leapyear(year)) ++days_in_months;
			}
			else
			{
				if (to_int(month) % 2 != 0)
					if (month < Month::aug) days_in_months = 31;
					else days_in_months = 30;
				else
					if (month < Month::aug) days_in_months = 30;
					else days_in_months = 31;
			}
			if (days <= days_in_months) break;
			days -= days_in_months;
			++month;
		}

		return month;
	}
	int day() const { 
		long int days = days_since_1970;
		int year = 1970;

		while (true)
		{
			int days_in_year = leapyear(year) ? 366 : 365;
			if (days < days_in_year) break;
			days -= days_in_year;
			++year;
		}

		Month month = Month::jan;

		while (true)
		{
			int days_in_months;
			if (month == Month::feb)							// special case of february
			{
				days_in_months = 28;
				if (leapyear(year)) ++days_in_months;
			}
			else
			{
				if (to_int(month) % 2 != 0)
					if (month < Month::aug) days_in_months = 31;
					else days_in_months = 30;
				else
					if (month < Month::aug) days_in_months = 30;
					else days_in_months = 31;
			}

			if (days <= days_in_months) break;
			days -= days_in_months;
			++month;
		}

		if (days == 0) return 31;
		return days;
	}

	void add_day(int n);
	void add_month(int n);
	void add_year(int n);

private:
	long int days_since_1970 = 0;					// no of days since January 1 1970
};

Date::Date(Year yy, Month mm, int dd)
{
	if (!is_valid(yy, mm, dd))
		throw Invalid{};

	// converts year, month, day to no of days since January 1 1970
	for (Year i = Year{ 1970 }; i < yy; ++i)
	{
		days_since_1970 += 365;
		if (leapyear(i.y)) ++days_since_1970;
	}

	for (Month i = Month::jan; i < mm; ++i)
	{

		if (i == Month::feb)							// special case of february
		{
			days_since_1970 += 28;
			if (leapyear(yy.y)) ++days_since_1970;
		}
		else
		{
			if (to_int(i) % 2 != 0)
				if (i < Month::aug) days_since_1970 += 31;
				else days_since_1970 += 30;
			else if (i < Month::aug)
				days_since_1970 += 30;
			else days_since_1970 += 31;
		}
	}

	days_since_1970 += dd;
	if (days_since_1970 < 0) throw Invalid{};
}

Date::Date(Year yy)
{
	for (Year i = Year{ 1970 }; i < yy; ++i)
	{
		days_since_1970 += 365;
		if (leapyear(i.y)) ++days_since_1970;
	}

	if (days_since_1970 < 0) throw Invalid{};
}

int days_in_month(Month m, Year y)
{
	if (m == Month::feb)							// special case of february
	{
		if (leapyear(y.y)) return 29;
		return 28;
	}
	else
	{
		if (to_int(m) % 2 != 0)
			if (m < Month::aug) return 31;
			else return 30;
		else 
			if (m < Month::aug) return 30;
			else return 31;
	}
}

bool Date::is_valid(Year y, Month m, int d)
{
	bool isMonth = 0 < to_int(m) && to_int(m) < 13;
	bool isDay = 0 < d && d <= days_in_month(m, y);
	return isMonth && isDay;
}

void Date::add_day(int n)
{
	days_since_1970 += n;
}

void Date::add_month(int n)
{
	days_since_1970 += days_in_month(month(), year());
}

void Date::add_year(int n)
{
	days_since_1970 += leapyear(year().y + 1) ? 366 : 365;
}

enum class Day {
	sunday = 1, monday, tuesday, wednesday, thursday, friday, saturday
};

vector<string> day_table = { "no day", "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };

int day_of_year(const Date& d)
{
	int days = 0;
	for (Month m{ Month::jan }; m < d.month(); ++m)
		if (m == Month::feb)							// special case of february
		{
			days += 28;
			if (leapyear(d.year().y)) ++days;
		}
		else
		{
			if (to_int(m) % 2 != 0)
				if (m < Month::aug) days += 31;
				else days += 30;
			else
				if (m < Month::aug) days += 30;
				else days+= 31;
		}
		//if (to_int(m) % 2 != 0) days += 31;
		//else
		//	if (m == Month::feb)
		//	{
		//		if (leapyear(d.year().y)) days += 29;
		//		else days += 28;
		//	}
		//	else days += 30;

	days += d.day();
	return days;
}

string next_workday(const Date& d)
{
	cout << "day_of_year == " << day_of_year(d) << '\n';
	int remainder = day_of_year(d) % 7;
	cout << "remainder == " << remainder << '\n';
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
	Date initiated_date{ Year{2025}, Month { 11 }, 13 };
	Date expiration_date = initiated_date;
	expiration_date.add_day(90);

	Date today{ Year{2025}, Month { 11 }, 14 };
	long int remaining_days = expiration_date.days() - today.days();


	cout << "initiated_date == " << initiated_date
		<< "\nexpiration_date == " << expiration_date
		<< "\ntoday == " << today
		<< "\nremaining days == " << remaining_days << '\n';

	if (remaining_days <= 15) cout << "renewing...\n";
	

		//<< "\nnext work day == " << next_workday(today);
		////<< "\nnext week end == " << week_of_year(today);

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