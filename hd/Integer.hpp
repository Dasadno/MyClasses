#pragma once

#include <iostream>
#include <cmath>

class Integer
{
public:
	//Конструкторы
	Integer();
	Integer(bool sign, unsigned units);
	Integer(int number);
	//Сетеры
	void setSign(bool sign);
	void setValue(unsigned value);
	//Гетеры
	bool getSign()const;
	unsigned getValue()const;
	// Функции проверки состояния
	bool isPrimeNum();
	bool isOdd(Integer val)const;
	bool isEven(Integer val)const;
	bool isPositive(Integer num)const;
	bool isNegative(Integer num)const;

	//Перегрузки операторов

	//Алгебраические операторы
	Integer operator + (const Integer& counter)const;

	Integer operator * (const Integer& counter)const;

	Integer operator / (const Integer& counter)const;

	Integer operator - (const Integer& counter)const;

	Integer operator % (const Integer& counter)const;


	// Операторы сравнения
	bool operator == (const Integer& counter)const;

	bool operator != (const Integer& counter)const;

	bool operator > (const Integer& counter)const;

	bool operator < (const Integer& counter)const;

	//Декремент, инкремент
	Integer& operator++ ();

	Integer& operator-- ();

	// постфиксные операторы
	Integer operator++ (int);

	Integer operator-- (int);

	// операторы присвоения
	Integer& operator += (const Integer& counter);

	Integer& operator -= (const Integer& counter);

	Integer& operator *= (const Integer& counter);

	Integer& operator /= (const Integer& counter);

private:
	bool sign_;
	unsigned value_;

};
