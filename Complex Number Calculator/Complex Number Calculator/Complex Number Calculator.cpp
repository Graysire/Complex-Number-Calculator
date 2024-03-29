/*
Name: Grayson Hill
Class: CECS 282
Instructor: Minhthong Nguyen
Purpose of the Program: Create a Complex Number Calculator that can parse text file input
Last Updated: 11/26/2019
*/

#include "pch.h"
#include "Complex.h"
#include "DoublyLinked.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void complexOperation(char oper, StackDoublyLinkedList<Complex>& operStack);

int main()
{
	ifstream in;
	ofstream out = ofstream("result.txt");
	in.open("expression.txt");
	StackDoublyLinkedList<Complex> operandStack;
	StackDoublyLinkedList<char> operatorStack;
	string temp;
	//while (getline(in,temp))
	////{
	//	istringstream iss(temp);
	//	iss >> temp;
	//	cout << temp;
	//}
	for (string line; getline(in, line);)
	{
		cout << line << endl;
		int a = 0;
		for (int i = 0; i < line.size(); i++)
		{
			if (isdigit(line[i]))
			{
				a *= 10;
				a += (int)line[i] - 48;
			}
			else if (isalpha(line[i]))
			{
				if (a == 0)
				{
					a = 1;
				}
				if (operatorStack.getTop() == '+' || operatorStack.getTop() == '-')
				{
					Complex b = operandStack.getTop();
					operandStack.popFront();
					if (operatorStack.getTop() == '+')
					{
						operandStack.addFront(b + Complex(0, a, 1));
					}
					else
					{
						operandStack.addFront(b - Complex(0, a, 1));
					}
					operatorStack.popFront();
				}
				else
				{
					operandStack.addFront(Complex(0, a, 1));
				}
				a = 0;
			}
			else
			{
				if (a != 0)
				{
					operandStack.addFront(Complex(a, 0, 1));
					a = 0;
				}
				if (line[i] == ')')
				{
					while (operatorStack.getTop() != '(')
					{
						complexOperation(operatorStack.getTop(), operandStack);
						operatorStack.popFront();
					}
					operatorStack.popFront();
				}
				else if (line[i] == '%')
				{
					complexOperation(line[i], operandStack);
				}
				else if ((line[i] == '*' || line[i] == '/') && !operatorStack.isEmpty() && (operatorStack.getTop() == '*' || operatorStack.getTop() == '/' || operatorStack.getTop() == '+' || operatorStack.getTop() == '-'))
				{
					complexOperation(operatorStack.getTop(), operandStack);
					operatorStack.popFront();
				}
				else if ((line[i] == '+' || line[i] == '-') && !operatorStack.isEmpty() && (operatorStack.getTop() == '+' || operatorStack.getTop() == '-'))
				{
					complexOperation(operatorStack.getTop(), operandStack);
					operatorStack.popFront();
				}
				else if (line[i] == '=')
				{
					if (a > 0)
					{
						operandStack.addFront(Complex(a, 0, 1));
					}
					while (!operatorStack.isEmpty())
					{
						complexOperation(operatorStack.getTop(), operandStack);
						operatorStack.popFront();
					}
					out << operandStack.getTop() << endl;
					break;
				}
				if (a != 0)
				{
					operandStack.addFront(Complex(a, 0, 1));
					a = 0;
				}
				if (line[i] != ')' && line[i] != '%')
				{
					operatorStack.addFront(line[i]);
				}

			
			}	
			
			//operandStack.popFront();
		}
		//cout << operandStack.getTop() << endl;
		//operandStack.popFront();
		//break;

	}


	//cout << temp << endl;


	return 0;
}

void complexOperation(char oper, StackDoublyLinkedList<Complex>& operStack)
{
	Complex a, b;
	switch(oper)
	{
	case '%':
		b = operStack.getTop();
		operStack.popFront();
		b = Complex(b.getReal(), -1 * b.getImaginary(), b.getDenominator());
		operStack.addFront(b);
		break;
	case '*':
		b = operStack.getTop();
		operStack.popFront();
		a = operStack.getTop();
		operStack.popFront();
		operStack.addFront(a * b);
		break;
	case '/':
		b = operStack.getTop();
		operStack.popFront();
		a = operStack.getTop();
		operStack.popFront();
		operStack.addFront(a / b);
		break;
	case '+':
		b = operStack.getTop();
		operStack.popFront();
		a = operStack.getTop();
		operStack.popFront();
		operStack.addFront(a + b);
		break;
	case '-':
		b = operStack.getTop();
		operStack.popFront();
		a = operStack.getTop();
		operStack.popFront();
		operStack.addFront(a - b);
		break;
	}

}