#include <iostream>

int main(){
     int input;

     std::cout << "enter your number" << std::endl;
     std::cin >> input;
     
     for(int i=1; i<(input+1); i++){
        
        for(int k=1; k<(input+1); k++){
            std::cout << i*k << "\t";
        }

        std::cout << std::endl;

     }



}