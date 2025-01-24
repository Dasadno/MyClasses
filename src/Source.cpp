#include <iostream>
#include "..\hd\Integer.hpp"
#include "..\hd\Fraction.hpp"
#include "..\hd\Rational.hpp"


int main() {

	Fraction Rat1;
	Fraction Rat2;

	Integer num1;
	num1 = 54;
	num1.setSign(false);

	Integer num2;
	num1 = 32;
	num1.setSign(true);
	
	Rat1.setDenum(1);
	Rat1.setNum(15);
	Rat1.setsign(true);

	Rat2.setDenum(5);
	Rat2.setNum(27);
	Rat2.setsign(true);

	std::cout << "Integer1: -> " << num1 << "\n";
	std::cout << "Integer2: -> " << num2 << "\n";
	std::cout << "Fraction1: -> " << Rat1 << "\n";
	std::cout << "Fraction2: -> " << Rat2 << "\n";


	return 0;
}                                             