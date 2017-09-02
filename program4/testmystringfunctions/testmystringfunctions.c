// Ryan Tong

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "mystringfunctions.h"

bool getAndRunTest();
void deepCopyStrTestA();
void deepCopyStrTestB();
void deepCopyStrTestC();
void isLowerOrDigitStrTestA();
void isLowerOrDigitStrTestB();
void isLowerOrDigitStrTestC();
void concatStrsTestA();
void concatStrsTestB();
void concatStrsTestC();
void flushStdin();

int main() {
  bool getInput = true;
  printf("Which unit test would you like to run?\n");
  printf("1) deepCopyStr\n");
  printf("\ta) n = 2, src = \"test string\"\n");
  printf("\tb) n = 0 returns \"\\0\"\n");
  printf("\tc) negative n returns NULL\n");
  printf("2) isLowerOrDigitStr\n");
  printf("\ta) n = 4, src = \"testString\"\n");
  printf("\tb) n = 5, src = \"testString\"\n");
  printf("\tc) n = 0\n");
  printf("3) concatStrs\n");
  printf("\ta) n = 5, str1 = \"test\", str2 = \"string\"\n");
  printf("\tb) n = 5, str1 = \"\", str2 = \"test string\" returns \"test \"\n");
  printf("\tc) n = 5, str1 = \"test\", str2 = \"\" returns NULL\n");
  while (getInput) {
    getInput = !getAndRunTest();
    flushStdin();
  }
  return 0;
}

bool getAndRunTest() {
  char function, test;
  if (scanf("%c%c", &function, &test) == 2) {
    switch (function) {
      case '1':
        switch (test) {
          case 'a':
            deepCopyStrTestA();
            return true;
          case 'b':
            deepCopyStrTestB();
            return true;
          case 'c':
            deepCopyStrTestC();
            return true;
          default:
            printf("Enter a, b, or c for the test case.\n");
            return false;
        }
      case '2':
        switch (test) {
          case 'a':
            isLowerOrDigitStrTestA();
            return true;
          case 'b':
            isLowerOrDigitStrTestB();
            return true;
          case 'c':
            isLowerOrDigitStrTestC();
            return true;
          default:
            printf("Enter a, b, or c for the test case.\n");
            return false;
        }
      case '3':
        switch (test) {
          case 'a':
            concatStrsTestA();
            return true;
          case 'b':
            concatStrsTestB();
            return true;
          case 'c':
            concatStrsTestC();
            return true;
          default:
            printf("Enter a, b, or c for the test case.\n");
            return false;
        }
      default:
        printf("Enter 1, 2, or 3 for the function to test.\n");
        return false;
    }
  }
  return false;
}

// Test n = 2 and src = "test string" returns "te"
void deepCopyStrTestA() {
  int n = 2;
  char src[12] = "test string";

  char* returnVal = deepCopyStr(src, n);

  assert(strncmp(returnVal, "te", 3) == 0);
  
  printf("Test successful.\n\n");
}

// Test n = 0 the returns "\0"
void deepCopyStrTestB() {
  int n = 0;
  char src[12] = "test string";

  char* returnVal = deepCopyStr(src, n);

  assert(strncmp(returnVal, "\0", 1) == 0);

  printf("Test successful.\n\n");
}

// Test negative n returns NULL"
void deepCopyStrTestC() {
  int n = -1;
  char src[12] = "test string";

  char* returnVal = deepCopyStr(src, n);

  assert(returnVal == NULL);

  printf("Test successful.\n\n");
}

// Test n = 4, src = "testString" returns true
void isLowerOrDigitStrTestA() {
  unsigned int n = 4;
  char src[11] = "testString";

  bool returnVal = isLowerOrDigitStr(src, n);

  assert(returnVal == true);

  printf("Test successful.\n\n");
}

// Test n = 5, src = "testString" returns false
void isLowerOrDigitStrTestB() {
  unsigned int n = 5;
  char src[11] = "testString";

  bool returnVal = isLowerOrDigitStr(src, n);

  assert(returnVal == false);

  printf("Test successful.\n\n");
}

// Test n = 0, src = "" returns true
void isLowerOrDigitStrTestC() {
  unsigned int n = 0;
  char src[1] = "";

  bool returnVal = isLowerOrDigitStr(src, n);

  assert(returnVal == true);

  printf("Test successful.\n\n");
}

// Test n = 5, str1 = "test", str2 = "string" returns "tests"
void concatStrsTestA() {
  int n = 5;
  char str1[5] = "test";
  char str2[7] = "string";

  char* returnVal = concatStrs(str1, str2, n);

  assert(strncmp(returnVal, "tests", 6) == 0);

  printf("Test successful.\n\n");
}

// n = 5, str1 = "", str2 = "test string" returns "test "
void concatStrsTestB() {
  int n = 5;
  char str1[1] = "";
  char str2[12] = "test string";

  char* returnVal = concatStrs(str1, str2, n);

  assert(strncmp(returnVal, "test ", 6) == 0);

  printf("Test successful.\n\n");
}

// n = 5, str1 = "test", str2 = "" returns NULL
void concatStrsTestC() {
  int n = 5;
  char str1[5] = "test";
  char str2[1] = "";

  char* returnVal = concatStrs(str1, str2, n);

  assert(returnVal == NULL);

  printf("Test successful.\n\n");
}

// Flush stdin buffer
void flushStdin() {
  char c;
  // Skip all characters until end-of-file marker
  // or new line / carriage return
  while ( (c = getchar()) != EOF &&
          c != '\n' &&
          c != '\r' ) {};
}
