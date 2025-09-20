 /*[5] Write a program to play a numbers guessing game.The user thinks of a number between 1 and 100 and your program asks
questions to figure out what the number is(e.g., “Is the number you are thinking of less than 50 ? ”).Your program should be
able to identify the number after asking no more than seven questions.*/

// Think of a number between 1 and 100, this program identify the number

#include "PPP.h"

int main()
{
	vector<int> numbers;
	for (int i = 1; i <= 100; ++i)
		numbers.push_back(i);
	
	char answer = ' ';
	while (numbers.size() != 1)
	{
		cout << "Is the number you are thinking of less than " << numbers[numbers.size() / 2] << " ? ";
		cin >> answer;

		switch (answer)
		{
		case 'y':
			numbers.erase(numbers.begin() + numbers.size() / 2, numbers.end());
			break;

		case 'n':
			numbers.erase(numbers.begin(), numbers.begin() + numbers.size() / 2);
			break;

		default:
			cout << "Sorry I don't know what " << answer << " means.\n";
		}
	}

	cout << "The number is : " << numbers[0];
}