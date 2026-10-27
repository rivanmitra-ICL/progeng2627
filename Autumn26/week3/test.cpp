#include <iostream>
int main(){
    int r = 0;
    for(int i = 3; i < 7; i++){
        if(!((r < i) && (r < 2))){
            r++;
        }
    }
    std::cout << r << std::endl;
}