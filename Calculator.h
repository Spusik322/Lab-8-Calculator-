#pragma once
#include <map>
#include <functional>
#include <iostream>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <string>

class Calculator {
public:

    std::map <char,int> operationPriority {{'(', 0},{'+', 1},{'-', 1},{'*', 2},{'/', 2},{'^', 3},{'~', 4}};
    std::string infixExpr;
    std::string postfixExpr;

    Calculator(std::string expression);

    std::string transformation(std::string& expr);

    bool isValidInput();

    long double Execute(char op, long double first, long double second);

    long double Calc();

    std::string GetStringNumber(const std::string &expr, int& pos);

    std::string ToPostfix(std::string infixExpr);

};