#pragma once

#include <iostream>
#include <cmath>

class Rational
{
public:
	//Конструкторы
	Rational();
	Rational(bool sign, float value);
	Rational(float number);
	//Сетеры
	void setSign(bool sign);
	void setValue(unsigned value);
	//Гетеры
	bool getSign()const;
	unsigned getValue()const;
	// Функции проверки состояния
	bool isPrimeNum();
	bool isPositive(Rational num)const;
	bool isNegative(Rational num)const;
private:
	bool sign_;
	float value_;
};

