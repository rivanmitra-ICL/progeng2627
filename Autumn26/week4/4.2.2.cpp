#include <iostream>

int smallest_factor(int n){
    
        for(int cf = 2; cf < n; cf++){
        if( (n % cf) == 0){
            return cf;
        }
    }
    return 0;
}

int main(){
    int LB, UB, result;

    std::cout << "enter the lower bound" << std::endl;
    std::cin >> LB;

    std::cout << "enter the upper bound" << std::endl;
    std::cin >> UB;

    for(int i=LB; i<(UB+1); i++){
        result = smallest_factor(i);
        if(result == 0){
        std::cout << i << " "; 
        }
    }

}


