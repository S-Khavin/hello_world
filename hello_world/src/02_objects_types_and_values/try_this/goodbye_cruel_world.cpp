 /*Compile the “Goodbye, cruel world!” program and
examine the error messages.Did the compiler find all
the errors ? What did it suggest as the problems ? Did the
compiler get confused and diagnose more than four
errors ? Remove the errors one by one, starting with the
lexically first, and see how the error messages change
(and improve).*/

// This program is for understanding errors that can occurs if names are not used correctly

import std;

int Main()
{
	std::string s = "Goodbye, cruel world!\n";
	std::cout << s << '\n';
}

 /*Did the compiler find all the errors ? 
	Yes, but at first it found only five errors, after fixing all those and recompiling it found one more error.
	'Main': must return a value

	then after adding return 0; at the end of Main it compiled successfully. but link failed because of missing main function.
	unresolved external symbol main referenced in function "int __cdecl invoke_main(void)" (?invoke_main@@YAHXZ)
	1 unresolved externals

	why did it not find all the errors at first ?
	It stops after finding a certain number of errors. 

	Explaination from gemini:-
	1. That's an excellent and very subtle question about how a C++ compiler works. The error 'Main': must return a value isn't shown in your first program because it had even more fundamental errors that the compiler needed to address first.
	2. The compiler processes code in a specific order. When it encountered STRING, cOut, and S, it immediately failed because these are not valid C++ keywords or identifiers. These are syntax errors (incorrect grammar) and undeclared identifier errors.
	3. The compiler stops at the first critical errors it finds. It couldn't even get to the point of checking whether the Main() function had a return statement because it couldn't correctly understand or parse the code inside the function body.
	4. Once you fixed the syntax and capitalization errors (string, cout, s), the compiler was then able to fully read and parse the function's contents. At that point, it performed a more thorough check and discovered the logical error: that a function declared to return an int (int Main()) did not have a return statement.
	*/

 /*What did it suggest as the problems ? 
	'STRING': undeclared identifier
	syntax error : missing ';' before identifier 's'
	's' : undeclared identifier
	'cOut' : undeclared identifier
	'S' : undeclared identifier*/

//Did the compiler get confused and diagnose more than four errors ? Yes