
#include <iostream>

void divide(int a, int b, int& quotient, int& remainder) {
    quotient = a / b;
    remainder = a % b;
}

int main() {
    int a, b;
    int q, r;

    std::cout << "Enter two integers: ";
    std::cin >> a >> b;

    divide(a, b, q, r);

    std::cout << "Quotient: " << q << std::endl;
    std::cout << "Remainder: " << r << std::endl;
}
