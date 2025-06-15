#include <iostream>
#define MOD 10007
using namespace std;

int main(int argc, char* argv[]){
    int n;
    cin >> n;
    int arr[1001];

    arr[1] = 1;
    arr[2] = 3;

    for(int i = 3; i <= n; i++){
        if(i % 2 == 1){
            arr[i] = ((arr[i-1] % MOD) * 2 - 1) % MOD;
        }
        else{
            arr[i] = ((arr[i-1] % MOD) * 2 + 1) % MOD;
        }
    }

    cout << arr[n];
    return 0;
}