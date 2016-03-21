#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double innerProduct(const vector<double> & a, const vector<double> &b){
	double sum = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		sum += a[i] * b[i];
	}

	return sum;
}

double norm(const vector<double> & a){
	return sqrt(innerProduct(a,a));
}

vector<double> operator/(const vector<double> & v, double b){
	
	vector<double> res;
	for (int i = 0; i < v.size(); ++i)
	{
		res.push_back(v[i]/b);
	}

	return res;
}

vector<double> operator*(const vector<double> & v, double b){
	
	vector<double> res;
	for (int i = 0; i < v.size(); ++i)
	{
		res.push_back(v[i]*b);
	}

	return res;
}

vector<double> operator+(const vector<double> & v1, const vector<double> & v2){
	
	vector<double> res;
	for (int i = 0; i < v1.size(); ++i)
	{
		res.push_back(v1[i] + v2[i]);
	}

	return res;
}

vector<double> operator-(const vector<double> & v1, const vector<double> & v2){
	
	vector<double> res;
	for (int i = 0; i < v1.size(); ++i)
	{
		res.push_back(v1[i] - v2[i]);
	}

	return res;
}

void print (const vector<double> & A)
{
	cout << "(";
	for (int i = 0; i < A.size(); ++i)
	{
	
			cout<< A[i]<< ", ";
	}
	cout <<")";
}

vector< vector<double> > gram_Schmidt(const vector< vector<double> > & A){
	vector< vector<double> > V;
	vector< vector<double> > Q;

	V.push_back(A[0]);
	Q.push_back(V[0]/ norm(V[0]));


	for (int i = 1; i < A.size(); ++i)
	{
		vector<double> sum(Q[0].size(), 0);
		for (int j = 0; j < i; ++j)
		{
			sum = sum + Q[j] * innerProduct(A[i], Q[j]);
		}
		V.push_back(A[i] - sum);
		Q.push_back(V[i]/norm(V[i]));


	}

	return Q;
}

void print (const vector< vector<double> > & A)
{
	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = 0; j < A[i].size(); ++j)
		{
			cout<< (A[i])[j] << "   ";
		}
		cout << endl;
	}
	cout <<endl;
}




int main()
{

	vector<double> a1, a2, a3;
	a1.push_back(2);a1.push_back(14);
	a2.push_back(3);a2.push_back(0);
	a3.push_back(13);a3.push_back(23);

	vector < vector<double> > A;
	A.push_back(a1);A.push_back(a2);A.push_back(a3);


	print(gram_Schmidt(A));


}