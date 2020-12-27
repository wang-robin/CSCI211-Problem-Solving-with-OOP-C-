#include <iostream>
#include <cmath>
using namespace std;

class Rational {
private:
	int n;
	int d;

public:
    Rational(int i, int j) {
		n = i;
		d = j;
	}

	Rational() : Rational(0, 1) {}
	Rational(int i) : Rational(i, 1) {}

	int getN() { return n; }
	int getD() { return d; }

	void setN(int i) {
	    n = i;
	    simplify(*this);
    }
	void setD(int i) {
        if (i == 0)
            return;
		d = i;
		simplify(*this);
	}

	Rational operator+(Rational r) {
		Rational t;
		t.n = n * r.d + d * r.n;
		t.d = d * r.d;
		simplify(t);
		return t;
	}

	Rational operator-(Rational r) {
        Rational t;
        t.n = n * r.d - d * r.n;
        t.d = d * r.d;
        simplify(t);
        return t;
	}

	Rational operator*(Rational r) {
        Rational t;
        t.n = n * r.n;
        t.d = d * r.d;
        simplify(t);
        return t;
	}

	Rational operator/(Rational r) {
        Rational t;
        t.n = n * r.d;
        t.d = d * r.n;
        simplify(t);
        return t;
	}

	int gcd(Rational r) {
        return gcd(abs(r.n), abs(r.d));
	}

	int gcd(int a, int b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
	}

	void simplify(Rational &t) {
        int a = gcd(t);
        t.n /= a;
        t.d /= a;
        if (t.d < 0) {
            t.n *= -1;
            t.d *= -1;
        }
    }

	friend ostream &operator<<(ostream &os, Rational r); // this one doesnt have an ampersand
	friend istream &operator>>(istream &is, Rational &r);
};

ostream &operator<<(ostream &os, Rational r) {
    if (r.n == 0)
        os << "0";
    else
        os << r.n << " / " << r.d << endl;
	return os;
}

istream &operator>>(istream &is, Rational &r) {
    is >> r.n >> r.d;
    r.simplify(r);
	return is;
}

int main() {
	Rational x(1, 2), y(2, 3), z;

	z = x + y;
	cout << z;

	x.setN(3);
	y.setD(2);

	z = x + y;
	cout << z;

    cout << "Enter a numerator and denominator, press enter between inputs\n";
	cin >> x;
	cout << x <<endl;

	z = x + 5;
	cout << z;

	return 0;
}
