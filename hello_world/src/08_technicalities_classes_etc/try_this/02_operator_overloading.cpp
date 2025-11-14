/*
	Try This
		Write, compile, and run a small example using ++ and << for Month
*/

#include "PPP.h"

enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

vector<string> month_tbl = { "Not a month", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int to_int(Month d)
{
	return static_cast<int>(d);
}

Month operator++(Month& m)		// prefix increment operator
{
	m = (m == Month::dec ? Month::jan : Month{ to_int(m) + 1 });
	return m;
}

ostream& operator<<(ostream& os, Month m)
{
	return os << month_tbl[to_int(m)];
}

int main()
try {
	Month m{ Month::jan };
	cout << ++m << '\n';
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
