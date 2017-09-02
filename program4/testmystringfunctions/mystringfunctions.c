#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "mystringfunctions.h"

// Creates a copy of the first n chars from string src
char* deepCopyStr(char* src, int n) {
  // Error if a negative integer is passed
  if (n < 0) {
    return NULL;
  }
  // Error if no src string passed
  if (src == NULL) {
    return NULL;
  }
  char* result = (char*) malloc (sizeof(char) * (n + 1));
  for (int i = 0; i < n; i++) {
    // Error if string has less than n characters
    if (src[i] == '\0') {
      free(result);
      return NULL;
    }
    result[i] = src[i];
  }
  result[n] = '\0';
  return result;
}

// Returns true if first n characters are lowercase letters or digits
bool isLowerOrDigitStr(char* src, unsigned int n) {
  for (int i = 0; i < n; i++) {
    if (('a' <= src[i] && src[i] <= 'z') ||
        ('0' <= src[i] && src[i] <= '9')) {
      continue;
    } else {
      return false;
    }
  }
  return true;
}

// Creates a copy of the first n chars from str1 concated with str2
char* concatStrs(char* str1, char* str2, int n) {
  // Error if a negative integer is passed
  if (n < 0) {
    return NULL;
  }
  int j = 0;
  char* result = (char*) malloc (sizeof(char) * (n + 1));
  char* srcStr = str1;
  for (int i = 0; i < n; i++, j++) {
    // Swap to str2 if at end of str1
    if (srcStr == str1 && srcStr[j] == '\0') {
      srcStr = str2;
      j = 0;
    }
    // Error if strings have less than n characters
    if (srcStr == str2 && srcStr[j] == '\0') {
      free(result);
      return NULL;
    }
    result[i] = srcStr[j];
  }
  result[n] = '\0';
  return result;
}
