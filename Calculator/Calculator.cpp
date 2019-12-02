// Calculator.cpp : Main here

#include <iostream>
#include <string.h>
#include "Headers.h"

using namespace std;




int main()
{
	// Examples of determining correctness of brackets amount

	char expr1[] = "20+5*(5-(-3+3))/(6-2)";
	int len_expr1 = strlen(expr1);
	char expr2[] = "(2+3)*3)";
	int len_expr2 = strlen(expr2);
	
	if (Is_Correct_Brackets(expr1, len_expr1))
	{
		cout << "Expression '" << expr1 << "' is correct" << endl;
	}
	else
		cout << "Expression '" << expr1 << "' is wrong" << endl;

	if (Is_Correct_Brackets(expr2, len_expr2))
	{
		cout << "Expression '" << expr1 << "' is correct" << endl;
	}
	else
		cout << "Expression '" << expr2 << "' is wrong" << endl;

}