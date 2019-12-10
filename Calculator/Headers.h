#pragma once
struct T_List
{
	float data;
	T_List* next;
};
void Make(T_List*& top);
void Add(T_List*& top, float data);
void Delete_Last(T_List*& top);
float Last(T_List*& top);
int Priority(char operat);
int Priority(float code);
bool Is_Empty(T_List* top);
bool Is_Correct_Brackets(const char* expr, const int len_expr);
float Calculate(float a, float b, int code_oper);
void Push_Calculation_Result(float& a, float& b, int& nums_amount, T_List*& Nums, T_List*& Opers);
bool Calc_Is_Available(T_List* Opers, const int nums_amount);