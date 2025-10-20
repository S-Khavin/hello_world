 /*Analysis :-
	The program is to calculate permutation or combination. 

	Permutation :-
		A permutation is an ordered subset of a set.
		P(a,b) = (a!) / ((a-b)!)

	Combination :-
		Combinations are similar to permutations, except that the
	order of the objects doesn’t matter
		C(a,b) = (P(a,b)) / (b!)

	Requirement :-
		Design a program that asks users for two numbers, asks
	them whether they want to calculate permutations or
	combinations, and prints out the result.*/

 /*Design :-
	Use cases for permutation:-
		To perform permutation or combinations ('p' or 'c') ? p
		Enter size of set : 2
		Enter size of subset : 2
		No of Permutation == 20

	Use case for combination:-
		To perform permutation or combinations ('p' or 'c') ? c
		Enter size of set : 5
		Enter size of subset : 2
		No of Combinations == 10
		
	Pseudo Code:-
		read p or c
		if not p or c print error and exit program
		read size of set	
		if input fails print error and exit program
		read size of subset
		if input fails print error and exit program
		both size of set and subset must be positive and size of subset must be lesser than if not print error and exit program
		if p then apply permutation formula P(a,b) = (a!) / ((a-b)!) on size of set and subset
		if c then apply combinations formula C(a,b) = (P(a,b)) / (b!) on size of set and subset
		write result

	int factorial(int x)
	int permutation(int a, int b)
	int combinations(int a, int b)
	main()*/

// Implementation


// This program calculates permutation and combinations from the given set and subset

#include "PPP.h"

//------------------------------------------------------------------------------

int factorial(int x){
	expect([&] {return x >= 0; }, "bad arguments for factorial()");
	if (x == 0)
		return 1;

	int fact = 1;
	for (int i = x; i >= 1; --i)
		fact *= i;

	expect([&] {return x > 0; }, "bad result for factorial()");
	return fact;
}

//------------------------------------------------------------------------------

int permutation(int a, int b)
		// calculates permutation
{
	expect([&] {return a >= 0 && b >= 0 && a >= b; }, "bad arguments for permutation()");

	int denominator = factorial(a - b);
	if (denominator == 0)
		error("divide by zero");
	int p = factorial(a) / denominator;	// calculates permutation

	expect([&] {return p >= 0; }, "bad result for permutation()");
	return p;
}

//------------------------------------------------------------------------------

int combinations(int a, int b)
		// calculates combinations
{
	expect([&] {return a >= 0 && b >= 0 && a >= b; }, "bad arguments for combinations()");

	int denominator = factorial(b);
	if (denominator == 0)
		error("divide by zero");
	int c = permutation(a,b) / denominator;	// calculates combinations

	expect([&] {return c >= 0; }, "bad result for combinations()");
	return c;
}

//------------------------------------------------------------------------------

int main() {
	try {
		// Determine which operation to perform
		cout << "To perform permutation or combinations ('p' or 'c') ? ";
		char option = ' ';
		cin >> option;
		if (!cin) error("unable to read option in main()");
		if (option != 'p' && option != 'c') error("invalid option");

		cout << "Enter size of set : ";
		int size_of_set = 0;
		cin >> size_of_set;
		if (!cin) error("unable to read size of set in main()");

		cout << "Enter size of subset : ";
		int size_of_subset = 0;
		cin >> size_of_subset;
		if (!cin) error("unable to read size of subset in main()");

		switch (option) {
		case 'p':
		{
			int perm = permutation(size_of_set, size_of_subset);
			cout << "No of Permutation == " << perm << '\n';
			break;
		}
		

		case 'c':
			int comb = combinations(size_of_set, size_of_subset);
			cout << "No of Combinations == " << comb << '\n';
			break;
		}
		return 0;
	}
	catch (exception& e)
	{
		cerr << "error: " << e.what() << '\n';
		return -1;
	}
	catch (...)
	{
		cerr << "Oops: unknown exception!\n";
	}
}

//------------------------------------------------------------------------------
