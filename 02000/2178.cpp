#include <iostream>
#define MAX 100
using namespace std;

int N, M;
char adj[MAX+1][MAX+1];
int counted[MAX+1][MAX+1];
pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int i, int j){
    for(int k = 0; k < 4; k++){
        int dy = i + dir[k].first;
        int dx = j + dir[k].second;
        if (dy < 1 || dy > N || dx < 1 || dx > M){
            continue;
        }
        if ((counted[dy][dx] != 0) && (counted[dy][dx] < counted[i][j] + 1)){
            continue;
        }
        if (adj[dy][dx] == '0'){
            continue;
        }

        counted[dy][dx] = counted[i][j] + 1;
        cout << dy << ' ' << dx << ' ' << counted[dy][dx] << '\n';
        dfs(dy, dx);
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        for(int j = 0; j < s.size(); j++){
            adj[i+1][j+1] = s[j];
        }
    }

    counted[1][1] = 1;
    dfs(1, 1);

    cout << counted[N][M];

    return 0;
}