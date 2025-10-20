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
		Assignment
		Expression
		Statement ";"
	
	Declaration:
		"#" Name "=" Expression
		const "#" Name "=" Expression

	Assignment:
		Name "=" Expression

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

	Name:
		seqence of letters
		digits starting with a letter
		underscores starting with a letter

	Input comes from cin through the Token_stream called ts.
 */

#include "PPP.h"

constexpr char number = '8';		// number token
constexpr char name = 'a';			// name token
constexpr char thousand = 'k';
constexpr char decl = '#';			// declaration token
constexpr char quit = 'q';			
constexpr char sqroot = 'S';		// sqroot denotes sqrt function
constexpr char power = 'P';			// P denotes pow function token
constexpr char output = ';';
constexpr char constant = 'C';
constexpr char help = 'h';

const string quitkey = "quit";		// quit keyword
const string sqrootkey = "sqrt";	// sqrt keyword
const string powerkey = "pow";		// pow keyword
const string prompt = "> ";
const string result = "= ";
const string constkey = "const";
const string helpkey = "help";

constexpr int max_buffer_size = 2;

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
	vector<Token> buffer;
};

Token Token_stream::get()
{
	if (buffer.size()) {
		Token temp = buffer.back();
		buffer.pop_back();		// Removes the last element of the buffer
		full = false;
		return temp;			// return removed buffer element
	}

	// if buffer is empty read from cin
	char ch;
	cin.get(ch);				// reads with whitespace characters

	if (isspace(ch))
	{
		switch (ch) {
		case '\n':
			return Token{ output };
		default:
			cin >> ch;			// ignores whitespaces
		}
	}

	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '=':
	case ',':
	case decl:
	case output:
	case thousand:
		return Token(ch);
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	case '.':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		int x = 0;
		return Token(number, narrow<int>(val));
	}
	default:
		if (isalpha(ch)) {			// checks for variable
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
				s += ch;
			cin.putback(ch);
			if (s == sqrootkey)
				return Token{ sqroot };
			else if (s == powerkey)
				return Token{ power };
			else if (s == quitkey)
				return Token{ quit };
			else if (s == constkey)
				return Token{ constant };
			else if (s == helpkey)
				return Token{ help };
			else
				return Token(name, s);
		}
			error("Bad token");
	}
}

void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer.push_back(t);
	if (buffer.size() == max_buffer_size) full = true;
}

void Token_stream::ignore(char c)
{
	if (buffer.size() && c == buffer.back().kind) {
		buffer.pop_back();
		full = false;
		return;
	}
	full = false;

	char ch = 0;
	while (cin.get(ch))
		if (ch == c)
			return;
}

class Variable {
public:
	string name;
	double value;
	bool isConst = false;
	Variable(string n, double v, bool b) :name(n), value(v), isConst(b) {}
};

class Symbol_table {
	public:
		vector<Variable> var_table;
		double get(string name);
		void set(string name, double value);
		bool is_declared(string name);
		double define(string name, double value, bool isConst);
};

double Symbol_table::get(string s)
		// get value of the variable from var_table
{
	for (const Variable& v : var_table)
		if (v.name == s)
			return v.value;
	error("trying to read undefined variable ", s);
}

void Symbol_table::set(string s, double d)
		// assign value to a variable from var_table
{
	for (Variable& v : var_table)
		if (v.name == s) {
			if (v.isConst) error("trying to write constant variable ", s);
			v.value = d;
			return;
		}
	error("trying to write undefined variable ", s);
}

bool Symbol_table::is_declared(string s)
		// check for duplicate variable declaration
{
	for (const Variable& v : var_table)
		if (v.name == s)
			return true;
	return false;
}

double Symbol_table::define(string var, double val, bool isConst)
		// creates new Variable with value
{
	if (is_declared(var))
		error(var, " declared twice");
	var_table.push_back(Variable{ var, val, isConst });
	return val;
}

Token_stream ts;
Symbol_table st;

double expression();	// forward declaration

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
		return st.get(t.name);	// return value of the variable
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
	// handles '*', '/' and '%'
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
	// handles '+' and '-'
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

double declaration(bool isConst)
	// declares a new variable
{
	Token t = ts.get();
	if (t.kind != name) 
		error("name expected in declaration");

	Token t2 = ts.get();
	if (t2.kind != '=') 
		error("= missing in declaration of ", t.name);
	double d = expression();
	st.define(t.name, d, isConst);
	return d;
}

double assignment(Token t)
	// assign new values for declared variable
{
	Token t2 = ts.get();
	if (t2.kind == '=') {
		double d = expression();
		st.set(t.name, d);
		return d;
	}

	/*if not assignment statement then putbacks name and next token 
	into Token Stream's buffer to used by expression() */
	ts.putback(t2);
	ts.putback(t);
	return expression();
}

double statement()
{
	Token t = ts.get();
	bool isConst = false;
	switch (t.kind) {
	case constant:
		t = ts.get();
		if (t.kind != decl) error("invalid const declaration statement");
		isConst = true;
		[[fallthrough]];
	case decl:
		return declaration(isConst);
	case name:
		return assignment(t);	// assignment needs declared name
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

		switch (t.kind) {
		case quit:
			return;
		case 'h':
		case 'H':
			cout << "#\tdeclaration\n"
				<< "=\tassignment\n"
				<< "k\tthousand\n"
				<< ";\tprints output\n"
				<< "h\thelp\n"
				<< "H\thelp\n"
				<< "exit\tends calculator program\n\n";
			[[fallthrough]];
		default:
			ts.putback(t);
			cout << result << statement() << "\n\n";
		}
	}
	catch (runtime_error& e) {
		cerr << "error: " << e.what() << '\n';
		clean_up_mess();			// clean up only the error expression
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		calculate();
		return;
	}
}

int main()
{
	try {
		st.define("pi", 3.1415926535, true);	// true defines constant variable
		st.define("e", 2.7182818284, true);
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
# a = 2;
# b = 3;
a + b;
b + a;
a* b;
b* a* a;
-a;
--a;
a+exit;
a* b + c;
*/