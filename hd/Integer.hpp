#pragma once

#include <iostream>
#include <cmath>
#include <numeric>

class Integer
{
public:
	//������������
	Integer();
	Integer(bool sign, unsigned units);
	Integer(int number);
	//������
	void setSign(bool sign);
	void setValue(unsigned value);
	//������
	bool getSign()const;
	unsigned getValue()const;
	// ������� �������� ���������
	//bool isPrimeNum();
	
	bool isOdd();
	bool isEven();
	bool isPositive()const;
	bool isNegative()const;
	int Nod(Integer other)const;
	bool isCoprime(Integer other)const;
	int Nok(Integer other)const;
	bool isSimple()const;

	//���������� ����������

	//�������������� ���������
	Integer& operator + (const Integer& counter)const;
	//������� +
	Integer operator + ();

	Integer operator * (const Integer& counter)const;

	Integer operator / (const Integer& counter)const;

	Integer& operator - (const Integer& counter)const;
	//������� -
	Integer operator - ();

	Integer operator % (const Integer& counter)const;


	// ��������� ���������
	friend bool operator == (const Integer& num, const Integer& other);

	friend bool operator != (const Integer& num, const Integer& other);

	friend bool operator > (const Integer& num, const Integer& other);

	friend bool operator < (const Integer& num, const Integer& other);

	friend bool operator <= (const Integer& num, const Integer& other);

	friend bool operator >= (const Integer& num, const Integer& other);

	//���������� ���������, ���������
	Integer& operator++ ();

	Integer& operator-- ();

	// ����������� ���������, ���������
	Integer operator++ (int);

	Integer operator-- (int);

	// ��������� ����������
	Integer& operator += (Integer other);

	Integer& operator -= (Integer other);

	Integer& operator *= (const Integer& counter);

	Integer& operator /= (const Integer& counter);
	
	//�������� ������
	friend std::ostream& operator<<(std::ostream& out, const Integer& other);

private:
	bool sign_;
	unsigned value_;

};
