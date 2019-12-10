// Calculator.cpp : Main here

/*
Works with natural numbers
For correct use of calculator, insert '=' to the end of expression
Example: "3+2*(6-4)="
*/

#include <iostream>
#include "Headers.h"

using namespace std;


int main()
{

	T_List* Nums = new T_List;
	T_List* Opers = new T_List; // code of operations: '+' = 0, '-' = 1, '*' = 2, '/' = 3, '(' = 4

	Make(Nums);
	Make(Opers);

	char c, op;
	char n[10] = {0};
	int i = 0; // index for digits of number (number as char*)
	int nums_amount = 0;
	bool num_ended = true;
	cout << "Enter math expression that ends with '='\n";

	while (cin >> c)
	{
		if (c == '=')
			break;
		if (c >= '0' && c <= '9')
		{
			num_ended = false;
			n[i] = c;
			i += 1;
		}
		else if (i != 0)
		{
			num_ended = true;

			int N = atoi(n);
			Add(Nums, N);
			nums_amount += 1;

			for (int k = 0; k < i; k++)
				n[k] = 0;
			i = 0;
		}
		if (num_ended)
		{
			op = c;
			if (op != '(' && Calc_Is_Available(Opers, nums_amount))
			{
				if (op == ')')
				{
					while (Calc_Is_Available(Opers, nums_amount))
					{
						float a, b;
						Push_Calculation_Result(a, b, nums_amount, Nums, Opers);

					}
					Delete_Last(Opers); // delete '('
				}
				else
					while (Calc_Is_Available(Opers, nums_amount) && Priority(Last(Opers)) >= Priority(op))
					{
						float a, b;
						Push_Calculation_Result(a, b, nums_amount, Nums, Opers);
					}
			}
			char ops[5] = { '+', '-', '*', '/', '(' };
			for (int code = 0; code <= 4; code++)
			{
				if (op == ops[code])
				{
					Add(Opers, code);
					break;
				}
			}
		}
	}
	if (n[0] != 0)
	{
		int N = atoi(n);
		Add(Nums, N);
		nums_amount += 1;
	}

	while (Calc_Is_Available(Opers, nums_amount))
	{
		float a, b;

		Push_Calculation_Result(a, b, nums_amount, Nums, Opers);
	}
	if (!Is_Empty(Nums))
		cout << "Result: " << Last(Nums);
	else
		cout << "You entered incorrect expression";

	return 0;

}