 /*Get the “repeated word detection program” to run. Test
it with the sentence She she laughed "he he he!" because
what he did did not look very very good good. How many
repeated words were there? Why? What is the definition
of word used here? What is the definition of repeated
word? (For example, is She she a repetition?)*/

// This program detects repeated words in a sentence.

#include "PPP.h";

int main()	// reads a stream of words and reports if a word is repeated
{
	string previous;				// previous word; initialized to ""
	string current;					// current word
	while (cin >> current) {		// read a stream of words
		if (previous == current)	// check if the word is the same as last
			cout << "repeated word: " << current << '\n';
		previous = current;
	}
}

//  How many repeated words were there ? 3
//  Why ? the current word matches the previous word
//	What is the definition of word used here ? character string without any whitespace is called a word
//	What is the definition of repeated word ? (For example, is She she a repetition?) A word is said to be repeated if the current word is exactly the same as the previous word, including case sensitivity. So "She" and "she" are not considered repetitions.