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

        Integer getUnits();

        bool getSign();

        Fraction GetFlipped();

        static Fraction& FractionReduce(Fraction frac);

        void setNum(Integer num);

        void setDenum(Integer num);

        void setSign(bool sign);

        void setUnits(Integer num);
        // Методы проверки состояния 
        bool IsSame(const Fraction other);

        static bool IsFracEqual(const Fraction obj, const Fraction other);

        bool IsProper();

        bool IsImproper();

        bool IsPositive();
        
        bool IsNegative();

        Fraction operator +(const Fraction& other) const;
      
        Fraction operator -(const Fraction& other) const;

        Fraction operator *(const Fraction& other) const;


        bool operator==(const Fraction& other) const;

        bool operator<=(const Fraction& other) const;
   
        friend std::ostream& operator<<(std::ostream& out, Fraction num);
    private:
        bool sign_;
        Integer num_;
        Integer denum_;
        Integer units_;
};
 
