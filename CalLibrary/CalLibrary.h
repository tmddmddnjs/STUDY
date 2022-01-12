#pragma once

#ifdef CREATEDLL_EXPORTS
#define CALLIBRARY_API __declspec(dllexport)
#else
#define CALLIBRARY_API __declspec(dllimport)
#endif

extern "C" CALLIBRARY_API int Sum(int a, int b);
extern "C" CALLIBRARY_API int Sub(int a, int b);
extern "C" CALLIBRARY_API int Mul(int a, int b);
extern "C" CALLIBRARY_API int Div(int a, int b);