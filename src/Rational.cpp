#include "..\hd\Rational.hpp"


Rational::Rational() :Rational(false, 0u) { };
Rational::Rational(bool sign, float value) :sign_(sign), value_(value_) { };
Rational::Rational(float number) {
	if (number < 0)
	{
		sign_ = true;
		value_ = abs(number);
	}
	else {
		sign_ = false;
	}
}
//������
void setSign(bool sign);
void setValue(float value);
//������
//bool getSign()const;
//float getValue()const;
// ������� �������� ���������
//bool isPrimeNum();
//bool isPositive(Rational num)const;
//bool isNegative(Rational num)const;