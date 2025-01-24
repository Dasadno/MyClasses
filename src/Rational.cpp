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
//Сетеры
void setSign(bool sign);
void setValue(float value);
//Гетеры
//bool getSign()const;
//float getValue()const;
// Функции проверки состояния
//bool isPrimeNum();
//bool isPositive(Rational num)const;
//bool isNegative(Rational num)const;