#include <iostream>

int main(){
    int n, steps;
    steps = 0;

    std::cout << "enter your number" << std::endl;
    std::cin >> n;

    while(n != 1){
        if((n % 2) == 0){
            n = n/2;
        }else{
            n = 3*n + 1;
        }
        steps++;
        std::cout << n << " ";
    }

    std::cout << "total steps: " << steps << std::endl;

}