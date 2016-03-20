#include <iostream>
#include <string>
using namespace std;

int computeScore(const string & s)
{
	int start = int('A');
	int sum = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		sum += (i+1) * (int(s[i]) - start);
	}

	return sum;
}
int main()
{
	string you = "YOU";
	string me = "ME";
	cout << computeScore(you) << endl;
	cout << computeScore(me) << endl;
	cout << computeScore("ZEOULOUS") << endl;
	cout << computeScore("TRANSPORTER") << endl;
	cout << computeScore("LECTURERS") << endl;
	return 0;
}