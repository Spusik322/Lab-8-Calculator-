#include "Calculator.h"
#include "stack.h"
#include <stdexcept>

Calculator::Calculator(std::string expression) {
    expression = transformation(expression);
    infixExpr = expression;
}

std::string Calculator::transformation(std::string& expr) {
    int length = expr.length();
    int i = 0;
    while (i < length) {
        if (expr[i] == ' ') {
            expr.erase(i, 1);
            length--;
            i--;
        }
        i++;
    }
    return expr;
}

bool Calculator::isValidInput() {
    int parenCount = 0;
    bool lastWasOperator = false;
    bool lastWasOperand = false;
    bool foundDigit = false;
    bool foundDot = false;
    for (size_t i = 0; i < infixExpr.length(); i++) {
        char c = infixExpr[i];
        if (c == '(') {
            parenCount++;
            if (lastWasOperand)
                return false;
            lastWasOperator = false;
            lastWasOperand = false;
            foundDigit = false;
        } else if (c == ')') {
            parenCount--;
            if (!foundDigit)
                return false;
            lastWasOperator = false;
            lastWasOperand = true;
        } else if (isdigit(c)) {
            lastWasOperator = false;
            lastWasOperand = true;
            foundDigit = true;
        } else if (c == '+' || c == '*' || c == '/') {
            if (lastWasOperator || !lastWasOperand)
                return false;
            foundDot = false;
            lastWasOperator = true;
            lastWasOperand = false;
        } else if (c == '-') {
            if (lastWasOperator) {
                if (i + 1 >= infixExpr.length() || !isdigit(infixExpr[i + 1]) && infixExpr[i + 1] != '(')
                    return false;
            } else if (i == 0 || (i > 0 && i + 1 <= infixExpr.length() && infixExpr[i - 1] == '(' && !(isdigit(infixExpr[i + 1]) || infixExpr[i + 1] == '(')) ) {
                return false;
            }
            lastWasOperator = true;
            lastWasOperand = false;
        } else if (c == '^') {
            if (lastWasOperator)
                return false;
            lastWasOperator = true;
            lastWasOperand = false;
        } else if (c == '.') {
            if (foundDot && !lastWasOperator)
                return false;
            if (i == 0)
                return false;
            if (!(isdigit(infixExpr[i - 1]) && isdigit(infixExpr[i + 1])))
                return false;
            foundDot = true;
        }
        else if (c != '.') {
            return false;
        }
    }
    return parenCount == 0 && !lastWasOperator && lastWasOperand;
}

long double Calculator::Execute(char op, long double first, long double second) {
    switch (op) {
        case '+': {
            return first + second;
        }
        case '-': {
            return first - second;
        }
        case '*': {
            return first * second;
        }
        case '/': {
            return first / second;
        }
        case '^': {
            return pow(first, second);
        }
        default: {
            return 0;
        }
    }
}

long double Calculator::Calc() {
    postfixExpr = ToPostfix(infixExpr);
    StackMinecraft<long double> locals;
    int counter = 0;
    for (int i = 0; i < postfixExpr.length(); i++) {
        char c = postfixExpr[i];
        if (isdigit(c)) {
            std::string number = GetStringNumber(postfixExpr, i);
            locals.push(stold(number));
        }
        else if (operationPriority.count(c)) {
            counter += 1;
            if (c == '~') {
                long double last = locals.size() > 0 ? locals.pop() : 0;
                locals.push(Execute('-', 0, last));
                continue;
            }
            long double second = locals.size() > 0 ? locals.pop() : 0,
            first = locals.size() > 0 ? locals.pop() : 0;
            locals.push(Execute(c, first, second));
        }
    }
    return locals.pop();
}

std::string Calculator::GetStringNumber(const std::string &expr, int& pos)
{
    std::string strNumber;
    for (; pos < expr.length(); pos++) {
        char num = expr[pos];
        if (isdigit(num) || num == '.') {
            strNumber += num;
        }
        else {
            pos--;
            break;
        }
    }
    return strNumber;
}

std::string Calculator::ToPostfix(std::string infixExpr) // Принятие на обработку
{
    std::string postfixExpr;
    StackMinecraft<char> stack = StackMinecraft<char>(infixExpr.length());
    for (int i = 0; i < infixExpr.length(); i++) {
        char c = infixExpr[i];
        if (isdigit(c)) {
            postfixExpr += GetStringNumber(infixExpr, i) + " ";
        }
        else if (c == '(') {
            stack.push(c);
        }
        else if (c == ')') {
            while (stack.size() > 0 && stack.top() != '(') {
                postfixExpr += stack.pop();
            }
            stack.pop();
        }
        else if (operationPriority.count(c)) {
            char op = c;
            if (op == '-' && (i == 0 || (i > 1 && operationPriority.count(infixExpr[i-1])))) {
                op = '~';
            }
            while (stack.size() > 0 && ( operationPriority[stack.top()] >= operationPriority[op]) && infixExpr[i-1] != ')') {
                postfixExpr += stack.pop();
            }
            stack.push(op);
        }
    }
    while(stack.size() > 0) {
        postfixExpr += stack.pop();
    }
    return postfixExpr;
}

long double Calculator::Processing() {
    if (isValidInput()) {
        return Calc();
    }
    throw std::invalid_argument("Invalid input");
}