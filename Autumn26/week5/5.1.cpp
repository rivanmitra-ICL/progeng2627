#include <iostream>
#include <vector>

int main(){
    std::vector<int> v;
    int n, t, input;

    std::cout << "enter the size of the vector, n: " << std::endl;
    std::cin >> n;
    std::cout << "enter your values: " << std::endl;
    for(int i=0; i<n; i++){
        std::cin >> input;
        v.push_back(input);
    }


    std::cout << "what is the maximum number, t: " << std::endl;
    std::cin >> t;
    for(int i = 0; i<n; i++){
        if(v[i] < t){
            std::cout << v[i] << " ";
        }
    }



}