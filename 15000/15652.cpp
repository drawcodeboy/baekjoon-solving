#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> seq;

void dfs(int x, int cnt){
    if(cnt == M){
        for(int i = 0; i < seq.size(); i++){
            cout << seq[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = x; i <= N; i++){
        seq.push_back(i);
        dfs(i, cnt+1);
        seq.pop_back();
    }
}

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        seq.push_back(i);
        dfs(i, 1);
        seq.pop_back();
    }
    return 0;
}