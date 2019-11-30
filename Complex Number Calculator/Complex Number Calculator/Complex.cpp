#include "pch.h"
#include "Complex.h"

//Default Constructor
Complex::Complex()
{
	re = 0;
	im = 0;
	dem = 1;
}

//Constructor defining real, imaginary, denominator
Complex::Complex(int r, int i, int d)
{
	re = r;
	im = i;
	dem = d;
}

//returns the real number portion of the Complex
int Complex::getReal() const
{
	return re;
}

//returns the imaginary portion of the complex
int Complex::getImaginary() const
{
	return im;
}

//return the denominator of the complex
int Complex::getDenominator() const
{
	return dem;
}

//sets the real portion of the Complex equal to real
void Complex::setReal(int real)
{
	re = real;
}

//sets the imagninary portion of the Complex equal to imi
void Complex::setImaginary(int imi)
{
	im = imi;
}

//sets the denominator of the Complex equal to den
void Complex::setDenominator(int den)
{
	dem = den;
}

//returns Complex in the form [real + imaginaryi] / denominator
std::string Complex::toString() const
{
	std::string temp = "[" + std::to_string(re);
	if (im > -1)
	{
		temp += "+";
	}
	temp += std::to_string(im) + "i]/" + std::to_string(dem);
	return temp;


}

//returns Complex c which equals a + b
Complex operator+(const Complex& a, const Complex& b)
{
	int r = a.getReal() * b.getDenominator() + b.getReal() * a.getDenominator();
	int i = a.getImaginary() * b.getDenominator() + b.getImaginary() * a.getDenominator();
	int d = lcm(a.getDenominator(), b.getDenominator());

	r = r / gcd(a.getDenominator(), b.getDenominator());
	i = i / gcd(a.getDenominator(), b.getDenominator());

	return Complex(r, i, d);
}

//returns Complex c which equals a - b
Complex operator-(const Complex& a, const Complex& b)
{
	int r = a.getReal() * b.getDenominator() - b.getReal() * a.getDenominator();
	int i = a.getImaginary() * b.getDenominator() - b.getImaginary() * a.getDenominator();
	int d = lcm(a.getDenominator(), b.getDenominator());

	r /= gcd(a.getDenominator(), b.getDenominator());
	i /= gcd(a.getDenominator(), b.getDenominator());

	return Complex(r, i, d);
}

//returns Complex c which equals a * b
Complex operator*(const Complex& a, const Complex& b)
{
	int r = a.getReal() * b.getReal() - a.getImaginary() * b.getImaginary();
	int i = a.getReal() * b.getImaginary() + b.getReal() * a.getImaginary();
	int d = lcm(a.getDenominator(), b.getDenominator());

	r /= gcd(a.getDenominator(), b.getDenominator());
	i /= gcd(a.getDenominator(), b.getDenominator());

	return Complex(r, i, d);
}

//returns Complex c which equals a / b
Complex operator/(const Complex& a, const Complex& b)
{
	Complex top = Complex(a.getReal() * b.getDenominator(), a.getImaginary() * b.getDenominator(), 1);
	Complex bot = Complex(b.getReal() * a.getDenominator(), b.getImaginary() * a.getDenominator(), 1);
	Complex botCancel = Complex(bot.getReal(), -1 * bot.getImaginary(), bot.getDenominator());

	Complex topResult = top * botCancel;
	
	int r = topResult.getReal() / gcd(a.getDenominator(),b.getDenominator());
	int i = topResult.getImaginary() / gcd(a.getDenominator(),b.getDenominator());
	int d = (bot * botCancel).getReal() / gcd(a.getDenominator(),b.getDenominator());
	int g = gcd(gcd(r, d), gcd(i, d));
	
	return Complex(r / g, i / g, d / g);
}

//adds toString fo Complex to ostream
std::ostream& operator<<(std::ostream& stream, const Complex& a)
{
	stream << a.toString();
	return stream;
}

//returns the greatest common denominator of a and b
int gcd(int a, int b)
{
	int r, q;
	while (true)
	{
		q = a / b;
		r = a % b;
		if (r == 0)
		{
			break;
		}
		a = b;
		b = r;
	}
	if (b < 0)
	{
		b *= -1;
	}
	return b;
}

//returns the least common multiple of a and b
int lcm(int a, int b)
{
	int lcm = a * b / gcd(a, b);
	if (lcm < 0)
	{
		lcm = lcm * -1;
	}
	return lcm;
}