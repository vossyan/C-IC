#include <iostream>
#include <vector>
#include <cmath>
#include <complex>

using namespace std;

template <typename T>
class Laurent_polynomial{
	int n;
	vector<T> coef;
public:
	Laurent_polynomial(int nn = 0, T a=0) : n(nn){
		coef = vector<T>(nn * 2 + 1, a);
	}
	int getN(){return n;}
	const T & operator[](int i) const{ return coef[i];}
	T & operator[](int i) {return coef[i];}

	Laurent_polynomial<T> operator+(const Laurent_polynomial<T> & p) const{
		Laurent_polynomial<T> res;
		const Laurent_polynomial<T> *st;
		if (n > p.n)
		{
			res = *this;
			st = &p;
		}else{
			res = p;
			st = this;
		}


		for (int i = 0; i <= st->n *2; ++i)
		{
			res[i] = res[i] + (*st)[i]; 
		}

		return res;
	}

	T value(T x) const{
		T sum = coef[0];
		
		for (int i = 1; i <= n; ++i)
		{
			sum = sum + coef[i] * pow(x, -i);
			sum = sum + coef[i+n] * pow(x, i);
		}

		return sum;
	}

};

int main(){
	Laurent_polynomial<double> p(3, 2.0);
	Laurent_polynomial<double> q(5, -1.5), s;
	double x(2.1), y(-1.25);
	cout << "p(y) = " << p.value(y) << endl;
	s = p + q;
	// N = 2, a_n = 1.0, n = -N,...,N.
	// value of polynomial p at y
	     for (int i = -s.getN(); i <= s.getN(); i++)
	       cout << "s[" << i << "] = " << s[i] << endl; // print coefficients a_n of s
	cout << "s(x) = " << s.value(x) << endl;


	complex<double> f(2,-2), g(0,5);
     Laurent_polynomial<complex<double> > u(2, f);
     Laurent_polynomial<complex<double> > v(5, g), t;
     complex<double> z(1,2), w(0,-1);
     cout << "u(w) = " << u.value(w) << endl;
     t = u + v;
     for (int i = -t.getN(); i <= t.getN(); i++)
       cout << "t[" << i << "] = " << t[i] << endl;
     cout << "t(z) = " << t.value(z) << endl;



}