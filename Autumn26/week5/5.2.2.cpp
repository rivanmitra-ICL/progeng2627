#include <iostream>
#include <vector>


void filter_v(const std::vector<int>& vin, int t, std::vector<int>& vout){

    for(int i = 0; i < vin.size() ; i++){
        if(vin[i] < t){
            vout.push_back(vin[i]);
        }

    }

}

int main(){

    std::vector<int> v;
    std::vector<int> v_out;
    int n, input, t;

    std::cout << "enter the filter of the vector, t: " << std::endl;
    std::cin >> t;
    std::cout << "enter the size of the vector, n: " << std::endl;
    std::cin >> n;
    std::cout << "enter your values: " << std::endl;
    for(int i=0; i<n; i++){
        std::cin >> input;
        v.push_back(input);
    }

    filter_v(v, t, v_out);
    std::cout << "printing vector:" << std::endl;
    for(int i = 0; i < v_out.size(); i++){
        std::cout << v_out[i] << " ";
    }

}