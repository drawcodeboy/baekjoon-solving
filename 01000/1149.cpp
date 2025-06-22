#include <iostream>
using namespace std;

int arr[1001][3];
int cache[1001][3];
int N;

int main(){
    cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 3; j++){
            cin >> arr[i][j];
            if (i == 1){
                cache[i][j] = arr[i][j];
            }
        }
    }

    for(int i = 2; i <= N; i++){
        cache[i][0] = arr[i][0] + min(cache[i-1][1], cache[i-1][2]);
        cache[i][1] = arr[i][1] + min(cache[i-1][0], cache[i-1][2]);
        cache[i][2] = arr[i][2] + min(cache[i-1][0], cache[i-1][1]);
    }

    int result = N * 1000;
    for(int i = 0; i < 3; i++){
        result = min(result, cache[N][i]);
    }
    cout << result;
    return 0;
}