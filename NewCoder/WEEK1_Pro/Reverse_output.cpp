#include <iostream>

int main(){
    int arr[3];

    for(int i = 0; i < 3; i ++){
        std::cin >> arr[i];
    }

    for(int i = 2; i >= 0; i --){
        std::cout << arr[i] << " ";
    }

    return 0;
}