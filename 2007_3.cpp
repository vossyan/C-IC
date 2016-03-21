#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class RV{
public:
	RV(){}
	virtual double generate() const  { return 0; }
	virtual double pdf(const double &) const { return 0; }
	virtual double cdf(const double &) const { return 0; }

};

class uniform :public RV{
	double a, b;
public:
	uniform(double aa, double bb) :a(aa), b(bb){};
	double generate() const{
		return (rand() / ((double)RAND_MAX )) * (b - a ) + a;
	}

	double pdf(const double &x) const{
		if (x>= a && x<= b)
		{
			return 1.0 / (double)(b - a);
		}
		return 0;
	}

	double cdf(const double &x) const{
		if (x<a)
		{
			return 0;
		}
		if (x<b)
		{
			return (double)(x - a) / (b - a);
		}
		return 1;
	}
};
double pi = 4 * atan(1);
class normal : public RV{
	double mu, sigma;
public:
	normal(double m=0, double s=1) :mu(m), sigma(s){}

	double generate() const{
		double u1 = rand() / (double)RAND_MAX;
		double epsilon = numeric_limits<double>::min();
		double u2;
		do
		{
			u2 = rand() / (double)RAND_MAX;
		} while (u2 <= epsilon);
		
		
		double X = sqrt(-2 * log(u2)) * cos(2 * pi * u1);
		return sigma*X + mu;
	}

	double pdf(const double & x) const {
		return exp(-pow(x - mu, 2) / (2 * pow(sigma, 2))) / (sqrt(2 * pi) * sigma);
	}
};

double return1(double x){
	return 1;
}

double returnE(double x){
	return exp(-x) + exp(-1 / x) / pow(x, 2);
}


double MC(double(*h)(double), const RV & rv, double min, double max, bool minInfinity= false, bool maxInfinity= false)
{
	double sum = 0;
	int n = 1000;
	for (size_t i = 0; i < n; i++)
	{
		double x = rv.generate();
		
		if (minInfinity && maxInfinity)
		{
			sum += h(x) / rv.pdf(x);
			
		}
		else if (minInfinity){
			if (x <= max)
			{
				sum += h(x) / rv.pdf(x);
			}
		}
		else if (maxInfinity){
			if (x >= min)
			{
				
				sum += h(x) / rv.pdf(x);
			}
		}
		else {
			if (x>=min && x <= max)
			{
				sum += h(x) / rv.pdf(x);
			}
		}
		
		
	}
	return sum / n;
}

double mean(const vector<double> & v){
	if (v.size() == 0 )
	{
		return 0;
	}
	double sum = 0;
	for (size_t i = 0; i < v.size(); i++)
	{
		sum += v[i];
	}

	return sum / v.size();
}

double variance(const vector<double> & v){
	double m ;
	m = mean(v);
	double tmp = 0;
	for (size_t i = 0; i < v.size(); i++)
	{
		tmp += pow(v[i] - m, 2);
	}

	return tmp / v.size();
}

int main(){
	srand(time(NULL));
	uniform uni(0, pi);
	//cout << MC(return1, uni, 0.25, 1) << endl;

	normal nor(pi/2, 1);
	//cout << MC(returnE, uni, 0, 1) << endl;


	vector<double> w1(100, 0);
	for (size_t i = 0; i < 100; i++)
	{
		w1[i] = MC(sin, nor, 0, pi);
	}
	cout << mean(w1) << "  " << variance(w1) << endl;
	return 0;
}