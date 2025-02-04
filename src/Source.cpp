#include <iostream>
#include "..\hd\Integer.hpp"
#include "..\hd\Fraction.hpp"



int main() {

	

	Integer num1;
	num1 = 54;
	num1.setSign(false);

	Integer num2;
	num2 = 32;
	num2.setSign(true);
	
	Fraction Rat1;
	Rat1.setDenum(1);
	Rat1.setNum(15);
	Rat1.setsign(true);

	Fraction Rat2;
	Rat2.setDenum(5);
	Rat2.setNum(27);
	Rat2.setsign(true);
	
	std::cout << Rat1 << "\n";
	std::cout << Rat2 << "\n";

	std::cout << Rat2.isPositive();


	return 0;
}                                             