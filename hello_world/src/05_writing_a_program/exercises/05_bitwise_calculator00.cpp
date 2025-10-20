 /*[5] Write a grammar for bitwise logical expressions.A bitwise logical expression is much like an arithmetic expression except
that the operators are !(not), ˜(complement), & (and), | (or ), and ˆ(exclusive or ).Each operator does its operation to each
bit of its integer operands(see PPP2.§25.5). !and ˜ are prefix unary operators.A ˆ binds tighter than a | (just as * binds
tighter than + ) so that x | yˆz means x | (yˆz)rather than(x | y)ˆz.The & operator binds tighter than ˆ so that xˆy & z means xˆ(y & z).*/

// a simple bitwise expression grammar:

/*
Expression:
	Term 1
	Expression "|" Term 1
Term 1:
	Term 2
	Term 1 "^" Term 2
Term 2:
	Unary
	Term 2 "&" Unary
Unary:
	Primary
	"~" Primary
Primary:
	Number
	"(" Expression ")"
Number:
	integer literal
*/

#include "PPP.h";

class Token {
public:
	char kind;
	int value;
	Token(char ch) : kind(ch), value(0){}
	Token(char ch, int val) : kind(ch), value(val) {}
};

class Token_stream {
public:
	Token get();
	void putback(Token t);
	Token_stream() : full(false), buffer(0) {}
private:
	bool full;
	Token buffer;
};

void Token_stream::putback(Token t) {
	if (full) error("putback() into full buffer");
	buffer = t;
	full = true;
}

Token Token_stream::get() {
	if (full)
	{
		full = false;
		return buffer;
	}
	
	char ch;
	cin >> ch;

	switch (ch) {
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);
		int val = 0;
		cin >> val;
		return Token{'8', val};
	}
	case 'x':	// quit
	case '=':	// print answer
	case '|': case '^': case '&': case '~': case '(': case ')':
		return Token{ ch };
	default:
		error("Bad token");
	}
}

Token_stream ts;

int expression();	// forward declaration to make use in primary()

int primary() {
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		int x = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return x;
	}
	case '8':
		return t.value;
	default:
		error("primary expected");
	}
}

int unary() {
	Token t = 0;
	int unary_op_repeat = 0;
	while (true)
	{
		t = ts.get();
		if(t.kind == '~')
			++unary_op_repeat;
		else
		{
			ts.putback(t);
			break;
		}
	}

	if (!unary_op_repeat)
	{
		return primary();
	}
	else
	{
		int right = primary();
		for(int i = 1; i <= unary_op_repeat; ++i)
			right = ~right;
		return right;
	}
}

int term_2() {
	int left = unary();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '&':
			left &= unary();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

int term_1() {
	int left = term_2();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '^':
			left ^= term_2();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

int expression() {
	int left = term_1();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '|':
			left |= term_1();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

int main()
{
	try {
		cout << "Welcome to our simple bitwise logical calculator.\n"
			<< "The operation that you can preform are | ^ & ~/\n"
			<< "To exit calculator press 'x' followed by 'Enter' to exit.\n"
			<< "Please enter expressions using integer numbers and press '=' followed by 'Enter' to get result.\n\n";

		int val = 0;
		while (cin) {
			Token t = ts.get();

			if (t.kind == 'x') break; // 'x' for quit
			if (t.kind == '=')        // '=' for "print now"
				cout << val << '\n';
			else
				ts.putback(t);
			val = expression();
		}

	}
	catch (exception& e)
	{
		cerr << "error: " << e.what() << '\n';
	}
	catch (...)
	{
		cerr << "Oops: unknown exception!\n";
	}
}