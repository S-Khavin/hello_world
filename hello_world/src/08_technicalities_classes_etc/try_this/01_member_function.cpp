/*
	Try This
	Get some example uses of a version of Date so far to run. For that, we need an output operator for Date. There is
	one in PPP_support, but for now use
	
		ostream& operator<<(ostream& os, Date d)
		{
		 return os << d.year() << '/’ << d.month() << '/’ << d.day();
		}

	Chapter 9 explains why and how that works.
*/

#include "PPP.h"

// simple Date
class Date {
public:
	class Invalid {};
	Date(int y, int m, int d);	// constructor: check for valid date and initialize
	void add_day(int n);		// increase the Date by n days
	int month() { return m; }
	int day() { return d; }
	int year() { return y; }
private:
	int y, m, d;				// year, month, day
};

Date::Date(int yy, int mm, int dd)	// constructor
	: y{ yy }, m{ mm }, d{ dd }		// note: member initializers
{
}

void Date::add_day(int n)
{
	// ...
}

ostream& operator << (ostream& os, Date d)
{
	return os << d.year() << '/' << d.month() << '/' << d.day();
}

int main() {
	try {
		double y = 2004;
		Date birthday{ y, 2, 3 };
		cout << "birthday year == " << birthday.year()
			<< "\nbirthday month == " << birthday.month()
			<< "\nbirthday month == " << birthday.day() << "\n\n";

		cout << "birthday == " << birthday << '\n';
		return 0;
	}
	catch (exception& e)
	{
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...)
	{
		cerr << "Oops, unknown exception!\n";
		return 2;
	}
}