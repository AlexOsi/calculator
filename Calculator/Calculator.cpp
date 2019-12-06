// Calculator.cpp : Main here

#include <iostream>
#include <string.h>
#include "Headers.h"

using namespace std;


int main()
{
	char expr[] = "20+5*(5-(-3+3))/(6-2)";
	int len_expr = strlen(expr);
	char based_expr[] = "2*35";
	cout << Simple_Calculate(based_expr, 4);
}