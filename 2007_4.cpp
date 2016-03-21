#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

template <typename T>
class RV{
public:
	RV(){}
	virtual T generate() const = 0;
	virtual double pdf(const T &) const = 0;
	virtual double cdf(const T &) const = 0;

};


class uniform :public RV<double>{
	double a, b;
public:
	uniform(double aa, double bb) :a(aa), b(bb){};
	double generate() const{
		return (rand() / ((double)RAND_MAX)) * (b - a) + a;
	}

	double pdf(const double &x) const{
		if (x >= a && x <= b)
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
class normal : public RV<double>{
	double mu, sigma;
public:
	normal(double m = 0, double s = 1) :mu(m), sigma(s){}

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

struct point{
	double a, b;
	point(double xx = 0, double yy = 0) :a(xx), b(yy){}

	point operator+(const point & p) const{
		return point(a + p.a, b + p.b);
	}

	point & operator+=(const point &p) {
		a += p.a;
		b += p.b;

		return *this;
	}
	point operator/(const point &p) const {
		return point(a / p.a, b / p.b);
	}
};



class uniform2d : public RV<point>{
	point x, y;

public:
	uniform2d(const point & pp1, const point & pp2) :x(pp1), y(pp2){}

	point generate() const{
		double u1 = (rand() / ((double)RAND_MAX)) * (x.b - x.a) + x.a;
		double u2 = (rand() / ((double)RAND_MAX)) * (y.b - y.a) + y.a;

		return point(u1, u2);
	}

	double pdf(const point & p) const {
		if ( p.a >= x.a && p.a <= x.b && p.b >= y.a && p.b <= y.b )
		{
			return 1/(x.b - x.a)/(y.b - y.a);
		}
		
		return 0;
	}

	double cdf(const point & x) const {
		return 0;
	}

};




double return1(point x){
	return 1;
}

double returnE(point x){
	return exp(-x.a) * x.b;
}

double exo(point p){
	double x = p.a, y = p.b;
	return exp(-pow(x, 2) + x*y) *cos(pi*x) * sin(pi * y);
}

template <typename T>
double MC(double(*h)(T), const RV<T> & rv)
{
	double sum = 0;
	unsigned int n = 100;
	for (size_t i = 0; i < n; i++)
	{
		T x = rv.generate();
		sum += h(x) / rv.pdf(x);

	}
	return sum / n;
}



int main(){
	srand(time(NULL));
	point x(-3, 3), y(-1, 1);

	uniform2d uni(x, y);
	cout << MC<point>(exo, uni) << endl;

	return 0;
}