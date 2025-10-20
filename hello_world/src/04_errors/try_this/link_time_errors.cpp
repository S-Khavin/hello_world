// This program demonstrates the link-time errors

int area(int length, int width);	// calculate area of a rectangle

int main()
{
	int x = area(2, 3);
}