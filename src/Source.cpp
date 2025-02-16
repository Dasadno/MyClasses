#include <iostream>
#include "..\hd\Integer.hpp"
#include "..\hd\Fraction.hpp"
#include "..\hd\String.h"


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
	

	String str1 = "asd";
	
	std::cout << str1;
	std::cout << Rat1 + Rat2;

	


	return 0;
}                                             