#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

std::vector<double> line_to_vector(std::string s){

    std::stringstream ss;
    std::string tmp;
    std::vector<double> out;

    ss << s;
    while(ss >> tmp){
        out.push_back(std::stod(tmp));
    }
    return out;
}

std::vector<std::vector<double>> fileToMatrix(std::string fileName){
    std::ifstream infile;
    std::vector<std::vector<double>> outMatrix;

    infile.open(fileName);
 
    std::string line;

    while(std::getline(infile, line)){
        outMatrix.push_back(line_to_vector(line));
    }

    return outMatrix;
}

double scalarProd(std::vector<double>& v1, std::vector<double>& v2){
    double total = 0;

    for(int i = 0; i < v1.size() ; i++){
        total = total + v1[i] * v2[i];
    }  

    return total;

}


std::vector<std::vector<double>> mult(const std::vector<std::vector<double>>& m1, const std::vector<std::vector<double>>& m2){
    std::vector<std::vector<double>> solution; 
    double inputToSol;

    for (int x = 0; x < m1.size() ; x++){
        std::vector<double> row = m1[x];
        std::vector<double> resultRow;
        
        for (int y = 0; y < m2[0].size() ; y++){
            
            std::vector<double> column;
            for(int i = 0; i < m2.size() ; i++){
                column.push_back(m2[i][y]);
            }

            inputToSol = scalarProd(row, column);
            resultRow.push_back(inputToSol);
        }

        solution.push_back(resultRow);
    }


    return solution;
}

void printMatrix(const std::vector<std::vector<double>>& m){
    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[i].size(); j++){
            std::cout << m[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}


int main(int argc, char* argv[]){

    if(argc != 3){
        std::cout << "two arguments needed" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<std::vector<double>> m1 = fileToMatrix(argv[1]);
    std::vector<std::vector<double>> m2 = fileToMatrix(argv[2]);

    std::vector<std::vector<double>> m3 = mult(m1, m2);

    printMatrix(m1);
    std::cout << " " << std::endl << std::endl;
    std::cout << "*" << std::endl << std::endl;
    printMatrix(m2);
    std::cout << " " << std::endl << std::endl;
    std::cout << "=" << std::endl << std::endl;
    printMatrix(m3);


}