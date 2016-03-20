#include <iostream>
#include <cmath>

using namespace std;

int fibonacci(int n, int F0, int F1)
{
	if (n == 0)
	{
		return F0;
	}

	if (n == 1)
	{
		return F1;
	}


	int a = F0, b= F1, c;
	for (int i = 2; i <= n; ++i)
	{
		c= a + b;
		a = b;
		b = c;
		
	}

	return c;
}

int flimit_phi(double epsilon, int F0, int F1)
{
	int F_n = F1, F_n_prev = F0;
	int n = 1;
	int F_n_next;
	double lim = (1+ sqrt(5) ) / 2.0;

	while(abs( (F_n / (double)F_n_prev) - lim) >= epsilon){
		F_n_next = F_n + F_n_prev;
		F_n_prev = F_n;
		F_n = F_n_next;

		n++;
	}

	return n;
}

double s_N (double x, int N, int F0, int F1)
{
	double sum = F0;
	int F_n = F1, F_n_prev = F0, F_n_next;

	for (int i = 0; i <= N; ++i)
	{
		sum += F_n * pow(x,i);

		F_n_next = F_n + F_n_prev;
		F_n_prev = F_n;
		F_n = F_n_next;
	}

	return sum;
}


int main()
{
	int F0 = 3, F1 = 4;
	double epsilon = pow(10, -6);

	cout << fibonacci(20, F0, F1) << endl;

	int n = flimit_phi(epsilon, F0, F1);
	int Fn = fibonacci(n, F0, F1);
	cout << n << "  " << Fn << endl;
	cout << s_N(0.1, 10, F0, F1) << endl;
}











