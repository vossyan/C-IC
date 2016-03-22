#include <iostream>
#include <cmath>
using namespace std;

int modMulti(int a, int b, int m){
	return ((a%m) * (b%m)) % m;
}

int modAdd(int a, int b, int m){
	return ((a%m) + (b%m)) % m;
}

int modFactorial(int n, int m){

	if (n == 1)
	{
		return 1;
	}
	int tmp = modMulti(1,2,m);
	for (size_t i = 3; i <= n ; i++)
	{
		tmp = modMulti(tmp, i, m);
	}

	return tmp;
}

int modPow(int n, int pow, int m){
	if (pow == 0)
	{
		return 1;
	}

	int tmp = n %m ;
	for (size_t i = 1; i < pow; i++)
	{
		tmp = modMulti(tmp, n, m);
	}

	return tmp;
}



int main(){

	cout << modFactorial(80, 997) << endl;
	cout << modPow(7, 128, pow(10, 6)) << endl;

	int tmp = modAdd(1, 4, 877);
	for (size_t n = 3; n <= 1000; n++)
	{
		tmp = modAdd(tmp, modPow(n, n, 877), 877);
	}

	cout << tmp << endl;
	return 0;
}