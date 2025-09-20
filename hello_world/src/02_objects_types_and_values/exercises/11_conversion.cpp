 /*Write a program that prompts the user to enter some number of pennies(1 - cent coins), nickels(5 - cent coins), dimes(10 - cent coins), quarters
 (25 - cent coins), half dollars(50 - cent coins), and one - dollar coins(100 - cent coins).Query the user separately for the number of each size coin, 
	e.g., “How many pennies do you have ? ” Then your program should print out
	something like this :
	Click here to view code image
	You have 23 pennies.
	You have 17 nickels.
	You have 14 dimes.
	You have 7 quarters.
	You have 3 half dollars.
	The value of all of your coins is 573 cents.
Make some improvements : if only one of a coin is reported, make the output grammatically correct, e.g., 14 dimes and 1 dime(not 1 dimes).
Also, report the sum in dollars and cents, i.e., .73 instead of 573 cents.*/

// This program calculates and outputs the money in cents.

#include "PPP.h";

int main()
{
	cout << "How many pennies do you have ? ";
	int pennies = 0;
	cin >> pennies;
	cout << "How many nickels do you have ? ";
	int nickels = 0;
	cin >> nickels;
	cout << "How many dimes do you have ? ";
	int dimes = 0;
	cin >> dimes;
	cout << "How many quarters do you have ? ";
	int quarters = 0;
	cin >> quarters;
	cout << "How many half dollars do you have ? ";
	int half_dollars = 0;
	cin >> half_dollars;
	cout << "How many one - dollars do you have ? ";
	int one_dollars = 0;
	cin >> one_dollars;
	cout << '\n';

	if (pennies > 1)
		cout << "You have " << pennies << " pennies.\n";
	if (pennies == 1)
		cout << "You have 1 pennie.\n";
	if (nickels > 1)
		cout << "You have " << nickels << " nickels.\n";
	if (nickels == 1)
		cout << "You have 1 nickel.\n";
	if (dimes > 1)
		cout << "You have " << dimes << " dimes.\n";
	if (dimes == 1)
		cout << "You have 1 dime.\n";
	if (quarters > 1)
		cout << "You have " << quarters << " quarters.\n";
	if (quarters == 1)
		cout << "You have 1 quarter.\n";
	if (half_dollars > 1)
		cout << "You have " << half_dollars << " half_dollars.\n";
	if (half_dollars == 1)
		cout << "You have 1 half_dollar.\n";
	if (one_dollars > 1)
		cout << "You have " << one_dollars << " one_dollars.\n";
	if (one_dollars == 1)
		cout << "You have 1 one_dollar.\n";

	int cents = pennies + nickels * 5 + dimes * 10 + quarters * 25 + half_dollars * 50 + one_dollars * 100;

	if (cents > 1)
		cout << "The value of all your coins is " << cents << " cents.\n";
	if (cents == 1)
		cout << "The value of all your coins is 1 cent.\n";
	if (cents <= 0)
		cout << "Sorry you have no money!\n";
}