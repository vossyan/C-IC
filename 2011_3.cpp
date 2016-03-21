#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


template <typename T>
class gen_charfn{
	T alpha;
	double a, b;
public:
	gen_charfn(const T & al, double aa, double bb) :alpha(al), a(aa), b(bb){}
	bool isUseful(){
		if (a==b)
		{
			return false;
		}
		return true;
	}
	T operator()(double x){
		if (x >=a && x < b)
		{
			return alpha * 1;
		}
		return alpha * 0;
	}

	T intR(){
		return alpha * (b - a);
	}

	gen_charfn<T> operator*(const gen_charfn<T> & g) const {
		double newa, newb;
		if (a <= g.a)
		{
			if (g.a > b){
				newa = 0;
				newb = 0;
			}
			else{
				newa = a;
				newb = g.b;
			}
				
		}
		else{
			if (a > g.b){
				newa = 0;
				newb = 0;
			}
			else{
				newa = g.a;
				newb = b;
			}
		}
		return gen_charfn<T>(alpha*g.alpha, newa, newb);
	}

};

template <typename T>
class step_function{
	vector<gen_charfn<T> > vec;
public:
	step_function(const vector<gen_charfn<T> > & v) :vec(v){}

	T operator()(double x){
		T sum = T(0);
		for (size_t i = 0; i < vec.size(); i++)
		{
			sum = sum + vec[i](x);
		}
		return sum;
	}

	T intR(){
		T sum = T(0);
		for (size_t i = 0; i < vec.size(); i++)
		{
			sum = sum + vec[i].intR();
		}
		return sum;
	}

	step_function<T> operator+(const step_function<T> & sf){
		vector<gen_charfn<T> > resvec;
		res = *this;
		for (size_t i = 0; i < sf.vec.size(); i++)
		{
			resvec.push_back(sf.vec[i]);
		}
		return step_function<T>(resvec);
	}

	step_function<T> operator*(const step_function<T> & sf){
		vector<gen_charfn<T> > resvec;
		for (size_t i = 0; i < vec.size(); i++)
		{
			for (size_t j = 0; j < sf.vec.size(); j++)
			{
				gen_charfn<T>  newg = vec[i] * sf.vec[j];
				if (newg.isUseful())
				{
					resvec.push_back(newg);
				}
			}
		}
		
		return step_function<T>(resvec);
	}


};

vector<double> uniform_parition(double a, double b, size_t n){
	vector<double> vec(n, 0);
	for (size_t i = 0; i < n; i++)
	{
		vec[i] = a + i * (b - a) / n;
	}

	return vec;

}

vector<double> logarithmic_parition(double a, double b, size_t n){
	vector<double> vec(n, 0);
	for (size_t i = 0; i < n; i++)
	{
		vec[i] = log(exp(a) + i * (exp(b) - exp(a)) / n);
	}

	return vec;

}


template <typename T>
step_function<T> interpolate(T(*func)(double), double a, double b, bool isLog){
	size_t n = 100;
	vector<gen_charfn<T> > vec;
	vector<double> partition;
	if (isLog)
	{
		partition = logarithmic_parition(a, b, n);
	}
	else {
		partition = uniform_parition(a, b, n);
	}

	for (size_t i = 1; i < n; i++)
	{
		vec.push_back(gen_charfn<T>(func(partition[i - 1]), partition[i - 1], partition[i]));
	}

	return step_function<T>(vec);
}



int main(){
	step_function<double> st = interpolate<double>(sin, 0, 1, true);
	step_function<double> st2 = interpolate<double>(cos, 0, 1, true);
	step_function<double> st3 = st*st2;
	cout << st.intR() << endl;
}