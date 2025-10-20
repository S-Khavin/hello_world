 /*Try This
	Test this program with a variety of values. Print out the values of area1, area2, area3, and ratio. Insert more tests
	until all errors are caught. How do you know that you caught all errors ? This is not a trick question. In this
	particular example, you can give a valid argument for having caught all errors.*/


// This program explains the problems that occurs at this error reporting approach

#include "PPP.h"

int area(int length, int width)
// calculate area of a rectangle
// return -1 to indicate a bad argument
{
	if (length <= 0 || width <= 0)
		return -1;
	return length * width;
}

int framed_area(int x, int y)
	// calculate area with frame
{
	constexpr int frame_width = 2;
	if (x - frame_width <= 0 || y - frame_width <= 0)
		error("non-positive area() argument called by framed_area()");
	return area(x - frame_width, y - frame_width);
}

int f(int x, int y, int z)
{
	int area1 = area(x, y);
	if (area1 <= 0)
		error("non-positive area");
	int area2 = framed_area(1, z);
	int area3 = framed_area(y, z);
	double ratio = double(area1 / area3);
	return ratio;
}

int main()
{
	cout << "ratio of f(0, 0, 0) == " << f(-1, 2, 3);
}