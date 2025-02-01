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
	bool isOdd(Integer val)const;
	bool isEven(Integer val)const;
	bool isPositive(Integer num)const;
	bool isNegative(Integer num)const;
	int Nod(Integer other)const;
	bool isCoprime(Integer other)const;
	int Nok(Integer other)const;
	bool isSimple()const;

	//���������� ����������

	//�������������� ���������
	Integer operator + (const Integer& counter)const;

	Integer operator * (const Integer& counter)const;

	Integer operator / (const Integer& counter)const;

	Integer operator - (const Integer& counter)const;

	Integer operator % (const Integer& counter)const;


	// ��������� ���������
	bool operator == (const Integer& other)const;

	bool operator != (const Integer& other)const;

	bool operator > (const Integer& other)const;

	bool operator < (const Integer& other)const;

	bool operator <= (const Integer& other) const;

	bool operator >= (const Integer& other) const;

	//���������� ���������, ���������
	Integer& operator++ ();

	Integer& operator-- ();

	// ����������� ���������, ���������
	Integer operator++ (int);

	Integer operator-- (int);

	// ��������� ����������
	Integer& operator += (const Integer& counter);

	Integer& operator -= (const Integer& counter);

	Integer& operator *= (const Integer& counter);

	Integer& operator /= (const Integer& counter);
	
	//�������� ������
	friend std::ostream& operator<<(std::ostream& out, const Integer& other);

private:
	bool sign_;
	unsigned value_;

};
