#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>


int search_vector(std::string s, const std::vector<std::string>& vin){
    for(int i = 0; i < vin.size(); i++){
        if(vin[i] == s){
            return i;
        }
    }
    return -1;
}

void union_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout){
    vout.clear();

    // everything from the first warehouse goes in
    for(int i = 0; i < vin1.size(); i++){
        vout.push_back(vin1[i]);
    }

    // only add items from the second warehouse that aren't already there
    for(int i = 0; i < vin2.size(); i++){
        if(search_vector(vin2[i], vout) == -1){
            vout.push_back(vin2[i]);
        }
    }
}

void intersection_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout){
    vout.clear();

    // keep items from the first warehouse that also appear in the second
    for(int i = 0; i < vin1.size(); i++){
        if(search_vector(vin1[i], vin2) != -1 && search_vector(vin1[i], vout) == -1){
            vout.push_back(vin1[i]);
        }
    }
}


int main(){

    std::vector<std::string> vin1;
    std::vector<std::string> vin2;
    std::vector<std::string> vout;

    std::string firstInput, secondInput, temp;
    std::cout << "enter the name of your first file:"<< std::endl;
    std::cin >> firstInput;
    std::cout << "enter the name of your second file:"<< std::endl;
    std::cin >> secondInput;

    std::ifstream firstFile; 
    firstFile.open(firstInput+".txt");

    if(!firstFile.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }
    while(firstFile >> temp){
        vin1.push_back(temp); 
    }
    firstFile.close(); 


        std::ifstream secondFile; 
    secondFile.open(secondInput+".txt");

    if(!secondFile.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }
    while(secondFile >> temp){
        vin2.push_back(temp); 
    }
    secondFile.close(); 

    std::vector<std::string> unionResult;
    std::vector<std::string> intersectionResult;

    union_vector(vin1, vin2, unionResult);
    intersection_vector(vin1, vin2, intersectionResult);

    // write the union
    std::ofstream unionFile;
    unionFile.open("union.txt");

    if(!unionFile.is_open()){
        std::cout << "error opening union.txt" << std::endl;
        return EXIT_FAILURE;
    }

    for(int i = 0; i < unionResult.size(); i++){
        unionFile << unionResult[i] << std::endl;
    }

    unionFile.close();

    // write the intersection
    std::ofstream intersectionFile;
    intersectionFile.open("intersection.txt");

    if(!intersectionFile.is_open()){
        std::cout << "error opening intersection.txt" << std::endl;
        return EXIT_FAILURE;
    }

    for(int i = 0; i < intersectionResult.size(); i++){
        intersectionFile << intersectionResult[i] << std::endl;
    }

    intersectionFile.close();


}