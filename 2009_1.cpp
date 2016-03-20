#include <iostream>
#include <cmath>
using namespace std;

class complex{
	double real, image;

public:
	complex(double r = 0, double i = 0) : real(r), image(i){}

	complex operator*(const complex & c) const{
		double newReal = real * c.real - image * c.image;
		double newImage = real*c.image + image * c.real;

		return complex(newReal, newImage);
	}

	double getReal() const{ return real;}
	double getImage() const{ return image;}

};

ostream & operator<<(ostream & os, const complex & c)
{
	os << c.getReal() << " + " << c.getImage() << "i" ;
	return os;
}

complex operator/(double d, const complex & c)
{	double a = c.getReal();
	double b = c.getImage();
	double real = a * d / (pow(a,2) + pow(b,2));
	double image = -b *d / (pow(a,2) + pow(b,2));

	return complex(real, image);
}

complex my_power(const complex & z, int n)
{
	if (n == 0)
	{
		return complex(1,0);
	}
	complex c = z;

	if (n > 0)
	{
		for (int i = 1; i < n; ++i)
		{
			c = c * z;
		}

	} else {
		n = -n;
		c = 1/z;
		for (int i = 1; i < n; ++i)
		{

			c = c * (1/z);
		}
	}
	

	

	return c;
}


int main(){
	double x = 4.1, y = -3.5;
	complex z(2, -2), v(0, 2), w(-4,6), res;

	cout << my_power(w,3) << endl;
	cout << my_power(v, -2) << endl;

	return 0;
}