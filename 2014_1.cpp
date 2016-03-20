#include <iostream>

using namespace std;

int facto(int n)
{
	for (int i = 2; i < n; ++i)
	{
		if (n%i == 0)
		{
			return i;
		}
	}

	return 0;
}

int main()
{
	double n1 = 97343;
	double n2 = 2539619;
	double a1 = facto(n1);
	double a2 = facto(n2);
	cout << a1 << "  " << n1/a1 << endl;
	cout << a2 << "  " << n2/a2 << endl;
	return 0;
}