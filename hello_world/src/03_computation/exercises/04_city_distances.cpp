 /*[4] Read a sequence of double values into a vector.Think of each value as the distance between two cities along a given route.
Compute and print the total distance(the sum of all distances). Find and print the smallest and greatest distance between two
neighboring cities.Find and print the mean distance between two neighboring cities.*/

// This program reads a sequence of distance of cities along a given route and prints the total distance, smallest and greatest distance and mean distance.

#include "PPP.h";

int main()
{
	vector<double> distances;	// distance of cities along a given route
	for (double distance; cin >> distance;)
		distances.push_back(distance);

	// compute total distance:
	double sum = 0;
	for (double x : distances)
		sum += x;
	cout << "Total distance : " << sum << '\n';

	// finds smallest and greatest distance between two neighboring cities:
	ranges::sort(distances);
	cout << "Smallest distance : " << distances[0];
	cout << "Greatest distance : " << distances[distances.size() - 1];

	// computes mean distance:
	cout << "Average distance : " << sum / distances.size() << '\n';
}