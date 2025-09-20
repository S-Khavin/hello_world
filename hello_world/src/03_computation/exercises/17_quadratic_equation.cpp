 /*Write a program to solve quadratic equations. A quadratic equation is of the form ax2 + bx + c = 0. If you don’t know
the formula for solving such an expression, do some research. Remember, researching how to solve a problem is often
necessary before a programmer can teach the computer how to solve it. Use doubles for the user inputs for a, b, and c. Since
there are two solutions to a quadratic equation, output both x1 and x2.*/

// This program solves quadratic equations

#include "PPP.h";

int main()
{
	cout << "Enter three values seperated by space then press 'Enter' : ";
	double a = 0;
	double b = 0;
	double c = 0;
	cin >> a >> b >> c;

	double x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	double x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

	cout << "x1 == " << x1 
		<< "\nx2 == " << x2 << '\n';
}