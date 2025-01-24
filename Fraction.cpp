#include "Fraction.hpp"


Fraction::Fraction(): Fraction(false, 0) { }
Fraction::Fraction(const Integer& num, const Integer& denum) 
{
    sign_ = true;
    this->num_ = num;
    if (num != 0)
    {
        this->denum_ = denum;
    }
    else{
        std::cerr << "constructor value error";
    }
   
}

Fraction Fraction::flip()
{
    return Fraction(denum_, num_);
}
Integer Fraction::getNum() {
    return num_;
}
Integer Fraction::getDenum()
{
    return denum_;
}

//Сокращает дробь
//void Fraction::FractionReduce()
//{
//    for (int k = 2; k <= num_ && k <= denum_; ++k) {
//        while (num_ % k == 0 && denum_ % k == 0) {
//            num_ /= k;
//            denum_ /= k;
//        }
//    }
//}


 Fraction Fraction::operator +(const Fraction& other) const {
    Integer num1;
    Integer num2;
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
    return Fraction(num1, num2);
}


 Fraction Fraction::operator -(const Fraction& other) const {
     Integer num1;
     Integer num2;
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
     return Fraction(num1, num2);
 }

 // Оператор вывода
//std::ostream& operator<<(const std::ostream& out, Fraction num)
// {
//     num.FractionReduce();
//     if (num.denum_ == 1) {
//         out << num.num_;
//     }
//     else {
//         out << num.num_ << "/" << num.denum_;
//     }
//     return out;
// }

