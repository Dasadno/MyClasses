#pragma once

#include <iostream>
#include <cmath>
#include <numeric>

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
	//bool isPrimeNum();
	
	bool isOdd();
	bool isEven();
	bool isPositive()const;
	bool isNegative()const;
	int Nod(Integer other)const;
	bool isCoprime(Integer other)const;
	int Nok(Integer other)const;
	bool isSimple()const;

	//Перегрузки операторов

	//Алгебраические операторы
	Integer& operator + (const Integer& counter)const;
	//Унарный +
	Integer operator + ();

	Integer operator * (const Integer& counter)const;

	Integer operator / (const Integer& counter)const;

	Integer& operator - (const Integer& counter)const;
	//Унарный -
	Integer operator - ();

	Integer operator % (const Integer& counter)const;


	// Операторы сравнения
	friend bool operator == (const Integer& num, const Integer& other);

	friend bool operator != (const Integer& num, const Integer& other);

	friend bool operator > (const Integer& num, const Integer& other);

	friend bool operator < (const Integer& num, const Integer& other);

	friend bool operator <= (const Integer& num, const Integer& other);

	friend bool operator >= (const Integer& num, const Integer& other);

	//Префексный Декремент, Инкремент
	Integer& operator++ ();

	Integer& operator-- ();

	// Постфиксный Декремент, Инкримент
	Integer operator++ (int);

	Integer operator-- (int);

	// операторы присвоения
	Integer& operator += (Integer other);

	Integer& operator -= (Integer other);

	Integer& operator *= (const Integer& counter);

	Integer& operator /= (const Integer& counter);
	
	//Оператор вывода
	friend std::ostream& operator<<(std::ostream& out, const Integer& other);

private:
	bool sign_;
	unsigned value_;

};
