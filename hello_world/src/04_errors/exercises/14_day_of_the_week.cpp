// This program collects value for each day of a week and print its details.

#include "PPP.h"

int main()
{
	try {
		cout << "Enter day value pairs (eg: Tuesday 23 Friday 56 Thursday -3 Thursday 99):-";
		string day;
		int val = 0;
		
		vector<pair<string, vector<int>>> day_values_pair = {
			{ "Monday", {} },
			{ "Tuesday", {} },
			{ "Wednesday", {} },
			{ "Thursday", {} },
			{ "Friday", {} },
			{ "Saturday", {} },
			{ "Sunday", {} }
		};

		int rejected_val_pair = 0;

		while (cin >> day >> val) {
			if (day == "Monday" || day == "monday" || day == "Mon")
				day_values_pair[0].second.push_back(val);
			else if (day == "Tuesday" || day == "tuesday" || day == "Tue")
				day_values_pair[1].second.push_back(val);
			else if (day == "Wednesday" || day == "wednesday" || day == "Wed")
				day_values_pair[2].second.push_back(val);
			else if (day == "Thursday" || day == "thursday" || day == "Thu")
				day_values_pair[3].second.push_back(val);
			else if (day == "Friday" || day == "friday" || day == "Fri")
				day_values_pair[4].second.push_back(val);
			else if (day == "Saturday" || day == "saturday" || day == "Sat")
				day_values_pair[5].second.push_back(val);
			else if (day == "Sunday" || day == "sunday" || day == "Sun")
				day_values_pair[6].second.push_back(val);
			else
				++rejected_val_pair;
		}

		for (int i = 0; i < day_values_pair.size(); ++i)
		{
			cout << day_values_pair[i].first;

			int sum = 0;
			for (int j = 0; j < day_values_pair[i].second.size(); ++j)
				sum += day_values_pair[i].second[j];

			cout << " == " << sum << '\n';
		}

		cout << "Number of rejected values == " << rejected_val_pair;
		return 0;
	}
	catch(exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops, unknown exception!\n";
		return 2;
	}
}