#pragma once

#include <iostream>

#include "Integer.hpp"



class Fraction
{ 
    public:
        Fraction();
        Fraction(bool sign, Integer num);
        Fraction(Integer number);
   
        void flip();

        Integer getNum();
        
        Integer getDenum();

        bool getSign();

        void FractionReduce(Integer num_, Integer denum_);

        void setNum(Integer num);

        void setDenum(Integer num);

        void setsign(bool sign);
        // ������ �������� ��������� 

        bool IsProper(Integer num_, Integer denum_);

        Fraction operator +(const Fraction& other) const;
      
        Fraction operator -(const Fraction& other) const;

        friend std::ostream& operator<<(std::ostream& out, Fraction num);

        bool operator<=(const Fraction& other);
   
    private:
        bool sign_;
        Integer num_;
        Integer denum_;
};
 
