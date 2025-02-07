#include "..\hd\Fraction.hpp"


Fraction::Fraction(): Fraction(Integer(1), Integer(1)) { }
Fraction::Fraction(Integer denum, Integer num) :denum_(denum_), num_(num_) { }
Fraction::Fraction(Integer number){
    if (number < 0)
    {
        this->num_ = number;
        this->denum_ = static_cast<Integer>(1);
    }
    else
    {
        this->num_ = number;
        this->denum_ = static_cast<Integer>(1);
    }
}

void Fraction::flip()
{
    Integer tmp;
    tmp = denum_;
    denum_ = num_;
    num_ = tmp;
}
//Геттеры
Integer Fraction::getNum() const{
    return num_;
}
Integer Fraction::getDenum() const
{
    return denum_;
}

bool Fraction::getSign() const{
    if (num_.getSign() != denum_.getSign())
    {
        return false;
    }
    return true;
}

Fraction Fraction::GetFlipped()
{
    Integer tmp;
    tmp = denum_;
    denum_ = num_;
    num_ = tmp;
    return *this;
}
//Сеттеры
void Fraction::setNum(Integer num)
{
    num_ = num;
    num_.setSign(num > 0 ? true: false);
   
}
void Fraction::setDenum(Integer num)
{
    denum_ = num;
    denum_.setSign(num > 0 ? true : false);
}

void Fraction::setSign(bool sign) {
    num_.setSign(sign);
    denum_.setSign(sign);
}

//Методы проверки состояния
bool Fraction::IsSame(const Fraction* other) const{
    return this == other;
}

bool Fraction::IsFracEqual(const Fraction& obj, const Fraction& other) {
    return FractionReduce(other) == FractionReduce(obj);
}

bool Fraction::IsProper() const{
    if (denum_ == Integer(1))
    {
        return true;
    }
    else {
        FractionReduce(*this);
        if (denum_ == 1)
        {
            return true;
        }
    }
    return false;
}
bool Fraction::IsImproper() const{
    if (denum_ == Integer(1))
    {
        return false;
    }
    else {
        FractionReduce(*this);
        if (denum_ == 1)
        {
            return false;
        }
    }
    return true;
}


bool Fraction::IsPositive() const{
    return num_.getSign() == true && denum_.getSign() == true;
}

bool Fraction::IsNegative() const{
    return num_.getSign() == false && denum_.getSign() == false;
}

//Сокращает дробь
Fraction& Fraction::FractionReduce(Fraction frac) {
    {
        Integer k = 2;
        while (frac.num_ % k == 0 && frac.denum_ % k == 0) {
            if (frac.num_ % k == 0 && frac.denum_ % k == 0)
            {
                frac.num_ /= k;
                frac.denum_ /= k;
            }
            if (frac.num_ == Integer(1) || frac.denum_ == Integer(1))
            {
                break;
            }
            k++;
        }

        return frac;
    }
}


    Fraction Fraction::operator+(const Fraction& other) const{
        Integer num1;
        Integer num2;
        Fraction result;
        if (IsPositive() == true && other.IsPositive() == true)
        {
            num1 = num_ * other.denum_ + other.num_ * denum_;
            num2 = denum_ * other.denum_;
            result.setSign(true);
        }
        else if (IsPositive() == false && other.IsPositive() == false) {

            num1 = denum_ * other.num_ - num_ * other.denum_;
            num2 = denum_ * other.denum_;
        }
        else {
            num1 = num_ * other.denum_ - denum_ * other.num_;
            num2 = denum_ * other.denum_;
        }
        result.num_ = num1;
        result.denum_ = num2;

        return result;
    }
/*
Fraction Fraction::operator *(const Fraction& other) const {
    Fraction result;
    if (sign_ == other.sign_)
    {
        Integer num1 = 
        Integer num2 =
    }
    else
    {

    }
}
*/
// оператор вычитания

 Fraction Fraction::operator -(const Fraction& other) const {
     Integer num1;
     Integer num2;
     Fraction result;
     if (getSign() == other.getSign())
     {
         Integer SideNum = denum_ * other.num_;
         Integer MainNum = num_ * other.denum_;
         if (SideNum > MainNum)
         {
         Integer num1 = SideNum - MainNum;
         }
         else {
         Integer num1 = MainNum - SideNum;
         }
         
         Integer num2 = denum_ * other.denum_;
     }
     else if (getSign() == false && other.getSign() == true) {
         Integer num1 = denum_ * other.num_ + num_ * other.denum_;
         Integer num2 = denum_ * other.denum_;
     }
     else {
         Integer num1 = num_ * other.denum_ - denum_ * other.num_;
         Integer num2 = denum_ * other.denum_;
     }
     result.num_ = num1;
     result.denum_ = num2;
     return result;
 }

 bool operator==(const Fraction& num, const Fraction& other){
     
         if (num.num_ == other.num_ && num.denum_ == other.denum_ && num.getSign() == other.getSign())
         {
             return true;
         }
     return false;
 }

 bool operator<=(const Fraction& num, const Fraction& other){
     if (num.getSign() == other.getSign())
     {
         Integer SideNum = num.denum_ * other.num_;
         Integer MainNum = num.num_ * other.denum_;
         return MainNum <= SideNum;
     }
     else if (num.getSign() == true && other.getSign() == false) {
         return false;
     }
     else {
         return true;
     }
 }

 // Оператор вывода
 std::ostream& operator<<(std::ostream& out, Fraction other)
 {

     if (other.getSign() == true)
     {
         if (other.denum_ == 1) {

             out << other.num_;
         }
         else {
             out << other.num_ << "/" << other.denum_;
         }
     }
     else
     {
         if (other.denum_ == 1) {
             out << '-' << other.num_;
         }
         else {
             out << '-' << other.num_ << "/" << other.denum_;
         }
     }
     return out;
 }

