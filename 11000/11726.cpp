#include <iostream>
#define MOD 10007
using namespace std;

int main(int argc, char* argv[]){
    int n;
    cin >> n;
    int arr[1001];

    arr[1] = 1;
    arr[2] = 2;

    for(int i = 3; i <= n; i++){
        arr[i] = ((arr[i-1] % MOD) + (arr[i-2] % MOD)) % MOD;
    }

    cout << arr[n];
    return 0;
}