#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define MAX 9
using namespace std;

int N, M;
vector<int> v;
vector<int> seq;
set<vector<int>> s;
bool counted[10001];

void dfs(int x, int cnt){
    if(cnt == M){
        vector<int> result;
        for(int i = 0; i < seq.size(); i++){
            result.push_back(seq[i]);
        }
        s.insert(result);
        return;
    }

    for(int i = x; i < v.size(); i++){
        seq.push_back(v[i]);
        dfs(i, cnt+1);
        seq.pop_back();
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        if(!counted[a]){
            v.push_back(a);
            counted[a] = true;
        }
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        seq.push_back(v[i]);
        dfs(i, 1);
        seq.pop_back();
    }

    set<vector<int>> ::iterator p;
    for(p = s.begin(); p != s.end(); p++){
        vector<int> r = *p;
        for(int i = 0; i < r.size(); i++){
            cout << r[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}