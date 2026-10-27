#include <iostream>

int main(){
    double temp, converted;
    std::string unit;

    std::cout << "enter the temperature and then the unit (C for celcius F for fahrenheit):" << std::endl;
    std::cin >> temp >> unit;
    
    if((unit == "C") || (unit == "c")){
        converted = (temp * (9.0/5.0)) + 32;
    }else if((unit == "F") || (unit == "f")){
        converted = ((temp - 32) * (5.0/9.0));
    }else{
        std::cout << "error enter only C or F for the 2nd input" << std::endl;
    }
    
    std::cout << "the converted temperature is:" << converted << std::endl;

}