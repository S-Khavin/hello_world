//[16] Write a program that finds the min, max, and mode of a sequence of strings.

// This program outputs min, max and mode of a sequence of strings.

#include "PPP.h";

int main()
{
	cout << "Enter sequence of strings followed by space then press 'enter' : \n";
	vector<string> sequence_of_strings;

	for(string word; cin >> word; )
		sequence_of_strings.push_back(word);

	ranges::sort(sequence_of_strings);

	cout << "Smallest == " << sequence_of_strings[0]
		<< "\nLargest == " << sequence_of_strings[sequence_of_strings.size() - 1] << '\n';

	// computes mode in string sequence:
	vector<string> modes;
	string current;
	string previous;
	int count = 0;
	int max_count = 0;

	for (int i = 0; i < sequence_of_strings.size(); ++i)
	{
		current = sequence_of_strings[i];

		if (i == 0 || previous == current)
			++count;

		if (previous != current || i == sequence_of_strings.size() - 1)
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

	cout << "Mode == ";
	for (string x : modes)
		cout << x << " ";
	cout << '\n';
}