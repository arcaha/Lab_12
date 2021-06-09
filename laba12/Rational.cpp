#include <math.h>
#include <iostream>
#include "Rational.h"

int NOD(int a, int b) {
	while (a != 0 && b != 0) {
		if (a > b) {
			a %= b;
		}
		else {
			 b %= a;
		}
	}
	return a + b;
}
int NOK(int a, int b) {
	int res = a * b / NOD(a, b);
	return res;
}


Rational::Rational(int _numerator, int _denominator) {
	if (_denominator < 0) {
	numerator = -_numerator;
	denominator = abs(_denominator);
    }
	if (_denominator == 0) {
    std::cerr << "Erorr, denominator is 0." << std::endl;
	exit(-1);
	}
	numerator = _numerator;
	denominator = _denominator;
}
 Rational::Rational(const Rational& other) {
	numerator = other.numerator;
	denominator = other.denominator;
}

Rational::~Rational() {}


void Rational::Set_numerator(int v_numerator) {
	numerator = v_numerator;
}
void Rational:: Set_denominator(int v_denominator){
	denominator = v_denominator;
}


int Rational::Get_numerator() const {
	return numerator;
}
int Rational::Get_denominator() const {
	return denominator;
}

Rational Rational::operator + (Rational& a) {
	Rational res;
	int nod = 0;
	res.denominator = NOK(denominator, a.denominator);
	res.numerator = a.numerator * res.denominator / a.denominator + numerator * res.denominator / denominator;
	nod = NOD(res.denominator, res.numerator);
	if (nod != res.denominator) {
		res.denominator = res.denominator / nod;
		res.numerator = res.numerator / nod;
	}
	return res;
}
Rational Rational::operator - (Rational& a) {
	Rational res;
	int nod;
	res.denominator = NOK(denominator, a.denominator);
	res.numerator = a.numerator * res.denominator / a.denominator - numerator * res.denominator / denominator;
	nod = NOD(res.denominator, res.numerator);
	if (nod != res.denominator) {
		res.denominator = res.denominator / nod;
		res.numerator = res.numerator / nod;
	}
	return res;
}

Rational Rational::operator * (Rational& a) {
	Rational res;
	int nod;
	res.denominator = denominator * a.denominator;
	res.numerator = numerator * a.numerator;
	nod = NOD(res.denominator, res.numerator);
	res.denominator = res.denominator / nod;
	res.numerator = res.numerator / nod;
	return res;
}
Rational Rational::operator / (Rational& a) {
	Rational res;
	int nod;
	res.denominator = denominator * a.numerator;
	res.numerator = numerator * a.denominator;
	nod = NOD(res.denominator, res.numerator);
	res.denominator = res.denominator / nod;
	res.numerator = res.numerator / nod;
	return res;
}
Rational& Rational::operator=(const Rational& other) {
	numerator = other.numerator;
	denominator = other.denominator;
	return *this;
}

 std::ostream& operator << (std::ostream& out, const Rational& res) {
	if(res.numerator == 0) out << '0';
	else  out << res.numerator << "/" << res.denominator;
	return out;
}
std::istream& operator >> (std::istream& in, Rational& fraction) {
	in >> fraction.numerator >> fraction.denominator;
	fraction = Rational(fraction.numerator, fraction.denominator);
	return in;
}
	
