 /*Write a program that “bleeps” out words that you don’t like; that is, you read in words using cin and print them again on cout.
If a word is among a few you have defined, you write out BLEEP instead of that word.Start with one “disliked word” such as
string disliked = "Broccoli"; When that works, add a few more.*/

// This programs prints "bleeps" if there is a disliked word among the sequence of words, Otherwise it prints the word as it is.

#include "PPP.h";

int main()
// simple dictionary: list of sorted words
{
	vector<string> disliked = { "Broccoli", "Sorry", "Cannot" };
	vector<string> words;

	for (string temp; cin >> temp;)		// read whitespace-seperated words
		words.push_back(temp);			// put into vector
	cout << "Number of words : " << words.size() << '\n';

	for (int i = 0; i < words.size(); ++i)
		if (words[i] == disliked[0] || words[i] == disliked[1] || words[i] == disliked[2])		// is this word Broccoli or Sorry or Cannot?
				cout << "bleeps\n";
		else 
			cout << words[i] << "\n";
}