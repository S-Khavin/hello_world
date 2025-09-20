/*[3] If we define the median of a sequence as “a number so that exactly as many elements come before it in the sequence as
come after it, ” fix the program in §3.6.3 so that it always prints out a median.Hint: A median need not be an element of the
sequence.*/

// This program fixes the median program to have exactly same elements before and after it.

#include "PPP.h";

int main()
// compute mean and median temperatures
{
	vector<double> temps;				// temperatures
	for (double temp; cin >> temp;)		// read into temp
		temps.push_back(temp);			// put temp into vector

	// compute mean temperature:
	double sum = 0;
	for (double x : temps)
		sum += x;
	cout << "Average temperature: " << sum / temps.size() << '\n';

	// compute median temperature:
	ranges::sort(temps);				// sort the temperatures
	if (temps.size() % 2 != 0)
		cout << "Median temperature: " << temps[temps.size() / 2] << '\n';
	else
		cout << "Median temperature: " << (temps[temps.size() / 2] + temps[temps.size() / 2 - 1]) / 2 << '\n';
}