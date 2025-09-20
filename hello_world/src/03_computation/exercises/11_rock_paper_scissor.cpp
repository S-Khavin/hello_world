 /*[11] Write a program that plays the game “Rock, Paper, Scissors.” If you are not familiar with the game do some research(e.g., on
the Web using Google).Research is a common task for programmers. Use a switch - statement to solve this exercise.
Also, the machine should give random answers(i.e., select the next rock, paper, or scissors randomly).Real randomness is too
hard to provide just now, so just build a vector with a sequence of values to be used as “the next value.” If you build the vector
into the program, it will always play the same game, so maybe you should let the user enter some values.Try variations to
make it less easy for the user to guess which move the machine will make next.*/

// This program plays the game "Rock, Paper, Scissors" with the user.

#include "PPP.h";

int main()
{
	// Vector to hold the machine's moves
	cout << "Enter the sequence for computer moves (Enter 'r' or 'p' or 's' and terminate with '|')\n";
	vector<char> computer_moves;	
	for (char computer_move; cin >> computer_move && computer_move != '|'; )
	{
		if (computer_move == 'r' || computer_move == 'p' || computer_move == 's')
			computer_moves.push_back(computer_move);
	}
	system("cls");

	char user_move = ' ';
	for (char x : computer_moves)
	{
		cout << "\nRock (r) , Paper (p), Scissors (s) : ";
		cin >> user_move;
		cout << "Your Move == " << user_move 
			<< "\nComputer Move == " << x << '\n';

		switch (user_move) {
		case 'r':
			switch (x)
			{
			case 'r':
				cout << "It's a Tie!";
				break;
			case 'p':
				cout << "Computer Wins!";
				break;
			case 's':
				cout << "You Win!";
				break;
			}
			break;
		case 'p':
			switch (x)
			{
			case 'r':
				cout << "You Win!";
				break;
			case 'p':
				cout << "It's a Tie!";
				break;
			case 's':
				cout << "Computer Wins!";
				break;
			}
			break;
		case 's':
			switch (x)
			{
			case 'r':
				cout << "Computer Wins!";
				break;
			case 'p':
				cout << "You Win!";
				break;
			case 's':
				cout << "It's a Tie!";
				break;
			}
			break;
		default:
			cout << "Sorry, I don't know what " << user_move << " means";
		}
		cout << "\n";
	}
}