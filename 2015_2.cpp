#include <iostream>
#include <cmath>
using namespace std;


int f(int a){
	if (a%2 == 0) // even
		return a/2;
	
	return (3*a + 1) / 2;

}

int c(int a)
{
	if (a == 1)
		return 0;

	int f_val = f(a);
	int n = 1;
	while(f_val > 1){
		f_val = f(f_val);
		n++;
	}
	return n;
}


int M(int l, int r)
{
	int max_c = 0;
	for (int i = l; i <= r; ++i)
	{
		int c_i= c(i);
		if (c_i > max_c)
		{
			max_c = c_i;
		}

	}

	return max_c;
}


int Sn(int n, int l, int r)
{
	int sum = 0;
	for (int i = l; i <= r; ++i)
	{
		int c_i = c(i);
		if (c_i == n)
		{
			sum += i;
		}
	}

	return sum;
}


int main()
{
	cout << c(1) << endl;
	cout << c(2) << endl;
	cout << c(3) << endl;
	cout << c(201503) << endl;
	cout << M(2*pow(10,5), 3* pow(10,5)) << endl;
	cout << Sn(99,1,pow(10,5)) << endl;

	return 0;
}


