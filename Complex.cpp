#include <iostream>
using namespace std;

class Complex {
private:
    double r;
	double i;

public:
    Complex(double r1, double i1) {
		r = r1;
		i = i1;
	}

	Complex() : Complex(0, 0) {}
	Complex(double r1) : Complex(r1, 0) {}

	int getR() { return r; }
	int getI() { return i; }

	void setR(double r1) { r = r1; }
	void setI(double i1) { i = i1; }

	Complex operator+(Complex c) {
        Complex d;
		d.r = r + c.r;
		d.i = i + c.i;
		return d;
	}

	Complex operator-(Complex c) {
        Complex d;
		d.r = r - c.r;
		d.i = i - c.i;
		return d;
	}

	Complex operator*(Complex c) {
        Complex d;
		d.r = r * c.r - i * c.i;
		d.i = i * c.r + r * c.i;
		return d;
	}

	Complex operator/(Complex c) {
	    int a = c.r * c.r + c.i * c.i;

        c.setI(-c.getI());
        Complex d = *this * c;

        d.r /= a;
        d.i /= a;

		return d;
	}

	friend ostream &operator<<(ostream &os, Complex c);
};

ostream &operator<<(ostream &os, Complex c) {
    if (c.i == 0)
        os << c.r;
    else if (c.r == 0)
        os << c.i << 'i';
    else if (c.i == 1)
        os << c.r << "+i";
    else os << c.r << '+' << c.i << 'i';
}

int main() {
	Complex c1, c2(1), c3(1,1);

	cout << c1 << endl;
	cout << c2 << endl;
	cout << c3 << endl;

	c1 = c2 + c3;
	cout << c1 << endl;

	c3 = c1 * c2;
	cout << c3 << endl;

	c3 = c3 / c2;
	cout << c3 << endl;

	c2 = c2 - c2;
	cout << c2 << endl;

    Complex c4(5,3);

    c1 = c4 / c3;
    cout << c1 << endl;

	return 0;
}
