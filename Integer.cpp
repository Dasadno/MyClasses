#include "Integer.h"

	//������������
	Integer::Integer() :Integer(false, 0u) { }
	Integer::Integer(bool sign, unsigned units) :sign_(sign), value_(value_) { }
	Integer::Integer(int number) {
		if (number < 0)
		{
			sign_ = true;
			value_ = abs(number);
		}
		else {
			sign_ = false;
			value_ = static_cast<unsigned>(number);
		}
	}
	//������
	void Integer::setSign(bool sign) {
		this->sign_ = sign;
	}
	void Integer::setValue(unsigned value) {
		this->value_ = value;
	}
	//������
	bool Integer::getSign()const {
		return sign_;
	}
	unsigned Integer::getValue()const {
		return value_;
	}
	// ������� �������� ���������
	bool Integer::isPrimeNum() {

	}
	bool Integer::isOdd(Integer val)const {
		return val % 2 != 0;
	}
	bool Integer::isEven(Integer val)const {
		return val % 2 == 0;
	}
	bool Integer::isPositive(Integer num)const {
		return sign_;
	}
	bool Integer::isNegative(Integer num) const{
		return !sign_;
	}

	//���������� ����������

	//�������������� ���������

	//�������� ��������, �������� ����� ���, ��� ������ �������� +
	Integer Integer::operator + (const Integer& other) const
	{
		Integer result;
		if (sign_ == other.sign_) 
		{
			result.sign_ = sign_;
			result.value_ = value_ + other.value_;
		}
		else {
			if (value_ > other.value_)
			{
				result.sign_ = sign_;
				result.value_ = value_ - other.value_;
			}
			else if (value_ < other.value_) {
				result.sign_ = other.sign_;
				result.value_ = other.value_ - value_;
			}
			else {
				result.sign_ = false;
				result.value_ = true;
			}
		}
		return result;
		
	}
	//�������� ���������
	Integer Integer::operator * (const Integer& other) const
	{
		Integer result;
		if (sign_ == other.sign_)
		{
			result.sign_ = sign_;
			result.value_ = value_ * other.value_;
		}
		else if (sign_ != other.sign_) {

			result.sign_ = false;
			result.value_ = value_ * other.value_;
		}
		return result;
	}
	//�������� �������
	Integer Integer::operator / (const Integer& other) const
	{
		Integer result;
		if (sign_ == other.sign_)
		{
			result.sign_ = sign_;
			result.value_ = value_ / other.value_;
		}
		else if (sign_ != other.sign_) {

			result.sign_ = false;
			result.value_ = value_ / other.value_;
		}
		return result;
	}
	//�������� ���������
	Integer Integer::operator - (const Integer& other) const
	{
		Integer result;
		if (sign_ == other.sign_ && sign_ == true && value_ > other.value_)
		{
			result.sign_ = sign_;
			result.value_ = value_ - other.value_;
		}
		else if (sign_ == other.sign_ && sign_ == true && value_ < other.value_) {
			result.sign_ = !sign_;
			result.value_ = other.value_ - value_;
		}
		else if (sign_ == other.sign_ && sign_ == false && value_ > other.value_) {
			result.sign_ = sign_;
			result.value_ = other.value_ + value_;
		}
		else if (sign_ == other.sign_&& sign_ == false && value_ < other.value_) {
			result.sign_ = sign_;
			result.value_ = other.value_ + value_;
		}
		else if (sign_ != other.sign_ && sign_ == true && value_ > other.value_) {
			result.sign_ = sign_;
			result.value_ = value_ - other.value_;
		}
		else if (sign_ != other.sign_ && sign_ == false && value_ > other.value_) {
			result.sign_ = sign_;
			result.value_ = value_ - other.value_;
		}
		else if (sign_ != other.sign_ && sign_ == true && value_ > other.value_) {
			result.sign_ = sign_;
			result.value_ = value_ - other.value_;
		}
		else if (sign_ != other.sign_ && sign_ == false && value_ < other.value_) {
			result.sign_ = other.sign_;
			result.value_ = other.value_ - value_;
		}

	}
	Integer Integer::operator % (const Integer& counter) const
	{
		return Integer{ value_ % counter.value_ };
	}


	// ��������� ���������
	bool Integer::operator == (const Integer & counter) const
	{
		return value_ == counter.value_;
	}
	bool Integer::operator != (const Integer& counter) const
	{
		return value_ != counter.value_;
	}
	bool Integer::operator > (const Integer& counter) const
	{

		return value_ > counter.value_;
	}
	bool Integer::operator < (const Integer& counter) const
	{
		return value_ < counter.value_;
	}

	//���������, ���������
	Integer& Integer::operator++ ()
	{
		value_ += 1;
		return *this;
	}
	Integer& Integer::operator-- ()
	{
		value_ -= 1;
		return *this;
	}
	// ����������� ���������
	Integer Integer::operator++ (int)
	{
		Integer copy{ *this };
		++(*this);
		return copy;
	}
	Integer Integer::operator-- (int)
	{
		Integer copy{ *this };
		--(*this);
		return copy;
	}
	// ��������� ����������
	Integer& Integer::operator += (const Integer& counter)
	{
		value_ += counter.value_;
		return *this;
	}
	Integer& Integer::operator -= (const Integer& counter)
	{
		value_ -= counter.value_;
		return *this;
	}
	Integer& Integer::operator *= (const Integer& counter)
	{
		value_ *= counter.value_;
		return *this;
	}
	Integer& Integer::operator /= (const Integer& counter)
	{
		value_ /= counter.value_;
		return *this;
	}


