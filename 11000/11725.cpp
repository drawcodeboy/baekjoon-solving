#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int N;
vector<int> adj[MAX];
bool visited[MAX];
int parent[MAX];

void tracking(int x){
    for(int i = 0; i < adj[x].size(); i++){
        if(!visited[adj[x][i]]){
            visited[adj[x][i]] = true;
            parent[adj[x][i]] = x;
            tracking(adj[x][i]);
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    visited[1] = true;
    tracking(1);

    for(int i = 2; i <= N; i++){
        cout << parent[i] << '\n';
    }

    return 0;
}