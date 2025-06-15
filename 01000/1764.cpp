#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

set<string> s;

int main(){
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string a; cin >> a;
        s.insert(a);
    }

    vector<string> v;
    for(int i = 0; i < M; i++){
        string a; cin >> a;
        if(s.count(a) == 1){
            v.push_back(a);
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << '\n';

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << '\n';
    }

    return 0;
}