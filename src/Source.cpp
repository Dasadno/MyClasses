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
	Rat1.setDenum(3);
	Rat1.setNum(10);
	Rat1.setSign(true);

	Fraction Rat2;
	Rat2.setDenum(16);
	Rat2.setNum(32);
	Rat2.setSign(true);
	


	
	std::cout << Fraction::FractionReduce(Rat1);
	std::cout << Fraction::FractionReduce(Rat2);
	


	return 0;
}                                             