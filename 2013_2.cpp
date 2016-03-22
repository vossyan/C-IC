#include <iostream>
#include <cmath>
#include <vector>
#include <complex>
using namespace std;


template <typename T>
class quaternion{
	vector<T> coef;

public:
	quaternion(T a1 = 1, T a2 = 0, T a3 = 0, T a4 = 0){
		coef.push_back(a1);
		coef.push_back(a2);
		coef.push_back(a3);
		coef.push_back(a4);
	}

	quaternion(const vector<T> &  c){
		for (int i = 0; i < 4; ++i)
		{
			coef.push_back(c[i]);
		}
	}

	vector<T> getCoef() const{
		return coef;
	}

	quaternion operator+(const quaternion & q){
		vector<T> c(4,0);

		for (int i = 0; i < 4; ++i)
		{
			c[i] = coef[i] + q.coef[i];
		}

		return quaternion(c);
	}

	quaternion operator-(const quaternion & q){
		vector<T> c(4,0);

		for (int i = 0; i < 4; ++i)
		{
			c[i] = coef[i] - q.coef[i];
		}


		return quaternion(c);
	}

	quaternion operator*(const quaternion & q){
		T a1 = coef[0] * q.coef[0];

		for (int i = 1; i < 4; ++i)
		{
			a1 -= coef[i] * q.coef[i];
		}

		T a2 = coef[0]*q.coef[1] + coef[1]*q.coef[0] + coef[2]*q.coef[3] - coef[3]*q.coef[2] ;
		T a3 = coef[0]*q.coef[2] - coef[1]*q.coef[3] + coef[2]*q.coef[0] + coef[3]*q.coef[1] ;
		T a4 = coef[0]*q.coef[3] + coef[1]*q.coef[2] - coef[2]*q.coef[1] + coef[3]*q.coef[0] ;

		return quaternion(a1, a2, a3, a4);
	}

	quaternion operator*(T b){

		vector<T> c(4,0);
		for (int i = 0; i < 4; ++i)
		{
			c[i] = coef[i] * b;
		}

		return quaternion(c);
	}

	quaternion conjugate(){
		quaternion i(0,1,0,0), j(0,0,1,0), k(0,0,0,1);
		return (*this + i*(*this)*i + j*(*this)*j + k*(*this)*k) * -0.5;

	}

	double norm(){
		double sum = 0;
		for (int i = 0; i < 4; ++i)
		{
			sum += pow(coef[i],2);
		}

		return sqrt(sum);
	}

	quaternion invers(){
		return  conjugate() * (1/ pow(norm(),2));
	}
};

template <typename T>
ostream & operator<<(ostream & os, const quaternion<T> & q){
	vector<T> coef = q.getCoef();
	os << "(";
	for (int i = 0; i < 4; ++i)
	{
		os << coef[i] << ",";
	}
	os <<")";

	return os;
}

template <typename T>
quaternion<T> pow(const quaternion<T> & q, int n){

	if (n == 0)
	{
		return quaternion<T>();
	}
	quaternion<T> res = q;
	for (int i = 1; i < n; ++i)
	{
		res = res * q;
	}
	return res;
}


int main()
{
	quaternion<double> i(0, 1, 0, 0), j(0, 0, 1, 0), k(0, 0, 0, 1);
	quaternion<double> aaa(-0.25, 3, 0, 1), bbb(0, 0, 5, -2);
	

	cout <<i*aaa*j<<endl;

	/*cout <<  i * a * j * b * k << endl;
	cout << pow(a,2) - pow(b,2) <<endl;
	cout << (a+b).conjugate() << endl;
	cout << a.invers() << endl;
	cout << b.invers() * a << endl;
	cout << a * (b.invers()) << endl;*/

	//quaternion<int> a(1, 2, 3, 4), b(-1, 0, 3, 2), c;

	//c = a*a - b * b;

	complex<double> z1(1, 1), z2(0, -1), z3(-1, 1), z4(5, 0);
	quaternion<complex<double> > aa(z1, z2, z3, z4), bb(z4, z3, z2, z1), cc;
	cc = aa*aa - bb*bb;
	/*quaternion<int> a(123456789, 12345, 54321, 987654321), b(-999, 111, 222, 333), c;

	cout << a*b << endl;
	cout << b*a << endl;
	cout << pow(a, 2) - pow(b, 2) << endl;*/

	quaternion<complex<double> > a(complex<double>(1, 1), complex<double>(-5, 0), complex<double>(2, -3), complex<double>(0, 1)), b(complex<double>(0, 0), complex<double>(0, 5), complex<double>(1, -1), complex<double>(8, 9));
	cout << a*b << endl;
	cout << b*a << endl;
	cout << pow(a, 2) - pow(b, 2) << endl;

}




