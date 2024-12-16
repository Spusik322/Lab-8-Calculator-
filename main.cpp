#include "Calculator.h"

int main() {
    std::string a = "1 - (";
    Calculator m = Calculator(a);
    std::cout << m.isValidInput() << std::endl;
    try {
        std::cout << m.Processing() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Error!" << std::endl;
    }
    std::cout << m.ToPostfix(a) << std::endl;
}