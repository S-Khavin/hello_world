 /*Write a program that takes an operation followed by two operands and outputs the result.For example :
+100 3.14
* 45
Read the operation into a string called operation and use an ifstatement to figure out which operation the user wants, for
example, if (operation == "+").Read the operands into variables
of type double.Implement this for operations called + , −, *, / ,
plus, minus, mul, and div with their obvious meanings.*/

// This program that takes an operation followed by two operands and outputs the result

#include "PPP.h";

int main()
{
	cout << "Enter an operation followed by two operands : ";
	string operation;
	double operand_1 = 0.0;
	double operand_2 = 0.0;
	cin >> operation >> operand_1 >> operand_2;

	if (operation == "+" || operation == "plus")
		cout << operand_1 << " + " << operand_2 << " == " << operand_1 + operand_2 << '\n';
	if (operation == "-" || operation == "minus")
		cout << operand_1 << " - " << operand_2 << " == " << operand_1 - operand_2 << '\n';
	if (operation == "*" || operation == "mul")
		cout << operand_1 << " * " << operand_2 << " == " << operand_1 * operand_2 << '\n';
	if (operation == "/" || operation == "div")
		cout << operand_1 << " / " << operand_2 << " == " << operand_1 / operand_2 << '\n';
}