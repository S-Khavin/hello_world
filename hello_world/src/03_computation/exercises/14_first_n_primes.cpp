/*[14] Write a program that takes an input value n and then finds the first n primes*/

// This program finds all prime numbers between 1 and n using the Sieve of Eratosthenes method.

#include "PPP.h";

int main()
{
	cout << "Enter the value of n to find all prime numbers between 1 and n: ";
	int n = 0;
	cin >> n;
	vector<int> number_sequence;

	// generates sequence of numbers from 0 to n:
	for (int i = 0; i <= n; ++i)			// starts from 0 to make indexing easier
		number_sequence.push_back(i);

	// Seive of Eratosthenes method for calculating prime numbers between 1 and n:
	number_sequence[1] = 0;					// 1 is not a prime	

	for (int i = 2; i * i <= n; ++i)		// starts from 2, as 0 and 1 are not prime numbers
		if (number_sequence[i] != 0)
			for (int j = i * 2; j < number_sequence.size(); j += number_sequence[i])
				number_sequence[j] = 0;		// make the number as 0 if the number is not a prime

	// outputs prime numbers:
	for (int x : number_sequence)
		if (x != 0)							// since the non prime nubers are marked as 0 we exclude
			cout << x << " ";
	cout << '\n';
}