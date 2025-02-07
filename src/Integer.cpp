#include "..\hd\Integer.hpp"

	//Конструкторы
	Integer::Integer() :Integer(false, 0u) { }
	Integer::Integer(bool sign, unsigned units) :sign_(sign), value_(value_) { }
	Integer::Integer(int number) {
		if (number < 0)
		{
			sign_ = false;
			value_ = abs(number);
		}
		else {
			sign_ = true;
			value_ = static_cast<unsigned>(number);
		}
	}
	//Сетеры
	void Integer::setSign(bool sign) {
		this->sign_ = sign;
	}

	void Integer::setValue(unsigned value) {
		this->value_ = value;
	}
	//Гетеры
	bool Integer::getSign()const {
		return sign_;
	}

	unsigned Integer::getValue()const {
		return value_;
	}
	// Функции проверки состояния
	bool Integer::isSimple()const
	{
		if (value_ < 2)
		{
			return false;
		}
		for (int i = 2; i <= value_ / 2; i++)
		{
			if (value_ % i == 0)
			{
				return false;
			}
		}
		return true;
	}
	bool Integer::isOdd() {
		return value_ % 2 != 0;
	}

	bool Integer::isEven() {
		return value_ % 2 == 0;
	}

	bool Integer::isPositive()const {
		return getSign;
	}

	bool Integer::isNegative() const{
		return !getSign();
	}

	bool Integer::isCoprime(Integer other)const
	{
		return std::gcd(value_, other.value_) == 1;
	}

	// нахождение наибольшего общего делителя
	int Integer::Nod(Integer other)const
	{
		return std::gcd(value_, other.value_);
	}

	// нахождение наибольшего общего кратного
	int Integer::Nok(Integer other)const
	{
		return std::lcm(value_, other.value_);
	}

	//Перегрузки операторов --------------------------------------

	//Алгебраические операторы

	//Оператор сложения
	Integer& Integer::operator + (const Integer& other) const
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
	//Унарный +
	Integer Integer::operator + () {
		return *this;
	}
	//Оператор умножения
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
	//Оператор деления
	Integer Integer::operator / (const Integer& other) const
	{
		if (other.value_ == 0)
		{
			std::cerr << "Invalid input";
			exit(-1);
		}
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
	//Оператор вычитания
	Integer& Integer::operator - (const Integer& other) const
	{
		Integer res;
		res = -(value_ + other.value_);
		return res;
	}
	//Унарный -
	Integer Integer::operator - ()
	{
		Integer copy{ *this };
		
			copy.sign_ = !copy.sign_;
			return copy;
	}

	Integer Integer::operator % (const Integer& other) const
	{
		if (sign_ == other.sign_)
		{
			return static_cast<Integer>(value_ % other.value_);
		}
		else
		{
			return static_cast<Integer>(-(value_ % other.value_));
		}	
	}
	// Операторы сравнения
	bool operator == (const Integer& num, const Integer& other)
	{
		if (num.getSign() == other.getSign())
		{
			return num.getValue() == other.getValue();
		}
		return false;
	}

	bool operator != (const Integer& num, const Integer& other)
	{
		if (num.getSign() == other.getSign())
		{
			return num.getValue() != other.getValue();
		}
		return true;
	}

	bool operator > (const Integer& num, const Integer& other)
	{
		if (num.getSign() == other.getSign())
		{
			return num.getValue() > other.getValue();
		}
		else if (num.getSign() == true && other.getSign() == false) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator < (const Integer& num, const Integer& other)
	{
		if (num.getSign() == other.getSign())
		{
			return num.getValue() < other.getValue();
		}
		else if (num.getSign() == true && other.getSign() == false) {
			return false;
		}
		else {
			return true;
		}
	}

	bool operator <= (const Integer& num, const Integer& other)
	{
		if (num.getSign() == other.getSign())
		{
			return num.getValue() <= other.getValue();
		}
		else if (num.getSign() == true && other.getSign() == false) {
			return false;
		}
		else {
			return true;
		}
	}

	bool operator>=(const Integer& num, const Integer& other)
	{
		if (num.getSign() == other.getSign())
		{
			return num.getValue() >= other.getValue();
		}
		else if (num.getSign() == true && other.getSign() == false) {
			return true;
		}
		else {
			return false;
		}
	}

	//Декремент, инкремент (Префиксные)
	Integer& Integer::operator++ ()
	{
		Integer copy{ *this };
		if (sign_ == true) {
			copy += static_cast<Integer>(1);
		}
		else {
			copy -= static_cast<Integer>(1);
		}
		return copy;
	}

	Integer& Integer::operator-- ()
	{
		Integer copy{ *this };
		if (sign_ == true) {
			copy -= static_cast<Integer>(1);
		}
		else {
			copy += static_cast<Integer>(1);
		}
		return copy;
	}
	//Декремент, инкремент (Постфиксные)
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
	// операторы присваивания
	Integer& Integer::operator += (Integer other)
	{
		return *this = *this + other;
	}

	Integer& Integer::operator -= (Integer other)
	{
		return *this = *this - other;
	}

	Integer& Integer::operator *= (const Integer& other)
	{
		return *this = *this * other;
		
	}

	Integer& Integer::operator /= (const Integer& other)
	{
		return *this = *this / other;
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

