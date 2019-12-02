#include "Headers.h"

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