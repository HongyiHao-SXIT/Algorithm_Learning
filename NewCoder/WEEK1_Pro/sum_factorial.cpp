#include <iostream>

long long factorial(int num){
    long long fact = 1;
    for(int i = 1; i <= num; i++){
        fact *= i;
    }
    return fact;
}

int main(){
    long long sum = 0;
    int num;
    std::cin >> num;

    for(int i = 1; i <= num; i++){
        sum += factorial(i);
    }

    std::cout <<"1! + 2! + ... + " << num << "! = " << sum << std::endl;
    return 0;
}
