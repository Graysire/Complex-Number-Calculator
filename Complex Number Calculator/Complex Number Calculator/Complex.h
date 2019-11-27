#pragma once
#ifndef COMPLEX
#define COMPLEX
#include <string>

class Complex
{
public:
	Complex();
	Complex(int r, int i, int d);
	std::string toString() const;

	int getReal() const;
	int getImaginary() const;
	int getDenominator() const;
	void setReal(int real);
	void setImaginary(int imi);
	void setDenominator(int den);
private:
	int re, im, dem;

};
Complex operator+(const Complex& a, const Complex& b);
Complex operator-(const Complex& a, const Complex& b);
Complex operator*(const Complex& a, const Complex& b);
Complex operator/(const Complex& a, const Complex& b);
std::ostream& operator<<(std::ostream& stream, const Complex& a);
int gcd(int a, int b);
int lcm(int a, int b);


#endif // !COMPLEX
