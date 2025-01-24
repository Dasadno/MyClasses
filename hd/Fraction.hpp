#pragma once

#include <iostream>

#include "Integer.hpp"



class Fraction
{ 
    public:
        Fraction();
        Fraction(const Integer& num, const Integer& denum);
   
        Fraction flip();

        Integer getNum();
        
        Integer getDenum();

        void FractionReduce();

        Fraction operator +(const Fraction& other) const;
      
        Fraction operator -(const Fraction& other) const;

        friend std::ostream& operator<<(const std::ostream& out, Fraction num);
   
    private:
        bool sign_;
        Integer num_;
        Integer denum_;
};
 
