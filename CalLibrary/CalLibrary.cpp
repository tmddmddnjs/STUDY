#include "pch.h" 
#include "CalLibrary.h"

int Sum(int a, int b) {
	return a + b;
}

int Sub(int a, int b) {
	if (a >= b)
		return a - b;
	else
		return b - a;
}

int Mul(int a, int b) {
	return a * b;
}

int Div(int a, int b) {
	return a / b;
}