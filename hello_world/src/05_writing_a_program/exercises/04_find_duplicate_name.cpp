 /*[4] Define a class Name_value that holds a string and a value.
Rework exercise 20 in Chapter 3 to use a vector<Name_value>
instead of two vectors.*/


// This program gets name and score and write's out the same to the monitor.

#include "PPP.h"

class Name_value {
public:
	string name;
	double value;
	Name_value(string str, double val): name(str), value(val) {
	}
};

int main()
{
	const string terminate_str = "NoName";
	constexpr double terminate_val = 0;

	cout << "Enter a sequence of pair of name and score :-\n";
	//vector<string> names;
	//vector<double> scores;

	vector<Name_value> student_details;
	string student_name;
	double student_score = 0;

	while (student_name != terminate_str || student_score != terminate_val)		// Terminate loop last entered student_name and student_score is NoName 0
	{
		cin >> student_name >> student_score;
		if (student_name != terminate_str || student_score != terminate_val)
		{
			student_details.push_back(Name_value(student_name, student_score));
		}
	}

	// sort student_details by student name (cannot use ranges::sort because the name is a member of Name_value):
	for (int i = 0; i < student_details.size(); ++i)
		for (int j = i + 1; j < student_details.size(); ++j)
			if (student_details[i].name > student_details[j].name)
			{
				Name_value temp_student_name = student_details[i];
				student_details[i] = student_details[j];
				student_details[j] = temp_student_name;
			}

	// Check that each student name is unique and terminate with an error message if a name is entered twice:
	string current;
	string previous;
	for (int i = 1; i < student_details.size(); ++i)
	{
		current = student_details[i].name;
		previous = student_details[i - 1].name;
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
		for (int i = 0; i < student_details.size(); ++i)
			if (student_details[i].name == search_name)
			{
				name_found = "yes";
				cout << search_name << "'s corresponding score == " << student_details[i].value << '\n';
			}
		if (name_found == "no")
			cout << search_name << " not found" << "\n\n";
	}

	// output corresponding names with the score entered
	cout << "\nEnter scores seperated by space to search for names :-\n";
	for (double search_score; cin >> search_score; )
	{
		string score_found = "no";
		for (int i = 0; i < student_details.size(); ++i)
			if (student_details[i].value == search_score)
			{
				score_found = "yes";
				cout << student_details[i].name << " ";
			}
		cout << '\n';
		if (score_found == "no")
			cout << search_score << " not found" << "\n\n";
	}

	// if no unique, write out all the (name, score) pairs, one per line:
	for(Name_value x: student_details)
		cout << "Name == " << x.name << ", Score == " << x.value << '\n';
	cout << '\n';
}