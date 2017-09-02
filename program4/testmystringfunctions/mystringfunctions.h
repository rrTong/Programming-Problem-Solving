#ifndef MYSTRINGFUNCTIONS
#define MYSTRINGFUNCTIONS

#include <stdbool.h>

char* deepCopyStr(char* src, int n);
// unsigned ints are non-negative
bool isLowerOrDigitStr(char* src, unsigned int n);
char* concatStrs(char* str1, char* str2, int n);

#endif
