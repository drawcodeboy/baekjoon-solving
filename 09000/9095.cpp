#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;

    int arr[11];

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    // DP
    for(int i = 4; i <= 10; i++){
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }

    for(int i = 0; i < T; i++){
        int N; cin >> N;
        cout << arr[N] << '\n';
    }

    return 0;
}