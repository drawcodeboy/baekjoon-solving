#include <iostream>
#include <map>
using namespace std;

int N, M;
map<string, string> m;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        string a, b;
        cin >> a >> b;
        m[a] = b;
    }

    for(int i = 0; i < M; i++){
        string a;
        cin >> a;
        cout << m[a] << '\n';
    }

    return 0;
}