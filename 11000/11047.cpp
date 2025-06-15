// A_i가 A_{i-1}이기 때문에 그리디로 단순하게 풀리는 문제임.
#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> v;

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        if (a > K){
            continue;
        }
        else{
            v.push_back(a);
        }
    }

    int res = 0;
    for(int i = v.size()-1; i >= 0; i--){
        res += (K / v[i]);
        K = K % v[i];
        if (K == 0) break;
    }

    cout << res;
    return 0;
}