#include "..\hd\Fraction.hpp"


Fraction::Fraction(): Fraction(false, Integer(1)) { }
Fraction::Fraction(bool sign, Integer num) :sign_(sign_), num_(num_) { }
Fraction::Fraction(Integer number){
    if (number < 0)
    {
        sign_ = false;
        this->num_ = number;
        this->denum_ = static_cast<Integer>(1);
    }
    else
    {
        sign_ = true;
        this->num_ = number;
        this->denum_ = static_cast<Integer>(1);
    }
    this->units_ = static_cast<Integer>(0);  
}

void Fraction::flip()
{
    Integer tmp;
    tmp = denum_;
    denum_ = num_;
    num_ = tmp;
}
//Геттеры
Integer Fraction::getNum() {
    return num_;
}
Integer Fraction::getDenum()
{
    return denum_;
}

Integer Fraction::getUnits() {
    return units_;
}

bool Fraction::getSign() 
{
    return sign_;
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
}
void Fraction::setDenum(Integer num)
{
    denum_ = num;
}
void Fraction::setSign(bool sign)
{
    sign_ = sign;
}
void Fraction::setUnits(Integer num)
{
    units_ = num;
}

//Методы проверки состояния
bool Fraction::IsSame(const Fraction other) {
    if (sign_ == other.sign_ && num_ == other.num_ && denum_ == other.denum_ && units_ == other.units_)
    {
        return true;
    }
    return false;
}

bool Fraction::IsFracEqual(const Fraction obj, const Fraction other) {
    FractionReduce(obj);
    FractionReduce(other);
    return obj == other ? true : false;
}

bool Fraction::IsProper() {
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
bool Fraction::IsImproper() {
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


bool Fraction::IsPositive() {
    return sign_ == true ? true : false;
}

bool Fraction::IsNegative() {
    return sign_ == false ? true : false;
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
                while (frac.num_ > frac.denum_) {
                    frac.num_ - frac.denum_;
                    frac.units_++;
                    if (frac.num_ == 0)
                    {
                        frac.denum_ - frac.denum_;
                    }
                }
            }
                break;
            }
            frac.units_.setSign(frac.sign_);
            k++;
        }
    return frac;
}


Fraction Fraction::operator +(const Fraction& other) const {
    Integer num1;
    Integer num2;
    Fraction result;
    if (sign_ == true && other.sign_ == true)
    {
        num1 = num_ * other.denum_ + other.num_ * denum_;
        num2 = denum_ * other.denum_;
        result.sign_ == true;
    }
    else if (sign_ == false && other.sign_ == true) {
       
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
     if (sign_ == other.sign_)
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
     else if (sign_ == false && other.sign_ == true) {
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

 bool Fraction::operator==(const Fraction& other) const{
     
         if (num_ == other.num_ && denum_ == other.denum_ && units_ == other.units_ && sign_ == other.sign_)
         {
             return true;
         }
     return false;
 }

 bool Fraction::operator<=(const Fraction& other) const{
     if (sign_ == other.sign_)
     {
         Integer SideNum = denum_ * other.num_;
         Integer MainNum = num_ * other.denum_;
         return MainNum <= SideNum;
     }
     else if (sign_ == true && other.sign_ == false) {
         return false;
     }
     else {
         return true;
     }
 }

 // Оператор вывода
std::ostream& operator<<(std::ostream& out, Fraction other)
 {
     
     if (other.sign_ == true)
     {
             if (other.denum_ == 0) {
                 
                 out << other.units_;
             }
             else if (other.units_ > 0 && other.denum_ != 0) {
                 out << other.units_ << " " << other.num_ << "/" << other.denum_;
             }
             else
             {
                 out << other.num_ << "/" << other.denum_;
             }
     }
     else
     {
         if (other.denum_ == 0) {

             out << '-' << other.units_;
         }
         else if (other.units_ > 0 && other.denum_ != 0) {
             out << '-' << other.units_ << " " << other.num_ << "/" << other.denum_;
         }
         else
         {
             out << '-' << other.num_ << "/" << other.denum_;
         }
     }
     return out;
 }

