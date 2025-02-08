# include <iostream>
# include <stdio.h>
# include <math.h>

using namespace std;

int n, arr[1010][5], sum[1010];
int cnt;

int main () {
    cin >> n;
    for(int i = 0; i <n; n++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        sum[i] = arr[i][0] + arr[i][1] + arr[i][2]; 
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(abs (arr[i][1] - arr[j][1]) <= 5 && abs (arr[i][2] - arr[j][2]) <= 5 && abs (arr[i][3] - arr[j][3]) <= 5 && abs (sum[i] - sum[j]) <= 10){
                cnt++;
            }
        }
    }
    cout << cnt <<endl;
    return 0;
}