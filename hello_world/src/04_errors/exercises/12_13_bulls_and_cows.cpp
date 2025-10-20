// This program prints 4 bulls if the user guesses the correct digits

#include "PPP.h"

vector<int> calculate_bulls_and_cows(vector<int> num_to_guess, vector<int> num_guessed)
	// num_to_guess.size() == num_guessed.size()
{
	expect([&] {return num_to_guess.size() == num_guessed.size(); }, "bad arguments to bulls_and_cows_game()");
	int bulls = 0;
	int cows = 0;

	// calculates Bulls:
	for (int i = 0; i < num_guessed.size(); ++i)
		if (num_guessed[i] == num_to_guess[i])
			++bulls;

	// calculates Cows:
	for (int i = 0; i < num_guessed.size(); ++i)
		for (int j = 0; j < num_to_guess.size(); ++j)
			if (num_guessed[i] == num_to_guess[j] && i != j)
				++cows;

	expect([&] {return 0 <= bulls && 0 <= cows; }, "bad bulls_and_cows_game() result");
	return { bulls, cows };
}


vector<int> generate_unique_int_vector(int x)
{
	vector<int> unique_int_vector;
	while (unique_int_vector.size() != x)
	{
		int random_val = random_int(0, 9);
		bool is_unique = true;
		for (int j = 0; j < unique_int_vector.size(); ++j)
			if (unique_int_vector[j] == random_val)
				is_unique = false;
		if (is_unique)
			unique_int_vector.push_back(random_val);
	}

	return unique_int_vector;
}

vector<int> read_int_vector(int n)
{
	vector<int> int_vector;
	for (int i = 0; i < n; ++i)
	{
		int x = 0;
		cin >> x;
		if (!cin)
			error("unable to read value in guessing_game()");
		int_vector.push_back(x);
	}

	return int_vector;
}

void guessing_game() 
{
	cout << "Enter any number to seed: ";
	int seed_num = 0;
	cin >> seed_num;
	if (!cin)
		error("unable to read int in guessing_game()");
	seed(seed_num);

	vector<int> num_to_guess = generate_unique_int_vector(4);

	cout << "Size == " << num_to_guess.size();

	int bulls = 0;
	int cows = 0;

	while (bulls != 4 && cin)
	{
		cout << "Enter 4 digit number seperated by space to guess the value: ";
		vector<int> num_guessed = read_int_vector(4);

		vector<int> bulls_and_cows = calculate_bulls_and_cows(num_to_guess, num_guessed);
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


















