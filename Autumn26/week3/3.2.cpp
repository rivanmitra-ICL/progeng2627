#include <iostream>

int main(){

    int n, total;
    std::cin >> n;
    total = n;

    for(int i = 1; i < n; i++){
        total = total*(n-i);
    }

    std::cout << total << std::endl;
}
