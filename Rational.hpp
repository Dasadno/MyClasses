#pragma once

#include <iostream>
#include <cmath>

class Rational
{
public:
	//������������
	Rational();
	Rational(bool sign, float value);
	Rational(float number);
	//������
	void setSign(bool sign);
	void setValue(unsigned value);
	//������
	bool getSign()const;
	unsigned getValue()const;
	// ������� �������� ���������
	bool isPrimeNum();
	bool isPositive(Rational num)const;
	bool isNegative(Rational num)const;
private:
	bool sign_;
	float value_;
};

