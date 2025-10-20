// This program prints 4 bulls if the user guesses the correct letters

#include "PPP.h"

vector<int> calculate_bulls_and_cows(vector<char> letters_to_guess, vector<char> letters_guessed)
// letters_to_guess.size() == letters_guessed.size()
{
	expect([&] {return letters_to_guess.size() == letters_guessed.size(); }, "bad arguments to bulls_and_cows_game()");
	int bulls = 0;
	int cows = 0;

	// calculates Bulls:
	for (int i = 0; i < letters_guessed.size(); ++i)
		if (letters_guessed[i] == letters_to_guess[i])
			++bulls;

	// calculates Cows:
	for (int i = 0; i < letters_guessed.size(); ++i)
		for (int j = 0; j < letters_to_guess.size(); ++j)
			if (letters_guessed[i] == letters_to_guess[j] && i != j)
				++cows;

	expect([&] {return 0 <= bulls && 0 <= cows; }, "bad bulls_and_cows_game() result");
	return { bulls, cows };
}


vector<char> generate_unique_char_vector(int x)
{
	vector<char> unique_int_vector;
	while (unique_int_vector.size() != x)
	{
		char random_val = random_int('a', 'z');
		bool is_unique = true;
		for (int j = 0; j < unique_int_vector.size(); ++j)
			if (unique_int_vector[j] == random_val)
				is_unique = false;
		if (is_unique)
			unique_int_vector.push_back(random_val);
	}

	return unique_int_vector;
}

vector<char> read_char_vector(char n)
{
	vector<char> char_vector;
	for (int i = 0; i < n; ++i)
	{
		char x = ' ';
		cin >> x;
		if (!cin)
			error("unable to read value in guessing_game()");
		if (!('a' <= x && x <= 'z'))
			error("invalid letter");
		char_vector.push_back(x);
	}

	return char_vector;
}

void guessing_game()
{
	cout << "Enter any number to seed: ";
	int seed_num = 0;
	cin >> seed_num;
	if (!cin)
		error("unable to read int in guessing_game()");
	seed(seed_num);

	vector<char> letters_to_guess = generate_unique_char_vector(4);

	int bulls = 0;
	int cows = 0;

	while (bulls != 4 && cin)
	{
		cout << "Enter 4 letters to guess the letters: ";
		vector<char> letters_guessed = read_char_vector(4);

		vector<int> bulls_and_cows = calculate_bulls_and_cows(letters_to_guess, letters_guessed);
		bulls = bulls_and_cows[0];
		cows = bulls_and_cows[1];

		if (bulls == 4)
			cout << "Congratulations! on getting 4 bulls, you guessed the number!\n\n";
		else
			cout << bulls << " Bull and " << cows << " Cow\n";
	}
}

int main()
{
	try {

		while (true)
		{
			cout << "Play Game? (enter 'y' or 'n'): ";
			char play_game;
			cin >> play_game;
			if (!cin)
				error("unable to read int in main()");

			if (play_game == 'y')
				guessing_game();
			else
				return 0;
		}

		return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops, unknown exception!\n";
		return 2;
	}
}