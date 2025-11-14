#include "PPP.h"

enum class Day {
	monday, tuesday, wednesday, thursday, friday, saturday, sunday
};

int to_int(Day d)
{
	return static_cast<int>(d);
}

Day int_to_day(int x)
// checked conversion
{
	if (x < to_int(Day::monday) || to_int(Day::sunday) < x)
		error("bad day");
	return Day{ x };
}

int main() {
	try {
		Day d1 = Day::monday;
		int x2 = int{ d1 };
		cout << "x2 == " << x2 << '\n';

		Day d2{ 20 };
		Day d3 = int_to_day(20);
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