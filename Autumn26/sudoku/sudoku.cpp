#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>

int twod_to_oned(int row, int col, int rowlen){
    return row*rowlen+col; //takes a position in the grid (x row,y col) and the dimension n, and returns the corresponding index for the 1d vector.
}

int mfind(int n, const std::vector<int>& v){ //function takes in a target value n and a vector. returns index of n, or -1 if n dne.
    for(int i = 0; i < v.size(); i++){ //loop thru vector and compare each index to the target
        if(v[i] == n){ 
            return i;
        }
    }
    return -1;
}

bool check_sequence(const std::vector<int>& v){ //checks a vector of n length for all numbers 1 to n.
    bool valid = true; //start it as true by default
    int find;
    int n = v.size();

    for(int i = 1; i <= n; i++){
        find = mfind(i,v);
        if(find == -1){
            valid = false; //as soon as we find one number 1 -> n not present in v it becomes false
        }
    }
    return valid; //no need to check for duplicates since v has n slots, if all numbers 1 to n are present, they will fill every slot and leave no extra room.
}


void get_row(int r, const std::vector<int>& in, std::vector<int>& out){
    int n = std::sqrt(in.size()); //finds the length of one row since in.size = n*n
    
    for(int i = 0; i < n; i++){
        int targetIndex = twod_to_oned(r,i,n);
        out.push_back(in[targetIndex]); //extracts the n values using twod_to_oned to convert an x,y,n into the number in the input vector
    }
}

void get_col(int c, const std::vector<int>& in, std::vector<int>& out){
    int n = std::sqrt(in.size()); //finds the length of one column since in.size = n*n
    
    for(int i = 0; i < n; i++){
        int targetIndex = twod_to_oned(i,c,n);
        out.push_back(in[targetIndex]); //extracts the n values using twod_to_oned to convert an x,y,n into the number in the input vector
    }
}


void get_subsq(int subs, const std::vector<int>& in, std::vector<int>& out){

    int side = std::sqrt(in.size()); //side length for whole grid
    int subSide = std::sqrt(side); //sidelength for subsquare

    int blockRow = subs / subSide; //how many full rows of subsquare blocks come before this one
    int blockCol = subs % subSide; //position of the block within its row of blocks - aka the column of the block

    int startRow = blockRow * subSide; //row index of the top left cell within our selected block 
    int startCol = blockCol * subSide; //column index of the top left cell within our selected block 

    for(int i = 0; i < subSide; i++){ //visit every cell of the subsquare, left to right -> top to bottom;
        for(int j = 0; j < subSide; j++){
            int targetIndex = twod_to_oned(startRow + i, startCol + j, side); //i and j are offsets from the top-left cell of the subsquare

            out.push_back(in[targetIndex]);
        }
    }
     
}

// function valid_sudoku 
// takes in input:
// - a one dimensional vector representing a sudoku
// returns:
// - a boolean which is true if the sudoku is valid and false if it isn't valid

// write your code where indicated
// i.e. within the two remaining incomplete 'for' loops
// do not alter anything else

bool valid_sudoku(const std::vector<int>& g){
    int side = std::sqrt(g.size()); 
    std::vector<int> seq;

    //for each row...
    for(int i = 0; i < side; i++){
        seq.clear();
        get_row(i, g, seq);

        if(!check_sequence(seq)){ 
            return false;
        }
    }

    //for each column...
    for(int i = 0; i < side; i++){
        seq.clear();
        get_col(i, g, seq);

        if(!check_sequence(seq)){ 
            return false;
        }
    }

    //for each subsquare...
   for(int i = 0; i < side; i++){
        seq.clear();
        get_subsq(i, g,seq);

        if(!check_sequence(seq)){ 
            return false;
        }
    }

    return true; //if it hasnt returned with false by this point, it is valid
}

int main(int argc, char* argv[]){

    if(argc != 2){
        std::cout << "one argument needed" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<int> s;

    // beginning of block of code reading the sudoku from the text file

    std::ifstream infile;
    infile.open(argv[1]);

    if(!infile.is_open()){
        std::cout << "error, can't open input file" << std::endl;
        return EXIT_FAILURE;
    }

    int tmp;

    while(infile >> tmp){
        s.push_back(tmp);
    }
    // end of block of code reading the sudoku from the text file
    // we now have the content of the sudoku in vector s

    int side = std::sqrt(s.size());
    // assuming it is a valid square grid in terms of size
    // (if it isn't, the program will not work properly, which is expected)

    // printing the content of the sudoku (as a square);
    // the sudoku is stored as a one-dimensional vector
    // but the vector can be indexed using two indices
    // by converting the indices of a two dimensional representation
    // into the corresponding one-dimensional index (using our function twod_to_oned)

    for(int i = 0; i < side; i++){
        for(int j = 0; j < side; j++){
            std::cout << s[twod_to_oned(i, j, side)] << " ";
        }
        std::cout << std::endl;
    }

    // calling the function checking if the sudoku is a valid one:

    bool valid = valid_sudoku(s);

    if(valid){
        std::cout << "valid" << std::endl;
    }
    else{
        std::cout << "not valid" << std::endl; 
    }

}