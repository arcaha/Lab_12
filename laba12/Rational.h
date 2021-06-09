#include <iostream>
class Rational
{
private:
	int numerator;
	int denominator;
public:
	Rational(int _numerator = 0, int _denominator = 1);
	~Rational();
	
	void Set_numerator(int v_numerator);
	void Set_denominator(int v_denominator);

	int Get_numerator() const;
	int Get_denominator() const;

	Rational(const Rational& other);
	Rational operator + (Rational& a);
	Rational operator - (Rational& a);
	Rational operator * (Rational& a);
	Rational operator / (Rational& a);
	Rational& operator = (const Rational& other);

	friend std::ostream& operator << (std::ostream& out, const Rational& res);
	friend std::istream& operator >> (std::istream& in, Rational& fraction);
};


