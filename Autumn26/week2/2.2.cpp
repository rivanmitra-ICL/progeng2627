#include <iostream>

int main(){
    int year, rem4, rem100, rem400;
    bool leapYear = false;
    std::cout << "enter the year" << std::endl;
    std::cin >> year;
    rem4 = year % 4;
    rem100 = year % 100;
    rem400 = year % 400;


    if(rem4 == 0){//its a multiple of 4
        
        if(rem100 != 0){
            leapYear = true;
        } else {
            if(rem400 == 0){
                leapYear = true;
            }
        }
    }

    if(leapYear == true){
        std::cout << "LEAP YEAR" << std::endl; 
    }else{
        std::cout << "NOT LEAP YEAR" << std::endl;
    }

}