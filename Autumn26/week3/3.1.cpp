#include <iostream>

int main(){
    std::string text;

    while((text != "STOP")&&(text != "stop")&&(text != "Stop")){
        std::cout << text << std::endl;
        std::cin >> text;
    }
}