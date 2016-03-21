#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


class quaternion{
	vector<double> coef;

public:
	quaternion(double a1 = 1, double a2 = 0, double a3 = 0, double a4 = 0){
		coef.push_back(a1);
		coef.push_back(a2);
		coef.push_back(a3);
		coef.push_back(a4);
	}

	quaternion(const vector<double> &  c){
		for (int i = 0; i < 4; ++i)
		{
			coef.push_back(c[i]);
		}
	}

	vector<double> getCoef() const{
		return coef;
	}

	quaternion operator+(const quaternion & q){
		vector<double> c(4,0);

		for (int i = 0; i < 4; ++i)
		{
			c[i] = coef[i] + q.coef[i];
		}

		return quaternion(c);
	}

	quaternion operator-(const quaternion & q){
		vector<double> c(4,0);

		for (int i = 0; i < 4; ++i)
		{
			c[i] = coef[i] - q.coef[i];
		}


		return quaternion(c);
	}

	quaternion operator*(const quaternion & q){
		double a1 = coef[0] * q.coef[0];

		for (int i = 1; i < 4; ++i)
		{
			a1 -= coef[i] * q.coef[i];
		}

		double a2 = coef[0]*q.coef[1] + coef[2]*q.coef[0] + coef[2]*q.coef[3] - coef[3]*q.coef[2] ;
		double a3 = coef[0]*q.coef[2] - coef[1]*q.coef[3] + coef[2]*q.coef[0] + coef[3]*q.coef[1] ;
		double a4 = coef[0]*q.coef[3] + coef[1]*q.coef[2] - coef[2]*q.coef[1] + coef[3]*q.coef[0] ;

		return quaternion(a1, a2, a3, a4);
	}

	quaternion operator*(double b){

		vector<double> c(4,0);
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

ostream & operator<<(ostream & os, const quaternion & q){
	vector<double> coef = q.getCoef();
	os << "(";
	for (int i = 0; i < 4; ++i)
	{
		os << coef[i] << ",";
	}
	os <<")";

	return os;
}

quaternion pow(const quaternion & q, int n){

	if (n == 0)
	{
		return quaternion();
	}
	quaternion res = q;
	for (int i = 1; i < n; ++i)
	{
		res = res * q;
	}
	return res;
}


int main()
{
	quaternion a(-0.25, 3, 0, 1), b(0, 0, 5, -2);
	quaternion i(0,1,0,0), j(0,0,1,0), k(0,0,0,1);

	cout <<a*j<<endl;

	cout <<  i * a * j * b * k << endl;
	cout << pow(a,2) - pow(b,2) <<endl;
	cout << (a+b).conjugate() << endl;
	cout << a.invers() << endl;
	cout << b.invers() * a << endl;
	cout << a * (b.invers()) << endl;

}




