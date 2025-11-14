/*
	Design and implement a Name_pairs class holding(name, age) pairs where name is a string and age is a double. Represent that
	as a vector<string>(called name) and a vector<double>(called age) member. Provide an input operation read_names() that
	reads a series of names. Provide a read_ages() operation that prompts the user for an age for each name. Provide a print()
	operation that prints out the(name[i], age[i]) pairs(one per line) in the order determined by the name vector. Provide a
	sort() operation that sorts the name vector in alphabetical order and reorganizes the age vector to match. Implement all
	“operations” as member functions.Test the class (of course : test early and often).
*/

#include "PPP.h"

class Name_Pair {
public:
	string name;
	double age = 0;
};

class Name_pairs {
public:
	void read_names();
	void read_ages();
	//void print();
	void sort();
	vector<Name_Pair> name_age;
};

void Name_pairs::read_names() {
	cout << "Enter pair of names and age followed by space (to stop reading type 'NoName' and 0 and press enter) :-\n";
	for (string s; ;)
	{
		cin >> s;
		if (!cin) error("failed to read names in read_names()");
		if (s == "NoName") break;
		name_age.push_back(Name_Pair {s, 0});
	}
	cout << '\n';
}

void Name_pairs::read_ages() {
	cout << "Enter age for each name :-\n";
	for (Name_Pair& x : name_age)
	{
		cout << x.name << " == ";
		double d = 0;
		cin >> d;
		if (!cin) error("failed to read ages in read_ages()");
		x.age = d;
	}
	cout << '\n';
}

//void Name_pairs::print() {
//	for (const Name_Pair& x : name_age)
//		cout << x.name << ", " << x.age << '\n';
//}

void Name_pairs::sort() {	
	for (int i = 0; i < name_age.size() - 1; ++i)
		for (int j = i + 1; j < name_age.size(); ++j)
			if (name_age[i].name > name_age[j].name)
			{
				Name_Pair temp = name_age[i];
				name_age[i] = name_age[j];
				name_age[j] = temp;
			}
}

ostream& operator << (ostream& os, Name_pairs& p)
{
	for (const Name_Pair& x : p.name_age)
		cout << x.name << ", " << x.age << '\n';
	return os;
}

bool operator == (Name_pairs& p1, Name_pairs& p2)
{
	return p1.name_age == p2.name_age;
}

bool operator != (Name_pairs& p1, Name_pairs& p2)
{
	return !(p1 == p2);
}

void f()
{
	Name_pairs employee;
	employee.read_names();
	employee.read_ages();
	cout << employee;
	employee.sort();
	cout << employee;
	Name_pairs student;
	student.read_names();
	student.read_ages();
	if (employee == student) cout << "Equal";
	else cout << "Not Equal";
	if (employee != student) cout << "!Equal";
	else cout << "!Not Equal";
}

int main()
try {
	f();
}
catch (exception& e)
{
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	cerr << "Oops, unexpected error occured!\n";
	return 2;
}