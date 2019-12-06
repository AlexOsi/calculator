#include "Headers.h"
#include <stdlib.h>

bool Is_Correct_Brackets(const char* expr, const int len_expr)
{
	/*
	Determines the correctness of brackets amount in mathematical expression
	*/
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

int Simple_Calculate(const char* expr, const int len_expr)
{
	/*
	Do simple calculation with 2 numbers and return result
	*/
	char operations[4] = { '+', '-', '*', '/' };

	char num_1[10] = {};
	int len_num1;
	char num_2[10] = {};
	int len_num2;
	int di = 0; // index of digit of number
	char operat = 'N'; // default NONE 
	bool is_num1 = true; // false -> num2
	bool is_digit = false;
	for (int i = 0; i < len_expr; i++)
	{
		is_digit = false;
		if (expr[i] >= 48 && expr[i] <= 57) // numbers in ascii between 48 and 57
		{
			is_digit = true;
			if (is_num1)
			{
				num_1[di] = expr[i];
				di += 1;
			}
			else // num2
			{
				num_2[di] = expr[i];
				di += 1;
			}
		}
		if (operat == 'N' && !(is_digit))
			for (int j = 0; j < 4; j++)
				if (expr[i] == operations[j])
				{
					operat = operations[j]; // operation saved
					if (is_num1)
					{
						is_num1 = false; // now save num2
						len_num1 = di;
						di = 0;
					}
					break;
				}
	}
	len_num2 = di;

	int n1 = atoi(num_1);
	int n2 = atoi(num_2);
	if (operat == '+')
		return n1 + n2;
	if (operat == '-')
		return n1 - n2;
	if (operat == '*')
		return n1 * n2;
	if (operat == '/')
		return n1 / n2;
	return 0;
}
