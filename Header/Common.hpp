#ifndef COMMON_H_
#define COMMON_H_

#include <string.h>
#include <string>
#include <iostream>

#define NEGATIVE "-"

#define TRACE_L_1
#undef TRACE_L_1

std::string subRem(std::string op, char borrow);
std::string sub(std::string op1, std::string op2);

std::string subDecision(std::string op1, std::string op2, bool isFirstNegative);

std::string add(std::string op1, std::string op2);

std::string rev(std::string str);
std::string charToString(char c);
std::string next(char c);
char prev(char c);
std::string rev(std::string str);
std::string remZ(std::string opZ);
std::string addDigit(char c1, char c2, char carryForward);

bool isGreaterThan0(char digit);
bool isGreaterThan1(char digit);
bool isGreaterThan2(char digit);
bool isGreaterThan3(char digit);
bool isGreaterThan4(char digit);
bool isGreaterThan5(char digit);
bool isGreaterThan6(char digit);
bool isGreaterThan7(char digit);
bool isGreaterThan8(char digit);
bool isGreaterThan9(char digit);
bool isGreaterDigit(char d1, char d2);

bool isGreaterThan(std::string op1, std::string op2);

#endif // COMMON_H_
