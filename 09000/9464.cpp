#include <iostream>
#define MAX 100001
using namespace std;

int arr[MAX][2];
int cache[MAX][2];

int main(){
    int T; cin >> T;
    for(int t = 0; t < T; t++){
        int N; cin >> N;
        for(int i = 1; i <= N; i++){
            cin >> arr[i][0];
        }
        for(int i = 1; i <= N; i++){
            cin >> arr[i][1];
        }

        cache[1][0] = arr[1][0];
        cache[1][1] = arr[1][1];

        cache[2][0] = cache[1][1] + arr[2][0];
        cache[2][1] = cache[1][0] + arr[2][1];

        for(int i = 3; i <= N; i++){
            cache[i][0] = arr[i][0] + max(cache[i-1][1], cache[i-2][1]);
            cache[i][1] = arr[i][1] + max(cache[i-1][0], cache[i-2][0]);
        }

        cout << max(cache[N][0], cache[N][1]) << '\n';
    }

    return 0;
}