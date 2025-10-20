 /*Try This
Feed a few such “problematic” expressions to the calculator and try to figure out in how many ways you
can get it to misbehave.Can you get it to crash, that is, to get it past our error handling and give a machine
error ? We don’t think you can.Can you get it to exit without a useful error message ? You can.*/



//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//#include "../std_lib_facilities.h"
#include "PPP.h"

constexpr char number = '8';        // t.kind == number means that t is a number Token
constexpr char quit = 'q';          // t.kind == quit means that t is a quit Token
constexpr char print_char = ';';         // t.kind == print_char means that t is a print_char Token
const string prompt = "> ";     
const string result = "= ";     // used to indicate that what follows is a result

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) {
    }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) {
    }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char c);    // discards character upto and including c
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {         // check if we already have a Token ready
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;          // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case print_char:
    case quit:
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
        return Token{ ch };                             // let each character represent itself
    case '.':                                           // a floating-point-literal can start with a dot
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':   // numeric literal
    {   cin.putback(ch);                                // put digit back into the input stream
        double val;
        cin >> val;                                     // read a floating-point number
        return Token{ number, val };
    }
    default:
        error("Bad token");
    }
}

void Token_stream::ignore(char c)
// c represents the kind of Token
{
    if (full && c == buffer.kind) { // first look in buffer
        full = false;
        return;
    }
    full = false;
    // now search input:
    char ch = 0;
    while (cin >> ch)
        if (ch == c)
            return;
}
//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case number:            // we use '8' to represent a number
        return t.value;  // return the number's value
    case '-':
        return -primary();
    case '+':
        return +primary();
    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            int i1 = narrow<int>(left);
            int i2 = narrow<int>(primary());

            //double d = primary();
            if (i2 == 0) error("divide by zero");
            //left = fmod(left, d);
            left = i1 % i2;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

void clean_up_mess() // naive
{
    ts.ignore(print_char);
}
//------------------------------------------------------------------------------

void calculate()
    // expression evaluation loop
{
    while (cin) 
    try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print_char)    // first discards all "print_char"
            t = ts.get();
        if (t.kind == quit)
            return;
        ts.putback(t);
        cout << result << expression() << '\n';
    }
    catch (exception& e) {
        cerr << e.what() << '\n';       // write error message
        clean_up_mess();
    }
}

int main()
try
{
    calculate();
    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    return 2;
}

//------------------------------------------------------------------------------
