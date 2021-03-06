#ifndef Rational_h
#define Rational_h
#include <iostream>
class Rational
{
private:
	int numerator;
	int denominator;
public:
	Rational(int _numerator = 0, int _denominator = 1);
	Rational(const Rational& other);
	~Rational();
	
	void Set_numerator(int v_numerator);
	void Set_denominator(int v_denominator);

	int Get_numerator() const;
	int Get_denominator() const;

	Rational operator + (const Rational& a);
	Rational operator - (const Rational& a);
	Rational operator * (const Rational& a);
	Rational operator / (const Rational& a);
	Rational& operator = (const Rational& other);
	Rational& operator += (const Rational& a);
	Rational& operator -= (const Rational& a);
	Rational& operator *= (const Rational& a);
	Rational& operator /= (const Rational& a);

	friend std::ostream& operator << (std::ostream& out, const Rational& res);
	friend std::istream& operator >> (std::istream& in, Rational& fraction);
};

#endif
