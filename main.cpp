#include "Calculator.h"

int main() {
    std::string a = "1 - (35*2 - 13 +15^2 - 5^3)";
    Calculator m = Calculator(a);
    std::cout << m.isValidInput() << std::endl;
    try {
        std::cout << m.Calc() << std::endl;
    } catch (const std::invalid_argument& e) {}
    std::cout << m.ToPostfix(a) << std::endl;
}