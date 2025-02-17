#pragma once

#include <iostream>

#include "Integer.hpp"



class Fraction
{ 
    public:
        Fraction();
        Fraction(Integer denum, Integer num);
        Fraction(Integer number);
   
        void flip();

        Integer getNum() const;
        
        Integer getDenum()const;

        bool getSign() const;

        Integer getUnits();

        Fraction GetFlipped() const;

        Fraction GetSimple() const;

        static Fraction& FractionReduce(Fraction frac);

        void setNum(Integer num);

        void setDenum(Integer num);

        void setSign(bool sign);

        // Методы проверки состояния 
        bool IsSame(const Fraction* other) const;

        bool IsFracEqual(const Fraction& other) const;

        bool IsProper() const;

        bool IsImproper() const;

        bool IsPositive() const;
        
        bool IsNegative() const;

        Fraction operator+(const Fraction& other) const;
      
        Fraction operator-(const Fraction& other) const;

        Fraction operator*(const Fraction& other) const;


        friend bool operator==(const Fraction& num, const Fraction& other);

        friend bool operator<=(const Fraction& num, const Fraction& other);
   
        friend std::ostream& operator<<(std::ostream& out, Fraction num);
    private:
        Integer num_;
        Integer denum_;
};
 
