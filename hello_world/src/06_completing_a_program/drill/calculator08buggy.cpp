 /*
	Simple Calculator

	This program implements a basic expression calculator that can use variables
	Input from cin; output to cout.
	The grammar for input is:

	Calculation:
		Statement
		Print
		Quit
		Calculation Statement

	Statement:
		Declaration
		Expression
	
	Declaration:
		"#" Name "=" Expression

	Expression:
		Term
		Expression "+" Term
		Expression "-" Term

	Term:
		Primary
		Term "*" Primary
		Term "/" Primary
		Term "%" Primary

	Primary:
		Number
		"(" Expression ")"
		"-" Primary
		"+" Primary
		Number "k"
		"sqrt" "(" Expression ")"
		"pow" "(" Expression ")"

	Number:
		floating-point-literal

	Input comes from cin through the Token_stream called ts.
 */

#include "PPP.h"

constexpr char number = '8';		// number token
constexpr char output = ';';		
const string prompt = "> ";
const string result = "= ";
constexpr char name = 'a';			// name token
constexpr char thousand = 'k';		// k denotes thousand
constexpr char decl = '#';			// declaration token

constexpr char quit = 'q';			// quit token
const string quitkey = "exit";		// quit keyword

constexpr char sqroot = 'S';		// sqrt token
const string sqrootkey = "sqrt";	// sqrt keyword

constexpr char power = 'P';			// pow token
const string powerkey = "pow";		// pow keyword

class Token {
public:
	char kind;
	double value;
	string name;				// name of variable
	Token() :kind{ 0 } {}									// default constructor
	Token(char ch) :kind(ch), value(0) {}					// initialize kind with ch
	Token(char ch, double val) :kind(ch), value(val) {}		// initialize kind and value
	Token(char ch, string str) :kind(ch), name(str) {}		// initialize kind and name
};

class Token_stream {
public:
	Token get();				// get Token
	void putback(Token t);		// putback token into buffer
	void ignore(char ch);		// discard characters up to and including a c
private:
	bool full = false;
	Token buffer = 0;
};

Token Token_stream::get()
{
	if (full) { 
		full = false; 
		return buffer;		// if buffer full return buffer
	}

	// if buffer not full read from cin
	char ch;
	cin >> ch;

	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case output:
	case '=':
	case thousand:
	case ',':
	case decl:
		return Token(ch);
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	case '.':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token(number, val);
	}
	default:
		if (isalpha(ch)) {			// checks for variable
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
				s += ch;
			cin.putback(ch);
			if (s == sqrootkey)
				return Token{ sqroot };
			else if (s == powerkey)
				return Token{ power };
			else if (s == quitkey)
				return Token{ quit };
			else
				return Token(name, s);
		}
		error("Bad token");
	}
}

void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer = t;
	full = true;
}


void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch = 0;
	while (cin >> ch)
		if (ch == c) 
			return;
}

class Variable {
public:
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) {}
};

vector<Variable> var_table;		// remembers variable names and its corresponding value

double get_value(string s)
		// get value of the variable
{
	for (const Variable& v : var_table)
		if (v.name == s)
			return v.value;
	error("trying to read undefined variable ", s);
}

void set_value(string s, double d)
		// assign value to a variable
{
	for (Variable& v : var_table)
		if (v.name == s) {
			v.value = d;
			return;
		}
	error("trying to write undefined variable ", s);
}

bool is_declared(string s)
		// check for duplicate variable declaration
{
	for (const Variable& v : var_table)
		if (v.name == s)
			return true;
	return false;
}

double define_name(string var, double val)
		// creates new Variable
{
	if (is_declared(var))
		error(var, " declared twice");
	var_table.push_back(Variable{ var, val });
	return val;
}

Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("'(' expected");
		return d;
	}
	case '-':
		return -primary();
	case '+':
		return +primary();
	case number:
	{
		double val = t.value;
		t = ts.get();
		if (t.kind == thousand)
			val *= 1000;
		else ts.putback(t);
		return val;
	}
	case name:
		return get_value(t.name);	// return value of the variable
	case sqroot:
	{
		t = ts.get();
		if (t.kind != '(') error("'(' expected for sqrt");

		double d = expression();
		if (d < 0) error("expected positive number for sqrt");

		t = ts.get();
		if (t.kind != ')') error("'(' expected for sqrt");
		return sqrt(d);
	}
	case power:
	{
		t = ts.get();
		if (t.kind != '(') error("'(' expected for pow");
		double d = expression();

		t = ts.get();
		if (t.kind != ',') error("expected , for pow");

		int i = narrow<int>(expression());

		t = ts.get();
		if (t.kind != ')') error("'(' expected for sqrt");
		return pow(d, i);
	}
	default:
		ts.putback(t);				// token used by ignore
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		case '%':
		{
			double d = primary();
			if (d == 0) error("% : divide by zero");
			left = fmod(left, d);
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != name) 
		error("name expected in declaration");

	Token t2 = ts.get();
	if (t2.kind != '=') 
		error("= missing in declaration of ", t.name);
	double d = expression();
	define_name(t.name, d);
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case decl:
		return declaration();
	default:
		ts.putback(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(output);
}

void calculate()
{
	while (cin) 
	try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == output)
			t = ts.get();			// ignores output character
		if (t.kind == quit) 
			return;
		ts.putback(t);
		cout << result << statement() << '\n';
	}
	catch (runtime_error& e) {
		cerr << "error: " << e.what() << '\n';
		clean_up_mess();			// clean up only the error expression
	}
}

int main()
{
	try {
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		//char c;
		//while (cin >> c && c != ';');
		return 1;
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		//char c;
		//while (cin >> c && c != ';');
		return 2;
	}
}

 /*
Testing
1 + 2;
1 + 2 + 3;
1 + 2 * 3;
(1 + 2) * 3;
1 * 2 - 1;
1 / 2 + 0.5;
5.0 + 5.5;
5 + 5;
2 / 2;
2 % 2;
2 % 2.0;
2 % 2.2;
1 - 2;
2 - 2 - 2;
-1 + 1;
-1 - 1;
-1 - 1 + -1;
-1 - 1 + (-1);
1 / 0;
2 / 0;
900000000000000000000000000000000000000000000000000000000000000000 * 90000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
900000000000000.3 * 100000000000000000000;
0;
silly input
let a = 2;
let b = 3;
a + b;
b + a;
a* b;
b* a* a;
-a;
--a;
a+q;
a* b + c;
*/