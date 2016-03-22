#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

int nbCom_global = 0;
class mydouble{
	double var;
	int nbCom, nbAffec;
public:
	mydouble(double v) :var(v), nbCom(0), nbAffec(0){}
	bool operator<(const mydouble & d) const{
		
		nbCom_global++;
		if (var < d.var)
		{
			return true;
		}return false;

	}

	mydouble & operator=(const mydouble & d){
		nbAffec++;
		var = d.var;
		return *this;
	}

	int getNbCom(){ return nbCom; }
	int getNbAffec(){ return nbAffec; }

};

void bubblesort(vector <mydouble> & vec){
	bool swap = false;
	do
	{
		swap = false; 
		for (size_t i = 0; i < vec.size() - 1; i++)
		{
			if (vec[i + 1] < vec[i]){
				mydouble tmp = vec[i + 1];
				vec[i + 1] = vec[i];
				vec[i] = tmp;
				swap = true;
			}
		}
		for (size_t i = vec.size() - 1 ; i > 0; i--)
		{
			if (vec[i] < vec[i-1]){
				mydouble tmp = vec[i];
				vec[i] = vec[i-1];
				vec[i-1] = tmp;
				swap = true;
			}
		}
	} while (swap);
	
}

void printNb(vector <mydouble> & vec){
	int sumCom = 0, sumAffec = 0;
	for (size_t i = 0; i < vec.size(); i++)
	{
		sumCom += vec[i].getNbCom();
		sumAffec += vec[i].getNbAffec();
	}

	cout << sumAffec / 2 << "  " << nbCom_global << endl;
}

int main(){
	ifstream file("data.txt");

	double v;
	vector <mydouble> vec;
	while (file >> v){
		vec.push_back(mydouble(v));
	}
	bubblesort(vec);

	//sort(vec.begin(), vec.end());
	printNb(vec);

	cin >> v;

}