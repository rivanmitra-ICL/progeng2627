#include <iostream>

int main(){
    int n, rem;

    std::cout << "please enter a number" << std::endl;
    std::cin >> n;

    rem = n % 3;

    if(rem == 0){
        std::cout << "it is a multiple of 3" << std::endl;
    }

    else{
        std::cout << "not a multiple of 3" << std::endl;
    }



}