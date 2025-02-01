#include "..\hd\Fraction.hpp"


Fraction::Fraction(): Fraction(false, Integer(1)) { }
Fraction::Fraction(bool sign, Integer num) :sign_(sign_), num_(num_) { }
Fraction::Fraction(int number){
    sign_ = true;
    this->num_ = number;
    this->denum_ = Integer(1);
    
   
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
bool Fraction::getSign()
{
    return sign_;
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
void Fraction::setsign(bool sign)
{
    sign_ = sign;
}

//Сокращает дробь
//void Fraction::FractionReduce()
//{
//    for (Integer k = 2; k <= num_ && k <= denum_; ++k) {
//        while (num_ % k == 0 && denum_ % k == 0) {
//            num_ /= k;
//            denum_ /= k;
//        }
//    }
//}


Fraction Fraction::operator +(const Fraction& other) const {
    Integer num1;
    Integer num2;
    Fraction result;
    if (sign_ == other.sign_)
    {
        Integer num1 = num_ * other.denum_ + denum_ * other.num_;
        Integer num2 = denum_ * other.denum_;
    }
    else if (sign_ == false && other.sign_ == true) {
        Integer num1 = denum_ * other.num_ - num_ * other.denum_;
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

 bool Fraction::operator<=(const Fraction& other) {
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
             if (other.denum_ == 1) {
                 
                 out << other.num_;
             }
             else {
                 //other.FractionReduce();
                 out << other.num_ << "/" << other.denum_;
             }
     }
     else
     {
         if (other.denum_ == 1) {
             out << '-' << other.num_;
         }
         else {
            // other.FractionReduce();
             out << '-' << other.num_ << "/" << other.denum_;
         }
     }
     return out;
 }

