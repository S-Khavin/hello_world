 /*[2] The following program takes in a temperature value in Celsius and converts it to Kelvin. This code has many errors in it. 
Find the errors, list them, and correct the code.

	double ctok(double c) // converts Celsius to Kelvin
	{
		int k = c + 273.25;
		return int
	}
	int main()
	{
		double c = 0; // declare input variable
		cin >> d; // retrieve temperature to input variable
		double k = ctok("c"); // convert temperature
		Cout << k << '/n'; // print out temperature
	}

[4] Do exercise 3 again, but this time handle the error inside
ctok().

[5] Add to the program so that it can also convert from Kelvin to
Celsius.

[6] Write a program that converts from Celsius to Fahrenheit and
from Fahrenheit to Celsius. Use estimation (§4.7.1) to see if
your results are plausible.
*/


// This program converts temperature value from Celsius to Kelvin.

#include "PPP.h"

double ctok(double c) // converts Celsius to Kelvin
{
	expect([&] { return -273.15 <= c; }, "Absolute zero is the lowest temperature that can be reached; it is - 273.15C, or 0K");
	double k = c + 273.15;
	return k;
}

double ktoc(double k) // converts Kelvin to Celsius
{
	expect([&] { return 0 <= k; }, "Absolute zero is the lowest temperature that can be reached; it is - 273.15C, or 0K");
	double c = k - 273.15;
	return c;
}

int main()
{
	try {
		cout << "Enter a value followed by unit to convert celsius to kelvin or vice versa : ";
		double val = 0;					// declare input variable
		string unit;					// unit to determine kelvin or celsius
		cin >> val >> unit;				// retrieve temperature to input variable
		if (!cin)
			error("couldn't read value in 'main()'");

		if (unit == "c" || unit == "celcius")
		{
			double k = 0;
			k = ctok(val);				// convert temperature from celcius to kelvin
			cout << k << "K\n";			// print out temperature in kelvin
		}
		else if (unit == "k" || unit == "kelvin")
		{
			double c = 0;
			c = ktoc(val);				// convert temperature from kelvin to celcius
			cout << c << "C\n";			// print out temperature in celsius
		}
		return 0;
	}
	catch (exception& e) 
	{
		cerr << "error : " << e.what() << '\n';

	}
	catch (...) 
	{
		cerr << "Oops: unknown exception!\n";
		return 2;
	}
}

 /* Compile-time errors :-
		d is not defined
		ctok expects double but passing int
		cout mispelled as Cout
		\n mispelled as /n
		returning keyword int instead of object
		semicolon missing in return
*/ 

/* Link-time errors :-
	   No link time error found
*/

/* Run-time errors :-
	   storing k as int instead of double
	   1 kelvin = 273.15 but it has 273.25
*/