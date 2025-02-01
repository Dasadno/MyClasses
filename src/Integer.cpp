#include "..\hd\Integer.hpp"

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
	bool Integer::isSimple()const
	{
		if (value_ < 2)
		{
			return false;
		}
		for (int i = 2; i * i <= value_; i++)
		{
			if (value_ % i == 0)
			{
				return false;
			}
		}
		return true;
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

	bool Integer::isCoprime(Integer other)const
	{
		return std::gcd(value_, other.value_) == 1;
	}

	// ���������� ����������� ������ ��������
	int Integer::Nod(Integer other)const
	{
		return std::gcd(value_, other.value_);
	}

	// ���������� ����������� ������ ��������
	int Integer::Nok(Integer other)const
	{
		return std::lcm(value_, other.value_);
	}

	//���������� ���������� --------------------------------------

	//�������������� ���������

	//�������� ��������
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
		return result;
	}

	Integer Integer::operator % (const Integer& counter) const
	{
		return static_cast<Integer>( value_ % counter.value_ );
	}

	// ��������� ���������
	bool Integer::operator == (const Integer & other) const
	{
		if (sign_ == other.sign_)
		{
			return value_ == other.value_;
		}
		return false;
	}

	bool Integer::operator != (const Integer& other) const
	{
		if (sign_ == other.sign_)
		{
			return value_ != other.value_;
		}
		return true;
	}

	bool Integer::operator > (const Integer& other) const
	{
		if (sign_ == other.sign_)
		{
			return value_ > other.value_;
		}
		else if (sign_ == true && other.sign_ == false) {
			return true;
		}
		else {
			return false;
		}
	}

	bool Integer::operator < (const Integer& other) const
	{
		if (sign_ == other.sign_)
		{
			return value_ < other.value_;
		}
		else if (sign_ == true && other.sign_ == false) {
			return false;
		}
		else {
			return true;
		}
	}

	bool Integer::operator <= (const Integer& other) const
	{
		if (sign_ == other.sign_)
		{
			return value_ <= other.value_;
		}
		else if (sign_ == true && other.sign_ == false) {
			return false;
		}
		else {
			return true;
		}
	}

	bool Integer::operator >= (const Integer& other) const
	{
		if (sign_ == other.sign_)
		{
			return value_ >= other.value_;
		}
		else if (sign_ == true && other.sign_ == false) {
			return true;
		}
		else {
			return false;
		}
	}

	//���������, ��������� (�����������)
	Integer& Integer::operator++ ()
	{
		Integer copy{ *this };
		if (sign_ == true) {
			copy += 1;
		}
		else {
			copy -= 1;
		}
		return copy;
	}

	Integer& Integer::operator-- ()
	{
		Integer copy{ *this };
		if (sign_ == true) {
			copy -= 1;
		}
		else {
			copy += 1;
		}
		return copy;
	}
	//���������, ��������� (����������)
	Integer Integer::operator++ (int)
	{
		Integer copy{ *this };
		if (sign_ == true)
		{
			++(copy);
		}
		else {
			--(copy);
		}
		return copy;
	}

	Integer Integer::operator-- (int)
	{
		Integer copy{ *this };
		if (sign_ == true)
		{
			--(copy);
		}
		else {
			++(copy);
		}
		return copy;
	}
	// ��������� ������������
	Integer& Integer::operator += (const Integer& other)
	{
		if (sign_ == other.sign_)
		{
			value_ += other.value_;
		}
		else if (sign_ == true && other.value_ == false) {

		}
		value_ += other.value_;
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

	std::ostream& operator<<(std::ostream& out, const Integer& other) {
		if (other.sign_ == true)
		{
			out << other.value_;
		}
		else
		{
			out << '-' << other.value_;
		}
		return out;
	}

