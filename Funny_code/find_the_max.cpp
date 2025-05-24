#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int num[10];
    void max(int arr[]);

    for(int i = 0; i < 10; i++){
        cin >> num[i];
    }

    max(num[10]);

    return 0;
}

void find_max(int arr[]){
    int max = arr[0], position = 0;

    for(int i = 0; i < 10; i++){
        if(max < arr[i]){
            max = arr[i];
            position = i + 1;
        }
    }

    for(int i = 0; i< 10; i++){
        cout<< arr[i] << " ";
    }

    cout <<endl;

    cout << "The largest number is :" << max << endl << "The positon of this number is : "<< position <<endl;
}