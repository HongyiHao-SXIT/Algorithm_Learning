#include <iostream>

using namespace std;

int main(){
    int num[10],positon = 0, max = 0;

    for(int i = 0; i < 10; i++){
        cin >> num[i];
    }

    max = num[0];

    for(int i = 0; i < 10; i++){
        if(max < num[i]){
            max = num[i];
            positon = i + 1;
        }
    }

    for(int i = 0; i< 10; i++){
        cout<< num[i] << " ";
    }

    cout <<endl;
    
    cout << "The largest number is :" << max << endl << "The positon of this number is : "<< positon <<endl;
    return 0;
}
