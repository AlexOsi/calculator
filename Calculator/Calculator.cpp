// Calculator.cpp : Main here

#include <iostream>
#include <string.h>

using namespace std;

bool Is_Correct_Brackets(const char* expr, const int len_expr);




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



bool Is_Correct_Brackets(const char* expr, const int len_expr)
{
	/*Determines the correctness of brackets amount in mathematical expression*/
	int counter = 0; // counts open brackets (+1) and closed brackets (-1)
	for (int i = 0; i < len_expr; i++)
	{
		if (expr[i] == ')')
		{
			counter -= 1;
			if (counter < 0) // if closed brackets counted more than open brackets
				return false;
		}
		else if (expr[i] == '(')
			counter += 1;
	}
	if (counter == 0)
		return true;
	return false;
}