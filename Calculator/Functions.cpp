#include "Headers.h"

void Make(T_List*& top)
{
	top = nullptr;
}

void Add(T_List*& top, float data)
{
	T_List* p = new T_List;
	p->data = data;
	p->next = top;
	top = p;
}

void Delete_Last(T_List*& top)
{
	T_List* p = top;
	top = p->next;
	delete p;
}

float Last(T_List*& top)
{
	float result = top->data;
	return result;
}

int Priority(char operat)
{
	if (operat == '+' || operat == '-')
		return 1;
	else if (operat == '*' || operat == '/')
		return 2;
	return 0;
}

int Priority(float code)
{
	if (code == 0 || code == 1)
		return 1;
	if (code == 2 || code == 3)
		return 2;
	return 0;
}

bool Is_Empty(T_List* top)
{
	if (top == nullptr)
		return true;
	return false;
}

void Push_Calculation_Result(float& a, float& b, int& nums_amount, T_List*& Nums, T_List*& Opers)
{
	a = Last(Nums);
	Delete_Last(Nums);
	nums_amount -= 1;

	b = Last(Nums);
	Delete_Last(Nums);
	nums_amount -= 1;

	Add(Nums, Calculate(b, a, Last(Opers)));
	nums_amount += 1;
	Delete_Last(Opers);
}

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

float Calculate(float a, float b, int code_oper)
{
	switch (code_oper)
	{
	case 0:
		return a + b;
	case 1:
		return a - b;
	case 2:
		return a * b;
	case 3:
		return a*1.0 / b;
	}
}

bool Calc_Is_Available(T_List* Opers, const int nums_amount)
{
	return nums_amount >= 2 && !Is_Empty(Opers) && Last(Opers) != 4;
}
