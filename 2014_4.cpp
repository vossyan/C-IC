#include <iostream>
#include <cmath>
#include "fraction.h"

using namespace std;


/*====================================================
Global functions for int fraction operators
======================================================*/

fraction operator+ (int n, const fraction & f) 
{
	return fraction(n) + f;
}

fraction operator- (int n, const fraction & f)
{
	return fraction(n) - f;
}

fraction operator* (int n, const fraction & f)
{
	return fraction(n) * f;
}

fraction operator/ (int n, const fraction & f)
{
	return fraction(n) / f;
}

fraction pow(const fraction & f, int n)
{
	fraction product(1);
	for (int i = 0; i < n; ++i)
	{
		product = product * f;
	}

	return product;
}



template <typename T>
T gibonacci(int n, const T & F0,  const T & F1)
{
	if (n == 0)
	{
		return F0;
	}

	if (n == 1)
	{
		return F1;
	}


	T a = F0, b= F1, c;
	for (int i = 2; i <= n; ++i)
	{
		c = a + b;
		a = b;
		b = c;
		
	}

	return c;
}


template <typename T>
T glimit_phi(double epsilon,  const T & F0,  const T & F1)
{
	T F_n = F1, F_n_prev = F0;
	int n = 1;
	T F_n_next;
	double lim = (1+ sqrt(5) ) / 2.0;

	while(abs( (F_n / F_n_prev) - lim) >= epsilon){
		F_n_next = F_n + F_n_prev;
		F_n_prev = F_n;
		F_n = F_n_next;

		n++;
	}

	return n;
}


template <typename T1, typename T2>
T2 r_N (const T2 & x, int N,  const T1 & F0,  const T1& F1)
{
	T2 sum = pow(x, 0) * F0;
	T1 F_n = F1, F_n_prev = F0, F_n_next;

	for (int i = 1; i <= N; ++i)
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
	fraction G0(1,2), G1(1,3);
	double epsilon = pow(10, -6);

	cout << gibonacci<fraction>(20, G0, G1) << endl;

	int n = glimit_phi(epsilon, G0, G1);
	fraction Gn = gibonacci<fraction>(n, G0, G1);
	cout << n << "  " << Gn << endl;
	cout << r_N(fraction(3,8), 5, G0, G1) << endl;

	cout << endl;

	cout << gibonacci<short>(90,0,1) << endl;
	cout << gibonacci<unsigned int>(90,0,1) << endl;
	cout << gibonacci<unsigned long>(90,0,1) << endl;
	cout << gibonacci<float>(90,0,1) << endl;

}











