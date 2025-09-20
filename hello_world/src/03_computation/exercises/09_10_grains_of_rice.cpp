 /*[9] There is an old story that the emperor wanted to thank the inventor of the game of chess and asked the inventor to name
his reward.The inventor asked for one grain of rice for the first square, 2 for the second, 4 for the third, and so on, doubling
for each of the 64 squares.That may sound modest, but there wasn’t that much rice in the empire! Write a program to
calculate how many squares are required to give the inventor at least 1000 grains of rice, at least 1, 000, 000 grains, and at
least 1, 000, 000, 000 grains.You’ll need a loop, of course, and probably an int to keep track of which square you are at, an int
to keep the number of grains on the current square, and an int to keep track of the grains on all previous squares.We suggest
that you write out the value of all your variables for each iteration of the loop so that you can see what’s going on.*/

 /*[10] Try to calculate the number of rice grains that the inventor asked for in exercise 9 above.You’ll find that the number is so
large that it won’t fit in an int or a double.Observe what happens when the number gets too large to represent exactly
as an int and as a double.What is the largest number of squares for which you can calculate the exact number of grains(using
an int) ? What is the largest number of squares for which you can calculate the approximate number of grains(using a double) ?*/

// This program calculate how many squares are required to give the chess inventor at least 1000, 1000000 and 1000000000 of grains.

#include "PPP.h";
int main()
{
	double total_grains = 0;
	double grains_current_square = 0;
	double atleast_1000 = 0;
	double atleast_1000000 = 0;
	double atleast_1000000000 = 0;

	for (int square = 1; square <= 64; ++square) {
		if (square == 1)
			++grains_current_square;
		else
			grains_current_square *= 2;

		total_grains += grains_current_square;
		
		cout << "Square == " << square
			<< "\nGrains in Current Square == " << grains_current_square 
			<< "\nTotal Grains == " << total_grains << "\n\n";

		// computes no of squares required to give the inventor atleast 1000, 1000000, 1000000000 of grains
		if (atleast_1000 == 0)
			if (total_grains > 1000)
				atleast_1000 = square;

		if (atleast_1000000 == 0)
			if (total_grains > 1000000)
				atleast_1000000 = square;

		if (atleast_1000000000 == 0)
			if (total_grains > 1000000000)
				atleast_1000000000 = square;
	}

	cout << "Squares are required to give the inventor at least 1000 grains of rice == " << atleast_1000
		<< "\nSquares are required to give the inventor at least 1000000 grains of rice == " << atleast_1000000
		<< "\nSquares are required to give the inventor at least 1000000000 grains of rice == " << atleast_1000000000 << '\n';

	/*What is the largest number of squares for which you can calculate the exact number of grains(using an int) ?
		Square == 31
		Grains in Current Square == 1073741824
		Total Grains == 2147483647*/

	/*What is the largest number of squares for which you can calculate the approximate number of grains(using a double) ?
		Square == 64
		Grains in Current Square == 9.22337e+18
		Total Grains == 1.84467e+19*/
}