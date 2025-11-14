import std;
int main()
{
	int i = 1;
	int x = ++i + i; // don’t: undefined order of evaluation
	std::cout << x;
}