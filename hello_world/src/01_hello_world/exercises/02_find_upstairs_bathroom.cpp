 /*Expanding on what you have learned, write a program that
lists the instructions for a computer to find the upstairs
bathroom, discussed in §1.1. Can you think of any more steps
that a person would assume, but that a computer would not?
Add them to your list. This is a good start in “thinking like a
computer.” Warning: For most people, “go to the bathroom” is
a perfectly adequate instruction. For someone with no
experience with houses or bathrooms (imagine a stone-age
person, somehow transported into your dining room) the list of
necessary instructions could be very long. Please don’t use
more than a page. For the benefit of the reader, you may add a
short description of the layout of the house you are imagining.*/

// This program instructs a computer precisely to find the upstairs bathroom

// layout of the house : My house has two floors.The ground floor has a staircase, a kitchen with dining area, a living room, storage room.The top floor has 2 bedrooms, a bathroom.

// I am assuming the computer is sitting in the living room watching Television.

import std;

int main()
{
	std::cout << "01. Stand up from the sofa.\n"
		<< "02. Turn right.\n"
		<< "03. Walk forward 5 steps to reach the living room door.\n"
		<< "04. Step out of the door.\n"
		<< "05. Look 45 degrees from your right to see the staircase.\n"
		<< "06. Walk forward 5 steps to reach the staircase.\n"
		<< "07. Hold the handrail with your right hand.\n"
		<< "08. Climb up the staircase step by step until you reach the top.\n"
		<< "09. Turn left to face the bathroom door.\n"
		<< "10. Open the bathroom door.\n"
		<< "11. Step into the bathroom.\n"
		<< "12. Close the bathroom door.\n"
		<< "13. You have reached the upstairs bathroom.\n";
	return 0;
}