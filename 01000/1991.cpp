#include <iostream>
#include <vector>
#define MAX 27
using namespace std;

int N;
vector<int> adj[MAX];

string dfs(int x, int m){
    string left = "", right = "";
    
    if (adj[x][0] != 0){
        left = dfs(adj[x][0], m);
    }
    if (adj[x][1] != 0){
        right = dfs(adj[x][1], m);
    }

    string ret;
    if (m == 0){ // 전위
        ret = (char)(x + 64) + left + right;
    }
    else if (m == 1){ // 중위
        ret = left + (char)(x + 64) + right;
    }
    else if (m == 2){ // 후위
        ret = left + right + (char)(x + 64);
    }
    return ret;
}

int main(){
    // char a = 65;
    // A = 1 // 후처리로 64 더해서 character로 출력하기
    cin >> N;

    for(int i = 0; i < N; i++){
        char parent, left, right;
        cin >> parent >> left >> right;
        int p = (int)(parent) - 64;
        int l = (int)(left) - 64;
        int r = (int)(right) - 64;

        if (left != '.'){
            adj[p].push_back(l);
        }
        else{
            adj[p].push_back(0);
        }
        if (right != '.'){
            adj[p].push_back(r);
        }
        else{
            adj[p].push_back(0);
        }
    }

    for(int i = 0; i < 3; i++){
        cout << dfs(1, i) << '\n';
    }

    return 0;
}