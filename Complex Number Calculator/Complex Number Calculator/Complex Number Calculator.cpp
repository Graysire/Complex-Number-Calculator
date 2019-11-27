/*
Name: Grayson Hill
Class: CECS 282
Instructor: Minhthong Nguyen
Purpose of the Program: Create a Complex Number Calculator that can parse text file input
Last Updated: 11/26/2019
*/

#include "pch.h"
#include "Complex.h"
#include <iostream>

using namespace std;
int main()
{
	Complex c1 = Complex(4, 3, 5);
	Complex c2 = Complex(3, 4, 2);

	cout << c1 << endl;
	cout << c2 << endl;

	cout << c1 + c2 << endl;
	cout << c1 - c2 << endl;
	cout << c1 * c2 << endl;
	cout << c1 / c2 << endl;


	cout << gcd(424, 664);
	return 0;
}
