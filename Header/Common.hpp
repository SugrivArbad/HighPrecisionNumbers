#pragma once

#ifndef COMMON_H_
#define COMMON_H_

#include <string>
#include <iostream>

#define NEGATIVE "-"

std::string subRem(std::string op, char borrow);
std::string sub(std::string op1, std::string op2);

std::string add(std::string op1, std::string op2);
std::string mult(std::string op1, std::string op2);

std::string rev(std::string str);
std::string charToString(char c);
std::string next(char c);
char prev(char c);
std::string rev(std::string str);
std::string remZ(std::string opZ);
std::string addDigit(char c1, char c2, char carryForward);

bool isGreaterThanDigit0(char digit);
bool isGreaterThanDigit1(char digit);
bool isGreaterThanDigit2(char digit);
bool isGreaterThanDigit3(char digit);
bool isGreaterThanDigit4(char digit);
bool isGreaterThanDigit5(char digit);
bool isGreaterThanDigit6(char digit);
bool isGreaterThanDigit7(char digit);
bool isGreaterThanDigit8(char digit);
bool isGreaterThanDigit9(char digit);
bool isGreaterDigit(char d1, char d2);

bool isGreaterThan(std::string op1, std::string op2);

#endif COMMON_H_
