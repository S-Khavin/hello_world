/*
		This exercise and the next few require you to design and implement a Book class, such as you can imagine as part of
	software for a library. Class Book should have members for the ISBN, title, author, and copyright date. Also store data on
	whether or not the book is checked out. Create functions for returning those data values. Create functions for checking a
	book in and out. Do simple validation of data entered into a Book; for example, accept ISBNs only of the form n−n−n−x
	where n is an integer and x is a digit or a letter. Store an ISBN as a string.

		Add operators for the Book class. Have the == operator check whether the ISBN numbers are the same for two books. Have !=
	also compare the ISBN numbers. Have a << print out the title, author, and ISBN on separate lines.

		Create an enumerated type for the Book class called Genre. Have the types be fiction, nonfiction, periodical, biography,
	and children. Give each book a Genre and make appropriate changes to the Book constructor and member functions.

		Create a Patron class for the library. The class will have a user’s name, library card number, and library fees (if owed).
	Have functions that access this data, as well as a function to set the fee of the user. Have a helper function that returns a
	Boolean (bool) depending on whether or not the user owes a fee.

	This program is a simple library software which maintains some basic book informations in library.
*/

#include "PPP.h"

enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

vector<string> month_tbl = { "Not a month", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int to_int(Month m)
{
	return static_cast<int>(m);
}

Month int_to_month(int x)
// checked conversion
{
	if (x < to_int(Month::jan) || to_int(Month::dec) < x)
		error("bad month");
	return Month{ x };
}

ostream& operator<<(ostream& os, Month m)
{
	return os << month_tbl[to_int(m)];
}

Month operator++(Month& m)
{
	m = (m == Month::dec ? Month::jan : Month{ to_int(m) + 1 });
	return m;
}

struct Year {
	int y;
};

ostream& operator<<(ostream& os, Year y)
{
	return os << y.y;
}

class Date {
public:
	class Invalid {};					// to be used as exception
	Date() {};
	Date(Year y, Month m, int d);
	Date(Year y);
	bool is_valid();

	Year year() const { return y; }
	Month month() const { return m; }
	int day() const { return d; }

	void add_day(int n);
	void add_month(int n);
	void add_year(int n);
private:
	Year y{ 2000 };
	Month m = { Month::jan };
	int d = 1;
};

Date::Date(Year yy, Month mm, int dd)
	: y{ yy }, m{ mm }, d{ dd }
{
	if (!is_valid())
		throw Invalid{};
}

Date::Date(Year yy)
	: y{ yy }
{
}

bool Date::is_valid()
{
	bool isMonth = 0 < to_int(m) && to_int(m) < 13;
	bool isDay = 0 < d && d < 32;
	return isMonth && isDay;
}

void Date::add_day(int n)
{
	d += n;
}

void Date::add_month(int n)
{
	m = Month{ to_int(m) + n };
}

void Date::add_year(int n)
{
	y = Year{ y.y + n };
}

ostream& operator << (ostream& os, Date d)
{
	return os << d.year() << '/' << d.month() << '/' << d.day();
}

bool operator == (const Date& d1, const Date& d2)
{
	return d1.day() == d2.day()
		&& d1.month() == d2.month()
		&& d1.year() == d2.year();
}

bool operator != (const Date& d1, const Date& d2)
{
	return !(d1 == d2);
}

struct ISBN
{
	int n1, n2, n3;
	char ch;
};

string get_isbn_string(const ISBN& isbn)
{
	string converted;
	converted += to_string(isbn.n1) + '-' + to_string(isbn.n2) + '-' + to_string(isbn.n3) + '-' + isbn.ch;
	return converted;
}

enum class Genre {
	fiction, nonfiction, periodical, biography, children
};

int to_int(Genre g) 
{
	return static_cast<int>(g);
}

vector<string> genre_tbl = { "fiction", "nonfiction", "periodical", "biography", "children" };

ostream& operator<<(ostream& os, Genre g)
{
	return os << genre_tbl[to_int(g)];
}

class Book 
{
public:
	Book(string isbn, string title, string author, Genre genre, Date copyright_date) 
		: isbn{ isbn }, title{ title }, author{ author }, genre{ genre }, copyright_date { copyright_date }
	{}

	string get_isbn() const { return isbn; }
	string get_title() const { return title; }
	string get_author() const { return author; }
	Genre get_genre() const { return genre; }
	Date get_copyright_date() const { return copyright_date; }
	bool get_checked_out() const { return checked_out; }

	void check_out();
	void check_in();

private:
	string isbn;
	string title;
	string author;
	Genre genre;
	Date copyright_date;
	bool checked_out = false;
};

void Book::check_in() {
	expect([&] { return !checked_out; }, "Already checked in");
	checked_out = false;
}

void Book::check_out() {
	expect([&] { return checked_out; }, "Already checked out");
	checked_out = true;
}

bool operator == (Book& b1, Book& b2)
{
	return b1.get_isbn() == b2.get_isbn();
}

bool operator != (Book& b1, Book& b2)
{
	return !(b1.get_isbn() == b2.get_isbn());
}

ostream& operator<<(ostream& os, Book b)
{
	return os << b.get_title() << '\n' << b.get_author() << '\n' << b.get_isbn() << '\n';
}

class Patron {
public:
	Patron(string user_name, string lib_card_no) : un{user_name}, lcn {lib_card_no} {}
	Patron(string user_name, string lib_card_no, double lib_fees) : un{ user_name }, lcn{ lib_card_no }, lf{ lib_fees } {}

	string user_name() const { return un; }
	string lib_card_number() const { return lcn; }
	double lib_fees() const { return lf; }
private:
	string un;
	string lcn;
	double lf = 0;
};

ostream& operator<<(ostream& os, Patron p)
{
	return os << p.user_name() << " (" << p.lib_card_number() << ") " << '\n';
}

bool operator == (Patron& p1, Patron& p2)
{
	return p1.lib_card_number() == p2.lib_card_number();
}

bool owes_fee(const Patron& p)
{
	return p.lib_fees() > 0 ? true : false;
}

struct Transaction {
	Book b;
	Patron p;
	Date d;
};

class Library {
public:
	void add_book(Book&);
	void add_patron(Patron&);
	void checkout_book(Patron&, Book&);
	vector<Patron> patrons_with_fees();

private:
	vector<Book> books;
	vector<Patron> patrons;
	vector<Transaction> transactions;
};

void Library::add_book(Book& x)
{
	books.push_back(x);
}

void Library::add_patron(Patron& x)
{
	patrons.push_back(x);
}

void Library::checkout_book(Patron& a, Book& b)
{
	bool user_exists = false;
	for (Patron& x : patrons)
		if (x == a) user_exists = true;

	bool book_exists = false;
	for (Book& x : books)
		if (x == b) book_exists = true;

	if (!user_exists) error("Sorry, user does not belongs to library");
	if (!book_exists) error(b.get_title(), " is not available at the moment");

	if (owes_fee(a)) error(a.user_name(), " already has a fee");
	
	transactions.push_back(Transaction{ b, a, Date {Year{2025}, Month::nov, 8} });
}

vector<Patron> Library::patrons_with_fees() 
{
	vector<Patron> temp;
	for (const Patron& x : patrons)
		if (owes_fee(x)) temp.push_back(x);
	return temp;
}

void f() 
{
	Book book { get_isbn_string(ISBN {0, 0, 0, '1'}), "Programming Principles and Practice using C++ 3rd edition", "Bjarney Stroustrup", Genre::periodical, Date {Year {2024}, Month::jan, 1} };
	Patron client{ "Khavin", "QWERTY", 250 };
	Patron client2{ "Pradeep", "ASDFGH" };
	Library lib;
	lib.add_patron(client);
	lib.add_patron(client2);
	for (const Patron& x : lib.patrons_with_fees())
		cout << x << '\n';
}

int main()
try {
	f();
}
catch (exception& e)
{
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	cerr << "Oops, unexpected error occured!\n";
	return 2;
}