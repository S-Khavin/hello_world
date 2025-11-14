// This program is to look up standard-library chrono

#include "PPP.h"

int main()
{
	try {
		chrono::weekday x{ 3 };
		cout << x << '\n';			// outputs Wed

		chrono::month m{ 2 };
		cout << m << '\n';

		chrono::day d{ 3 };

		chrono::month_day md{ m, d };
		cout << md << '\n';

		chrono::month_day_last mdl{ m };
		cout << mdl << '\n';
		return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops, unknown exception!\n";
		return 2;
	}
}