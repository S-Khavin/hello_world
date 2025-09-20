 /*[12] Create a program to find all the prime numbers between 1 and 100. One way to do this is to write a function that will check if
a number is prime(i.e., see if the number can be divided by a prime number smaller than itself) using a vector of primes in order
(so that if the vector is called primes, primes[0] == 2, primes[1] == 3, primes[2] == 5, etc.).Then write a loop that goes
from 1 to 100, checks each number to see if it is a prime, and stores each prime found in a vector.Write another loop that lists the primes
you found.You might check your result by comparing your vector of prime numbers with primes.Consider 2 the first prime.*/


// This program outputs all the prime numbers between 1 and 100.

#include "PPP.h";

int is_prime(int num, vector<int> primes) 
	// return 1 if the number is prime, return 0 if no.
{
	if (num > 2) // 1 is not a prime, 2 is prime but if we allow 2, 2 % 2 == 0; returns 0 since 2 is already considered as first prime we don't want an operation with 2 again.
	{
		for (int x : primes)
			if (num % x == 0)
				return 0;
		return 1;
	}
	else
		return 0;
}

int main()
{	
	vector<int> primes = { 2 }; // considering first prime as 2

	for (int i = 1; i <= 100; ++i)
	{
		int x = is_prime(i, primes);
		if (x == 1)
			primes.push_back(i);
	}

	cout << "The prime numbers between 1 and 100 :-\n";
	for (int x : primes)
		cout << x << " ";
	cout << '\n';
}