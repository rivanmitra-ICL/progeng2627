#include <iostream>

int main(){
    double input, sum, counter;
    sum = 0.0;
    counter = 0.0;

    while(input != 0){
        std::cin >> input;
        sum = sum + input;
        counter = counter + 1;
        std::cout << "average is: " << sum/counter << std::endl;
    }

}