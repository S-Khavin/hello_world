 /*[13] Create a program to find all the prime numbers between 1 and 100. There is a classic method for doing this, called the “Sieve
of Eratosthenes.” If you don’t know that method, get on the Web and look it up. Write your program using this method.*/

// This program finds all prime numbers between 1 and 100 using the Sieve of Eratosthenes method.

#include "PPP.h";

int main()
{
	vector<int> number_sequence;

	// generates sequence of numbers from 0 to 100:
	for (int i = 0; i <= 100; ++i)			// starts from 0 to make indexing easier
		number_sequence.push_back(i);

	// Seive of Eratosthenes method for calculating prime numbers between 1 and 100:
	number_sequence[1] = 0;					// 1 is not a prime	

	for (int i = 2; i * i <= 100; ++i)		// starts from 2, as 0 and 1 are not prime numbers
		if (number_sequence[i] != 0)
			for (int j = i * 2; j < number_sequence.size(); j += number_sequence[i])
				number_sequence[j] = 0;		// make the number as 0 if the number is not a prime
	 
	// outputs prime numbers:
	for (int x : number_sequence)
		if (x != 0)							// since the non prime nubers are marked as 0 we exclude
			cout << x << " ";
	cout << '\n';
}