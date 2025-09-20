 /*Write a program that produces a simple form letter based on user input.Begin by typing the code from §2.1 prompting a
user to enter his or her first name and writing “Hello, first_name” where first_name is the name entered by the user.
Then modify your code as follows : change the prompt to “Enter the name of the person you want to write to” and change 
the output to “Dear first_name, ”.Don’t forget the comma.*/

 /*Add an introductory line or two, like “How are you ? I am fine.I miss you.” Be sure to indent the first line.Add a few
more lines of your choosing – it’s your letter*/

 /*Now prompt the user for the name of another friend and store it in friend_name.Add a line to your letter : “Have you
seen friend_name lately ? ”*/

 /*Prompt the user to enter the age of the recipient and assign it to an int variable age.Have your program write “I hear
you just had a birthday and you are age years old.” If age is 0 or less or 110 or more, call simple_error("you’re kidding!")
using simple_error() from PPP_support.*/

 /*Add this to your letter : If your friend is under 12, write “Next year you will be age + 1.” If your friend is 17, write 
“Next year you will be able to vote.” If your friend is over 70, write “Are you retired ? ” Check your program to make sure 
it responds appropriately to each kind of value.*/

// Add “Yours sincerely, ” followed by two blank lines for a signature, followed by your name.

// This program produces a simple form letter

#include "PPP.h";

int main()
{
	cout << "Enter the name of the person you want to write to (followed by 'enter'):\n";
	string first_name;		// first_name is a variable of type string
	cin >> first_name;		// read characters into first_name

	cout << "Enter your friend name to mention in this letter (followed by 'enter'):\n";
	string friend_name;
	cin >> friend_name;

	cout << "Enter the age of the recipient (followed by 'enter'):\n";
	int recipient_age = 0;
	cin >> recipient_age;

	if (recipient_age <= 0 || recipient_age > 110)
		simple_error("you’re kidding!");

	cout << "Dear " << first_name << ", \n\tHow are you ? I am fine. I miss you. I heard that you got married today.\n"
		<< "Congratulation on your getting married!\n\n"
		<< "\tHave you seen " << friend_name << " lately ?\n\n"
		<< "\tI hear you just had a birthday and you are " << recipient_age << " years old. ";

	if (recipient_age < 12)
		cout << "Next year you will be " << recipient_age + 1 << ".\n\n";
	
	if (recipient_age == 17)
		cout << "Next year you will be able to vote.\n\n";

	if (recipient_age > 70)
		cout << "Are you retired?\n\n";

	cout << "Yours sincerely, \n\n" << first_name << '\n';
}