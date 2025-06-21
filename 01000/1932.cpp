#include <iostream>
#define MAX 501
using namespace std;

int n;

int arr[MAX][MAX];
int cache[MAX][MAX];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> arr[i][j];
        }
    }

    cache[1][1] = arr[1][1];
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            int temp;
            if (j == 1){
                temp = cache[i-1][j];
            }
            else if(j == i){
                temp = cache[i-1][j-1];
            }
            else{
                temp = max(cache[i-1][j-1], cache[i-1][j]);
            }

            cache[i][j] = arr[i][j] + temp;
        }
    }

    int result = 0;
    for(int i = 1; i <= n; i++){
        result = max(result, cache[n][i]);
    }

    cout << result;

    return 0;
}