#include <iostream>
#include <string>

int main(){
    
    std::string userName;
    std::string userSurname;
    std::cout << "what is your name" << std::endl;
    std::cin >> userName;
    std::cout << "what is your surname" << std::endl;
    std::cin >> userSurname;
    std::cout << "hello " << userName << userSurname << std::endl;
    
}