 /*[2] Write a program that reads a string from input and then, for each character read, 
prints out the character and its integer value on a line.*/

// This program reads a string from input and then, for each character read, prints out the character and its integer value on a line.

#include "PPP.h";

int main()
{
	cout << "Enter a string : ";
	string word;
	cin >> word;

	for (char character : word)
		cout << character << " == " << int(character) << '\n';
}