#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;
int T, P;

int main(){
    cin >> N;
    for(int i = 0; i < 6; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    cin >> T >> P;

    int ans1 = 0;
    for(int i = 0; i < v.size(); i++){
        ans1 += (v[i] / T);
        if (v[i] % T != 0) ans1 += 1;
    }

    cout << ans1 << '\n';
    cout << N / P << ' ' << N % P;

    return 0;
}