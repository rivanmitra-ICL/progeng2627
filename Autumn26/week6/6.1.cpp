#include <iostream>
#include <fstream>
#include <cstdlib>

int main(){

    std::string userFile;
    std::cout << "enter the name of your file:"<< std::endl;
    std::cin >> userFile;


    std::ifstream infile; 

    infile.open(userFile + ".txt");

    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    int tmp;

    while(infile >> tmp){
        std::cout << tmp << std::endl;
    }

    infile.close();
}