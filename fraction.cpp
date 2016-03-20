
#include <iostream>
#include "fraction.h"
using namespace std;
// condition : a >= b
int fraction::gcd(int a, int b)
{
	if (b == 0) return a;

	return gcd(b, a%b);
}
void fraction::reduce()
{
	//using Euclid Algorithm to compute gcd
	int divisor = numerator > denominator ? gcd(numerator, denominator) : gcd(denominator, numerator);

	numerator /= divisor;
	denominator /= divisor;

	// change position of -
	if (numerator > 0 && denominator < 0)
	{
		numerator = -numerator;
		denominator = -denominator;
	}
}

fraction::operator double () const
{
	return double(numerator)/denominator;
}

ostream & operator << (ostream &os, const fraction &f)
{
	if (f.denominator == 1)
	{
		os << f.numerator;
	}
	else{
		os << f.numerator << "/" << f.denominator;
	}
	return os;
}

fraction fraction::operator+ (const fraction &f) const
{
	int n = numerator * f.denominator + f.numerator * denominator;
	int d = denominator * f.denominator;
	return fraction(n, d);
}

bool fraction::operator< (const fraction &f) const
{
	int n1 = numerator * f.denominator;
	int n2 = f.numerator * denominator;
	return n1 < n2;
}

bool fraction::operator> (const fraction &f) const
{
	if (*this < f || *this == f)
	{
		return false;
	}
	return true;
}
bool fraction::operator>= (const fraction &f) const
{
	return !(*this < f);
}
bool fraction::operator<= (const fraction &f) const
{
	return !(*this > f);
}
bool fraction::operator== (const fraction &f) const
{
	return numerator == f.numerator && denominator == f.denominator;
}
bool fraction::operator!= (const fraction &f) const
{
	return !(*this == f);
}

fraction &fraction::operator+= (const fraction &f)
{
	numerator = numerator * f.denominator + f.numerator * denominator;
	denominator = denominator * f.denominator;

	reduce();

	return *this;
}

fraction fraction::operator- (const fraction &f) const
{
	return *this + (-f);
}

fraction &fraction::operator-= (const fraction &f)
{
	return *this += (-f);
}


fraction fraction::operator* (const fraction &f) const
{
	int n = numerator *  f.numerator;
	int d = denominator * f.denominator;
	return fraction(n, d);
}


fraction &fraction::operator*= (const fraction &f)
{
	numerator *= f.numerator;
	denominator *= f.denominator;
	reduce();

	return *this;
}
fraction fraction::operator/ (const fraction &f) const
{
	if (f.numerator == 0)
	{
		return fraction();
	}

	fraction inverse(f.denominator, f.numerator);
	return *this * inverse;
}
fraction &fraction::operator/= (const fraction &f)
{
	if (f.numerator == 0)
	{
		numerator = 0;
		reduce();
	}
	else {
		fraction inverse(f.denominator, f.numerator);
		*this *= inverse;
	}

	return *this;
}

fraction fraction::operator+ (int n) const
{
	return *this + fraction(n);
}
fraction &fraction::operator+= (int n)
{
	return *this+=fraction(n);
}
fraction fraction::operator- (int n) const
{
	return *this - fraction(n);
}

double fraction::operator- (double n) const
{
	return numerator / double(denominator) - n;
}


fraction &fraction::operator-= (int n)
{
	return *this-=fraction(n);
}
fraction fraction::operator* (int n) const
{
	return *this *fraction(n);
}
fraction &fraction::operator*= (int n)
{
	return *this*=fraction(n);
}	
fraction fraction::operator/ (int n) const
{
	return *this / fraction(n);
}
fraction &fraction::operator/= (int n)
{
	return *this/=fraction(n);
}
