
using namespace std;
class fraction {
	friend ostream &operator<< (ostream &os, const fraction &f);
private:
	int numerator, denominator;
	void reduce();
	int gcd(int a, int b);
public:
	fraction(int n = 0, int d = 1) : numerator(n), denominator(d) { reduce(); }
	fraction operator+ (const fraction &f) const;
	fraction &operator+= (const fraction &f);
	fraction operator- (const fraction &f) const;
	fraction &operator-= (const fraction &f);
	fraction operator* (const fraction &f) const;
	fraction &operator*= (const fraction &f);
	fraction operator/ (const fraction &f) const;
	fraction &operator/= (const fraction &f);

	fraction operator+ (int n) const;
	fraction &operator+= (int n);
	fraction operator- (int n) const;
	double operator- (double n) const;
	fraction &operator-= (int n);
	fraction operator* (int n) const;
	fraction &operator*= (int n);
	fraction operator/ (int n) const;
	fraction &operator/= (int n);
	operator double () const;

	bool operator< (const fraction &f) const;
	bool operator> (const fraction &f) const;
	bool operator>= (const fraction &f) const;
	bool operator<= (const fraction &f) const;
	bool operator== (const fraction &f) const;
	bool operator!= (const fraction &f) const;
	fraction operator- () const { fraction res(-numerator, denominator); return res; }
};