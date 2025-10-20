/*
	Student Score Tracker
	
	This program implements a basic student score tracking system.

	Write a program where you first enter a set of name - and -value pairs, such as Joe 17 and Barbara 22. For each pair, add the
	name to a vector called names and the number to a vector called scores (in corresponding positions, so that if
	names[7] == "Joe" then scores[7] == 17). Terminate input with NoName 0. Check that each name is unique and terminate with
	an error message if a name is entered twice. Write out all the (name, score) pairs, one per line.

	Modify the program from the previous exercise so that once you have entered the name - and -value pairs, you ask for values:
	In a loop, when you enter a name, the program will output the corresponding score or name not found. 	
*/

// This program gets name and score and write's out the same to the monitor.

#include "PPP.h"

int main()
{
	try {
	const string terminate_str = "NoName";	// input termination name
	constexpr double terminate_val = 0;		// input termination value

	cout << "Enter a sequence of pair of name and score :-\n";
	vector<string> names;
	vector<double> scores;
	string student_name;
	double student_score = 0;

	while (true)		
	{
		cin >> student_name >> student_score;

		if (student_name == terminate_str && student_score == terminate_val) break; // stops reading values if entered student_name and student_score is NoName 0
		names.push_back(student_name);
		scores.push_back(student_score);
	}

	// sort names along with its corresponding scores (cannot use ranges::sort because names are mapped with scores):
	for (int i = 0; i < names.size(); ++i)
		for (int j = ++i; j < names.size(); ++j)
			if (names[i] > names[j])
			{
				string temp_student_name = names[i];
				names[i] = names[j];
				names[j] = temp_student_name;

				// put score to its corresponding name's position:
				double temp_student_score = scores[i];
				scores[i] = scores[j];
				scores[j] = temp_student_score;
			}

	// Check that each name is unique and terminate with an error message if a name is entered twice:
	string current;
	string previous;
	for (int i = 1; i < names.size(); ++i)
	{
		current = names[i];
		previous = names[i - 1];
		if (current == previous)
		{
			cout << "Error : name is entered twice";
			return 1;			// if unique name found, the program terminates with status code 1
		}
	}

	// output corresponding score for the name entered
	cout << "Enter names seperated by space to search for score :-\n";
	for (string search_name; cin >> search_name && search_name != "NoName"; )
	{
		string name_found = "no";
		for (int i = 0; i < names.size(); ++i)
			if (names[i] == search_name)
			{
				name_found = "yes";
				cout << search_name << "'s corresponding score == " << scores[i] << '\n';
			}
		if (name_found == "no")
			cout << search_name << " not found" << "\n\n";
	}

	// output corresponding names with the score entered
	cout << "\nEnter scores seperated by space to search for names :-\n";
	for (double search_score; cin >> search_score; )
	{
		string score_found = "no";
		for (int i = 0; i < scores.size(); ++i)
			if (scores[i] == search_score)
			{
				score_found = "yes";
				cout << names[i] << " ";
			}
		cout << '\n';
		if (score_found == "no")
			cout << search_score << " not found" << "\n\n";
	}

	// if no unique, write out all the (name, score) pairs, one per line:
	for (int i = 0; i < names.size(); ++i)
		cout << "Name == " << names[i] << ", Score == " << scores[i] << '\n';
	cout << '\n';

	return 0;
	}
	catch (exception& e) {
		cout << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cout << "Oops: unknown exception!\n";
	}
}