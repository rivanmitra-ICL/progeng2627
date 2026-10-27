#include <iostream>
#include <cmath>

double myPow(double base, int exp){
    double result = 1;
    if(exp<0){
        base = 1/base;
        exp = -exp;
    }
    for(int i = 0; i < exp; i++){
        result = result * base;
    }
    return result;
}

double sumOfPowers(double x, int n){
    double result = 0;
    for(int i = 1; i <= n; i++){
        result = result + myPow(x, i);
    }
    return result;
}

int main(){
    double x, output;
    int n;
    // std::cout << "please enter x:" << std::endl;
    // std::cin >> x;
    // std::cout << "please enter n:" << std::endl;
    // std::cin >> n;

    // output = sumOfPowers(x,n);
    // std::cout << "the result is: " << output << std::endl;

    std::cout << (sumOfPowers(2,3) == 14) << std::endl;
    std::cout << (sumOfPowers(3,2) == 12) << std::endl;
    std::cout << (sumOfPowers(0.5,2) == 0.75) << std::endl;
    std::cout << (sumOfPowers(5,1) == 5) << std::endl;

    std::cout << (sumOfPowers(5,1) == 1) << std::endl;

}