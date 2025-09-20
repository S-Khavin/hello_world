 /*[15] In the drill, you wrote a program that, given a series of numbers, found the max and min of that series. The number that 
appears the most times in a sequence is called the mode. Create a program that finds the mode of a set of positive integers.*/

// This program keep track on smalles and largest number in a sequence

#include "PPP.h";

int main()
{
	cout << "Enter sequence of values followed by space then press 'enter' : \n";
	double v1 = 0.0;
	string unit;
	double smallest_so_far = 0.0;			// keep track of smallest number in the sequence
	double largest_so_far = 0.0;			// keep track of largest number in the sequence
	int i = 0;								// keep track of number of elements entered
	double sum = 0.0;

	// 1m==100cm, 1in==2.54cm, 1ft == 12in
	constexpr double m_per_cm = 1.0 / 100.0;
	constexpr double m_per_in = 2.54 * m_per_cm;
	constexpr double m_per_ft = 12.0 * m_per_in;

	vector<double> sequence_in_meters;

	while (cin >> v1 >> unit)
	{
		if (unit == "cm" || unit == "m" || unit == "in" || unit == "ft")
		{
			if (i == 0)						// there is no value to compare with the first value entered
			{
				smallest_so_far = v1;
				largest_so_far = v1;
				cout << v1 << " is both smallest and largest so far\n";
			}
			else
				if (v1 < smallest_so_far)
				{
					smallest_so_far = v1;
					cout << v1 << " the smallest so far\n";
				}
				else if (v1 > largest_so_far)
				{
					largest_so_far = v1;
					cout << v1 << " the largest so far\n";
				}
				else
					cout << v1 << '\n';

			if (unit == "m")
			{
				sequence_in_meters.push_back(v1);
				sum += v1;
			}
			else if (unit == "cm")
			{
				sequence_in_meters.push_back(v1 * m_per_cm);
				sum += v1 * m_per_cm;
			}
			else if (unit == "in")
			{
				sequence_in_meters.push_back(v1 * m_per_in);
				sum += v1 * m_per_in;
			}
			else if (unit == "ft")
			{
				sequence_in_meters.push_back(v1 * m_per_ft);
				sum += v1 * m_per_ft;
			}
			else;

		}
		else
			cout << "I don't know a unit called " << unit << ".\n";
		++i;
	}

	cout << "Smallest == " << smallest_so_far
		<< "\nLargest == " << largest_so_far
		<< "\nNumber of values == " << i
		<< "\nSum == " << sum << "m\n";

	ranges::sort(sequence_in_meters);

	for (double x : sequence_in_meters)
		cout << x << "m ";
	cout << '\n';

	// computes mode int the sequence:
	vector<double> modes;
	double current = 0;
	double previous = 0;
	int count = 0;
	int max_count = 0;
	for (int i = 0; i < sequence_in_meters.size(); ++i)
	{
		current = sequence_in_meters[i];

		if (i == 0 || previous == current)
			++count;
		else
		{
			if (count > 1)
				if (count > max_count)
				{
					max_count = count;
					modes.clear();
					modes.push_back(previous);
				}
				else if (count == max_count)
					modes.push_back(previous);
			count = 1;
		}

		previous = current;
	}

	for (double x : modes)
		cout << x << " ";
	cout << '\n';

	// computes mode int the sequence (wrong version):
	/*vector<double> sequence_in_meters = {1, 2, 3, 4};
	vector<double> modes;
	double current = 0;
	double previous = 0;
	int count = 0;
	int max_count = 0;
	for (int i = 0; i < sequence_in_meters.size(); ++i)
	{
		current = sequence_in_meters[i];

		if (current != previous || i == sequence_in_meters.size() - 1)
		{
			if (i == sequence_in_meters.size() - 1)
				++count;

			if (count != 1)
			{
				if (count > max_count)
				{
					max_count = count;
					modes.clear();
					modes.push_back(previous);
				}
				else if (count == max_count)
					modes.push_back(previous);
			}
			count = 0;
		}

		++count;

		previous = current;
	}

	for (double x : modes)
		cout << x << " ";*/

}