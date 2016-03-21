#include <vector>
#include <iostream>
#include <cmath>



using namespace std;

class polynomial{
	unsigned int n;
	vector<double> a;

public:
	polynomial(unsigned int nn = 0, double x = 0) :n(nn){
		for (int i = 0; i <= n; i++) a.push_back(x);

	}

	unsigned int getN() const { return n;}

	const double &operator[](int i) const{return a[i];}
	double &operator[](int i) {return a[i];}

	polynomial operator*(const polynomial & q) const{
		int newn = n + q.n;
		polynomial res(newn);

		for (int i = 0; i <= n; ++i)
		{
			for (int j = 0; j <= q.n; ++j)
			{
				res[i+j] += a[i] * q[j];
			}
		}

		return res;
	}

	polynomial operator+(const polynomial & q) const
	{
		polynomial res;

		const polynomial * p;
		if (n > q.n)
		{
			res = *this;
			p = &q;

		}
		else{
			res = q;
			p = this;
		}

		for (int i = 0; i <= p->n; i++){
			res[i] += (*p)[i];
		}
		return res;
	}
	
	double operator()(double x)
	{
		double sum = 0;
		for (int i = 0; i <= n; ++i)
		{
			sum += a[i] * pow(x,i);
		}

		return sum;
	}




};

polynomial pow(const polynomial & q, int m)
{
	if (m == 0)
	{
		return polynomial(0,1);
	}

	polynomial res = q;
	for (int i = 1; i < m; ++i)
	{
		res = res * q;	
	}

	return res;
}

polynomial operator * (double alpha, const polynomial & q)
{
	polynomial res = q;

	for (int i = 0; i <= q.getN(); ++i)
	{
		res[i] = alpha * q[i];
	}

	return res;

}

int main()
{
	double x[] = {-3,-1,0,2,3 };

	polynomial p(0,1);
	for (int i = 0; i < 4; ++i)
	{
	 	polynomial k(1);
	 	k[0] = -x[i]/(x[4] - x[i]);
	 	k[1] = 1/(x[4]-x[i]);
	 	p = p * k;
	}


	polynomial q(1);
	q[0] = -2*x[4];
	q[1] = 2;

	polynomial r = pow(p,2) * q;

	cout << p[3] << endl;
	cout << r[7] << endl;
	cout << r(-2) << endl;

	for (int i = 0; i < 5; ++i)
	{
		cout << p(x[i]) << endl;
	}




}


