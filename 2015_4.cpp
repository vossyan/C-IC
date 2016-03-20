#include <cmath>
#include <iostream>

#define PRIME 79


using namespace std;

template <unsigned int p>
class primefield{
	unsigned int v;
public:
	primefield(unsigned int v);

	unsigned int getv()const;
	primefield<p> operator/(const primefield<p> & a) const;
	primefield<p> operator+(const primefield<p> & a) const;
	primefield<p> operator-(const primefield<p> & a) const;
	primefield<p> operator*(const primefield<p> & a) const;
	primefield<p>& operator+=(const primefield<p> & a);

	friend ostream& operator<<(ostream & os, const primefield<p> & a){
		os <<a.v;
		return os;
	}
};


template <unsigned int p>
unsigned int primefield<p>::getv()const
{
	return this->v;
}

template <unsigned int p>
primefield<p>::primefield(unsigned int v)
{
	this->v = v % p;
}

template <unsigned int p>
primefield<p> primefield<p>::operator/(const primefield<p> & a) const 
{

	 

	return *this * power(a, p-2);
}

template <unsigned int p>
primefield<p> primefield<p>::operator+(const primefield<p> & a) const
{
	int res = this->v + a.v;
	res = res%p;

	return primefield<p>(res);

}


template <unsigned int p>
primefield<p> primefield<p>::operator-(const primefield<p> & a) const
{
	int res = this->v - a.v;
	if (res < 0)
	{
		res+= p;
	}
	res = res%p;

	return primefield<p>(res);
}


template <unsigned int p>
primefield<p> primefield<p>::operator*(const primefield<p> & a) const
{
	int res = this->v * a.v;
	res = res%p;

	return primefield<p>(res);
}

template <unsigned int p>
primefield<p>& primefield<p>::operator+=(const primefield<p> & a)
{
	this->v += a.v;
	this->v = this->v%p;

	return *this;
}

template <unsigned int p>
primefield<p> power(const primefield<p> & a, unsigned int n)
{
	primefield<p> res(1);
	for (int i = 0; i < n; ++i)
	{
		res = res * a;
	}
	return res;
}

template <unsigned int p>
primefield<p> factorial(const primefield<p> & a)
{
	primefield<p> product(1);
	for (int i = 1; i <= a.getv(); ++i)
	{
		product = product * primefield<p>(i);
	}

	return product;
}


int main() {
	primefield<PRIME> partial_sum(0);
	for (unsigned int i = 1; i <= 50; ++i) {
		partial_sum += primefield<PRIME>(1) / primefield<PRIME>(i);
	}
	cout << "sum_i=1^50 1/i = " << partial_sum << endl;
	unsigned int aa, bb;
	cout << "a, b = "; cin >> aa >> bb;
	primefield<PRIME> a(aa), b(bb);
	cout << "a + b = " << a + b << endl;
	cout << "a - b = " << a - b << endl;
	cout << "a * b = " << a * b << endl;
	cout << "a / b = " << a / b << endl;
	cout << "a^10 = " << power(a, 10) << endl;
	cout << "a! = " << factorial(a) << endl;

	primefield<PRIME> c(3), d(21), e(5), f(67), g(50);

	cout << c/d + e/f << endl;
	cout << c/d - e/f << endl;
	cout << factorial(g) << endl;
	

	return 0;
}