 /*[7] Quadratic equations are of the form a* x2 + b * x + c = 0. To solve these, one uses the quadratic formula :
.There is a problem, though : if b2 - 4ac is less than zero, then it will fail. Write a program that can
calculate x for a quadratic equation.Create a function that prints out the roots of a quadratic equation, given a, b, c.When
the program detects an equation with no real roots, have it print out a message. How do you know that your results are
plausible ? Can you check that they are correct ?*/


// This program solves quadratic equations

#include "PPP.h";

vector<double> roots_of_qe(double a, double b, double c)
{
	expect([&] {return a != 0; }, "a is 0, the equation is no longer a quadratic equation");
	double discriminant = b * b - 4 * a * c;
	if (0 > discriminant)
		return {};
	double x1 = (-b + sqrt(discriminant)) / (2 * a);
	double x2 = (-b - sqrt(discriminant)) / (2 * a);

	return { x1, x2 };
}

int main()
{
	cout << "Enter three values seperated by space then press 'Enter' : ";
	double a = 0;
	double b = 0;
	double c = 0;
	cin >> a >> b >> c;

	vector<double> roots = roots_of_qe(a, b, c);

	if (roots.size() == 0)
		cout << "The equation has no real roots." << '\n';
	else 
		if (roots[0] == roots[1])
			cout << "The single real root is == " << roots[0] << '\n';
		else
			cout << "The two real root are == " << roots[0] << ", " << roots[1] << '\n';
}