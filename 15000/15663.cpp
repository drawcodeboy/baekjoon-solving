#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include<string>
#define MAX 9
using namespace std;

int N, M;
vector<int> v;
vector<int> seq;
set<vector<int>> s;
bool visited[MAX];

void dfs(int x, int cnt){
    if(cnt == M){
        vector<int> result;
        for(int i = 0; i < seq.size(); i++){
            result.push_back(seq[i]);
        }
        // cout << result;
        s.insert(result);
        // cout << '\n';
        return;
    }

    for(int i = 0; i < v.size(); i++){
        if (visited[i] == true) continue;
        visited[i] = true;
        seq.push_back(v[i]);
        dfs(v[i], cnt+1);
        visited[i] = false;
        seq.pop_back();
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        visited[i] = true;
        seq.push_back(v[i]);
        dfs(v[i], 1);
        visited[i] = false;
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